#include "emailutils.h"
#include <QSslSocket>
#include <QTextStream>
#include <QDebug>

bool EmailUtils::sendEmailSSL(const QString& to, const QString& subject, const QString& body, QString& err)
{
    QSslSocket socket;

    socket.connectToHostEncrypted("smtp.mail.ru", 465);  // Подключение через SSL
    if (!socket.waitForEncrypted(5000)) {
        err = "Unable to establish secure connection with the server.";
        qDebug() << err;
        return false;
    }

    QTextStream stream(&socket);
    stream.flush();  // Немедленно отправляем данные

    stream << "EHLO localhost\r\n";
    socket.waitForReadyRead(1000);

    QString username = "mnykh02@bk.ru";
    QString password = "Zm2UFjvKGnqaP0Y64yTs";

    stream << "AUTH LOGIN\r\n";
    socket.waitForReadyRead(1000);

    stream << username.toUtf8().toBase64() + "\r\n";  // Логин в Base64
    socket.waitForReadyRead(1000);

    stream << password.toUtf8().toBase64() + "\r\n";  // Пароль в Base64
    socket.waitForReadyRead(1000);

    // Формирование письма
    stream << "MAIL FROM: <" << username << ">\r\n";  // Отправитель
    socket.waitForReadyRead(1000);

    stream << "RCPT TO: <" << to << ">\r\n";  // Получатель
    socket.waitForReadyRead(1000);

    stream << "DATA\r\n";
    socket.waitForReadyRead(1000);

    // Заголовки письма и тело
    stream << "From: " << username << "\r\n";
    stream << "To: " << to << "\r\n";
    stream << "Subject: " << subject << "\r\n";
    stream << "\r\n";  // Пустая строка перед текстом письма
    stream << body << "\r\n";  // Текст письма

    // Завершаем письмо
    stream << ".\r\n";
    socket.waitForReadyRead(1000);

    stream << "QUIT\r\n";
    socket.waitForReadyRead(1000);

    return true;  // Письмо успешно отправлено
}
