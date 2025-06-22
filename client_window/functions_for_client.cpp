#include "functions_for_client.h"
#include "networkclient.h"
#include <QDebug>

bool auth(const QString& login, const QString& password)
{
    qDebug() << "[Logic] Авторизация пользователя" << login;
    bool success = NetworkClient::instance()->authenticate(login, password);
    if (success) {
        qDebug() << "[Logic] Авторизация успешна";
    } else {
        qDebug() << "[Logic] Ошибка авторизации";
    }
    return success;
}

bool regUser(const QString& login, const QString& password, const QString& email)
{
    qDebug() << "[Logic] Запрос регистрации для" << login << email;
    // Только 3 параметра
    bool success = NetworkClient::instance()->registerUser(login, password, email);
    if (success) {
        qDebug() << "[Logic] Регистрация успешна";
    } else {
        qDebug() << "[Logic] Ошибка регистрации";
    }
    return success;
}

QString requestRegisterCode(const QString& email)
{
    qDebug() << "[Logic] Запрос кода регистрации для" << email;
    QString code = NetworkClient::instance()->requestRegisterCode(email);
    if (!code.isEmpty()) {
        qDebug() << "[Logic] Получен код регистрации:" << code;
    } else {
        qDebug() << "[Logic] Не удалось получить код регистрации";
    }
    return code;
}

QString requestRecoveryCode(const QString& login)
{
    qDebug() << "[Logic] Запрос кода восстановления для" << login;
    QString code = NetworkClient::instance()->requestRecoveryCode(login);
    if (!code.isEmpty()) {
        qDebug() << "[Logic] Получен код восстановления:" << code;
    } else {
        qDebug() << "[Logic] Не удалось получить код восстановления";
    }
    return code;
}

bool emailExists(const QString& email)
{
    qDebug() << "[Logic] Проверка email" << email;
    bool exists = NetworkClient::instance()->emailExists(email);
    qDebug() << (exists ? "[Logic] Email существует" : "[Logic] Email свободен");
    return exists;
}

bool loginExists(const QString& login)
{
    qDebug() << "[Logic] Проверка логина" << login;
    bool exists = NetworkClient::instance()->checkLoginExists(login);
    qDebug() << (exists ? "[Logic] Логин существует" : "[Logic] Логин свободен");
    return exists;
}

bool changeUserPassword(const QString& login, const QString& newPassword)
{
    qDebug() << "[Logic] Запрос изменения пароля для" << login;
    bool success = NetworkClient::instance()->changePassword(login, newPassword);
    if (success) {
        qDebug() << "[Logic] Пароль успешно изменён";
    } else {
        qDebug() << "[Logic] Ошибка изменения пароля";
    }
    return success;
}

QString solveEquation(const QString& functionText,
                      double a,
                      double b,
                      int methodIndex,
                      double tolerance,
                      int maxIterations)
{
    qDebug() << "[Logic] Отправка задачи решения уравнения";
    QString result = NetworkClient::instance()->getSolution(
        functionText, a, b, methodIndex, tolerance, maxIterations
        );
    if (!result.isEmpty()) {
        qDebug() << "[Logic] Решение получено";
    } else {
        qDebug() << "[Logic] Ошибка при получении решения";
    }
    return result;
}
