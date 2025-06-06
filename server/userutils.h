#ifndef USERUTILS_H
#define USERUTILS_H

#include <QString>

class UserUtils
{
public:
    static int registerUser(const QString& login, const QString& password, const QString& email, QString& error);
    static bool login(const QString& login, const QString& password);
    static bool loginExists(const QString& login);
    static bool emailExists(const QString& email);

    static int sendRecoveryCode(const QString& email, QString& code, QString& error);
    static bool verifyRecoveryCode(const QString& email, const QString& code);
    static bool changePassword(const QString& email, const QString& newPassword);

    static QString hashPassword(const QString& password); // <--- Новая функция
};

#endif // USERUTILS_H
