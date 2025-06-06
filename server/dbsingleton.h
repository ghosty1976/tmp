/**
 * @file dbsingleton.h
 * @brief Singleton для работы с базой данных (SQLite/MySQL).
 */

#ifndef DBSINGLETON_H
#define DBSINGLETON_H

#include <QSqlDatabase>

/**
 * @class DbSingleton
 * @brief Паттерн Singleton для управления подключением к БД.
 */
class DbSingleton
{
private:
    static DbSingleton* p_instance; ///< Единственный экземпляр.
    QSqlDatabase db; ///< Объект базы данных.

    DbSingleton(); ///< Приватный конструктор.

public:
    /**
     * @brief Получение экземпляра класса.
     * @return Указатель на экземпляр.
     */
    static DbSingleton* instance();

    /**
     * @brief Открытие базы данных.
     * @param dbPath Путь к файлу БД (для SQLite) или строка подключения.
     * @return true, если подключение успешно.
     */
    bool openDB(const QString& dbPath);

    /**
     * @brief Доступ к объекту БД.
     * @return Ссылка на QSqlDatabase.
     */
    QSqlDatabase& database();

    ~DbSingleton(); ///< Деструктор (закрывает соединение).
};

#endif // DBSINGLETON_H