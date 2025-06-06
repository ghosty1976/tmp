#include "mytcpserver.h"
#include "userutils.h"
#include "emailutils.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QRandomGenerator>
#include <QDebug>
#include <QCoreApplication>
#include <QDir>
#include <QRegularExpression>

QString getDatabasePath() {
    QString appDir = QCoreApplication::applicationDirPath();
    QString dbPath = QDir(appDir).filePath("DataBase.db");
    return QDir(dbPath).absolutePath();
}

MyTcpServer::MyTcpServer(QObject *parent)
    : QTcpServer(parent)
{
    if (!connectToDatabase()) {
        qDebug() << "Failed to connect to database!";
        return;
    }
    if (this->listen(QHostAddress::Any, 33333)) {
        qDebug() << "Server listening on port 33333";
    } else {
        qDebug() << "Error starting server: " << this->errorString();
    }
}

MyTcpServer::~MyTcpServer() {}

bool MyTcpServer::connectToDatabase()
{
    QString dbPath = getDatabasePath();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);
    if (!db.open()) {
        qDebug() << "Error: Unable to connect to the database at" << dbPath << db.lastError().text();
        return false;
    }
    qDebug() << "Database connected successfully at" << dbPath;
    return true;
}

void MyTcpServer::incomingConnection(qintptr socketDescriptor)
{
    mTcpSocket = new QTcpSocket(this);
    if (mTcpSocket->setSocketDescriptor(socketDescriptor)) {
        connect(mTcpSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    } else {
        delete mTcpSocket;
    }
}

void MyTcpServer::slotServerRead()
{
    QByteArray request = mTcpSocket->readAll();
    QString req = QString::fromUtf8(request).trimmed();
    QStringList parts = req.split(" ", Qt::SkipEmptyParts);

    if (parts.isEmpty()) {
        mTcpSocket->write("ERROR Invalid request\n");
        return;
    }
    QString command = parts[0].toUpper();

    if (command == "REGISTER" && parts.size() == 4) {
        handleRegister(parts[1], parts[2], parts[3]);
    }
    else if (command == "LOGIN" && parts.size() == 3) {
        handleLogin(parts[1], parts[2]);
    }
    else if (command == "EMAILCHECK" && parts.size() == 2) {
        handleCheckEmail(parts[1]);
    }
    else if (command == "LOGINCHECK" && parts.size() == 2) {
        handleCheckLogin(parts[1]);
    }
    else if (command == "RECOVERY" && parts.size() == 2) {
        handleRecovery(parts[1]);
    }
    else if (command == "VERIFY_CODE" && parts.size() == 2) {
        handleVerifyCode(parts[1]);
    }
    else if (command == "CHANGE" && parts.size() == 2) {
        handleChangePassword(parts[1]);
    }
    else if (command == "SOLUTION" && parts.size() == 5) {
        handleSolve(parts[1], parts[2].toDouble(), parts[3].toDouble(), parts[4].toInt());
    }
    else {
        mTcpSocket->write("ERROR Unknown command\n");
    }
}

// РЕГИСТРАЦИЯ
void MyTcpServer::handleRegister(const QString& login, const QString& password, const QString& email)
{
    QString err;
    int res = UserUtils::registerUser(login, password, email, err);
    if (res == 0)
        mTcpSocket->write("OK Registered\n");
    else if (res == 1)
        mTcpSocket->write("ERROR Login already taken\n");
    else if (res == 2)
        mTcpSocket->write("ERROR Email already exists\n");
    else
        mTcpSocket->write(QString("ERROR Registration failed: %1\n").arg(err).toUtf8());
}

// АВТОРИЗАЦИЯ
void MyTcpServer::handleLogin(const QString& login, const QString& password) {
    if (UserUtils::login(login, password))
        mTcpSocket->write("OK Logged in\n");
    else
        mTcpSocket->write("ERROR Invalid login or password\n");
}

// ПРОВЕРКА EMAIL
void MyTcpServer::handleCheckEmail(const QString& email) {
    if (UserUtils::emailExists(email))
        mTcpSocket->write("OK Email Exists\n");
    else
        mTcpSocket->write("ERROR Email does not exist\n");
}

// ПРОВЕРКА LOGIN
void MyTcpServer::handleCheckLogin(const QString& login) {
    if (UserUtils::loginExists(login))
        mTcpSocket->write("OK Login Exists\n");
    else
        mTcpSocket->write("ERROR Login does not exist\n");
}

// RECOVERY — универсальная команда
void MyTcpServer::handleRecovery(const QString& identifier)
{
    QString code = QString::number(QRandomGenerator::global()->bounded(100000, 999999));
    bool isEmail = identifier.contains("@") || identifier.contains(".");

    if (isEmail) {
        // Сначала ищем email в БД
        if (UserUtils::emailExists(identifier)) {
            QSqlQuery upd;
            upd.prepare("UPDATE Users SET restore_code = :code WHERE email = :email");
            upd.bindValue(":code", code);
            upd.bindValue(":email", identifier);
            if (!upd.exec()) {
                mTcpSocket->write("ERROR Database error\n");
                return;
            }
        } else {
            // Добавляем новую строку с этим email и restore_code
            QSqlQuery ins;
            ins.prepare("INSERT INTO Users (email, restore_code) VALUES (:email, :code)");
            ins.bindValue(":email", identifier);
            ins.bindValue(":code", code);
            if (!ins.exec()) {
                mTcpSocket->write("ERROR Database error\n");
                return;
            }
        }
        // Отправляем код на email в любом случае
        QString mailErr;
        if (EmailUtils::sendEmailSSL(identifier, "Recovery Code", "Your code: " + code, mailErr)) {
            mTcpSocket->write("OK Code Sent");
        } else {
            qDebug() << "MAIL SEND ERROR:" << mailErr;
            mTcpSocket->write("ERROR Failed to send code\n");
        }
        return;
    }

    // === логика если это логин ===
    QString email;
    QSqlQuery q;
    q.prepare("SELECT email FROM Users WHERE login = :login");
    q.bindValue(":login", identifier);
    if (!q.exec() || !q.next()) {
        mTcpSocket->write("ERROR No such login\n");
        return;
    }
    email = q.value(0).toString();

    QSqlQuery setId;
    setId.prepare("UPDATE Users SET student_id = 55, restore_code = :code WHERE email = :email");
    setId.bindValue(":code", code);
    setId.bindValue(":email", email);
    setId.exec();

    QString mailErr;
    if (EmailUtils::sendEmailSSL(email, "Recovery Code", "Your code: " + code, mailErr)) {
        mTcpSocket->write("OK Code Sent\n");
    } else {
        mTcpSocket->write("ERROR Failed to send code\n");
    }
}


// VERIFY_CODE — проверка кода (один аргумент)
void MyTcpServer::handleVerifyCode(const QString& code)
{
    QSqlQuery query;
    query.prepare("SELECT email FROM Users WHERE restore_code = :code");
    query.bindValue(":code", code);
    if (query.exec() && query.next()) {
        // Нашли — удаляем restore_code
        QString email = query.value(0).toString();
        QSqlQuery clear;
        clear.prepare("UPDATE Users SET restore_code = NULL WHERE email = :email");
        clear.bindValue(":email", email);
        clear.exec();
        mTcpSocket->write("OK Code Verified\n");
    } else {
        mTcpSocket->write("ERROR Invalid code\n");
    }
}

// CHANGE — меняет пароль, только там где student_id == 55
void MyTcpServer::handleChangePassword(const QString& password)
{
    QSqlQuery query;
    query.prepare("SELECT email FROM Users WHERE student_id = 55");
    if (query.exec() && query.next()) {
        QString email = query.value(0).toString();
        // Сохраняем новый хэш пароля
        QString hash = UserUtils::hashPassword(password);
        QSqlQuery upd;
        upd.prepare("UPDATE Users SET password = :password, student_id = NULL WHERE email = :email");
        upd.bindValue(":password", hash);
        upd.bindValue(":email", email);
        if (upd.exec())
            mTcpSocket->write("OK Password Changed\n");
        else
            mTcpSocket->write("ERROR Failed to change password\n");
    } else {
        mTcpSocket->write("ERROR No user for password change\n");
    }
}

// SOLUTION — стандартная обработка
void MyTcpServer::handleSolve(const QString& functionText, double a, double b, int methodIndex)
{
    // Здесь будет логика решения уравнения, если нужно — реализовать как в старом коде.
    mTcpSocket->write("OK Solution (not implemented here)\n");
}
