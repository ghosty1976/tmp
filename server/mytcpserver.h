#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include "userutils.h"
#include "equationssolver.h"

/**
 * @brief TCP-сервер для обработки клиентских запросов
 * 
 * Обрабатывает входящие соединения, читает данные от клиентов
 * и делегирует выполнение операций соответствующим обработчикам.
 */
class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    /**
     * @brief Конструктор TCP-сервера
     * @param userUtils Утилиты для работы с пользователями
     * @param eqSolver Решатель уравнений
     * @param parent Родительский QObject
     */
    explicit MyTcpServer(UserUtils* userUtils, EquationsSolver* eqSolver, QObject *parent = nullptr);
    
    /**
     * @brief Деструктор TCP-сервера
     */
    ~MyTcpServer();

protected:
    /**
     * @brief Обработчик входящих соединений
     * @param socketDescriptor Дескриптор сокета нового соединения
     */
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    /**
     * @brief Слот для чтения данных от клиента
     */
    void slotServerRead();

private:
    QTcpSocket *mTcpSocket = nullptr;       ///< Указатель на текущий TCP-сокет
    UserUtils* m_userUtils;                 ///< Утилиты для работы с пользователями
    EquationsSolver* m_eqSolver;            ///< Решатель уравнений

    /**
     * @brief Обработчик регистрации пользователя
     * @param login Логин пользователя
     * @param password Пароль пользователя
     * @param email Email пользователя
     */
    void handleRegister(const QString& login, const QString& password, const QString& email);

    /**
     * @brief Обработчик авторизации пользователя
     * @param login Логин пользователя
     * @param password Пароль пользователя
     */
    void handleLogin(const QString& login, const QString& password);

    /**
     * @brief Обработчик проверки email
     * @param email Email для проверки
     */
    void handleCheckEmail(const QString& email);

    /**
     * @brief Обработчик проверки логина
     * @param login Логин для проверки
     */
    void handleCheckLogin(const QString& login);

    /**
     * @brief Обработчик запроса кода регистрации
     * @param email Email для отправки кода
     */
    void handleRegisterCode(const QString& email);

    /**
     * @brief Обработчик запроса кода восстановления
     * @param login Логин для восстановления пароля
     */
    void handleRecoveryCode(const QString& login);

    /**
     * @brief Обработчик смены пароля
     * @param login Логин пользователя
     * @param password Новый пароль
     */
    void handleChangePassword(const QString& login, const QString& password);

    /**
     * @brief Обработчик решения уравнения
     * @param functionText Текст функции
     * @param a Левая граница интервала
     * @param b Правая граница интервала
     * @param methodIndex Индекс метода решения
     * @param tolerance Точность решения
     * @param maxIterations Максимальное количество итераций
     */
    void handleSolve(const QString& functionText, double a, double b, int methodIndex, double tolerance, int maxIterations);
};

#endif // MYTCPSERVER_H