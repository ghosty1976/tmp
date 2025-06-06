/**
 * @file userutils.h
 * @brief Утилиты для работы с пользователями (регистрация, аутентификация, восстановление пароля).
 */

#ifndef USERUTILS_H
#define USERUTILS_H

#include <QString>

/**
 * @class UserUtils
 * @brief Статический класс для операций с пользователями.
 */
class UserUtils
{
public:
    /**
     * @brief Регистрация нового пользователя.
     * @param login Логин пользователя.
     * @param password Пароль (открытый текст).
     * @param email Email пользователя.
     * @param[out] error Сообщение об ошибке (если есть).
     * @return Код ошибки (0 - успех).
     */
    static int registerUser(const QString& login, const QString& password, const QString& email, QString& error);

    /**
     * @brief Аутентификация пользователя.
     * @param login Логин или email.
     * @param password Пароль.
     * @return true, если аутентификация успешна.
     */
    static bool login(const QString& login, const QString& password);

    /**
     * @brief Проверка существования логина.
     * @param login Логин для проверки.
     * @return true, если логин занят.
     */
    static bool loginExists(const QString& login);

    /**
     * @brief Проверка существования email.
     * @param email Email для проверки.
     * @return true, если email занят.
     */
    static bool emailExists(const QString& email);

    /**
     * @brief Отправка кода восстановления.
     * @param email Email пользователя.
     * @param[out] code Сгенерированный код.
     * @param[out] error Сообщение об ошибке.
     * @return Код ошибки (0 - успех).
     */
    static int sendRecoveryCode(const QString& email, QString& code, QString& error);

    /**
     * @brief Верификация кода восстановления.
     * @param email Email пользователя.
     * @param code Код для проверки.
     * @return true, если код верен.
     */
    static bool verifyRecoveryCode(const QString& email, const QString& code);

    /**
     * @brief Смена пароля.
     * @param email Email пользователя.
     * @param newPassword Новый пароль.
     * @return true, если пароль изменён.
     */
    static bool changePassword(const QString& email, const QString& newPassword);

    /**
     * @brief Хеширование пароля (bcrypt/scrypt).
     * @param password Пароль в открытом виде.
     * @return Хеш пароля в формате QString.
     */
    static QString hashPassword(const QString& password);
};

#endif // USERUTILS_H