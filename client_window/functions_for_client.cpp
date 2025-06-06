#include "functions_for_client.h"
#include "networkclient.h"  // Подключаем NetworkClient
#include <QDebug>

// Авторизация через сервер
bool auth(QString login, QString password)
{
    NetworkClient* client = NetworkClient::instance();
    bool result = client->authenticate(login, password);  // Отправляем запрос на сервер
    if (!result) {
        qDebug() << "Ошибка авторизации.";
    }
    return result;  // Возвращаем результат
}

// Регистрация через сервер
bool reg(QString login, QString password, QString email)
{
    NetworkClient* client = NetworkClient::instance();
    bool result = client->registerUser(login, password, email);  // Отправляем запрос на сервер
    if (!result) {
        qDebug() << "Ошибка регистрации.";
    }
    return result;  // Возвращаем результат
}

// Проверка email (реализовано через сервер)
bool email(QString email)
{
    NetworkClient* client = NetworkClient::instance();
    bool result = client->emailExists(email);  // Отправляем запрос на сервер для проверки email
    if (!result) {
        qDebug() << "Этот email уже существует.";
    }
    return result;  // Возвращаем результат
}

// Отправка кода восстановления через сервер
bool sendRecoveryCode(QString email)
{
    NetworkClient* client = NetworkClient::instance();
    bool result = client->sendRecoveryCode(email);  // Отправляем запрос на сервер
    if (!result) {
        qDebug() << "Ошибка отправки кода восстановления.";
    }
    return result;  // Возвращаем результат
}

// Изменение пароля на сервере
bool changePassword(QString newPassword)
{
    NetworkClient* client = NetworkClient::instance();
    bool result = client->changePassword(newPassword);  // Отправляем запрос на сервер для смены пароля
    if (!result) {
        qDebug() << "Ошибка смены пароля.";
    }
    return result;  // Возвращаем результат
}

// Отправка данных для решения уравнения на сервер
bool solveEquation(QString functionText, double a, double b, int methodIndex, double tolerance, int maxIterations)
{
    NetworkClient* client = NetworkClient::instance();
    // Отправляем запрос на сервер для решения уравнения с новыми параметрами
    bool result = client->sendToServer(functionText, a, b, methodIndex, tolerance, maxIterations);

    if (!result) {
        qDebug() << "Ошибка отправки данных для решения уравнения.";
    }

    return result;  // Возвращаем результат
}

