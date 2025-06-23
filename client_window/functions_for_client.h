#ifndef FUNCTIONS_FOR_CLIENT_H
#define FUNCTIONS_FOR_CLIENT_H

#include <QString>

/**
 * @file functions_for_client.h
 * @brief Набор функций для взаимодействия клиента с сервером
 */

/**
 * @brief Авторизация пользователя на сервере
 * @param login Логин пользователя
 * @param password Пароль пользователя
 * @return true если авторизация успешна, false в случае ошибки
 */
bool auth(const QString& login, const QString& password);

/**
 * @brief Регистрация нового пользователя
 * @param login Логин пользователя
 * @param password Пароль пользователя
 * @param email Email пользователя
 * @return true если регистрация успешна, false в случае ошибки
 */
bool regUser(const QString& login, const QString& password, const QString& email);

/**
 * @brief Запрос кода подтверждения регистрации
 * @param email Email для отправки кода подтверждения
 * @return Код подтверждения или пустую строку при ошибке
 */
QString requestRegisterCode(const QString& email);

/**
 * @brief Запрос кода восстановления пароля
 * @param login Логин пользователя для восстановления пароля
 * @return Код восстановления или пустую строку при ошибке
 */
QString requestRecoveryCode(const QString& login);

/**
 * @brief Проверка существования email на сервере
 * @param email Email для проверки
 * @return true если email существует, false если доступен
 */
bool emailExists(const QString& email);

/**
 * @brief Проверка существования логина на сервере
 * @param login Логин для проверки
 * @return true если логин существует, false если доступен
 */
bool loginExists(const QString& login);

/**
 * @brief Смена пароля пользователя
 * @param login Логин пользователя
 * @param newPassword Новый пароль
 * @return true если смена пароля успешна, false в случае ошибки
 */
bool changeUserPassword(const QString& login, const QString& newPassword);

/**
 * @brief Решение уравнения на сервере
 * @param functionText Текст функции для решения (например, "x^2 - 4")
 * @param a Левая граница интервала
 * @param b Правая граница интервала
 * @param methodIndex Индекс метода решения (0 - дихотомия, 1 - итерации)
 * @param tolerance Точность вычислений
 * @param maxIterations Максимальное количество итераций
 * @return HTML-контент с решением или пустую строку при ошибке
 */
QString solveEquation(const QString& functionText,
                     double a,
                     double b,
                     int methodIndex,
                     double tolerance,
                     int maxIterations);

#endif // FUNCTIONS_FOR_CLIENT_H