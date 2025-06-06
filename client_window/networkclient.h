/**
 * @file networkclient.h
 * @brief Заголовочный файл класса NetworkClient для сетевого взаимодействия клиента с сервером.
 *
 * Класс реализует функционал для установки соединения, авторизации, регистрации,
 * восстановления пароля и других операций, связанных с сетевым взаимодействием.
 */

#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

#include <QObject>
#include <QTcpSocket>

/**
 * @class NetworkClient
 * @brief Класс для управления сетевым взаимодействием клиента с сервером.
 *
 * Реализован как синглтон, обеспечивает все необходимые операции для связи с сервером,
 * включая обработку ошибок и передачу данных.
 */
class NetworkClient : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Возвращает единственный экземпляр класса (синглтон).
     * @return Указатель на экземпляр NetworkClient.
     */
    static NetworkClient* instance();

    /**
     * @brief Аутентифицирует пользователя на сервере.
     * @param login Логин пользователя.
     * @param password Пароль пользователя.
     * @return true, если аутентификация успешна, иначе false.
     */
    bool authenticate(const QString& login, const QString& password);

    /**
     * @brief Регистрирует нового пользователя на сервере.
     * @param login Логин пользователя.
     * @param password Пароль пользователя.
     * @param email Электронная почта пользователя.
     * @return true, если регистрация успешна, иначе false.
     */
    bool registerUser(const QString& login, const QString& password, const QString& email);

    /**
     * @brief Отправляет код восстановления на указанную почту.
     * @param email Электронная почта пользователя.
     * @return true, если код отправлен успешно, иначе false.
     */
    bool sendRecoveryCode(const QString& email);

    /**
     * @brief Проверяет код восстановления пароля.
     * @param code Код для проверки.
     * @return true, если код верен, иначе false.
     */
    bool verifyRecoveryCode(const QString& code);

    /**
     * @brief Проверяет существование email в системе.
     * @param email Электронная почта для проверки.
     * @return true, если email существует, иначе false.
     */
    bool emailExists(const QString& email);

    /**
     * @brief Проверяет существование логина в системе.
     * @param login Логин для проверки.
     * @return true, если логин существует, иначе false.
     */
    bool checkLoginExists(const QString& login);

    /**
     * @brief Изменяет пароль пользователя.
     * @param newPassword Новый пароль.
     * @return true, если пароль изменен успешно, иначе false.
     */
    bool changePassword(const QString& newPassword);

    /**
     * @brief Отправляет данные на сервер для решения уравнения.
     * @param functionText Текст функции для решения.
     * @param a Начальная точка интервала.
     * @param b Конечная точка интервала.
     * @param methodIndex Индекс метода решения.
     * @param tolerance Допустимая погрешность.
     * @param maxIterations Максимальное количество итераций.
     * @return true, если данные отправлены успешно, иначе false.
     */
    bool sendToServer(const QString& functionText, double a, double b, int methodIndex, double tolerance, int maxIterations);

private:
    /**
     * @brief Приватный конструктор (реализация синглтона).
     * @param parent Родительский объект (по умолчанию nullptr).
     */
    explicit NetworkClient(QObject *parent = nullptr);

    QTcpSocket *socket; ///< Указатель на сокет для соединения с сервером.

    /**
     * @brief Устанавливает соединение с сервером.
     * @return true, если соединение установлено, иначе false.
     */
    bool connectToServer();

private slots:
    /**
     * @brief Слот для обработки входящих данных от сервера.
     */
    void onReadyRead();

    /**
     * @brief Слот для обработки ошибок сокета.
     * @param socketError Тип ошибки сокета.
     */
    void onSocketError(QAbstractSocket::SocketError socketError);

signals:
    /**
     * @brief Сигнал об успешной аутентификации.
     */
    void authenticationSuccessful();

    /**
     * @brief Сигнал о неудачной аутентификации.
     */
    void authenticationFailed();

    /**
     * @brief Сигнал о возникновении ошибки.
     * @param socketError Тип ошибки сокета.
     */
    void errorOccurred(QAbstractSocket::SocketError socketError);
};

#endif // NETWORKCLIENT_H