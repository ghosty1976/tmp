#ifndef REGISTRATIONFORM_H
#define REGISTRATIONFORM_H

#include <QDialog>
#include <QKeyEvent>
#include <QMessageBox>
namespace Ui {
class RegistrationForm;
}

class RegistrationForm : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationForm(QWidget *parent = nullptr);
    ~RegistrationForm();

    // Добавленный слот для сброса формы
    void slot_show();

signals:
    void switchToAuthForm();

private slots:
    void on_pushButtonNext_clicked();
    void on_pushButtonCreateAccount_clicked();
    void on_pushButtonBackToAuth_clicked();

private:
    Ui::RegistrationForm *ui;
    QString receivedCode;
    QString currentEmail;

    enum Step {
        StepCredentials,
        StepCode
    };
    Step currentStep = StepCredentials;

    void showError(const QString& title, const QString& message);
    void showInfo(const QString& title, const QString& message);
    void updateUI();
    bool validateCredentials();
    bool validateCode();
    void lockFields();  // Добавлено для блокировки полей
    bool eventFilter(QObject *obj, QEvent *event) override;  // Добавлено для навигации по Enter
};

#endif // REGISTRATIONFORM_H
