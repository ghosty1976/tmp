#include "networkclient.h"
#include <QByteArray>
#include <QDebug>

NetworkClient* NetworkClient::instance()
{
    static NetworkClient instance;
    return &instance;
}

NetworkClient::NetworkClient(QObject *parent)
    : QObject(parent), socket(new QTcpSocket(this))
{
    connect(socket, &QTcpSocket::readyRead, this, &NetworkClient::onReadyRead);
    connect(socket, &QTcpSocket::errorOccurred, this, &NetworkClient::onSocketError);
}

bool NetworkClient::connectToServer()
{
    // Проверка, если сокет уже подключен или пытается подключиться
    if (socket->state() == QAbstractSocket::ConnectedState || socket->state() == QAbstractSocket::ConnectingState) {
        return true;  // Если уже подключен или подключается, то возвращаем true
    }

    // Подключаемся к серверу, если сокет не подключен
    socket->connectToHost("127.0.0.1", 33333);  // Подключение к серверу
    if (!socket->waitForConnected(3000)) {  // Ждем 3 секунды для подключения
        qDebug() << "Не удалось подключиться к серверу!";
        return false;
    }

    qDebug() << "Подключено к серверу!";
    return true;
}



bool NetworkClient::authenticate(const QString& login, const QString& password)
{
    if (!connectToServer()) {
        qDebug() << "Ошибка подключения к серверу!";
        return false;
    }

    QByteArray data = QString("LOGIN %1 %2").arg(login).arg(password).toUtf8();
    socket->write(data);
    socket->flush();

    if (!socket->waitForReadyRead(3000)) {
        qDebug() << "Не получили ответа от сервера!";
        socket->close();  // Закрытие соединения
        return false;
    }

    QByteArray response = socket->readAll();
    socket->close();  // Закрытие соединения после получения ответа
    qDebug() << "Ответ сервера: " << response;

    if (response.startsWith("OK Logged in")) {
        return true;  // Успешная авторизация
    } else {
        qDebug() << "Ошибка авторизации: " << response;
        return false;  // Ошибка авторизации
    }
}

// Реализация регистрации пользователя
bool NetworkClient::registerUser(const QString& login, const QString& password, const QString& email)
{
    if (!connectToServer()) {
        return false;
    }

    QByteArray data = QString("REGISTER %1 %2 %3").arg(login).arg(password).arg(email).toUtf8();
    socket->write(data);
    socket->flush();

    if (!socket->waitForReadyRead(3000)) {
        qDebug() << "Не получили ответа от сервера!";
        return false;
    }

    QByteArray response = socket->readAll();
    qDebug() << "Ответ сервера: " << response;

    if (response.startsWith("OK Registered")) {
        return true;
    } else {
        qDebug() << "Ошибка регистрации: " << response;
        return false;
    }
}

// Проверка существования email
bool NetworkClient::emailExists(const QString& email)
{
    if (!connectToServer()) {
        return false;
    }

    QByteArray data = QString("EMAILCHECK %1").arg(email).toUtf8();
    socket->write(data);
    socket->flush();

    if (!socket->waitForReadyRead(3000)) {
        qDebug() << "Не получили ответа от сервера!";
        return false;
    }

    QByteArray response = socket->readAll();
    qDebug() << "Ответ сервера: " << response;

    return response.startsWith("OK Email Exists");
}

// Проверка существования логина
bool NetworkClient::checkLoginExists(const QString& login)
{
    if (!connectToServer()) {
        return false;
    }

    QByteArray data = QString("LOGINCHECK %1").arg(login).toUtf8();
    socket->write(data);
    socket->flush();

    if (!socket->waitForReadyRead(3000)) {
        qDebug() << "Не получили ответа от сервера!";
        return false;
    }

    QByteArray response = socket->readAll();
    qDebug() << "Ответ сервера: " << response;

    return response.startsWith("OK Login Exists");
}

// Отправка кода восстановления
bool NetworkClient::sendRecoveryCode(const QString& email)
{
    if (!connectToServer()) {
        return false;
    }

    QByteArray data = QString("RECOVERY %1").arg(email).toUtf8();
    socket->write(data);
    socket->flush();

    if (!socket->waitForReadyRead(3000)) {
        qDebug() << "Не получили ответа от сервера!";
        return false;
    }

    QByteArray response = socket->readAll();
    qDebug() << "Ответ сервера: " << response;

    return response.startsWith("OK Code Sent");
}

// Проверка кода восстановления
bool NetworkClient::verifyRecoveryCode(const QString& code)
{
    if (!connectToServer()) {
        return false;
    }

    QByteArray data = QString("VERIFY_CODE %1").arg(code).toUtf8();
    socket->write(data);
    socket->flush();

    if (!socket->waitForReadyRead(3000)) {
        qDebug() << "Не получили ответа от сервера!";
        return false;
    }

    QByteArray response = socket->readAll();
    qDebug() << "Ответ сервера: " << response;

    return response.startsWith("OK Code Verified");
}

// Изменение пароля
bool NetworkClient::changePassword(const QString& newPassword)
{
    if (!connectToServer()) {
        return false;
    }

    QByteArray data = QString("CHANGE %1").arg(newPassword).toUtf8();
    socket->write(data);
    socket->flush();

    if (!socket->waitForReadyRead(3000)) {
        qDebug() << "Не получили ответа от сервера!";
        return false;
    }

    QByteArray response = socket->readAll();
    qDebug() << "Ответ сервера: " << response;

    return response.startsWith("OK Password Changed");
}

// Отправка данных на сервер
bool NetworkClient::sendToServer(const QString& functionText, double a, double b, int methodIndex, double tolerance, int maxIterations)
{
    if (!connectToServer()) {
        return false;
    }

    // Формируем запрос с всеми необходимыми данными
    QByteArray data = QString("SOLUTION %1 %2 %3 %4 %5 %6")
                          .arg(functionText)     // Функция
                          .arg(a)                 // Левая граница интервала
                          .arg(b)                 // Правая граница интервала
                          .arg(methodIndex)       // Индекс метода
                          .arg(tolerance)         // Точность
                          .arg(maxIterations)     // Максимальное количество итераций
                          .toUtf8();

    socket->write(data);
    socket->flush();

    if (!socket->waitForReadyRead(3000)) {
        qDebug() << "Не получили ответа от сервера!";
        return false;
    }

    QByteArray response = socket->readAll();
    qDebug() << "Ответ сервера: " << response;

    return response.startsWith("OK Solution");
}


// Слот для обработки полученных данных
void NetworkClient::onReadyRead()
{
    QByteArray response = socket->readAll();
    qDebug() << "Получены данные: " << response;
}

// Слот для обработки ошибок сокета
void NetworkClient::onSocketError(QAbstractSocket::SocketError socketError)
{
    qDebug() << "Ошибка сокета: " << socketError;
}
