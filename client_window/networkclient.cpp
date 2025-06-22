#include "networkclient.h"
#include <QDebug>

NetworkClient* NetworkClient::instance()
{
    static NetworkClient inst;
    return &inst;
}

NetworkClient::NetworkClient(QObject *parent)
    : QObject(parent),
    socket(new QTcpSocket(this)),
    connectionTimer(new QTimer(this))
{
    connect(socket, &QTcpSocket::errorOccurred, this, &NetworkClient::onSocketError);
    connectionTimer->setSingleShot(true);
    connect(connectionTimer, &QTimer::timeout, this, &NetworkClient::onConnectionTimeout);
}

void NetworkClient::disconnectFromServer()
{
    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->disconnectFromHost();
        if (socket->state() != QAbstractSocket::UnconnectedState) {
            socket->waitForDisconnected(1000);
        }
    }
}

bool NetworkClient::connectToServer()
{
    // Если уже подключен - возвращаем true
    if (socket->state() == QAbstractSocket::ConnectedState) {
        return true;
    }

    // Если в процессе подключения - ждем завершения
    if (socket->state() == QAbstractSocket::ConnectingState) {
        connectionTimer->start(5000);  // Таймаут 5 секунд
        if (socket->waitForConnected(5000)) {
            connectionTimer->stop();
            return true;
        }
        return false;
    }

    qDebug() << "[NetworkClient] Подключение к серверу 127.0.0.1:33333...";
    socket->connectToHost("127.0.0.1", 33333);
    connectionTimer->start(10000);  // Таймаут 10 секунд

    if (socket->waitForConnected(10000)) {
        connectionTimer->stop();
        qDebug() << "[NetworkClient] Успешное подключение к серверу";
        return true;
    }

    qDebug() << "[NetworkClient] Ошибка подключения:" << socket->errorString();
    emit errorOccurred("Ошибка подключения: " + socket->errorString());
    return false;
}

// Слот для обработки таймаута подключения
void NetworkClient::onConnectionTimeout()
{
    if (socket->state() == QAbstractSocket::ConnectingState) {
        socket->abort();
        qDebug() << "[NetworkClient] Таймаут подключения";
        emit errorOccurred("Таймаут подключения к серверу");
    }
}

// Общий метод для выполнения запросов
bool NetworkClient::sendRequest(const QByteArray& request, QString& response)
{
    if (!connectToServer()) return false;

    qDebug() << "[NetworkClient] Отправка:" << request.trimmed();
    socket->write(request);

    if (!socket->waitForBytesWritten(5000)) {
        qDebug() << "[NetworkClient] Ошибка отправки данных:" << socket->errorString();
        return false;
    }

    if (!socket->waitForReadyRead(30000)) {
        qDebug() << "[NetworkClient] Таймаут ожидания ответа";
        return false;
    }

    response = QString::fromUtf8(socket->readAll()).trimmed();
    qDebug() << "[NetworkClient] Ответ сервера:" << response;
    return true;
}

bool NetworkClient::authenticate(const QString& login, const QString& password)
{
    QString response;
    QByteArray request = QString("LOGIN %1 %2\n").arg(login, password).toUtf8();

    if (!sendRequest(request, response)) {
        return false;
    }

    // Обработка успешной авторизации
    if (response.startsWith("OK Logged in")) {
        return true;
    }

    // Обработка ошибок
    if (response.startsWith("ERROR")) {
        emit errorOccurred(response);
    }

    return false;
}

bool NetworkClient::registerUser(const QString& login, const QString& password,
                                 const QString& email)
{
    QString response;
    QByteArray request = QString("REGISTER %1 %2 %3\n")
                             .arg(login, password, email).toUtf8();

    if (!sendRequest(request, response)) {
        qDebug() << "[NetworkClient] Ошибка отправки запроса";
        return false;
    }

    qDebug() << "[NetworkClient] Полный ответ сервера:" << response;

    if (response.startsWith("OK Registered")) {
        return true;
    }

    // Детализация ошибок
    if (response.contains("already taken")) {
        emit errorOccurred("Логин уже занят");
    }
    else if (response.contains("already exists")) {
        emit errorOccurred("Email уже зарегистрирован");
    }
    else if (response.contains("failed")) {
        emit errorOccurred("Ошибка базы данных");
    }
    else {
        emit errorOccurred("Неизвестная ошибка: " + response);
    }

    return false;
}

