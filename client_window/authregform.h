#ifndef AUTHREGFORM_H
#define AUTHREGFORM_H

#include <QDialog>
#include <QMessageBox>
#include <QRegularExpressionValidator>
#include <QLineEdit>

namespace Ui {
class AuthRegForm;
}

class AuthRegForm : public QDialog
{
    Q_OBJECT

public:
    explicit AuthRegForm(QWidget *parent = nullptr);
    ~AuthRegForm();

private slots:
    void on_pushButtonAuth_clicked();  // Обработка авторизации
    void on_pushButtonReg_clicked();   // Переход на форму регистрации
    void on_pushButtonForgotPassword_clicked();  // Восстановление пароля

private:
    Ui::AuthRegForm *ui;  // Указатель на интерфейс формы
    void showError(const QString &title, const QString &message);  // Показать ошибку с соответствующим названием окна
    void setupFieldFocus();  // Настройка перехода между полями
    bool isValidEnglishInput(const QString& input);  // Проверка ввода на английские буквы и цифры
    bool isRequestSent = false;
    int authAttempts;  // Количество неудачных попыток авторизации

signals:
    void auth_ok(const QString &login);  // Успешная авторизация
    void switchToMainWindow();  // Переход в главное окно
    void switchToRegistrationForm();  // Переход на форму регистрации
    void recovery_ok();  // Открытие формы восстановления пароля

public slots:
    void clear();  // Очистка всех полей
};

#endif // AUTHREGFORM_H
