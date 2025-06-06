#include "solution.h"
#include "ui_solution.h"
#include <QMessageBox>

Solution::Solution(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Solution)  // Инициализация указателя ui
{
    ui->setupUi(this);  // Инициализация UI
    setWindowTitle("Результат решения");
}

Solution::~Solution()
{
    delete ui;
}

void Solution::slot_show()
{
    this->show();  // Показываем окно Solution
}

void Solution::setSolution(const QString &solution)
{
    // Составляем HTML-формат для вывода решения
    QString formattedSolution = "<h3>Решение:</h3>"
                                "<p><b>Метод:</b> " + methodText + "</p>"
                                               "<p><b>Интервал:</b> " + intervalText + "</p>"
                                                 "<p><b>Точность:</b> " + QString::number(tolerance) + "</p>"
                                                               "<p><b>Ответ:</b> " + answer + "</p>"
                                           "<p><b>Количество итераций:</b> " + QString::number(maxIterations) + "</p>";

    // Отображаем решение в QTextBrowser
    ui->textBrowser->setHtml(formattedSolution);
}

