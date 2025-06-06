#include "userutils.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>
#include <QDebug>
#include <QRandomGenerator>

// Хэширование пароля
QString UserUtils::hashPassword(const QString& password) {
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString(hash.toHex());
}

int UserUtils::registerUser(const QString& login, const QString& password, const QString& email, QString& error)
{
    if (loginExists(login)) return 1; // Login already taken
    if (emailExists(email)) return 2; // Email already exists

    QSqlQuery query;
    query.prepare("UPDATE Users SET login = :login, password = :password WHERE email = :email");
    query.bindValue(":login", login);
    query.bindValue(":password", hashPassword(password));
    query.bindValue(":email", email);

    if (query.exec()) {
        return 0; // OK Registered
    } else {
        error = query.lastError().text();
        return 3; // Registration failed
    }
}

bool UserUtils::login(const QString& login, const QString& password)
{
    QSqlQuery query;
    query.prepare("SELECT password FROM Users WHERE login = :login");
    query.bindValue(":login", login);
    if (query.exec() && query.next()) {
        QString hash = query.value(0).toString();
        return (hash == hashPassword(password));
    }
    return false;
}

bool UserUtils::loginExists(const QString& login)
{
    QSqlQuery query;
    query.prepare("SELECT 1 FROM Users WHERE login = :login");
    query.bindValue(":login", login);
    if (query.exec() && query.next()) return true;
    return false;
}

bool UserUtils::emailExists(const QString& email)
{
    QSqlQuery query;
    query.prepare("SELECT 1 FROM Users WHERE email = :email");
    query.bindValue(":email", email);
    if (query.exec() && query.next()) return true;
    return false;
}

int UserUtils::sendRecoveryCode(const QString& email, QString& code, QString& error)
{
    if (!emailExists(email)) return 1;
    code = QString::number(QRandomGenerator::global()->bounded(100000, 999999));
    QSqlQuery query;
    query.prepare("UPDATE Users SET restore_code = :code WHERE email = :email");
    query.bindValue(":code", code);
    query.bindValue(":email", email);
    if (!query.exec()) {
        error = query.lastError().text();
        return 2;
    }
    return 0;
}

bool UserUtils::verifyRecoveryCode(const QString& email, const QString& code)
{
    QSqlQuery query;
    query.prepare("SELECT restore_code FROM Users WHERE email = :email");
    query.bindValue(":email", email);
    if (query.exec() && query.next()) {
        QString db_code = query.value(0).toString();
        if (db_code == code) {
            // После успешной проверки стираем код
            QSqlQuery clearQuery;
            clearQuery.prepare("UPDATE Users SET restore_code = NULL WHERE email = :email");
            clearQuery.bindValue(":email", email);
            clearQuery.exec();
            return true;
        }
    }
    return false;
}

bool UserUtils::changePassword(const QString& email, const QString& newPassword)
{
    // Можно добавить проверку, что код уже был подтвержден
    QSqlQuery query;
    query.prepare("UPDATE Users SET password = :password, restore_code = NULL WHERE email = :email");
    query.bindValue(":password", hashPassword(newPassword));
    query.bindValue(":email", email);
    return query.exec();
}
