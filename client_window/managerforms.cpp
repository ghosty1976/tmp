#include "managerforms.h"
#include "ui_managerforms.h"

ManagerForms::ManagerForms(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ManagerForms)
{
    ui->setupUi(this);
    this->curr_auth = new AuthRegForm();
    this->curr_auth->show();
}

ManagerForms::~ManagerForms()
{
    delete ui;
}
