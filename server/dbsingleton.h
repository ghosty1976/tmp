#ifndef DBSINGLETON_H
#define DBSINGLETON_H

#include <QObject>
#include <QSqlDatabase>

class DbSingleton
{
private:
    QSqlDatabase db;
    DbSingleton();
public:
    static DbSingleton& instance(); // теперь возвращает ссылку!
    bool openDB(const QString& dbPath);
    QSqlDatabase& database();
    ~DbSingleton();
};

#endif // DBSINGLETON_H
