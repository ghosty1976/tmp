#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QPointer>
#include <QTimer>

class NetworkClient : public QObject
{
    Q_OBJECT

public:
    static NetworkClient* instance();

    // Авторизация
    bool authenticate(const QString& login, const QString& password);

    // Регистрация - только 3 параметра
    bool registerUser(const QString& login, const QString& password, const QString& email);

    // Запрос кода для подтверждения регистрации
    QString requestRegisterCode(const QString& email);

    // Запрос кода для восстановления пароля
    QString requestRecoveryCode(const QString& login);

    // Проверка занятости email
    bool emailExists(const QString& email);

    // Проверка существования логина
    bool checkLoginExists(const QString& login);

    // Смена пароля
    bool changePassword(const QString& login, const QString& newPassword);

    // Отправка данных для решения уравнения
    QString getSolution(const QString& functionText,
                        double a, double b,
                        int methodIndex,
                        double tolerance,
                        int maxIterations);

    // Закрытие соединения
    void disconnectFromServer();

signals:
    void errorOccurred(const QString& message);

private:
    explicit NetworkClient(QObject *parent = nullptr);

    // Приватный метод для отправки запросов
    bool sendRequest(const QByteArray& request, QString& response);

    QPointer<QTcpSocket> socket;
    QTimer* connectionTimer;

    bool connectToServer();

private slots:
    void onSocketError(QAbstractSocket::SocketError socketError);
    void onConnectionTimeout();
};

#endif // NETWORKCLIENT_H
