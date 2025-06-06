#ifndef EMAILUTILS_H
#define EMAILUTILS_H

#include <QString>

class EmailUtils
{
public:
    static bool sendEmailSSL(const QString& to, const QString& subject, const QString& body, QString& err);
};

#endif // EMAILUTILS_H
