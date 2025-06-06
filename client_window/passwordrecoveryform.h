#ifndef PASSWORDRECOVERYFORM_H
#define PASSWORDRECOVERYFORM_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class passwordrecoveryform;  // Имя класса с маленькой буквы
}

class passwordrecoveryform : public QDialog
{
    Q_OBJECT

public:
    explicit passwordrecoveryform(QWidget *parent = nullptr);
    ~passwordrecoveryform();

public slots:
    void slot_show();  // Сделаем слот публичным

private slots:
    void on_pushButtonNext_clicked();    // Переход между шагами восстановления пароля
    void on_pushButtonSave_clicked();    // Сохранение нового пароля

private:
    Ui::passwordrecoveryform *ui; // Используем имя класса с маленькой буквы
    void showError(const QString& title, const QString& message); // Показ ошибки с конкретным названием окна
    void setupFieldFocus();  // Настройка перехода через поля
    void sendCode(); // Отправка кода на почту
    bool checkPasswordMatch(); // Проверка совпадения пароля
    void recoverPassword(); // Завершение восстановления пароля
    bool isEnglishInput(const QString &input); // Проверка на английские буквы и цифры
    bool isValidLogin(const QString &login); // Проверка на корректность логина
    bool isCodeValid;  // Переменная для хранения статуса кода
};

#endif // PASSWORDRECOVERYFORM_H
