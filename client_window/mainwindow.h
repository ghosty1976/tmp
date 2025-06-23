#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "solution.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief Главное окно приложения для решения уравнений
 * 
 * Предоставляет интерфейс для ввода функции и параметров решения,
 * отправки задачи на сервер и отображения результатов.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор главного окна
     * @param parent Родительский виджет
     */
    explicit MainWindow(QWidget *parent = nullptr);
    
    /**
     * @brief Деструктор главного окна
     */
    ~MainWindow();

signals:
    /**
     * @brief Сигнал успешного получения решения
     * @param html HTML-форматированное решение уравнения
     */
    void solution_ok(const QString &html);

public slots:
    /**
     * @brief Слот для отображения главного окна
     */
    void slot_show();

private slots:
    /**
     * @brief Слот обработки нажатия кнопки "Решить"
     */
    void on_pushButtonSolve_clicked();

private:
    Ui::MainWindow *ui; ///< Указатель на графический интерфейс
    Solution *solutionWindow = nullptr; ///< Указатель на окно с решением
    
    /**
     * @brief Проверка валидности введенной функции
     * @param function Строка с функцией для проверки
     * @return true если функция валидна, false если есть ошибки
     */
    bool isValidFunction(const QString& function);
    
    /**
     * @brief Проверка валидности введенного интервала
     * @param interval Строка с интервалом для проверки
     * @return true если интервал валиден, false если есть ошибки
     */
    bool isValidInterval(const QString& interval);
};

#endif // MAINWINDOW_H