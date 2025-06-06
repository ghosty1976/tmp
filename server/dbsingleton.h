#ifndef DBSINGLETON_H
#define DBSINGLETON_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

class DbSingleton
{
private:
    static DbSingleton* p_instance;
    QSqlDatabase db;
    DbSingleton(); // скрытый конструктор

public:
    static DbSingleton* instance();
    bool openDB(const QString& dbPath);
    QSqlDatabase& database();
    ~DbSingleton();
};

#endif // DBSINGLETON_H