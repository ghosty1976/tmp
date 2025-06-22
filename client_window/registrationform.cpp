#include "registrationform.h"
#include "ui_registrationform.h"
#include "networkclient.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QPalette>

RegistrationForm::RegistrationForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationForm),
    currentStep(StepCredentials)
{
    ui->setupUi(this);
    setWindowTitle("Регистрация пользователя");

    // Валидатор для логина и пароля: только английские буквы и цифры
    QRegularExpression regexAlnum("^[a-zA-Z0-9]+$");
    ui->lineEditLogin->setValidator(new QRegularExpressionValidator(regexAlnum, this));
    ui->lineEditPassword->setValidator(new QRegularExpressionValidator(regexAlnum, this));
    ui->lineEditPasswordCheck->setValidator(new QRegularExpressionValidator(regexAlnum, this));
    ui->lineEditCode->setValidator(new QRegularExpressionValidator(QRegularExpression("^[0-9]{6}$"), this));

    // Валидатор для email: английские буквы, цифры и основные символы
    QRegularExpression regexEmail("[a-zA-Z0-9._%+-@]+");
    ui->lineEditMail->setValidator(new QRegularExpressionValidator(regexEmail, this));

    // Скрытый ввод пароля
    ui->lineEditPassword->setEchoMode(QLineEdit::Password);
    ui->lineEditPasswordCheck->setEchoMode(QLineEdit::Password);

    // Placeholder'ы
    ui->lineEditMail->setPlaceholderText("...");
    ui->lineEditLogin->setPlaceholderText("...");
    ui->lineEditPassword->setPlaceholderText("...");
    ui->lineEditPasswordCheck->setPlaceholderText("...");
    ui->lineEditCode->setPlaceholderText("...");

    // Установка фильтра событий
    ui->lineEditMail->installEventFilter(this);
    ui->lineEditLogin->installEventFilter(this);
    ui->lineEditPassword->installEventFilter(this);
    ui->lineEditPasswordCheck->installEventFilter(this);
    ui->lineEditCode->installEventFilter(this);

    // Обновляем интерфейс
    updateUI();
}

RegistrationForm::~RegistrationForm()
{
    delete ui;
}

void RegistrationForm::slot_show()
{
    currentStep = StepCredentials;

    // Очищаем поля
    ui->lineEditMail->clear();
    ui->lineEditLogin->clear();
    ui->lineEditPassword->clear();
    ui->lineEditPasswordCheck->clear();
    ui->lineEditCode->clear();

    // Разблокируем все поля
    ui->lineEditMail->setReadOnly(false);
    ui->lineEditLogin->setReadOnly(false);
    ui->lineEditPassword->setReadOnly(false);
    ui->lineEditPasswordCheck->setReadOnly(false);

    // Восстанавливаем стандартный цвет
    ui->lineEditMail->setPalette(QPalette());
    ui->lineEditLogin->setPalette(QPalette());
    ui->lineEditPassword->setPalette(QPalette());
    ui->lineEditPasswordCheck->setPalette(QPalette());

    updateUI();
    show();
}

void RegistrationForm::lockFields()
{
    ui->lineEditMail->setReadOnly(true);
    ui->lineEditLogin->setReadOnly(true);
    ui->lineEditPassword->setReadOnly(true);
    ui->lineEditPasswordCheck->setReadOnly(true);

    QPalette palette;
    palette.setColor(QPalette::Base, Qt::white);
    ui->lineEditMail->setPalette(palette);
    ui->lineEditLogin->setPalette(palette);
    ui->lineEditPassword->setPalette(palette);
    ui->lineEditPasswordCheck->setPalette(palette);
}

bool RegistrationForm::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter) {
            if (obj == ui->lineEditMail) {
                ui->lineEditLogin->setFocus();
                return true;
            } else if (obj == ui->lineEditLogin) {
                ui->lineEditPassword->setFocus();
                return true;
            } else if (obj == ui->lineEditPassword) {
                ui->lineEditPasswordCheck->setFocus();
                return true;
            } else if (obj == ui->lineEditPasswordCheck) {
                if (currentStep == StepCredentials) {
                    on_pushButtonNext_clicked();
                    return true;
                }
            } else if (obj == ui->lineEditCode) {
                if (currentStep == StepCode) {
                    on_pushButtonCreateAccount_clicked();
                    return true;
                }
            }
        }
    }
    return QDialog::eventFilter(obj, event);
}

void RegistrationForm::showError(const QString& title, const QString& message)
{
    QMessageBox::warning(this, title, message);
}

void RegistrationForm::showInfo(const QString& title, const QString& message)
{
    QMessageBox::information(this, title, message);
}

