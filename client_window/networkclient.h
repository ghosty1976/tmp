#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

#include <QObject>
#include <QTcpSocket>

class NetworkClient : public QObject
{
    Q_OBJECT

public:
    static NetworkClient* instance();  // Синглтон

    bool authenticate(const QString& login, const QString& password);  // Авторизация
    bool registerUser(const QString& login, const QString& password, const QString& email);  // Регистрация
    bool sendRecoveryCode(const QString& email);  // Отправка кода на почту
    bool verifyRecoveryCode(const QString& code);  // Проверка кода
    bool emailExists(const QString& email);  // Проверка существования email
    bool checkLoginExists(const QString& login); // Проверка существования логина
    bool changePassword(const QString& newPassword);  // Изменение пароля
    bool sendToServer(const QString& functionText, double a, double b, int methodIndex, double tolerance, int maxIterations); // Отправка данных для решения уравнения

private:
    explicit NetworkClient(QObject *parent = nullptr);  // Конструктор
    QTcpSocket *socket;  // Сокет для взаимодействия с сервером

    bool connectToServer();  // Метод для подключения к серверу

private slots:
    void onReadyRead();  // Слот для обработки полученных данных от сервера
    void onSocketError(QAbstractSocket::SocketError socketError);  // Слот для обработки ошибок сокета

signals:
    void authenticationSuccessful();
    void authenticationFailed();
    void errorOccurred(QAbstractSocket::SocketError socketError);
};

#endif // NETWORKCLIENT_H
