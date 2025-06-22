#include "solution.h"
#include "ui_solution.h"

Solution::Solution(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Solution)
{
    ui->setupUi(this);
    setWindowTitle("Результат решения");
}

Solution::~Solution()
{
    delete ui;
}

void Solution::slot_show()
{
    this->show();
}

void Solution::setSolution(const QString &html)
{
    ui->textBrowser->setHtml(html);
}
