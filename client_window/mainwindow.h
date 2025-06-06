/**
 * @file mainwindow.h
 * @brief Заголовочный файл класса MainWindow, представляющего главное окно приложения.
 *
 * Этот класс предоставляет интерфейс для ввода данных, отправки их на сервер
 * и отображения результатов решения уравнений.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief Класс, представляющий главное окно приложения.
 *
 * Класс MainWindow обеспечивает взаимодействие пользователя с приложением,
 * включая ввод данных, отправку запросов на сервер и отображение результатов.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса MainWindow.
     * @param parent Родительский виджет (по умолчанию nullptr).
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса MainWindow.
     */
    ~MainWindow();

private slots:
    /**
     * @brief Обработчик нажатия кнопки "Решить".
     *
     * Выполняет проверку введенных данных и отправляет их на сервер для решения уравнения.
     */
    void on_pushButtonSolve_clicked();

public slots:
    /**
     * @brief Слот для отображения окна с результатом.
     */
    void slot_show();

signals:
    /**
     * @brief Сигнал для отправки данных на сервер.
     * @param functionText Текст функции для решения.
     * @param a Начальная точка интервала.
     * @param b Конечная точка интервала.
     * @param methodIndex Индекс выбранного метода решения.
     * @param tolerance Допустимая погрешность.
     * @param maxIterations Максимальное количество итераций.
     */
    void sendToServer(QString functionText, double a, double b, int methodIndex, double tolerance, int maxIterations);

    /**
     * @brief Сигнал для отображения решения.
     * @param solution Строка с решением уравнения.
     */
    void solution_ok(QString solution);

private:
    Ui::MainWindow *ui; ///< Указатель на интерфейс формы.
    double tolerance;   ///< Допустимая погрешность при решении уравнения.
    int maxIterations;  ///< Максимальное количество итераций для решения уравнения.

    /**
     * @brief Проверяет валидность введенной функции.
     * @param function Строка с функцией для проверки.
     * @return true, если функция валидна, иначе false.
     */
    bool isValidFunction(const QString& function);

    /**
     * @brief Проверяет валидность введенного интервала.
     * @param interval Строка с интервалом для проверки.
     * @return true, если интервал валиден, иначе false.
     */
    bool isValidInterval(const QString& interval);

    /**
     * @brief Проверяет, является ли строка числом.
     * @param text Строка для проверки.
     * @return true, если строка является числом, иначе false.
     */
    bool isValidNumber(const QString& text);
};

#endif // MAINWINDOW_H