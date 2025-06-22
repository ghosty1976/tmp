#ifndef FUNCTIONS_FOR_CLIENT_H
#define FUNCTIONS_FOR_CLIENT_H

#include <QString>

// Авторизация пользователя на сервере
bool auth(const QString& login, const QString& password);

// Регистрация нового пользователя (только 3 параметра)
bool regUser(const QString& login, const QString& password, const QString& email);

// Запрос кода подтверждения регистрации по email
QString requestRegisterCode(const QString& email);

// Запрос кода восстановления пароля по login
QString requestRecoveryCode(const QString& login);

// Проверка, существует ли email на сервере
bool emailExists(const QString& email);

// Проверка, существует ли логин на сервере
bool loginExists(const QString& login);

// Смена пароля для пользователя
bool changeUserPassword(const QString& login, const QString& newPassword);

// Отправка задачи решения уравнения на сервер
// Возвращает HTML-контент с решением или пустую строку при ошибке
QString solveEquation(const QString& functionText,
                      double a,
                      double b,
                      int methodIndex,
                      double tolerance,
                      int maxIterations);

#endif // FUNCTIONS_FOR_CLIENT_H
