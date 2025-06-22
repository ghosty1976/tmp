#include "managerformss.h"
#include "authregform.h"
#include "mainwindow.h"
#include "passwordrecoveryform.h"
#include "registrationform.h"

ManagerFormss::ManagerFormss(QWidget *parent, MainWindow *mainWindow)
    : QMainWindow(parent),
    main_window(mainWindow)
{
    // 1) Форма авторизации
    this->curr_auth = new AuthRegForm();
    this->curr_auth->show();

    // 2) Форма восстановления пароля
    this->recovery_password = new passwordrecoveryform();

    // 3) Главное окно (ввод уравнения)
    this->curr_solution = new Solution();

    // 4) Форма регистрации
    this->registrationForm = new RegistrationForm();

    // 1.1. При успешной авторизации показываем MainWindow
    connect(curr_auth, &AuthRegForm::auth_ok,
            main_window, &MainWindow::slot_show);

    // 2.1. При запросе «Забыли пароль?» передаем логин в форму восстановления
    connect(curr_auth, &AuthRegForm::openRecoveryForm,
            this, [this](const QString& login) {
                recovery_password->setLogin(login); // Устанавливаем логин
                recovery_password->slot_show();     // Показываем форму
            });

    // 3.1. При успешном восстановлении пароля вернёмся в AuthForm
    connect(recovery_password, &passwordrecoveryform::switchToAuthForm,
            this, [this]() {
                curr_auth->show();                 // Показываем форму авторизации
                recovery_password->hide();          // Скрываем форму восстановления
            });

    // 4.1. При переходе из AuthForm в RegistrationForm
    connect(curr_auth, &AuthRegForm::switchToRegistrationForm,
            this, &ManagerFormss::showRegistrationForm);

    // 4.2. Когда нажали «Назад к авторизации» в RegistrationForm
    connect(registrationForm, &RegistrationForm::switchToAuthForm,
            this, &ManagerFormss::showAuthForm);

    // 5.1. При получении решения показываем окно Solution
    connect(main_window, &MainWindow::solution_ok,
            curr_solution, [this](const QString &html) {
                curr_solution->setSolution(html);
                curr_solution->show();
            });
}

ManagerFormss::~ManagerFormss()
{
    curr_auth->deleteLater();
    recovery_password->deleteLater();
    curr_solution->deleteLater();
    registrationForm->deleteLater();
}

void ManagerFormss::showRegistrationForm()
{
    registrationForm->slot_show();
    curr_auth->hide();
}

void ManagerFormss::showAuthForm()
{
    curr_auth->show();
    registrationForm->hide();
}