QString NetworkClient::requestRegisterCode(const QString& email)
{
    // Удаляем пробелы и экранируем спецсимволы
    QString cleanEmail = email.trimmed();

    QString response;
    QByteArray request = QString("REGISTER_CODE %1\n").arg(cleanEmail).toUtf8();

    if (!sendRequest(request, response)) {
        return QString();
    }

    // Обработка успешного получения кода
    if (response.startsWith("OK ")) {
        return response.section(' ', 3, 3);
    }

    // Обработка ошибок
    if (response.startsWith("ERROR Email already exists")) {
        emit errorOccurred("Email уже зарегистрирован");
    }
    else if (response.startsWith("ERROR")) {
        emit errorOccurred(response);
    }

    return QString();
}

QString NetworkClient::requestRecoveryCode(const QString& login)
{
    // Удаляем пробелы
    QString cleanLogin = login.trimmed();

    QString response;
    QByteArray request = QString("RECOVERY_CODE %1\n").arg(cleanLogin).toUtf8();

    if (!sendRequest(request, response)) {
        return QString();
    }

    // Обработка успешного получения кода
    if (response.startsWith("OK ")) {
        return response.section(' ', 3, 3);
    }

    // Обработка ошибок
    if (response.startsWith("ERROR Login does not exist")) {
        emit errorOccurred("Логин не существует");
    }
    else if (response.startsWith("ERROR No email found")) {
        emit errorOccurred("Email не найден для этого логина");
    }
    else if (response.startsWith("ERROR")) {
        emit errorOccurred(response);
    }

    return QString();
}

bool NetworkClient::emailExists(const QString& email)
{
    QString response;
    QByteArray request = QString("EMAILCHECK %1\n").arg(email).toUtf8();

    if (!sendRequest(request, response)) {
        return false;
    }

    // Обработка существующего email
    if (response.startsWith("OK Email Exists")) {
        return true;
    }

    // Обработка ошибок
    if (response.startsWith("ERROR")) {
        emit errorOccurred(response);
    }

    return false;
}

bool NetworkClient::checkLoginExists(const QString& login)
{
    QString response;
    QByteArray request = QString("LOGINCHECK %1\n").arg(login).toUtf8();

    if (!sendRequest(request, response)) {
        return false;
    }

    // Обработка существующего логина
    if (response.startsWith("OK Login Exists")) {
        return true;
    }

    // Обработка ошибок
    if (response.startsWith("ERROR")) {
        emit errorOccurred(response);
    }

    return false;
}

bool NetworkClient::changePassword(const QString& login, const QString& newPassword)
{
    QString response;
    QByteArray request = QString("CHANGE %1 %2\n").arg(login, newPassword).toUtf8();

    if (!sendRequest(request, response)) {
        return false;
    }

    // Обработка успешной смены пароля
    if (response.startsWith("OK Password Changed")) {
        return true;
    }

    // Обработка ошибок
    if (response.startsWith("ERROR Login does not exist")) {
        emit errorOccurred("Логин не существует");
    }
    else if (response.startsWith("ERROR")) {
        emit errorOccurred(response);
    }

    return false;
}

QString NetworkClient::getSolution(const QString& functionText,
                                   double a, double b,
                                   int methodIndex,
                                   double tolerance,
                                   int maxIterations)
{
    QString response;
    QByteArray request = QString("SOLUTION %1 %2 %3 %4 %5 %6\n")
                             .arg(functionText)
                             .arg(a)
                             .arg(b)
                             .arg(methodIndex)
                             .arg(tolerance)
                             .arg(maxIterations)
                             .toUtf8();

    if (!sendRequest(request, response)) {
        return QString();
    }

    // Обработка успешного решения
    if (response.startsWith("OK Solution")) {
        auto lines = response.split('\n');
        lines.removeFirst(); // Удаляем первую строку "OK Solution"
        return lines.join('\n');
    }

    // Обработка ошибок
    if (response.startsWith("ERROR")) {
        emit errorOccurred(response);
    }

    return QString();
}

void NetworkClient::onSocketError(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError);
    QString errorMsg = socket->errorString();
    qDebug() << "[NetworkClient] Ошибка сокета:" << errorMsg;
    emit errorOccurred("Ошибка сети: " + errorMsg);
}
