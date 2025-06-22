#ifndef USERUTILS_H
#define USERUTILS_H

#include <QString>
#include <QSqlDatabase>

class UserUtils
{
public:
    UserUtils(QSqlDatabase& db);

    int registerUser(const QString& login, const QString& password, const QString& email, QString& error);
    bool login(const QString& login, const QString& password);
    bool loginExists(const QString& login);
    bool emailExists(const QString& email);

    QString generateRandomCode(int length);
    bool sendEmailWithCode(const QString& to, const QString& code, QString& error);
    QString getEmailByLogin(const QString& login);
    bool changePasswordByLogin(const QString& login, const QString& newPassword);

    static QString hashPassword(const QString& password);
private:
    QSqlDatabase& m_db;
};

#endif // USERUTILS_H
