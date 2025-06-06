/**
 * @file authregform.h
 * @brief Заголовочный файл класса AuthRegForm, представляющего форму авторизации и регистрации.
 */

#ifndef AUTHREGFORM_H
#define AUTHREGFORM_H

#include <QDialog>
#include <QMessageBox>
#include <QRegularExpressionValidator>
#include <QLineEdit>

namespace Ui {
class AuthRegForm;
}

/**
 * @class AuthRegForm
 * @brief Класс, представляющий диалоговое окно для авторизации и регистрации пользователей.
 *
 * Этот класс предоставляет интерфейс для входа в систему, перехода к регистрации 
 * и восстановления пароля. Он также включает валидацию вводимых данных.
 */
class AuthRegForm : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса AuthRegForm.
     * @param parent Родительский виджет (по умолчанию nullptr).
     */
    explicit AuthRegForm(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса AuthRegForm.
     */
    ~AuthRegForm();

private slots:
    /**
     * @brief Обработчик нажатия кнопки авторизации.
     */
    void on_pushButtonAuth_clicked();

    /**
     * @brief Обработчик нажатия кнопки перехода к форме регистрации.
     */
    void on_pushButtonReg_clicked();

    /**
     * @brief Обработчик нажатия кнопки восстановления пароля.
     */
    void on_pushButtonForgotPassword_clicked();

private:
    Ui::AuthRegForm *ui; ///< Указатель на интерфейс формы.
    bool isRequestSent;  ///< Флаг, указывающий, был ли отправлен запрос.
    int authAttempts;    ///< Счетчик неудачных попыток авторизации.

    /**
     * @brief Отображает сообщение об ошибке.
     * @param title Заголовок окна ошибки.
     * @param message Текст сообщения об ошибке.
     */
    void showError(const QString &title, const QString &message);

    /**
     * @brief Настраивает переход между полями ввода.
     */
    void setupFieldFocus();

    /**
     * @brief Проверяет, содержит ли ввод только английские буквы и цифры.
     * @param input Строка для проверки.
     * @return true, если ввод корректен, иначе false.
     */
    bool isValidEnglishInput(const QString& input);

signals:
    /**
     * @brief Сигнал, испускаемый при успешной авторизации.
     * @param login Логин пользователя.
     */
    void auth_ok(const QString &login);

    /**
     * @brief Сигнал для перехода в главное окно.
     */
    void switchToMainWindow();

    /**
     * @brief Сигнал для перехода к форме регистрации.
     */
    void switchToRegistrationForm();

    /**
     * @brief Сигнал, испускаемый при успешном запросе восстановления пароля.
     */
    void recovery_ok();

public slots:
    /**
     * @brief Очищает все поля ввода формы.
     */
    void clear();
};

#endif // AUTHREGFORM_H