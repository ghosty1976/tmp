#ifndef DBSINGLETON_H
#define DBSINGLETON_H

#include <QObject>
#include <QSqlDatabase>

/**
 * @brief Класс-одиночка для работы с базой данных
 * 
 * Реализует паттерн Singleton для обеспечения единственного экземпляра
 * соединения с базой данных в приложении.
 */
class DbSingleton
{
private:
    QSqlDatabase db;    ///< Объект базы данных Qt
    DbSingleton();      ///< Приватный конструктор

public:
    /**
     * @brief Получение единственного экземпляра класса
     * @return Ссылка на единственный экземпляр DbSingleton
     */
    static DbSingleton& instance(); // теперь возвращает ссылку!

    /**
     * @brief Открытие соединения с базой данных
     * @param dbPath Путь к файлу базы данных
     * @return true если соединение успешно установлено, false в случае ошибки
     */
    bool openDB(const QString& dbPath);

    /**
     * @brief Получение объекта базы данных
     * @return Ссылка на объект QSqlDatabase
     */
    QSqlDatabase& database();

    /**
     * @brief Деструктор класса
     * 
     * Закрывает соединение с базой данных при уничтожении объекта
     */
    ~DbSingleton();
};

#endif // DBSINGLETON_H