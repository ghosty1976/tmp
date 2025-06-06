#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"  // Подключаем сгенерированный файл UI

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);  // Конструктор
    ~MainWindow();  // Деструктор

private slots:
    void on_pushButtonSolve_clicked();  // Обработка нажатия кнопки "Решить"

public slots:
    void slot_show();  // Слот для отображения окна с результатом

signals:
    void sendToServer(QString functionText, double a, double b, int methodIndex, double tolerance, int maxIterations); // Сигнал для отправки данных на сервер
    void solution_ok(QString solution); // Сигнал для отображения решения

private:
    Ui::MainWindow *ui;  // Указатель на интерфейс формы

    // Проверки на валидность данных
    bool isValidFunction(const QString& function);
    bool isValidInterval(const QString& interval);
    bool isValidNumber(const QString& text);

    // Переменные для хранения точности и числа итераций
    double tolerance;
    int maxIterations;
};

#endif // MAINWINDOW_H
