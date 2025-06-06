#ifndef REGISTRATIONFORM_H
#define REGISTRATIONFORM_H

#include <QDialog>
#include <QMessageBox>
#include <QRegularExpressionValidator>
#include <QLineEdit>

namespace Ui {
class RegistrationForm;
}

class RegistrationForm : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationForm(QWidget *parent = nullptr);
    ~RegistrationForm();

private slots:
    void on_pushButtonNext_clicked();    // Переход между шагами регистрации
    void on_pushButtonCreateAccount_clicked(); // Создание учетной записи
    void on_pushButtonBackToAuth_clicked(); // Переход на форму авторизации

private:
    Ui::RegistrationForm *ui; // Указатель на интерфейс формы
    void showError(const QString& title, const QString& message); // Показ ошибки
    void setupFieldFocus();  // Настройка перехода между полями
    void sendCode(); // Отправка кода на почту
    bool checkPasswordMatch(); // Проверка совпадения пароля
    bool isValidEmail(const QString& email); // Проверка на корректность почты
    bool isEnglishAndDigitInput(const QString &input); // Проверка на английские буквы и цифры
    bool isValidLogin(const QString &login); // Проверка на допустимую длину логина
    bool verifyCode(const QString& code); // Проверка кода на сервере
    bool isLoginAvailable(const QString& login); // Проверка доступности логина

signals:
    void switchToAuthForm();  // Сигнал для перехода обратно на форму авторизации
};

#endif // REGISTRATIONFORM_H
