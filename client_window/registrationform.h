#ifndef REGISTRATIONFORM_H
#define REGISTRATIONFORM_H

#include <QDialog>
#include <QKeyEvent>
#include <QMessageBox>

namespace Ui {
class RegistrationForm;
}

/**
 * @brief Форма регистрации нового пользователя
 * 
 * Предоставляет двухэтапный процесс регистрации: ввод учетных данных
 * и подтверждение через код, отправленный на email.
 */
class RegistrationForm : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор формы регистрации
     * @param parent Родительский виджет
     */
    explicit RegistrationForm(QWidget *parent = nullptr);
    
    /**
     * @brief Деструктор формы регистрации
     */
    ~RegistrationForm();

    /**
     * @brief Слот для отображения и сброса формы
     */
    void slot_show();

signals:
    /**
     * @brief Сигнал перехода на форму авторизации
     */
    void switchToAuthForm();

private slots:
    /**
     * @brief Слот обработки перехода к следующему шагу регистрации
     */
    void on_pushButtonNext_clicked();
    
    /**
     * @brief Слот обработки создания аккаунта
     */
    void on_pushButtonCreateAccount_clicked();
    
    /**
     * @brief Слот обработки возврата к форме авторизации
     */
    void on_pushButtonBackToAuth_clicked();

private:
    Ui::RegistrationForm *ui; ///< Указатель на графический интерфейс формы
    QString receivedCode;     ///< Полученный код подтверждения
    QString currentEmail;     ///< Email, используемый для регистрации

    /**
     * @brief Этапы процесса регистрации
     */
    enum Step {
        StepCredentials, ///< Этап ввода учетных данных
        StepCode        ///< Этап ввода кода подтверждения
    };
    
    Step currentStep = StepCredentials; ///< Текущий этап регистрации

    /**
     * @brief Показать сообщение об ошибке
     * @param title Заголовок сообщения
     * @param message Текст сообщения
     */
    void showError(const QString& title, const QString& message);
    
    /**
     * @brief Показать информационное сообщение
     * @param title Заголовок сообщения
     * @param message Текст сообщения
     */
    void showInfo(const QString& title, const QString& message);
    
    /**
     * @brief Обновить интерфейс в соответствии с текущим этапом
     */
    void updateUI();
    
    /**
     * @brief Проверить валидность введенных учетных данных
     * @return true если данные валидны, false если есть ошибки
     */
    bool validateCredentials();
    
    /**
     * @brief Проверить валидность введенного кода подтверждения
     * @return true если код верен, false если есть ошибки
     */
    bool validateCode();
    
    /**
     * @brief Заблокировать поля ввода после успешного запроса
     */
    void lockFields();
    
    /**
     * @brief Обработчик событий для навигации по Enter
     * @param obj Объект, вызвавший событие
     * @param event Событие
     * @return true если событие обработано, false иначе
     */
    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // REGISTRATIONFORM_H