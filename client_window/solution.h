#ifndef SOLUTION_H
#define SOLUTION_H

#include <QMainWindow>

namespace Ui {
class Solution;
}

/**
 * @brief Класс для отображения решения уравнения
 * 
 * Окно отображает результаты решения уравнения в HTML-формате,
 * полученные от сервера, включая графики и текстовое описание.
 */
class Solution : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор окна решения
     * @param parent Родительский виджет
     */
    explicit Solution(QWidget *parent = nullptr);
    
    /**
     * @brief Деструктор окна решения
     */
    ~Solution();

    /**
     * @brief Установка HTML-контента с решением
     * @param html HTML-строка с результатами решения уравнения
     */
    void setSolution(const QString &html);

public slots:
    /**
     * @brief Слот для отображения окна с решением
     */
    void slot_show();  // Показываем окно

private:
    Ui::Solution *ui; ///< Указатель на графический интерфейс окна решения
};

#endif // SOLUTION_H