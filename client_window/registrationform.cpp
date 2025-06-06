#include "registrationform.h"
#include "ui_registrationform.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include "networkclient.h"

RegistrationForm::RegistrationForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationForm)
{
    ui->setupUi(this); // Инициализация UI
    setWindowTitle("Регистрация пользователя"); // Название окна

    // Устанавливаем фокус на поле почты
    ui->lineEditMail->setFocus();

    // Подключение слотов к кнопкам
    connect(ui->pushButtonNext, &QPushButton::clicked, this, &RegistrationForm::on_pushButtonNext_clicked);
    connect(ui->pushButtonCreateAccount, &QPushButton::clicked, this, &RegistrationForm::on_pushButtonCreateAccount_clicked);
    connect(ui->pushButtonBackToAuth, &QPushButton::clicked, this, &RegistrationForm::on_pushButtonBackToAuth_clicked); // Слот для кнопки назад

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

    // Скрываем все поля и лейблы, кроме почты
    ui->lineEditCode->setVisible(false);
    ui->lineEditLogin->setVisible(false);
    ui->lineEditPassword->setVisible(false);
    ui->lineEditPasswordCheck->setVisible(false);
    ui->pushButtonCreateAccount->setVisible(false);

    ui->labelMail->setVisible(true); // Лейбл для почты
    ui->labelCode->setVisible(false); // Лейбл для кода
    ui->labelLogin->setVisible(false); // Лейбл для логина
    ui->labelPassword->setVisible(false); // Лейбл для пароля
    ui->labelPasswordCheck->setVisible(false); // Лейбл для подтверждения пароля

    ui->lineEditMail->setPlaceholderText("Введите ваш email");  // Подсказка для поля email
    ui->lineEditLogin->setPlaceholderText("Введите логин");     // Подсказка для поля логина
    ui->lineEditPassword->setPlaceholderText("Введите пароль"); // Подсказка для поля пароля
    ui->lineEditPasswordCheck->setPlaceholderText("Подтвердите пароль"); // Подсказка для поля подтверждения пароля
    ui->lineEditCode->setPlaceholderText("Введите код");      // Подсказка для поля кода
}

RegistrationForm::~RegistrationForm() {
    delete ui;
}

// Отображение ошибки с названием окна
void RegistrationForm::showError(const QString& title, const QString& message) {
    QMessageBox::warning(this, title, message);
}

// Настройка перехода между полями (Enter)
void RegistrationForm::setupFieldFocus() {
    setTabOrder(ui->lineEditMail, ui->lineEditCode);  // Переход между полями почты и кода
    setTabOrder(ui->lineEditCode, ui->lineEditLogin);  // Переход к логину
    setTabOrder(ui->lineEditLogin, ui->lineEditPassword);  // Переход к паролю
    setTabOrder(ui->lineEditPassword, ui->lineEditPasswordCheck);  // Переход к подтверждению пароля
    setTabOrder(ui->lineEditPasswordCheck, ui->pushButtonNext);  // Переход к кнопке "Далее"
}

// Проверка на корректность почты
bool RegistrationForm::isValidEmail(const QString& email) {
    QRegularExpression regex("^\\S+@\\S+\\.\\S+$"); // Проверка на стандартный формат почты
    return regex.match(email).hasMatch();  // Проверяем, что почта соответствует регулярному выражению
}

// Проверка на английские буквы и цифры
bool RegistrationForm::isEnglishAndDigitInput(const QString &input) {
    QRegularExpression regex("^[a-zA-Z0-9]+$");
    return regex.match(input).hasMatch();  // Проверяем, что ввод состоит только из английских букв и цифр
}

// Отправка кода на почту
void RegistrationForm::sendCode() {
    QString email = ui->lineEditMail->text();
    if (email.isEmpty()) {
        showError("Пустое поле для почты", "Пожалуйста, заполните поле для почты.");
        return;
    }

    // Отправляем запрос на сервер для генерации и отправки кода
    bool success = NetworkClient::instance()->sendRecoveryCode(email); // Метод отправки на сервер
    if (success) {
        QMessageBox::information(this, "Код отправлен", "Код был отправлен на вашу почту.");
    } else {
        showError("Ошибка при отправке кода", "Не удалось отправить код на почту.");
    }
}

// Проверка паролей на совпадение
bool RegistrationForm::checkPasswordMatch() {
    if (ui->lineEditPassword->text() != ui->lineEditPasswordCheck->text()) {
        showError("Пароли не совпадают", "Пожалуйста, введите одинаковые пароли.");
        return false;
    }
    return true;
}

