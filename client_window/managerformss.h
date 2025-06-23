#ifndef MANAGERFORMSS_H
#define MANAGERFORMSS_H

#include <QMainWindow>
#include "authregform.h"
#include "mainwindow.h"
#include "passwordrecoveryform.h"
#include "solution.h"
#include "registrationform.h"

/**
 * @brief Класс для управления переключением между окнами приложения
 * 
 * Обеспечивает централизованное управление всеми формами приложения,
 * включая навигацию между окнами авторизации, регистрации,
 * восстановления пароля и основным интерфейсом.
 */
class ManagerFormss : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Переключение на форму регистрации
     */
    void showRegistrationForm();  // Переход на форму регистрации
    
    /**
     * @brief Переключение на форму авторизации
     */
    void showAuthForm();          // Переход обратно на форму авторизации
    
    /**
     * @brief Конструктор менеджера форм
     * @param parent Родительский виджет
     * @param mainWindow Указатель на главное окно приложения
     */
    explicit ManagerFormss(QWidget *parent = nullptr, MainWindow *mainWindow = nullptr);
    
    /**
     * @brief Деструктор менеджера форм
     */
    ~ManagerFormss(); // Деструктор

private:
    AuthRegForm *curr_auth;            ///< Указатель на форму авторизации/регистрации
    passwordrecoveryform *recovery_password; ///< Форма восстановления пароля
    Solution *curr_solution;           ///< Форма для отображения решения уравнения
    MainWindow *main_window;           ///< Указатель на главное окно приложения
    RegistrationForm *registrationForm; ///< Указатель на форму регистрации
};

#endif // MANAGERFORMSS_H