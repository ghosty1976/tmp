#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Решение корня уравнения");

    // Добавление методов решения в выпадающий список
    ui->comboBoxMethod->addItem("Метод дихотомии");
    ui->comboBoxMethod->addItem("Метод простой итерации");

    ui->lineEditFunction->setPlaceholderText("Введите функцию");  // Подсказка для функции
    ui->lineEditInterval->setPlaceholderText("Введите интервал"); // Подсказка для интервала
    ui->lineEditTolerance->setPlaceholderText("Введите точность"); // Подсказка для точности
    ui->lineEditMaxIterations->setPlaceholderText("Введите кол-во итераций"); // Подсказка для итераций
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_show()
{
    this->show();  // Показываем окно Solution
}

void MainWindow::on_pushButtonSolve_clicked()
{
    // Получаем данные из полей
    QString functionText = ui->lineEditFunction->text().trimmed();
    QString intervalText = ui->lineEditInterval->text().trimmed();
    int methodIndex = ui->comboBoxMethod->currentIndex();

    // Проверка на пустые поля
    if (functionText.isEmpty() || intervalText.isEmpty()) {
        QMessageBox::warning(this, "Пустые поля", "Пожалуйста, заполните все обязательные поля.");
        return;
    }

    // Проверка на правильность ввода функции
    if (!isValidFunction(functionText)) {
        QMessageBox::warning(this, "Ошибка ввода", "Функция должна содержать только латинские буквы, цифры, операторы и скобки.");
        return;
    }

    // Проверка интервала
    if (!isValidInterval(intervalText)) {
        QMessageBox::warning(this, "Ошибка ввода", "Интервал должен быть в формате: a,b, например 2,3.");
        return;
    }

    // Получаем значения точности и максимального числа итераций
    bool ok1, ok2;
    double tolerance = ui->lineEditTolerance->text().toDouble(&ok1);  // Преобразуем строку в double
    int maxIterations = ui->lineEditMaxIterations->text().toInt(&ok2);  // Преобразуем строку в int

    // Проверка на обязательность точности и числа итераций
    if (!ok1 || tolerance <= 0 || tolerance > 0.1) {
        QMessageBox::warning(this, "Ошибка ввода", "Пожалуйста, введите корректную точность в пределах от 0.001 до 0.1.");
        return;
    }

    if (!ok2 || maxIterations <= 0 || maxIterations > 100) {
        QMessageBox::warning(this, "Ошибка ввода", "Количество итераций должно быть целым числом от 1 до 100.");
        return;
    }

    // Разбиение интервала на части
    QStringList parts = intervalText.split(",");
    if (parts.size() != 2) {
        QMessageBox::warning(this, "Ошибка ввода", "Введите интервал в формате: a,b.");
        return;
    }

    double a = parts[0].toDouble(&ok1);
    double b = parts[1].toDouble(&ok2);

    if (!ok1 || !ok2) {
        QMessageBox::warning(this, "Ошибка ввода", "Некорректные значения интервала!");
        return;
    }

    // Проверка a < b
    if (a >= b) {
        QMessageBox::warning(this, "Ошибка ввода", "Левая граница интервала должна быть меньше правой.");
        return;
    }

    // Отправка данных на сервер
    emit sendToServer(functionText, a, b, methodIndex, tolerance, maxIterations);

    // Уведомление пользователя
    QMessageBox::information(this, "Успех", "Данные отправлены на сервер.");

    // Открываем окно Solution, чтобы отобразить решение
    slot_show();
}



// Проверка функции на правильность ввода
bool MainWindow::isValidFunction(const QString& function)
{
    // Разрешенные символы в функции (латинские буквы, цифры, операторы, скобки)
    QRegularExpression regex("^[a-zA-Z0-9\\+\\-\\*\\/\\(\\)\\^\\.\\s]*$");
    return regex.match(function).hasMatch();
}

// Проверка интервала на корректность
bool MainWindow::isValidInterval(const QString& interval)
{
    // Интервал должен быть в формате "a,b" или "a, b" с дробными числами
    QRegularExpression regex("^\\d+(\\.\\d+)?\\s*,\\s*\\d+(\\.\\d+)?$");
    return regex.match(interval).hasMatch();
}

// Проверка чисел на корректность
bool MainWindow::isValidNumber(const QString& text)
{
    bool ok;
    double value = text.toDouble(&ok);
    return ok && value > 0;  // Проверка, что значение больше нуля
}
