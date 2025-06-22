#include "mytcpserver.h"
#include <QDebug>
#include "dbsingleton.h"
#include <QCoreApplication>
#include <QDir>
#include <QDateTime>
#include <QSqlError>
#include <limits>

QString getDatabasePath() {
    QDir dir(QCoreApplication::applicationDirPath());
    dir.cdUp();
    dir.cdUp();
    dir.cdUp();
    QString dbPath = dir.filePath("DataBase.db");
    return QDir(dbPath).absolutePath();
}

MyTcpServer::MyTcpServer(UserUtils* userUtils, EquationsSolver* eqSolver, QObject *parent)
    : QTcpServer(parent), m_userUtils(userUtils), m_eqSolver(eqSolver)
{
    QString dbPath = getDatabasePath();
    if (!DbSingleton::instance().openDB(dbPath)) {
        qInfo() << "[SERVER] Failed to connect to database!";
        return;
    }
    if (this->listen(QHostAddress::Any, 33333)) {
        qInfo() << "[SERVER] Server listening on port 33333";
    } else {
        qInfo() << "[SERVER] Error starting server:" << this->errorString();
    }
}

MyTcpServer::~MyTcpServer() {}

void MyTcpServer::incomingConnection(qintptr socketDescriptor)
{
    mTcpSocket = new QTcpSocket(this);
    if (mTcpSocket->setSocketDescriptor(socketDescriptor)) {
        qInfo() << "[SERVER] Новый клиент подключился! SocketDescriptor:" << socketDescriptor;
        connect(mTcpSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
        connect(mTcpSocket, &QTcpSocket::disconnected, this, [this](){
            qInfo() << "[SERVER] The client has disconnected!";
            mTcpSocket->deleteLater();
        });
    } else {
        qInfo() << "[SERVER] Failed to initialize socket!";
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
        qInfo() << "[SERVER] Sent to the client: ERROR Invalid request";
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
    else if (command == "REGISTER_CODE" && parts.size() == 2) {
        handleRegisterCode(parts[1]);
    }
    else if (command == "RECOVERY_CODE" && parts.size() == 2) {
        handleRecoveryCode(parts[1]);
    }
    else if (command == "CHANGE" && parts.size() == 3) {
        handleChangePassword(parts[1], parts[2]);
    }
    else if (command == "SOLUTION" && parts.size() == 7) {
        handleSolve(
            parts[1],
            parts[2].toDouble(),
            parts[3].toDouble(),
            parts[4].toInt(),
            parts[5].toDouble(),
            parts[6].toInt()
            );
    }
    else {
        mTcpSocket->write("ERROR Unknown command\n");
        qInfo() << "[SERVER] Sent to client: ERROR Unknown command";
    }
}

void MyTcpServer::handleRegister(const QString& login, const QString& password, const QString& email)
{
    QString err;
    int res = m_userUtils->registerUser(login, password, email, err);
    if (res == 0) {
        mTcpSocket->write("OK Registered\n");
    } else if (res == 1) {
        mTcpSocket->write("ERROR Login already taken\n");
    } else if (res == 2) {
        mTcpSocket->write("ERROR Email already exists\n");
    } else {
        mTcpSocket->write(("ERROR " + err + "\n").toUtf8());
    }
}

void MyTcpServer::handleLogin(const QString& login, const QString& password)
{
    if (m_userUtils->login(login, password)) {
        mTcpSocket->write("OK Logged in\n");
    } else {
        mTcpSocket->write("ERROR Invalid login or password\n");
    }
}

void MyTcpServer::handleCheckEmail(const QString& email)
{
    bool exists = m_userUtils->emailExists(email);
    mTcpSocket->write(exists ? "YES\n" : "NO\n");
}

void MyTcpServer::handleCheckLogin(const QString& login)
{
    bool exists = m_userUtils->loginExists(login);
    mTcpSocket->write(exists ? "YES\n" : "NO\n");
}

void MyTcpServer::handleRegisterCode(const QString& email)
{
    QString code = m_userUtils->generateRandomCode(6);
    QString error;
    bool ok = m_userUtils->sendEmailWithCode(email, code, error);
    if (ok)
        mTcpSocket->write(("OK Code sent " + code + "\n").toUtf8());
    else
        mTcpSocket->write(("ERROR " + error + "\n").toUtf8());
}

void MyTcpServer::handleRecoveryCode(const QString& login)
{
    QString email = m_userUtils->getEmailByLogin(login);
    if (email.isEmpty()) {
        mTcpSocket->write("ERROR No such user\n");
        return;
    }
    QString code = m_userUtils->generateRandomCode(6);
    QString error;
    bool ok = m_userUtils->sendEmailWithCode(email, code, error);
    if (ok)
        mTcpSocket->write(("OK Code sent " + code + "\n").toUtf8());
    else
        mTcpSocket->write(("ERROR " + error + "\n").toUtf8());
}

void MyTcpServer::handleChangePassword(const QString& login, const QString& password)
{
    bool ok = m_userUtils->changePasswordByLogin(login, password);
    mTcpSocket->write(ok ? "OK Password Changed" : "ERROR Password not changed\n");
}

void MyTcpServer::handleSolve(const QString& functionText, double a, double b, int methodIndex, double tolerance, int maxIterations)
{
    QString methodName = (methodIndex == 0) ? "Дихотомия" : "Простая итерация";
    QList<double> roots;
    int iterations = 0;
    bool success = false;

    if (methodIndex == 0) {
        roots = m_eqSolver->findAllRootsDichotomy(functionText, a, b, (b - a) / 1000.0, tolerance, maxIterations);
        success = !roots.isEmpty();
    } else if (methodIndex == 1) {
        roots = m_eqSolver->findAllRootsIteration(functionText, a, b, tolerance, maxIterations, 20);
        success = !roots.isEmpty();
    } else {
        mTcpSocket->write("ERROR Invalid method\n");
        return;
    }

    QStringList rootStrings;
    for (double r : roots)
        rootStrings << QString::number(r, 'g', 12);

    QString resultText = success
                             ? QString("x = <b>%1</b>").arg(rootStrings.join(", "))
                             : "<span style='color:red;'>Нет корней</span>";

    QString html = QString(
                       "<div style='font-family: Arial, sans-serif;'>"
                       "<h3 style='color: #2a2a2a;'>Решение уравнения</h3>"
                       "<p><b>Уравнение:</b> <code>%1 = 0</code></p>"
                       "<p><b>Метод:</b> %2</p>"
                       "<p><b>Интервал:</b> [%3, %4]</p>"
                       "<p><b>Точность:</b> %5</p>"
                       "<p><b>Ответ:</b> %6</p>"
                       "<p><b>Итераций:</b> %7</p>"
                       "</div>")
                       .arg(functionText)
                       .arg(methodName)
                       .arg(a)
                       .arg(b)
                       .arg(tolerance)
                       .arg(resultText)
                       .arg(methodIndex == 0 ? "-" : QString::number(iterations));

    QString response = "OK Solution\n" + html + "\n";
    mTcpSocket->write(response.toUtf8());
}
