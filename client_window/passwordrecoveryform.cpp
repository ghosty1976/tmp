#include "passwordrecoveryform.h"
#include "ui_passwordrecoveryform.h"
#include "networkclient.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QPalette>
#include <QKeyEvent>

passwordrecoveryform::passwordrecoveryform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::passwordrecoveryform),
    currentStep(StepCredentials)
{
    ui->setupUi(this);
    setWindowTitle("Восстановление пароля");

    // Валидатор для логина и пароля: только английские буквы и цифры
    QRegularExpression regexAlnum("^[a-zA-Z0-9]+$");
    ui->lineEditLogin->setValidator(new QRegularExpressionValidator(regexAlnum, this));
    ui->lineEditPassword->setValidator(new QRegularExpressionValidator(regexAlnum, this));
    ui->lineEditPasswordCheck->setValidator(new QRegularExpressionValidator(regexAlnum, this));

    // Валидатор для кода: 6 цифр
    ui->lineEditCode->setValidator(new QRegularExpressionValidator(QRegularExpression("^[0-9]{6}$"), this));

    // Скрытый ввод пароля (точки)
    ui->lineEditPassword->setEchoMode(QLineEdit::Password);
    ui->lineEditPasswordCheck->setEchoMode(QLineEdit::Password);

    // Переименовываем кнопки
    ui->pushButtonConfirm->setText("ПОДТВЕРДИТЬ");
    ui->pushButtonRecover->setText("ВОССТАНОВИТЬ");

    // Начальная настройка UI
    updateUI();

    // Placeholder'ы
    ui->lineEditLogin->setPlaceholderText("...");
    ui->lineEditPassword->setPlaceholderText("...");
    ui->lineEditPasswordCheck->setPlaceholderText("...");
    ui->lineEditCode->setPlaceholderText("...");

    // Настройка навигации по Enter
    ui->lineEditLogin->installEventFilter(this);
    ui->lineEditPassword->installEventFilter(this);
    ui->lineEditPasswordCheck->installEventFilter(this);
    ui->lineEditCode->installEventFilter(this);
}

passwordrecoveryform::~passwordrecoveryform()
{
    delete ui;
}

bool passwordrecoveryform::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter) {
            if (obj == ui->lineEditLogin) {
                ui->lineEditPassword->setFocus();
                return true;
            } else if (obj == ui->lineEditPassword) {
                ui->lineEditPasswordCheck->setFocus();
                return true;
            } else if (obj == ui->lineEditPasswordCheck) {
                if (ui->pushButtonConfirm->isVisible()) {
                    on_pushButtonConfirm_clicked();
                    return true;
                }
            } else if (obj == ui->lineEditCode) {
                if (ui->pushButtonRecover->isVisible()) {
                    on_pushButtonRecover_clicked();
                    return true;
                }
            }
        }
    }
    return QDialog::eventFilter(obj, event);
}

void passwordrecoveryform::setLogin(const QString& login) {
    ui->lineEditLogin->setText(login);
}

void passwordrecoveryform::showError(const QString &title, const QString &message) {
    QMessageBox::warning(this, title, message);
}

void passwordrecoveryform::showInfo(const QString &title, const QString &message) {
    QMessageBox::information(this, title, message);
}

void passwordrecoveryform::lockFields() {
    // Блокируем поля ввода
    ui->lineEditLogin->setReadOnly(true);
    ui->lineEditPassword->setReadOnly(true);
    ui->lineEditPasswordCheck->setReadOnly(true);

    // Устанавливаем белый цвет фона
    QPalette palette;
    palette.setColor(QPalette::Base, Qt::white);
    ui->lineEditLogin->setPalette(palette);
    ui->lineEditPassword->setPalette(palette);
    ui->lineEditPasswordCheck->setPalette(palette);
}

void passwordrecoveryform::updateUI() {
    switch(currentStep) {
    case StepCredentials:
        // Шаг 1: Все поля видимы
        ui->labelCode->setVisible(false);
        ui->lineEditCode->setVisible(false);
        ui->pushButtonRecover->setVisible(false);

        ui->labelPassword->setVisible(true);
        ui->lineEditPassword->setVisible(true);
        ui->labelPasswordCheck->setVisible(true);
        ui->lineEditPasswordCheck->setVisible(true);
        ui->pushButtonConfirm->setVisible(true);

        // Разблокируем все поля
        ui->lineEditLogin->setReadOnly(false);
        ui->lineEditPassword->setReadOnly(false);
        ui->lineEditPasswordCheck->setReadOnly(false);

        // Восстанавливаем стандартный цвет
        ui->lineEditLogin->setPalette(QPalette());
        ui->lineEditPassword->setPalette(QPalette());
        ui->lineEditPasswordCheck->setPalette(QPalette());

        // Скрытый ввод пароля (точки)
        ui->lineEditPassword->setEchoMode(QLineEdit::Password);
        ui->lineEditPasswordCheck->setEchoMode(QLineEdit::Password);

        // Снимаем фокус со всех полей
        ui->lineEditLogin->clearFocus();
        ui->lineEditPassword->clearFocus();
        ui->lineEditPasswordCheck->clearFocus();
        ui->lineEditCode->clearFocus();

        // Фокус только на поле логина
        ui->lineEditLogin->setFocus();
        break;

    case StepCode:
        // Шаг 2: Все поля остаются видимыми
        ui->labelPassword->setVisible(true);
        ui->lineEditPassword->setVisible(true);
        ui->labelPasswordCheck->setVisible(true);
        ui->lineEditPasswordCheck->setVisible(true);
        ui->labelCode->setVisible(true);
        ui->lineEditCode->setVisible(true);
        ui->pushButtonConfirm->setVisible(false);
        ui->pushButtonRecover->setVisible(true);

        // Блокируем основные поля с белым фоном
        lockFields();

        // Снимаем фокус со всех полей
        ui->lineEditLogin->clearFocus();
        ui->lineEditPassword->clearFocus();
        ui->lineEditPasswordCheck->clearFocus();
        ui->lineEditCode->clearFocus();

        // Фокус только на поле кода
        ui->lineEditCode->setFocus();
        break;
    }
}