// Проверка логина на допустимую длину
bool RegistrationForm::isValidLogin(const QString &login) {
    if (login.length() < 3 || login.length() > 20) {
        showError("Неверный логин", "Логин должен быть от 3 до 20 символов.");
        return false;
    }
    return true;
}

// Проверка доступности логина
bool RegistrationForm::isLoginAvailable(const QString &login) {
    return NetworkClient::instance()->checkLoginExists(login); // Проверка доступности логина
}

// Переход по шагам
void RegistrationForm::on_pushButtonNext_clicked() {
    if (ui->lineEditMail->isVisible()) {
        // Шаг 1: Ввод почты
        if (ui->lineEditMail->text().isEmpty()) {
            showError("Пустое поле для почты", "Пожалуйста, заполните поле для почты.");
            return;
        }
        if (!isValidEmail(ui->lineEditMail->text())) {
            showError("Неверный email", "Введите корректный email.");
            return;
        }
        sendCode();
        ui->lineEditCode->setVisible(true);
        ui->labelCode->setVisible(true);  // Показать лейбл для кода
        ui->pushButtonNext->setText("Далее");
    } else if (ui->lineEditCode->isVisible()) {
        // Шаг 2: Ввод кода
        if (ui->lineEditCode->text().isEmpty()) {
            showError("Пустое поле для кода", "Пожалуйста, заполните поле для кода.");
            return;
        }

        // Проверяем код, отправленный на сервер
        bool isCodeValid = NetworkClient::instance()->verifyRecoveryCode(ui->lineEditCode->text());
        if (!isCodeValid) {
            showError("Неверный код", "Вы ввели неправильный код. Пожалуйста, перепроверьте код.");
            return;
        }

        ui->lineEditLogin->setVisible(true);
        ui->labelLogin->setVisible(true);  // Показать лейбл для логина
        ui->pushButtonNext->setText("Далее");
    } else if (ui->lineEditLogin->isVisible()) {
        // Шаг 3: Ввод логина
        if (ui->lineEditLogin->text().isEmpty()) {
            showError("Пустое поле для логина", "Пожалуйста, заполните поле для логина.");
            return;
        }
        if (!isValidLogin(ui->lineEditLogin->text())) {
            showError("Неверный логин", "Введите корректный логин.");
            return;
        }

        // Проверяем доступность логина
        if (!isLoginAvailable(ui->lineEditLogin->text())) {
            showError("Неверный логин", "Такого логина не существует.");
            return;
        }

        ui->lineEditPassword->setVisible(true);
        ui->labelPassword->setVisible(true);  // Показать лейбл для пароля
        ui->pushButtonNext->setText("Далее");
    } else if (ui->lineEditPassword->isVisible()) {
        // Шаг 4: Ввод пароля
        if (ui->lineEditPassword->text().isEmpty()) {
            showError("Пустое поле для пароля", "Пожалуйста, заполните поле для пароля.");
            return;
        }
        ui->lineEditPasswordCheck->setVisible(true);
        ui->labelPasswordCheck->setVisible(true);  // Показать лейбл для подтверждения пароля
        ui->pushButtonNext->setText("Сохранить");
    } else if (ui->lineEditPasswordCheck->isVisible()) {
        // Шаг 5: Ввод подтверждения пароля
        if (ui->lineEditPasswordCheck->text().isEmpty()) {
            showError("Пустое поле для подтверждения пароля", "Пожалуйста, подтвердите пароль.");
            return;
        }
        // Перейдем к созданию учетной записи
        on_pushButtonCreateAccount_clicked();
    }
}

// Создание учётной записи
void RegistrationForm::on_pushButtonCreateAccount_clicked() {
    QString password = ui->lineEditPassword->text();
    if (password.length() < 5 || password.length() > 15) {
        showError("Недопустимая длина пароля", "Пароль должен быть от 5 до 15 символов.");
        return;
    }

    if (checkPasswordMatch()) {
        // Реализуем регистрацию на сервере
        bool success = NetworkClient::instance()->registerUser(ui->lineEditLogin->text(), ui->lineEditPassword->text(), ui->lineEditMail->text());
        if (success) {
            QMessageBox::information(this, "Регистрация", "Учётная запись создана!");
            this->close();  // Закрываем форму после регистрации
            emit switchToAuthForm();  // Переход на форму авторизации
        } else {
            showError("Ошибка регистрации", "Ошибка при регистрации.");
        }
    }
}

// Переход на форму авторизации
void RegistrationForm::on_pushButtonBackToAuth_clicked() {
    emit switchToAuthForm();  // Переход на форму авторизации
}