void RegistrationForm::updateUI()
{
    // Управление фокусом без двойных курсоров
    ui->lineEditMail->clearFocus();
    ui->lineEditLogin->clearFocus();
    ui->lineEditPassword->clearFocus();
    ui->lineEditPasswordCheck->clearFocus();
    ui->lineEditCode->clearFocus();

    switch(currentStep) {
    case StepCredentials:
        ui->lineEditCode->setVisible(false);
        ui->labelCode->setVisible(false);
        ui->pushButtonCreateAccount->setVisible(false);
        ui->pushButtonNext->setVisible(true);
        ui->pushButtonNext->setText("ПОДТВЕРДИТЬ");

        // Разблокируем основные поля
        ui->lineEditMail->setEnabled(true);
        ui->lineEditLogin->setEnabled(true);
        ui->lineEditPassword->setEnabled(true);
        ui->lineEditPasswordCheck->setEnabled(true);

        // Фокус на поле email
        ui->lineEditMail->setFocus();
        break;

    case StepCode:
        ui->lineEditCode->setVisible(true);
        ui->labelCode->setVisible(true);
        ui->pushButtonCreateAccount->setVisible(true);
        ui->pushButtonNext->setText("Отправить код повторно");

        // Блокируем основные поля с белым фоном
        lockFields();

        // Фокус на поле кода
        ui->lineEditCode->setFocus();
        break;
    }
}

bool RegistrationForm::validateCredentials()
{
    QString email = ui->lineEditMail->text().trimmed();
    QString login = ui->lineEditLogin->text().trimmed();
    QString password = ui->lineEditPassword->text();
    QString passwordCheck = ui->lineEditPasswordCheck->text();

    // Проверка email
    if (email.isEmpty()) {
        showError("Ошибка ввода", "Пожалуйста, введите ваш email");
        return false;
    }

    QRegularExpression regexEmail("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,6}$");
    if (!regexEmail.match(email).hasMatch()) {
        showError("Ошибка ввода", "Введите корректный email адрес");
        return false;
    }

    // Проверка занятости email
    if (NetworkClient::instance()->emailExists(email)) {
        showError("Ошибка регистрации", "Этот email уже зарегистрирован");
        return false;
    }

    // Проверка логина
    if (login.isEmpty()) {
        showError("Ошибка ввода", "Введите ваш логин");
        return false;
    }

    if (login.length() < 3 || login.length() > 20) {
        showError("Ошибка ввода", "Логин должен быть от 3 до 20 символов");
        return false;
    }

    // Проверка занятости логина
    if (NetworkClient::instance()->checkLoginExists(login)) {
        showError("Ошибка регистрации", "Этот логин уже занят");
        return false;
    }

    // Проверка пароля
    if (password.length() < 5 || password.length() > 15) {
        showError("Ошибка ввода", "Пароль должен быть от 5 до 15 символов");
        return false;
    }

    if (password != passwordCheck) {
        showError("Ошибка ввода", "Пароли не совпадают");
        return false;
    }

    return true;
}

bool RegistrationForm::validateCode()
{
    QString enteredCode = ui->lineEditCode->text().trimmed();

    if (enteredCode.isEmpty()) {
        showError("Ошибка ввода", "Введите код из письма");
        return false;
    }

    if (enteredCode != receivedCode) {
        showError("Ошибка ввода", "Неверный код подтверждения");
        return false;
    }

    return true;
}

void RegistrationForm::on_pushButtonNext_clicked()
{
    if (currentStep == StepCredentials) {
        if (validateCredentials()) {
            QString email = ui->lineEditMail->text().trimmed();
            receivedCode = NetworkClient::instance()->requestRegisterCode(email);

            if (receivedCode.isEmpty()) {
                showError("Ошибка регистрации", "Не удалось отправить код на указанный email");
                return;
            }

            showInfo("Код отправлен", "Код подтверждения отправлен на вашу почту");
            currentStep = StepCode;
            updateUI();
        }
    } else if (currentStep == StepCode) {
        // Повторная отправка кода
        QString email = ui->lineEditMail->text().trimmed();
        receivedCode = NetworkClient::instance()->requestRegisterCode(email);

        if (receivedCode.isEmpty()) {
            showError("Ошибка", "Не удалось отправить код");
            return;
        }

        showInfo("Код отправлен повторно", "Новый код подтверждения отправлен на вашу почту");
    }
}



void RegistrationForm::on_pushButtonCreateAccount_clicked()
{
    if (!validateCode()) return;

    QString login = ui->lineEditLogin->text().trimmed();
    QString password = ui->lineEditPassword->text();
    QString email = ui->lineEditMail->text().trimmed();

    // Убрали параметр code - теперь только 3 параметра
    if (NetworkClient::instance()->registerUser(login, password, email)) {
        showInfo("Регистрация завершена", "Учётная запись успешно создана! Теперь вы можете войти в систему");
        emit switchToAuthForm();
        close();
    } else {
        showError("Ошибка регистрации", "Не удалось завершить регистрацию. Проверьте правильность данных");
    }
}

void RegistrationForm::on_pushButtonBackToAuth_clicked()
{
    emit switchToAuthForm();
    close();
}
