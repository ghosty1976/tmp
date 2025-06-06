/**
 * @file passwordrecoveryform.h
 * @brief Заголовочный файл класса passwordrecoveryform для восстановления пароля пользователя.
 *
 * Класс предоставляет интерфейс для поэтапного восстановления пароля,
 * включая проверку кода подтверждения и установку нового пароля.
 */

#ifndef PASSWORDRECOVERYFORM_H
#define PASSWORDRECOVERYFORM_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class passwordrecoveryform; ///< Форма восстановления пароля (имя класса с маленькой буквы)
}

/**
 * @class passwordrecoveryform
 * @brief Класс формы восстановления пароля пользователя.
 *
 * Реализует процесс восстановления пароля через email с проверкой кода подтверждения
 * и установкой нового пароля.
 */
class passwordrecoveryform : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса passwordrecoveryform.
     * @param parent Родительский виджет (по умолчанию nullptr).
     */
    explicit passwordrecoveryform(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса passwordrecoveryform.
     */
    ~passwordrecoveryform();

public slots:
    /**
     * @brief Слот для отображения формы.
     */
    void slot_show();

private slots:
    /**
     * @brief Обработчик нажатия кнопки "Далее" для перехода между шагами восстановления.
     */
    void on_pushButtonNext_clicked();

    /**
     * @brief Обработчик нажатия кнопки "Сохранить" для установки нового пароля.
     */
    void on_pushButtonSave_clicked();

private:
    Ui::passwordrecoveryform *ui; ///< Указатель на интерфейс формы.
    bool isCodeValid; ///< Флаг валидности введенного кода подтверждения.

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
     * @brief Завершает процесс восстановления пароля.
     */
    void recoverPassword();

    /**
     * @brief Проверяет, содержит ли ввод только английские буквы и цифры.
     * @param input Строка для проверки.
     * @return true, если ввод корректен, иначе false.
     */
    bool isEnglishInput(const QString &input);

    /**
     * @brief Проверяет корректность логина пользователя.
     * @param login Логин для проверки.
     * @return true, если логин корректен, иначе false.
     */
    bool isValidLogin(const QString &login);
};

#endif // PASSWORDRECOVERYFORM_H