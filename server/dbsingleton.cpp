#include "dbsingleton.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

DbSingleton::DbSingleton() {}

DbSingleton::~DbSingleton() {
    if (db.isOpen()) db.close();
}

DbSingleton& DbSingleton::instance() {
    static DbSingleton s;
    return s;
}

bool DbSingleton::openDB(const QString& dbPath) {
    if (db.isOpen()) return true;
    db = QSqlDatabase::addDatabase("QSQLITE", "singleton_connection");
    db.setDatabaseName(dbPath);
    if (!db.open()) {
        qDebug() << "[DBSINGLETON] Error opening DB:" << db.lastError().text();
        return false;
    }
    return true;
}

QSqlDatabase& DbSingleton::database() {
    return db;
}
