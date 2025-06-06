#include "authregform.h"
#include "ui_authregform.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include "networkclient.h"
#include <QInputDialog>

AuthRegForm::AuthRegForm(QWidget *parent)
    : QDialog(parent), ui(new Ui::AuthRegForm), authAttempts(0)
{
    ui->setupUi(this);

    ui->lineEditPassword->setEchoMode(QLineEdit::Password);
    ui->lineEditLogin->setPlaceholderText("Введите логин");    // Подсказка для логина
    ui->lineEditPassword->setPlaceholderText("Введите пароль"); // Подсказка для пароля

    setupFieldFocus();  // Настройка перехода по полям через Enter

    setWindowTitle("Авторизация"); // Название окна

    // Настройка проверки ввода, теперь разрешаем цифры и английские буквы
    QRegularExpression regex("^[a-zA-Z0-9]+$");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);
    ui->lineEditLogin->setValidator(validator);
    ui->lineEditPassword->setValidator(validator);

    // Подключение слотов к кнопкам
    connect(ui->pushButtonAuth, &QPushButton::clicked, this, &AuthRegForm::on_pushButtonAuth_clicked);
    connect(ui->pushButtonReg, &QPushButton::clicked, this, &AuthRegForm::on_pushButtonReg_clicked);
    connect(ui->pushButtonForgotPassword, &QPushButton::clicked, this, &AuthRegForm::on_pushButtonForgotPassword_clicked);
}

AuthRegForm::~AuthRegForm() {
    delete ui;
}

// Показать ошибку с соответствующим названием окна
void AuthRegForm::showError(const QString &title, const QString &message) {
    QMessageBox::warning(this, title, message);
}

// Настройка перехода между полями
void AuthRegForm::setupFieldFocus() {
    setTabOrder(ui->lineEditLogin, ui->lineEditPassword);  // Переключение на следующее поле по нажатию Enter
    setTabOrder(ui->lineEditPassword, ui->pushButtonAuth);  // Переход на кнопку входа
}

// Проверка, что ввод содержит только английские буквы и цифры
bool AuthRegForm::isValidEnglishInput(const QString& input) {
    QRegularExpression regex("^[a-zA-Z0-9]+$"); // Регулярное выражение для английских букв и цифр
    return regex.match(input).hasMatch();  // Проверяем, соответствует ли строка регулярному выражению
}

// Обработка авторизации
void AuthRegForm::on_pushButtonAuth_clicked() {
    if (isRequestSent) return;  // Если запрос уже отправлен, не выполняем его повторно

    isRequestSent = true;  // Устанавливаем флаг, что запрос был отправлен

    QString login = ui->lineEditLogin->text();
    QString password = ui->lineEditPassword->text();

    // Проверка на пустые поля
    if (login.isEmpty()) {
        showError("Пустое поле для логина", "Пожалуйста, заполните поле для логина.");
        ui->lineEditLogin->setFocus();
        isRequestSent = false;  // Сбрасываем флаг, так как запрос не был отправлен
        return;
    }
    if (password.isEmpty()) {
        showError("Пустое поле для пароля", "Пожалуйста, заполните поле для пароля.");
        ui->lineEditPassword->setFocus();
        isRequestSent = false;  // Сбрасываем флаг, так как запрос не был отправлен
        return;
    }

    // Проверка на английские буквы и цифры для логина
    if (!isValidEnglishInput(login)) {
        showError("Неверный логин", "Логин должен содержать только английские буквы и цифры.");
        ui->lineEditLogin->setFocus();
        isRequestSent = false;  // Сбрасываем флаг, так как запрос не был отправлен
        return;
    }

    // Проверка на английские буквы и цифры для пароля
    if (!isValidEnglishInput(password)) {
        showError("Неверный пароль", "Пароль должен содержать только английские буквы и цифры.");
        ui->lineEditPassword->setFocus();
        isRequestSent = false;  // Сбрасываем флаг, так как запрос не был отправлен
        return;
    }

    if (authAttempts >= 3) {
        showError("Ошибка авторизации", "Вы превысили количество попыток авторизации.");
        isRequestSent = false;  // Сбрасываем флаг, так как запрос не был отправлен
        return;
    }

    // Проверка длины пароля
    if (password.length() < 5 || password.length() > 15) {
        showError("Недопустимая длина пароля", "Пароль должен быть от 5 до 15 символов.");
        isRequestSent = false;  // Сбрасываем флаг, так как запрос не был отправлен
        return;
    }

    // Попытка авторизации
    if (NetworkClient::instance()->authenticate(login, password)) {
        emit auth_ok(login);  // Успешная авторизация
        QMessageBox::information(this, "Авторизация успешна", "Вы успешно вошли в систему.");
        emit switchToMainWindow(); // Переход в главное окно
        this->close();
    } else {
        authAttempts++;
        showError("Неверный логин или пароль", "Логин или пароль неверны. Пожалуйста, проверьте введенные данные.");
        if (authAttempts == 1) {
            ui->pushButtonForgotPassword->setVisible(true);
        }
    }

    isRequestSent = false;  // Сбрасываем флаг после завершения запроса
}

// Переход на форму регистрации
void AuthRegForm::on_pushButtonReg_clicked() {
    emit switchToRegistrationForm();  // Сигнал для перехода на форму регистрации
}

// Восстановление пароля
void AuthRegForm::on_pushButtonForgotPassword_clicked() {
    emit recovery_ok(); // Открытие формы восстановления пароля
}

// Очистка всех полей
void AuthRegForm::clear() {
    ui->lineEditLogin->clear();
    ui->lineEditPassword->clear();
}
