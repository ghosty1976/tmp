#ifndef AUTHREGFORM_H
#define AUTHREGFORM_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class AuthRegForm;
}

/**
 * @brief Форма авторизации и регистрации пользователя
 * 
 * Предоставляет интерфейс для входа в систему, регистрации новых пользователей
 * и восстановления пароля. Включает валидацию вводимых данных.
 */
class AuthRegForm : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор формы авторизации/регистрации
     * @param parent Родительский виджет
     */
    explicit AuthRegForm(QWidget *parent = nullptr);
    
    /**
     * @brief Деструктор формы
     */
    ~AuthRegForm();

private slots:
    /**
     * @brief Слот обработки нажатия кнопки авторизации
     */
    void on_pushButtonAuth_clicked();  // Обработка авторизации
    
    /**
     * @brief Слот обработки нажатия кнопки регистрации
     */
    void on_pushButtonReg_clicked();   // Переход на форму регистрации
    
    /**
     * @brief Слот обработки нажатия кнопки восстановления пароля
     */
    void on_pushButtonForgotPassword_clicked();  // Восстановление пароля

private:
    Ui::AuthRegForm *ui;  ///< Указатель на сгенерированный интерфейс формы
    
    /**
     * @brief Показать сообщение об ошибке
     * @param title Заголовок окна ошибки
     * @param message Текст сообщения об ошибке
     */
    void showError(const QString &title, const QString &message);  // Показать ошибку с соответствующим названием окна
    
    /**
     * @brief Настроить переход между полями ввода по Tab/Enter
     */
    void setupFieldFocus();  // Настройка перехода между полями
    
    /**
     * @brief Проверить ввод на допустимые символы (англ. буквы и цифры)
     * @param input Входная строка для проверки
     * @return true если ввод корректен, false если есть недопустимые символы
     */
    bool isValidEnglishInput(const QString& input);  // Проверка ввода на английские буквы и цифры
    
    bool isRequestSent = false;  ///< Флаг отправки запроса на сервер
    int authAttempts;            ///< Счетчик неудачных попыток авторизации
    
    /**
     * @brief Фильтр событий для обработки специальных клавиш
     * @param obj Объект, вызвавший событие
     * @param event Событие
     * @return true если событие обработано, false иначе
     */
    bool eventFilter(QObject *obj, QEvent *event) override;

signals:
    /**
     * @brief Сигнал успешной авторизации
     * @param login Логин авторизованного пользователя
     */
    void auth_ok(const QString &login);  // Успешная авторизация
    
    /**
     * @brief Сигнал перехода в главное окно приложения
     */
    void switchToMainWindow();  // Переход в главное окно
    
    /**
     * @brief Сигнал перехода на форму регистрации
     */
    void switchToRegistrationForm();  // Переход на форму регистрации
    
    /**
     * @brief Сигнал успешного начала восстановления пароля
     */
    void recovery_ok();  // Открытие формы восстановления пароля
    
    /**
     * @brief Сигнал открытия формы восстановления пароля
     * @param login Логин для восстановления
     */
    void openRecoveryForm(const QString &login);

public slots:
    /**
     * @brief Слот для очистки всех полей формы
     */
    void clear();  // Очистка всех полей
};

#endif // AUTHREGFORM_H