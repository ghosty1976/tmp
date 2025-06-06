#ifndef MANAGERFORMSS_H
#define MANAGERFORMSS_H

#include <QMainWindow>
#include "authregform.h"
#include "mainwindow.h"
#include "passwordrecoveryform.h"
#include "solution.h"
#include "registrationform.h"

// Класс для управления переключением между окнами приложения
class ManagerFormss : public QMainWindow
{
    Q_OBJECT

public:
    void showRegistrationForm();  // Переход на форму регистрации
    void showAuthForm();          // Переход обратно на форму авторизации
    explicit ManagerFormss(QWidget *parent = nullptr, MainWindow *mainWindow = nullptr);
    ~ManagerFormss(); // Деструктор

private:
    AuthRegForm *curr_auth;            // Указатель на форму авторизации/регистрации
    passwordrecoveryform *recovery_password; // Форма восстановления пароля
    Solution *curr_solution;           // Форма для отображения решения уравнения
    MainWindow *main_window;           // Указатель на главное окно приложения
    RegistrationForm *registrationForm; // Указатель на форму регистрации

};
#endif // MANAGERFORMSS_H
