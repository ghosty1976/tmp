/**
 * @file mytcpserver.h
 * @brief TCP-сервер для обработки клиентских запросов.
 */

#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

/**
 * @class MyTcpServer
 * @brief Сервер, обрабатывающий команды регистрации, аутентификации и математических вычислений.
 */
class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();

protected:
    /**
     * @brief Обработчик новых подключений.
     * @param socketDescriptor Дескриптор сокета.
     */
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    /// Чтение данных от клиента.
    void slotServerRead();

private:
    QTcpSocket *mTcpSocket; ///< Текущий активный сокет.

    /// Подключение к БД.
    bool connectToDatabase();

    // Обработчики команд:
    void handleRegister(const QString& login, const QString& password, const QString& email);
    void handleLogin(const QString& login, const QString& password);
    void handleCheckEmail(const QString& email);
    void handleCheckLogin(const QString& login);
    void handleRecovery(const QString& identifier);
    void handleVerifyCode(const QString& code);
    void handleChangePassword(const QString& password);

    /**
     * @brief Вычисление значения математического выражения.
     * @param expr Выражение (например, "x^2 + 1").
     * @param x Значение переменной x.
     * @return Результат вычисления.
     */
    double evalExpression(const QString& expr, double x);

    /**
     * @brief Поиск корня методом дихотомии.
     * @param func Функция в виде строки.
     * @param a Левая граница интервала.
     * @param b Правая граница интервала.
     * @param[out] root Найденный корень.
     * @param tol Точность.
     * @param maxIter Максимум итераций.
     * @param[out] iters Фактическое число итераций.
     * @return true, если корень найден.
     */
    bool findRootDichotomyExpr(const QString& func, double a, double b, double& root, double tol, int maxIter, int& iters);

    /// Аналогично для метода итераций...
    bool findRootIterationExpr(const QString& func, double a, double b, double& root, double tol, int maxIter, int& iters);

    /**
     * @brief Обработчик запроса на решение уравнения.
     * @param functionText Уравнение (например, "sin(x) = 0.5").
     * @param methodIndex 0 - дихотомия, 1 - итерации.
     */
    void handleSolve(const QString& functionText, double a, double b, int methodIndex, double tolerance, int maxIterations);
};

#endif // MYTCPSERVER_H
