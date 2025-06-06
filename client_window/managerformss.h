/**
 * @file managerformss.h
 * @brief Заголовочный файл класса ManagerFormss для управления переключением между окнами приложения.
 *
 * Этот класс предоставляет функционал для управления переходами между различными формами приложения,
 * включая авторизацию, регистрацию, восстановление пароля и отображение решений.
 */

#ifndef MANAGERFORMSS_H
#define MANAGERFORMSS_H

#include <QMainWindow>
#include "authregform.h"
#include "mainwindow.h"
#include "passwordrecoveryform.h"
#include "solution.h"
#include "registrationform.h"

/**
 * @class ManagerFormss
 * @brief Класс для управления переключением между окнами приложения.
 *
 * Класс ManagerFormss координирует переходы между различными формами приложения,
 * обеспечивая корректное отображение и взаимодействие пользователя с интерфейсом.
 */
class ManagerFormss : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса ManagerFormss.
     * @param parent Родительский виджет (по умолчанию nullptr).
     * @param mainWindow Указатель на главное окно приложения (по умолчанию nullptr).
     */
    explicit ManagerFormss(QWidget *parent = nullptr, MainWindow *mainWindow = nullptr);

    /**
     * @brief Деструктор класса ManagerFormss.
     */
    ~ManagerFormss();

    /**
     * @brief Переключает на форму регистрации.
     */
    void showRegistrationForm();

    /**
     * @brief Переключает обратно на форму авторизации.
     */
    void showAuthForm();

private:
    AuthRegForm *curr_auth;            ///< Указатель на форму авторизации/регистрации.
    passwordrecoveryform *recovery_password; ///< Указатель на форму восстановления пароля.
    Solution *curr_solution;           ///< Указатель на форму для отображения решения уравнения.
    MainWindow *main_window;           ///< Указатель на главное окно приложения.
    RegistrationForm *registrationForm; ///< Указатель на форму регистрации.
};

#endif // MANAGERFORMSS_H