bool passwordrecoveryform::validateCredentials() {
    QString login = ui->lineEditLogin->text().trimmed();
    QString password = ui->lineEditPassword->text();
    QString passwordCheck = ui->lineEditPasswordCheck->text();

    if (login.isEmpty()) {
        showError("Ошибка ввода", "Пожалуйста, введите ваш логин");
        ui->lineEditLogin->setFocus();
        return false;
    }

    // Проверка длины логина (3-20 символов)
    if (login.length() < 3 || login.length() > 20) {
        showError("Ошибка ввода", "Логин должен быть от 3 до 20 символов");
        ui->lineEditLogin->setFocus();
        return false;
    }

    // Проверка длины пароля (5-15 символов)
    if (password.length() < 5 || password.length() > 15) {
        showError("Ошибка ввода", "Пароль должен быть от 5 до 15 символов");
        ui->lineEditPassword->setFocus();
        return false;
    }

    if (password != passwordCheck) {
        showError("Ошибка ввода", "Пароли не совпадают. Пожалуйста, убедитесь, что введенные пароли идентичны");
        ui->lineEditPasswordCheck->setFocus();
        return false;
    }

    return true;
}

void passwordrecoveryform::on_pushButtonConfirm_clicked() {
    if (!validateCredentials()) return;

    currentLogin = ui->lineEditLogin->text().trimmed();

    // Запрашиваем код восстановления
    receivedCode = NetworkClient::instance()->requestRecoveryCode(currentLogin);

    if (receivedCode.isEmpty()) {
        showError("Ошибка отправки", "Не удалось отправить код восстановления. Проверьте правильность логина и повторите попытку");
        return;
    }

    // Переходим к шагу ввода кода
    currentStep = StepCode;
    updateUI();
    showInfo("Код отправлен", "Код восстановления был отправлен на вашу электронную почту. Пожалуйста, проверьте почтовый ящик.");
}

void passwordrecoveryform::on_pushButtonRecover_clicked() {
    QString enteredCode = ui->lineEditCode->text().trimmed();

    if (enteredCode.isEmpty()) {
        showError("Ошибка ввода", "Пожалуйста, введите код подтверждения, который вы получили по электронной почте");
        ui->lineEditCode->setFocus();
        return;
    }

    if (enteredCode != receivedCode) {
        showError("Ошибка проверки", "Введённый код не совпадает с отправленным. Пожалуйста, проверьте код и попробуйте снова");
        ui->lineEditCode->setFocus();
        ui->lineEditCode->selectAll();
        return;
    }

    QString password = ui->lineEditPassword->text();

    if (NetworkClient::instance()->changePassword(currentLogin, password)) {
        showInfo("Пароль изменен", "Ваш пароль был успешно изменён! Теперь вы можете войти в систему, используя новый пароль");
        emit switchToAuthForm();
        close();
    } else {
        showError("Ошибка восстановления", "Не удалось изменить пароль. Пожалуйста, повторите попытку позже");
    }
}

void passwordrecoveryform::slot_show() {
    currentStep = StepCredentials;

    // Очищаем поля
    ui->lineEditPassword->clear();
    ui->lineEditPasswordCheck->clear();
    ui->lineEditCode->clear();

    // Разблокируем все поля
    ui->lineEditLogin->setReadOnly(false);
    ui->lineEditPassword->setReadOnly(false);
    ui->lineEditPasswordCheck->setReadOnly(false);

    // Восстанавливаем стандартный цвет
    ui->lineEditLogin->setPalette(QPalette());
    ui->lineEditPassword->setPalette(QPalette());
    ui->lineEditPasswordCheck->setPalette(QPalette());

    // Восстанавливаем скрытый ввод пароля (точки)
    ui->lineEditPassword->setEchoMode(QLineEdit::Password);
    ui->lineEditPasswordCheck->setEchoMode(QLineEdit::Password);

    updateUI();
    show();
}
