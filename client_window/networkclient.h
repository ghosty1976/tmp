#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QPointer>
#include <QTimer>

/**
 * @brief Класс для сетевого взаимодействия клиента с сервером
 * 
 * Реализует singleton-паттерн и предоставляет методы для выполнения
 * всех операций с сервером: авторизация, регистрация, решение уравнений.
 */
class NetworkClient : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Получение единственного экземпляра класса (Singleton)
     * @return Указатель на экземпляр NetworkClient
     */
    static NetworkClient* instance();

    /**
     * @brief Аутентификация пользователя
     * @param login Логин пользователя
     * @param password Пароль пользователя
     * @return true при успешной авторизации, false при ошибке
     */
    bool authenticate(const QString& login, const QString& password);

    /**
     * @brief Регистрация нового пользователя
     * @param login Логин пользователя
     * @param password Пароль пользователя
     * @param email Email пользователя
     * @return true при успешной регистрации, false при ошибке
     */
    bool registerUser(const QString& login, const QString& password, const QString& email);

    /**
     * @brief Запрос кода подтверждения регистрации
     * @param email Email для отправки кода
     * @return Код подтверждения или пустую строку при ошибке
     */
    QString requestRegisterCode(const QString& email);

    /**
     * @brief Запрос кода восстановления пароля
     * @param login Логин пользователя
     * @return Код восстановления или пустую строку при ошибке
     */
    QString requestRecoveryCode(const QString& login);

    /**
     * @brief Проверка существования email
     * @param email Email для проверки
     * @return true если email уже существует, false если доступен
     */
    bool emailExists(const QString& email);

    /**
     * @brief Проверка существования логина
     * @param login Логин для проверки
     * @return true если логин уже существует, false если доступен
     */
    bool checkLoginExists(const QString& login);

    /**
     * @brief Смена пароля пользователя
     * @param login Логин пользователя
     * @param newPassword Новый пароль
     * @return true при успешной смене пароля, false при ошибке
     */
    bool changePassword(const QString& login, const QString& newPassword);

    /**
     * @brief Получение решения уравнения с сервера
     * @param functionText Текст функции для решения
     * @param a Левая граница интервала
     * @param b Правая граница интервала
     * @param methodIndex Индекс метода (0 - дихотомия, 1 - итерации)
     * @param tolerance Точность вычислений
     * @param maxIterations Максимальное число итераций
     * @return Решение в формате HTML или пустую строку при ошибке
     */
    QString getSolution(const QString& functionText,
                        double a, double b,
                        int methodIndex,
                        double tolerance,
                        int maxIterations);

    /**
     * @brief Закрытие соединения с сервером
     */
    void disconnectFromServer();

signals:
    /**
     * @brief Сигнал об ошибке сети
     * @param message Текст ошибки
     */
    void errorOccurred(const QString& message);

private:
    /**
     * @brief Приватный конструктор
     * @param parent Родительский объект
     */
    explicit NetworkClient(QObject *parent = nullptr);

    /**
     * @brief Отправка запроса на сервер
     * @param request Данные запроса
     * @param response Сюда будет записан ответ сервера
     * @return true при успешной отправке, false при ошибке
     */
    bool sendRequest(const QByteArray& request, QString& response);

    QPointer<QTcpSocket> socket;  ///< Указатель на TCP-сокет
    QTimer* connectionTimer;      ///< Таймер для контроля соединения

    /**
     * @brief Подключение к серверу
     * @return true при успешном подключении, false при ошибке
     */
    bool connectToServer();

private slots:
    /**
     * @brief Обработчик ошибок сокета
     * @param socketError Тип ошибки
     */
    void onSocketError(QAbstractSocket::SocketError socketError);

    /**
     * @brief Обработчик таймаута соединения
     */
    void onConnectionTimeout();
};

#endif // NETWORKCLIENT_H