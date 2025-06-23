#ifndef PASSWORDRECOVERYFORM_H
#define PASSWORDRECOVERYFORM_H

#include <QDialog>
#include <QKeyEvent>
#include <QMessageBox>

namespace Ui {
class passwordrecoveryform;
}

/**
 * @brief Форма восстановления пароля
 * 
 * Предоставляет интерфейс для восстановления пароля пользователя
 * через двухэтапную процедуру: запрос кода подтверждения
 * и ввод нового пароля.
 */
class passwordrecoveryform : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор формы восстановления пароля
     * @param parent Родительский виджет
     */
    explicit passwordrecoveryform(QWidget *parent = nullptr);
    
    /**
     * @brief Деструктор формы
     */
    ~passwordrecoveryform();

    /**
     * @brief Обработчик событий для навигации по Enter
     * @param obj Объект, вызвавший событие
     * @param event Событие
     * @return true если событие обработано, false иначе
     */
    bool eventFilter(QObject *obj, QEvent *event) override;

public slots:
    /**
     * @brief Слот для отображения формы
     */
    void slot_show();
    
    /**
     * @brief Установка логина для восстановления
     * @param login Логин пользователя
     */
    void setLogin(const QString& login);

signals:
    /**
     * @brief Сигнал перехода на форму авторизации
     */
    void switchToAuthForm();

private slots:
    /**
     * @brief Слот обработки подтверждения кода восстановления
     */
    void on_pushButtonConfirm_clicked();
    
    /**
     * @brief Слот обработки запроса восстановления пароля
     */
    void on_pushButtonRecover_clicked();

private:
    Ui::passwordrecoveryform *ui; ///< Указатель на графический интерфейс формы
    QString currentLogin;         ///< Текущий логин для восстановления
    QString receivedCode;         ///< Полученный код подтверждения

    /**
     * @brief Этапы процесса восстановления пароля
     */
    enum Step {
        StepCredentials, ///< Этап ввода учетных данных
        StepCode        ///< Этап ввода кода подтверждения
    };
    
    Step currentStep = StepCredentials; ///< Текущий этап восстановления

    /**
     * @brief Показать сообщение об ошибке
     * @param title Заголовок сообщения
     * @param message Текст сообщения
     */
    void showError(const QString &title, const QString &message);
    
    /**
     * @brief Показать информационное сообщение
     * @param title Заголовок сообщения
     * @param message Текст сообщения
     */
    void showInfo(const QString &title, const QString &message);
    
    /**
     * @brief Обновить интерфейс формы в соответствии с текущим этапом
     */
    void updateUI();
    
    /**
     * @brief Проверить введенные учетные данные
     * @return true если данные валидны, false если есть ошибки
     */
    bool validateCredentials();
    
    /**
     * @brief Заблокировать поля ввода после успешного запроса
     */
    void lockFields();
};

#endif // PASSWORDRECOVERYFORM_H