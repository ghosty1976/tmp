/**
 * @file emailutils.h
 * @brief Утилиты для отправки email через SSL.
 */

#ifndef EMAILUTILS_H
#define EMAILUTILS_H

#include <QString>

/**
 * @class EmailUtils
 * @brief Отправка электронных писем.
 */
class EmailUtils
{
public:
    /**
     * @brief Отправка письма через SSL.
     * @param to Адрес получателя.
     * @param subject Тема письма.
     * @param body Тело письма.
     * @param[out] err Текст ошибки (если есть).
     * @return true, если отправка успешна.
     */
    static bool sendEmailSSL(const QString& to, const QString& subject, const QString& body, QString& err);
};

#endif // EMAILUTILS_H