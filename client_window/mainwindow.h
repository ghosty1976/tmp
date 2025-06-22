#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "solution.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void solution_ok(const QString &html);

public slots:
    void slot_show();

private slots:
    void on_pushButtonSolve_clicked();

private:
    Ui::MainWindow *ui;
    Solution *solutionWindow = nullptr;
    bool isValidFunction(const QString& function);
    bool isValidInterval(const QString& interval);
};

#endif // MAINWINDOW_H
