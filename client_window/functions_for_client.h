#ifndef FUNCTIONS_FOR_CLIENT_H
#define FUNCTIONS_FOR_CLIENT_H
#include<QString>

// Файл (заголовочный) для функций

bool auth(QString, QString);  // Функция для авторизации

bool reg(QString, QString, QString);  // Функция для регистрации

bool email(QString);  // Функция для проверки email через сервер

bool sendRecoveryCode(QString email);  // Функция для отправки кода на почту через сервер

bool changePassword(QString newPassword);  // Функция для изменения пароля через сервер

bool solveEquation(QString functionText, double a, double b, int methodIndex);  // Функция для решения уравнения

bool sendToServer(const QString& functionText, double a, double b, int methodIndex, double tolerance, int maxIterations);  // Отправка данных для решения уравнения

#endif // FUNCTIONS_FOR_CLIENT_H
