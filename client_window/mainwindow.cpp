#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "networkclient.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    solutionWindow(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("Решение корня уравнения");

    ui->comboBoxMethod->addItem("Дихотомия");
    ui->comboBoxMethod->addItem("Итерация");

    // Устанавливаем значения по умолчанию
    ui->lineEditTolerance->setText("0.0001");
    ui->lineEditMaxIterations->setText("100");

    // Делаем поля только для чтения
    ui->lineEditTolerance->setReadOnly(true);
    ui->lineEditMaxIterations->setReadOnly(true);

    // Добавляем подсказки
    ui->lineEditFunction->setPlaceholderText("Пример: x^2-4");
    ui->lineEditInterval->setPlaceholderText("Пример: 1,2");
}

MainWindow::~MainWindow()
{
    delete ui;
    if (solutionWindow) {
        delete solutionWindow;
        solutionWindow = nullptr;
    }
}

void MainWindow::slot_show()
{
    this->show();
}

void MainWindow::on_pushButtonSolve_clicked()
{
    // 1) Считываем поля
    QString functionText = ui->lineEditFunction->text().trimmed();
    QString intervalText = ui->lineEditInterval->text().trimmed();
    int methodIndex = ui->comboBoxMethod->currentIndex();

    // Удаляем все пробелы из функции
    functionText = functionText.remove(' ');

    // 2) Простые проверки
    if (functionText.isEmpty() || intervalText.isEmpty()) {
        QMessageBox::warning(this, "Пустые поля",
                             "Пожалуйста, заполните все необходимые поля:\n"
                             "- Функция\n"
                             "- Интервал");
        return;
    }

    if (!isValidFunction(functionText)) {
        QMessageBox::warning(this, "Ошибка в функции",
                             "Функция содержит недопустимые символы или русские буквы.\n\n"
                             "Разрешены только:\n"
                             "• Латинские буквы (a-z, A-Z)\n"
                             "• Цифры (0-9)\n"
                             "• Математические операторы: + - * / ^ ( )\n"
                             "• Точка для десятичных дробей\n\n"
                             "Используйте abs(x) вместо |x|\n"
                             "Пример правильной функции: x^2-4*sin(x)");
        return;
    }

    if (!isValidInterval(intervalText)) {
        QMessageBox::warning(this, "Ошибка в интервале",
                             "Некорректный формат интервала.\n\n"
                             "Требования:\n"
                             "• Два числа разделённые запятой\n"
                             "• Левое число должно быть меньше правого\n"
                             "• Допускаются отрицательные числа\n\n"
                             "Примеры правильных интервалов:\n"
                             "1,2\n"
                             "-3.5,0\n"
                             "0.1,5.7");
        return;
    }

    // Фиксированные значения по методичке
    double tolerance = 0.0001;
    int maxIterations = 100;

    QStringList parts = intervalText.split(",");
    if (parts.size() != 2) {
        QMessageBox::warning(this, "Ошибка формата",
                             "Интервал должен содержать ровно два числа, разделённых запятой.\n"
                             "Пример: 1,2");
        return;
    }

    bool ok1, ok2;
    double a = parts[0].toDouble(&ok1);
    double b = parts[1].toDouble(&ok2);

    if (!ok1 || !ok2) {
        QMessageBox::warning(this, "Ошибка чисел",
                             "Одно или оба числа в интервале не являются допустимыми числами.\n"
                             "Пожалуйста, используйте только цифры и точку для десятичных дробей.");
        return;
    }

    if (a >= b) {
        QMessageBox::warning(this, "Некорректный интервал",
                             "Левая граница интервала должна быть меньше правой.\n\n"
                             "Вы ввели: [" + QString::number(a) + ", " + QString::number(b) + "]\n"
                                                                                    "Исправьте интервал так, чтобы первое число было меньше второго.");
        return;
    }

    // 3) Запрашиваем решение у сервера
    QString html = NetworkClient::instance()->getSolution(
        functionText,
        a, b,
        methodIndex,
        tolerance,
        maxIterations
        );

    if (html.isEmpty()) {
        QMessageBox::warning(this, "Ошибка сервера",
                             "Сервер не смог решить уравнение.\n\n"
                             "Возможные причины:\n"
                             "• Некорректная функция\n"
                             "• Отсутствие решения на интервале\n"
                             "• Проблемы с подключением\n\n"
                             "Проверьте функцию и интервал и попробуйте снова.");
        return;
    }

    // 4) Отображаем решение
    emit solution_ok(html);
}

// Проверка функции из допустимых символов
bool MainWindow::isValidFunction(const QString& function)
{
    // Разрешаем только латинские буквы, цифры, математические операторы и точку
    QRegularExpression regex("^[a-zA-Z0-9\\+\\-\\*\\/\\(\\)\\^\\.]+$");
    return regex.match(function).hasMatch();
}

// Проверка интервала "a,b"
bool MainWindow::isValidInterval(const QString& interval)
{
    QRegularExpression regex("^\\s*[-+]?\\d+(\\.\\d+)?\\s*,\\s*[-+]?\\d+(\\.\\d+)?\\s*$");
    return regex.match(interval).hasMatch();
}
