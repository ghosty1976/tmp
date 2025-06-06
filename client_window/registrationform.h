/**
 * @file registrationform.h
 * @brief Заголовочный файл класса RegistrationForm для регистрации новых пользователей.
 *
 * Класс предоставляет интерфейс для многоэтапной регистрации пользователей,
 * включая проверку вводимых данных и подтверждение email.
 */

#ifndef REGISTRATIONFORM_H
#define REGISTRATIONFORM_H

#include <QDialog>
#include <QMessageBox>
#include <QRegularExpressionValidator>
#include <QLineEdit>

namespace Ui {
class RegistrationForm; ///< Форма регистрации пользователя
}

/**
 * @class RegistrationForm
 * @brief Класс формы регистрации новых пользователей.
 *
 * Реализует процесс регистрации с проверкой данных, подтверждением email
 * и созданием учетной записи пользователя.
 */
class RegistrationForm : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса RegistrationForm.
     * @param parent Родительский виджет (по умолчанию nullptr).
     */
    explicit RegistrationForm(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса RegistrationForm.
     */
    ~RegistrationForm();

private slots:
    /**
     * @brief Обработчик нажатия кнопки "Далее" для перехода между шагами регистрации.
     */
    void on_pushButtonNext_clicked();

    /**
     * @brief Обработчик нажатия кнопки "Создать аккаунт" для завершения регистрации.
     */
    void on_pushButtonCreateAccount_clicked();

    /**
     * @brief Обработчик нажатия кнопки "Назад" для возврата к форме авторизации.
     */
    void on_pushButtonBackToAuth_clicked();

private:
    Ui::RegistrationForm *ui; ///< Указатель на интерфейс формы.

    /**
     * @brief Отображает сообщение об ошибке.
     * @param title Заголовок окна ошибки.
     * @param message Текст сообщения об ошибке.
     */
    void showError(const QString& title, const QString& message);

    /**
     * @brief Настраивает переход между полями ввода.
     */
    void setupFieldFocus();

    /**
     * @brief Отправляет код подтверждения на email пользователя.
     */
    void sendCode();

    /**
     * @brief Проверяет совпадение введенных паролей.
     * @return true, если пароли совпадают, иначе false.
     */
    bool checkPasswordMatch();

    /**
     * @brief Проверяет корректность формата email.
     * @param email Email для проверки.
     * @return true, если email корректен, иначе false.
     */
    bool isValidEmail(const QString& email);

    /**
     * @brief Проверяет, содержит ли ввод только английские буквы и цифры.
     * @param input Строка для проверки.
     * @return true, если ввод корректен, иначе false.
     */
    bool isEnglishAndDigitInput(const QString &input);

    /**
     * @brief Проверяет допустимость длины логина.
     * @param login Логин для проверки.
     * @return true, если длина логина допустима, иначе false.
     */
    bool isValidLogin(const QString &login);

    /**
     * @brief Проверяет код подтверждения на сервере.
     * @param code Код для проверки.
     * @return true, если код верен, иначе false.
     */
    bool verifyCode(const QString& code);

    /**
     * @brief Проверяет доступность логина.
     * @param login Логин для проверки.
     * @return true, если логин доступен, иначе false.
     */
    bool isLoginAvailable(const QString& login);

signals:
    /**
     * @brief Сигнал для перехода к форме авторизации.
     */
    void switchToAuthForm();
};

#endif // REGISTRATIONFORM_H