#ifndef PASSWORDRECOVERYFORM_H
#define PASSWORDRECOVERYFORM_H

#include <QDialog>
#include <QKeyEvent>
#include <QMessageBox>
namespace Ui {
class passwordrecoveryform;
}

class passwordrecoveryform : public QDialog
{
    Q_OBJECT

public:
    explicit passwordrecoveryform(QWidget *parent = nullptr);
    ~passwordrecoveryform();

    // Обработчик событий для навигации по Enter
    bool eventFilter(QObject *obj, QEvent *event) override;

public slots:
    void slot_show();
    void setLogin(const QString& login);

signals:
    void switchToAuthForm();

private slots:
    void on_pushButtonConfirm_clicked();
    void on_pushButtonRecover_clicked();

private:
    Ui::passwordrecoveryform *ui;
    QString currentLogin;
    QString receivedCode;

    enum Step {
        StepCredentials,
        StepCode
    };
    Step currentStep = StepCredentials;

    void showError(const QString &title, const QString &message);
    void showInfo(const QString &title, const QString &message);
    void updateUI();
    bool validateCredentials();
    void lockFields();
};

#endif // PASSWORDRECOVERYFORM_H
