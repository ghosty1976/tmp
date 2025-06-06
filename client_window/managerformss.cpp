#include "managerformss.h"
#include "authregform.h"
#include "mainwindow.h"
#include "passwordrecoveryform.h"
#include "solution.h"
#include "registrationform.h" // Подключаем форму регистрации

ManagerFormss::ManagerFormss(QWidget *parent, MainWindow *mainWindow)
    : QMainWindow(parent), main_window(mainWindow) // Инициализация главного окна
{
    // Инициализация форм:
    this->curr_auth = new AuthRegForm();     // Создание формы авторизации
    this->curr_auth->show();                 // Показ формы авторизации при старте
    this->recovery_password = new passwordrecoveryform(); // Форма восстановления пароля
    this->curr_solution = new Solution();    // Форма для вывода решения
    this->registrationForm = new RegistrationForm(); // Форма для регистрации

    // Соединение сигналов и слотов:
    // 1. При успешной авторизации показать главное окно
    connect(curr_auth, &AuthRegForm::auth_ok, main_window, &MainWindow::slot_show);

    // 2. При запросе восстановления пароля показать соответствующую форму
    connect(curr_auth, &AuthRegForm::recovery_ok, recovery_password, &passwordrecoveryform::slot_show);

    // 3. При завершении расчета показать окно с решением
    connect(main_window, &MainWindow::solution_ok, curr_solution, &Solution::slot_show);

    // 4. При переходе на форму регистрации
    connect(curr_auth, &AuthRegForm::switchToRegistrationForm, this, &ManagerFormss::showRegistrationForm);
    connect(registrationForm, &RegistrationForm::switchToAuthForm, this, &ManagerFormss::showAuthForm);
}

// Деструктор (очистка ресурсов)
ManagerFormss::~ManagerFormss()
{
    // Используем deleteLater, чтобы гарантировать корректное удаление объектов
    curr_auth->deleteLater(); // Удаление формы авторизации
    recovery_password->deleteLater(); // Удаление формы восстановления пароля
    curr_solution->deleteLater(); // Удаление формы с решением
    registrationForm->deleteLater(); // Удаление формы регистрации
}

void ManagerFormss::showRegistrationForm() {
    if (registrationForm) {
        this->registrationForm->show();   // Показываем форму регистрации
        this->curr_auth->hide();          // Скрываем форму авторизации
    }
}

void ManagerFormss::showAuthForm() {
    if (curr_auth) {
        this->curr_auth->show();          // Показываем форму авторизации
        this->registrationForm->hide();   // Скрываем форму регистрации
    }
}
