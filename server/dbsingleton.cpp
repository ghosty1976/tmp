#include "dbsingleton.h"

DbSingleton* DbSingleton::p_instance = nullptr;

DbSingleton::DbSingleton() {}

DbSingleton::~DbSingleton() {
    if (db.isOpen()) db.close();
}

DbSingleton* DbSingleton::instance() {
    if (!p_instance) p_instance = new DbSingleton();
    return p_instance;
}

bool DbSingleton::openDB(const QString& dbPath) {
    if (db.isOpen()) return true;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);
    return db.open();
}

QSqlDatabase& DbSingleton::database() {
    return db;
}