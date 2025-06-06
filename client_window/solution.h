#ifndef SOLUTION_H
#define SOLUTION_H

#include <QMainWindow>
#include "ui_solution.h"  // Подключаем сгенерированный файл UI

QT_BEGIN_NAMESPACE
namespace Ui { class Solution; }
QT_END_NAMESPACE

class Solution : public QMainWindow
{
    Q_OBJECT

public:
    explicit Solution(QWidget *parent = nullptr);  // Конструктор
    ~Solution();  // Деструктор

    void setSolution(const QString &solution);  // Установка решения в QTextBrowser

public slots:
    void slot_show();  // Слот для отображения окна с решением

private:
    Ui::Solution *ui;

    // Члены для хранения данных, которые будем выводить в Solution
    QString functionText;
    QString intervalText;
    QString methodText;
    QString answer;

    // Переменные для хранения точности и числа итераций
    double tolerance;       // Точность
    int maxIterations;      // Количество итераций
};

#endif // SOLUTION_H
