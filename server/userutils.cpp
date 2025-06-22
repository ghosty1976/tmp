#include "userutils.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>
#include <QDebug>
#include <QRandomGenerator>
#include <QSslSocket>

UserUtils::UserUtils(QSqlDatabase& db) : m_db(db) {}

QString UserUtils::hashPassword(const QString& password) {
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString(hash.toHex());
}

int UserUtils::registerUser(const QString& login, const QString& password, const QString& email, QString& error)
{
    QSqlQuery checkQuery(m_db);
    checkQuery.prepare("SELECT login FROM Users WHERE email = :email");
    checkQuery.bindValue(":email", email);

    if (!checkQuery.exec()) {
        error = checkQuery.lastError().text();
        return 3;
    }

    if (checkQuery.next()) {
        QString existingLogin = checkQuery.value(0).toString();
        if (!existingLogin.isEmpty()) {
            return 2;
        }
        QSqlQuery updateQuery(m_db);
        updateQuery.prepare("UPDATE Users SET login = :login, password = :password WHERE email = :email");
        updateQuery.bindValue(":login", login);
        updateQuery.bindValue(":password", hashPassword(password));
        updateQuery.bindValue(":email", email);

        if (updateQuery.exec()) {
            return 0;
        } else {
            error = updateQuery.lastError().text();
            return 3;
        }
    }

    if (loginExists(login)) return 1;

    QSqlQuery insertQuery(m_db);
    insertQuery.prepare("INSERT INTO Users (login, password, email) VALUES (:login, :password, :email)");
    insertQuery.bindValue(":login", login);
    insertQuery.bindValue(":password", hashPassword(password));
    insertQuery.bindValue(":email", email);

    if (insertQuery.exec()) {
        return 0;
    } else {
        error = insertQuery.lastError().text();
        return 3;
    }
}

bool UserUtils::login(const QString& login, const QString& password)
{
    QSqlQuery query(m_db);
    query.prepare("SELECT password FROM Users WHERE login = :login");
    query.bindValue(":login", login);
    if (query.exec() && query.next()) {
        QString hash = query.value(0).toString();
        return (hash == hashPassword(password));
    }
    return false;
}

bool UserUtils::loginExists(const QString& login) {
    QSqlQuery query(m_db);
    query.prepare("SELECT 1 FROM Users WHERE TRIM(login) = TRIM(:login)");
    query.bindValue(":login", login.trimmed());
    if (!query.exec()) {
        qDebug() << "loginExists: ошибка выполнения запроса:" << query.lastError().text();
        return false;
    }
    return query.next();
}

bool UserUtils::emailExists(const QString& email) {
    QSqlQuery query(m_db);
    query.prepare("SELECT 1 FROM Users WHERE TRIM(email) = TRIM(:email)");
    query.bindValue(":email", email.trimmed());
    if (!query.exec()) {
        qDebug() << "emailExists: ошибка выполнения запроса:" << query.lastError().text();
        return false;
    }
    return query.next();
}

QString UserUtils::generateRandomCode(int length) {
    QString code;
    for (int i = 0; i < length; ++i)
        code += QString::number(QRandomGenerator::global()->bounded(0, 10));
    return code;
}

bool UserUtils::sendEmailWithCode(const QString& to, const QString& code, QString& error) {
    QSslSocket socket;
    socket.connectToHostEncrypted("smtp.mail.ru", 465);
    if (!socket.waitForEncrypted(3000)) {
        error = socket.errorString();
        return false;
    }
    auto write = [&](const QString &data) {
        socket.write((data + "\r\n").toUtf8());
        if (!socket.waitForBytesWritten(3000))
            return false;
        if (!socket.waitForReadyRead(3000))
            return false;
        socket.readAll();
        return true;
    };
    const QString smtpLogin = "mnykh02@bk.ru";
    const QString smtpPass = "vXM0b6VbfBYDIk4r9hM0";
    const QString from = "mnykh02@bk.ru";

    if (!write("EHLO example.com")) { error = "EHLO failed"; return false; }
    if (!write("AUTH LOGIN")) { error = "AUTH LOGIN failed"; return false; }
    if (!write(QByteArray(smtpLogin.toUtf8()).toBase64())) { error = "login failed"; return false; }
    if (!write(QByteArray(smtpPass.toUtf8()).toBase64())) { error = "password failed"; return false; }
    if (!write("MAIL FROM: <" + from + ">")) { error = "MAIL FROM failed"; return false; }
    if (!write("RCPT TO: <" + to + ">")) { error = "RCPT TO failed"; return false; }
    if (!write("DATA")) { error = "DATA failed"; return false; }

    write("From: Yanchik <" + from + ">");
    write("To: <" + to + ">");
    write("Subject: Verification Code");
    write("");
    write("Your verification code: " + code);
    if (!write(".")) { error = "mail dot failed"; return false; }
    write("QUIT");
    return true;
}

QString UserUtils::getEmailByLogin(const QString& login) {
    QSqlQuery query(m_db);
    query.prepare("SELECT email FROM Users WHERE login = :login");
    query.bindValue(":login", login);
    if (query.exec() && query.next())
        return query.value(0).toString();
    return "";
}

bool UserUtils::changePasswordByLogin(const QString& login, const QString& newPassword) {
    QSqlQuery query(m_db);
    query.prepare("UPDATE Users SET password = :password WHERE login = :login");
    query.bindValue(":password", hashPassword(newPassword));
    query.bindValue(":login", login);
    return query.exec();
}
