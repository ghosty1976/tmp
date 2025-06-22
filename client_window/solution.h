#ifndef SOLUTION_H
#define SOLUTION_H

#include <QMainWindow>

namespace Ui { class Solution; }

class Solution : public QMainWindow
{
    Q_OBJECT

public:
    explicit Solution(QWidget *parent = nullptr);
    ~Solution();

    // Просто устанавливаем весь HTML, полученный от сервера
    void setSolution(const QString &html);

public slots:
    void slot_show();  // Показываем окно

private:
    Ui::Solution *ui;
};

#endif // SOLUTION_H
