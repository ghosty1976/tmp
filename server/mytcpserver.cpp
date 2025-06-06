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
extern "C" {
#include "tinyexpr.h"
}
#include <limits>
#include <cmath>

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
        handleSolve(parts[1], parts[2].toDouble(), parts[3].toDouble(), parts[4].toInt(), parts[5].toDouble(), parts[6].toInt());

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

// RECOVERY
void MyTcpServer::handleRecovery(const QString& identifier)
{
    QString code = QString::number(QRandomGenerator::global()->bounded(100000, 999999));
    bool isEmail = identifier.contains("@") || identifier.contains(".");

    if (isEmail) {
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
        // Отправляем код на email
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


// VERIFY_CODE
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

// CHANGE
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

// SOLUTION
void MyTcpServer::handleSolve(const QString& functionText, double a, double b, int methodIndex, double tolerance, int maxIterations)
{
    QString methodName = (methodIndex == 0) ? "Дихотомия" : "Простая итерация";
    QList<double> roots;
    int iterations = 0;
    bool success = false;
    double root = 0;

    if (methodIndex == 0) {
        success = findRootDichotomyExpr(functionText, a, b, root, tolerance, maxIterations, iterations);
        if (success) roots.append(root);
    } else if (methodIndex == 1) {
        success = findRootIterationExpr(functionText, a, b, root, tolerance, maxIterations, iterations);
        if (success) roots.append(root);
    } else {
        mTcpSocket->write("ERROR Invalid method\n");
        return;
    }

    // КРАСИВЫЙ HTML (как раньше)
    QString html =
        R"(
    <div style="font-family:Segoe UI,Arial,sans-serif;max-width:460px;padding:16px 18px;background:#f8fafc;border-radius:10px;box-shadow:0 2px 8px rgba(0,0,0,0.10);">
      <h2 style="margin-top:0;color:#274690;text-align:center;letter-spacing:1px;">Результат решения</h2>
      <table style="width:100%;margin:18px 0 16px 0;font-size:16px;">
        <tr><td style="padding:4px 0;"><b>Метод:</b></td><td style="padding:4px 0;color:#4376b1;">%1</td></tr>
        <tr><td style="padding:4px 0;"><b>Интервал:</b></td><td style="padding:4px 0;">[%2, %3]</td></tr>
        <tr><td style="padding:4px 0;"><b>Точность:</b></td><td style="padding:4px 0;">%4</td></tr>
        <tr><td style="padding:4px 0;"><b>Количество итераций:</b></td><td style="padding:4px 0;">%5</td></tr>
        <tr><td style="padding:4px 0;"><b>Ответ:</b></td>
          <td style="padding:4px 0;color:#25653d;font-weight:bold;">%6</td>
        </tr>
      </table>
    </div>
    )";

    QString answer;
    if (success) {
        answer = QString("x = %1").arg(root, 0, 'g', 12);
    } else {
        answer = "Нет корней на этом интервале";
    }

    QString htmlReady = html.arg(
        methodName,
        QString::number(a), QString::number(b),
        QString::number(tolerance),
        QString::number(iterations),
        answer
        );

    QString response = "OK Solution\n" + htmlReady + "\n";
    mTcpSocket->write(response.toUtf8());
}


double MyTcpServer::evalExpression(const QString& expr, double x)
{
    // tinyexpr поддерживает переменную x
    te_variable vars[] = { {"x", &x} };
    int err = 0;
    te_expr *expression = te_compile(expr.toUtf8().constData(), vars, 1, &err);
    if (!expression) {
        return std::numeric_limits<double>::quiet_NaN();
    }
    double result = te_eval(expression);
    te_free(expression);
    return result;
}



bool MyTcpServer::findRootDichotomyExpr(const QString& func, double a, double b, double& root, double tol, int maxIter, int& iters) {
    double fa = evalExpression(func, a);
    double fb = evalExpression(func, b);
    if (std::isnan(fa) || std::isnan(fb) || fa * fb > 0) return false;
    double mid = 0;
    iters = 0;
    for (; iters < maxIter; ++iters) {
        mid = 0.5 * (a + b);
        double fmid = evalExpression(func, mid);
        if (std::isnan(fmid)) return false;
        if (fabs(fmid) < tol || fabs(b - a) < tol)
            break;
        if (fa * fmid < 0) {
            b = mid;
            fb = fmid;
        } else {
            a = mid;
            fa = fmid;
        }
    }
    root = 0.5 * (a + b);
    return true;
}

bool MyTcpServer::findRootIterationExpr(const QString& func, double a, double b, double& root, double tol, int maxIter, int& iters) {
    double x0 = (a + b) / 2.0;
    double x1 = x0;
    iters = 0;
    for (; iters < maxIter; ++iters) {
        double fx = evalExpression(func, x0);
        // Производная численно (центральная разность)
        double h = 1e-6;
        double dfx = (evalExpression(func, x0 + h) - evalExpression(func, x0 - h)) / (2 * h);
        double M = fabs(dfx) > tol ? fabs(dfx) : 1.0;
        x1 = x0 - fx / M;
        if (x1 < a) x1 = a;
        if (x1 > b) x1 = b;
        if (fabs(x1 - x0) < tol)
            break;
        x0 = x1;
    }
    if (fabs(evalExpression(func, x1)) > tol * 10) return false;
    root = x1;
    return true;
}

