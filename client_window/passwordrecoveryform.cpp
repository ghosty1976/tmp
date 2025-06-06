#include "passwordrecoveryform.h"
#include "ui_passwordrecoveryform.h"  // Подключаем сгенерированный файл UI с маленькой буквы
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include "networkclient.h"

passwordrecoveryform::passwordrecoveryform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::passwordrecoveryform),  // Используем с маленькой буквы
    isCodeValid(false)  // Инициализация переменной
{
    ui->setupUi(this);  // Настройка интерфейса
    setWindowTitle("Восстановление пароля");

    // Подключение слотов к кнопкам
    connect(ui->pushButtonNext, &QPushButton::clicked, this, &passwordrecoveryform::on_pushButtonNext_clicked);
    connect(ui->pushButtonSave, &QPushButton::clicked, this, &passwordrecoveryform::on_pushButtonSave_clicked);

    // Настройка проверки ввода английскими буквами и цифрами для логина и пароля
    QRegularExpression regex("^[a-zA-Z0-9]+$");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);
    ui->lineEditLogin->setValidator(validator);
    ui->lineEditPassword->setValidator(validator);
    ui->lineEditPasswordCheck->setValidator(validator);

    // Настройка поля для ввода кода (только цифры)
    QRegularExpression codeRegex("^[0-9]+$");
    QRegularExpressionValidator *codeValidator = new QRegularExpressionValidator(codeRegex, this);
    ui->lineEditCode->setValidator(codeValidator);

    // Устанавливаем скрытие текста для полей пароля
    ui->lineEditPassword->setEchoMode(QLineEdit::Password);
    ui->lineEditPasswordCheck->setEchoMode(QLineEdit::Password);

    // Скрываем все поля и лейблы, кроме логина
    ui->lineEditCode->setVisible(false);
    ui->lineEditLogin->setVisible(true);
    ui->lineEditPassword->setVisible(false);
    ui->lineEditPasswordCheck->setVisible(false);
    ui->pushButtonSave->setVisible(false);

    ui->labelLogin->setVisible(true); // Лейбл для логина
    ui->labelCode->setVisible(false); // Лейбл для кода
    ui->labelPassword->setVisible(false); // Лейбл для пароля
    ui->labelPasswordCheck->setVisible(false); // Лейбл для подтверждения пароля

    // Устанавливаем подсказки для полей ввода
    ui->lineEditLogin->setPlaceholderText("Введите логин");    // Подсказка для логина
    ui->lineEditCode->setPlaceholderText("Введите код"); // Подсказка для кода
    ui->lineEditPassword->setPlaceholderText("Введите новый пароль"); // Подсказка для нового пароля
    ui->lineEditPasswordCheck->setPlaceholderText("Подтвердите новый пароль"); // Подсказка для подтверждения пароля
}

passwordrecoveryform::~passwordrecoveryform() {
    delete ui;
}

// Показать ошибку с названием окна
void passwordrecoveryform::showError(const QString &title, const QString &message) {
    QMessageBox::warning(this, title, message);
}

// Настройка перехода между полями (Enter)
void passwordrecoveryform::setupFieldFocus() {
    setTabOrder(ui->lineEditLogin, ui->lineEditCode);  // Переход между полями логина и кода
    setTabOrder(ui->lineEditCode, ui->lineEditPassword);  // Переход к новому паролю
    setTabOrder(ui->lineEditPassword, ui->lineEditPasswordCheck);  // Переход к подтверждению пароля
    setTabOrder(ui->lineEditPasswordCheck, ui->pushButtonNext);  // Переход к кнопке "Далее"
}

// Проверка на английские буквы и цифры
bool passwordrecoveryform::isEnglishInput(const QString &input) {
    QRegularExpression regex("^[a-zA-Z0-9]+$");
    return regex.match(input).hasMatch();  // Проверяем, что ввод состоит только из английских букв и цифр
}

// Проверка на корректность логина
bool passwordrecoveryform::isValidLogin(const QString &login) {
    return !login.isEmpty(); // Логин не должен быть пустым
}

// Отправка кода на почту
void passwordrecoveryform::sendCode() {
    QString login = ui->lineEditLogin->text();
    if (login.isEmpty()) {
        showError("Пустое поле для логина", "Пожалуйста, заполните поле для логина.");
        return;
    }

    bool success = NetworkClient::instance()->sendRecoveryCode(login); // Метод отправки кода на сервер
    if (success) {
        QMessageBox::information(this, "Код отправлен", "Код был отправлен на вашу почту.");
    } else {
        showError("Ошибка при отправке кода", "Не удалось отправить код на почту.");
    }
}

// Проверка паролей на совпадение
bool passwordrecoveryform::checkPasswordMatch() {
    if (ui->lineEditPassword->text() != ui->lineEditPasswordCheck->text()) {
        showError("Пароли не совпадают", "Пожалуйста, введите одинаковые пароли.");
        return false;
    }
    return true;
}

// Завершение восстановления пароля
void passwordrecoveryform::recoverPassword() {
    // Логика восстановления пароля (например, отправка нового пароля на сервер)
    QMessageBox::information(this, "Восстановление пароля", "Пароль успешно восстановлен!");
    this->close();  // Закрываем форму после восстановления пароля
}

// Переход по шагам
void passwordrecoveryform::on_pushButtonNext_clicked() {
    if (ui->lineEditLogin->isVisible()) {
        // Шаг 1: Ввод логина
        if (ui->lineEditLogin->text().isEmpty()) {
            showError("Неверный логин", "Заполните поле для логина!");
            return;
        }
        if (!isValidLogin(ui->lineEditLogin->text())) {
            showError("Неверный логин", "Введите корректный логин!");
            return;
        }
        sendCode();
        ui->lineEditCode->setVisible(true);
        ui->labelCode->setVisible(true);  // Показать лейбл для кода
        ui->pushButtonNext->setText("Далее");
    } else if (ui->lineEditCode->isVisible()) {
        // Шаг 2: Ввод кода
        if (ui->lineEditCode->text().isEmpty()) {
            showError("Неверный код", "Заполните поле для кода!");
            return;
        }
        // Проверяем код, отправленный на сервер
        bool isCodeValid = NetworkClient::instance()->verifyRecoveryCode(ui->lineEditCode->text());
        if (!isCodeValid) {
            showError("Неверный код", "Неверный код!");
            return;
        }

        ui->lineEditPassword->setVisible(true);
        ui->lineEditPasswordCheck->setVisible(true);
        ui->labelPassword->setVisible(true);  // Показать лейбл для пароля
        ui->labelPasswordCheck->setVisible(true); // Показать лейбл для подтверждения пароля
        ui->pushButtonNext->setText("Сохранить");
    }
}

// Сохранение нового пароля
void passwordrecoveryform::on_pushButtonSave_clicked() {
    if (checkPasswordMatch()) {
        recoverPassword();
    }
}

// Показываем форму
void passwordrecoveryform::slot_show() {
    this->show();  // Показываем форму восстановления
}
