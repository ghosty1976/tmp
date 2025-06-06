#ifndef MANAGERFORMS_H
#define MANAGERFORMS_H

#include <QMainWindow>
#include "authregform.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class ManagerForms;
}
QT_END_NAMESPACE

class ManagerForms : public QMainWindow
{
    Q_OBJECT

public:
    ManagerForms(QWidget *parent = nullptr);
    ~ManagerForms();
private:
    Ui::ManagerForms *ui;
    AuthRegForm * curr_auth;
};
#endif // MANAGERFORMS_H
