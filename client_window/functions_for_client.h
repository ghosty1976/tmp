/**
 * @file functions_for_client.h
 * @brief Заголовочный файл с функциями для клиентской части приложения.
 *
 * Этот файл содержит объявления функций, используемых для взаимодействия
 * с сервером, включая авторизацию, регистрацию, восстановление пароля
 * и решение уравнений.
 */

#ifndef FUNCTIONS_FOR_CLIENT_H
#define FUNCTIONS_FOR_CLIENT_H

#include <QString>

/**
 * @brief Проверяет авторизационные данные пользователя на сервере.
 * @param login Логин пользователя.
 * @param password Пароль пользователя.
 * @return true, если авторизация успешна, иначе false.
 */
bool auth(QString login, QString password);

/**
 * @brief Регистрирует нового пользователя на сервере.
 * @param login Логин пользователя.
 * @param password Пароль пользователя.
 * @param email Электронная почта пользователя.
 * @return true, если регистрация успешна, иначе false.
 */
bool reg(QString login, QString password, QString email);

/**
 * @brief Проверяет валидность email через сервер.
 * @param email Электронная почта для проверки.
 * @return true, если email валиден, иначе false.
 */
bool email(QString email);

/**
 * @brief Отправляет код восстановления пароля на указанную почту.
 * @param email Электронная почта пользователя.
 * @return true, если код отправлен успешно, иначе false.
 */
bool sendRecoveryCode(QString email);

/**
 * @brief Изменяет пароль пользователя через сервер.
 * @param newPassword Новый пароль.
 * @return true, если пароль изменен успешно, иначе false.
 */
bool changePassword(QString newPassword);

/**
 * @brief Решает уравнение с заданными параметрами.
 * @param functionText Текст функции для решения.
 * @param a Начальная точка интервала.
 * @param b Конечная точка интервала.
 * @param methodIndex Индекс выбранного метода решения.
 * @return true, если решение найдено, иначе false.
 */
bool solveEquation(QString functionText, double a, double b, int methodIndex);

/**
 * @brief Отправляет данные на сервер для решения уравнения.
 * @param functionText Текст функции для решения.
 * @param a Начальная точка интервала.
 * @param b Конечная точка интервала.
 * @param methodIndex Индекс выбранного метода решения.
 * @param tolerance Допустимая погрешность.
 * @param maxIterations Максимальное количество итераций.
 * @return true, если данные отправлены успешно, иначе false.
 */
bool sendToServer(const QString& functionText, double a, double b, int methodIndex, double tolerance, int maxIterations);

#endif // FUNCTIONS_FOR_CLIENT_H