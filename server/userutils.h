#ifndef USERUTILS_H
#define USERUTILS_H

#include <QString>
#include <QSqlDatabase>

/**
 * @brief Класс для работы с пользователями и их данными
 * 
 * Предоставляет функционал для регистрации, авторизации пользователей,
 * работы с электронной почтой и управления паролями.
 */
class UserUtils
{
public:
    /**
     * @brief Конструктор класса UserUtils
     * @param db Ссылка на объект базы данных
     */
    UserUtils(QSqlDatabase& db);

    /**
     * @brief Регистрация нового пользователя
     * @param login Логин пользователя
     * @param password Пароль пользователя
     * @param email Email пользователя
     * @param error Строка для возврата сообщения об ошибке
     * @return ID зарегистрированного пользователя или -1 в случае ошибки
     */
    int registerUser(const QString& login, const QString& password, const QString& email, QString& error);

    /**
     * @brief Авторизация пользователя
     * @param login Логин пользователя
     * @param password Пароль пользователя
     * @return true если авторизация успешна, false в случае ошибки
     */
    bool login(const QString& login, const QString& password);

    /**
     * @brief Проверка существования логина
     * @param login Логин для проверки
     * @return true если логин уже существует, false если доступен
     */
    bool loginExists(const QString& login);

    /**
     * @brief Проверка существования email
     * @param email Email для проверки
     * @return true если email уже существует, false если доступен
     */
    bool emailExists(const QString& email);

    /**
     * @brief Генерация случайного кода
     * @param length Длина генерируемого кода
     * @return Сгенерированный код
     */
    QString generateRandomCode(int length);

    /**
     * @brief Отправка email с кодом подтверждения
     * @param to Адрес получателя
     * @param code Код подтверждения
     * @param error Строка для возврата сообщения об ошибке
     * @return true если отправка успешна, false в случае ошибки
     */
    bool sendEmailWithCode(const QString& to, const QString& code, QString& error);

    /**
     * @brief Получение email по логину пользователя
     * @param login Логин пользователя
     * @return Email пользователя или пустую строку если не найден
     */
    QString getEmailByLogin(const QString& login);

    /**
     * @brief Изменение пароля пользователя
     * @param login Логин пользователя
     * @param newPassword Новый пароль
     * @return true если изменение успешно, false в случае ошибки
     */
    bool changePasswordByLogin(const QString& login, const QString& newPassword);

    /**
     * @brief Хеширование пароля
     * @param password Пароль для хеширования
     * @return Хеш пароля
     */
    static QString hashPassword(const QString& password);

private:
    QSqlDatabase& m_db; ///< Ссылка на объект базы данных
};

#endif // USERUTILS_H