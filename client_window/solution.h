/**
 * @file solution.h
 * @brief Header file for the Solution class that displays mathematical solutions.
 *
 * This class provides a window to display the solution of mathematical equations,
 * including function details, interval, method used, and the computed answer.
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <QMainWindow>
#include "ui_solution.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Solution; }
QT_END_NAMESPACE

/**
 * @class Solution
 * @brief A window that displays the solution of mathematical equations.
 *
 * The Solution class shows detailed information about the solved equation including
 * the function, interval, method, and the computed result. It also stores
 * precision and iteration information.
 */
class Solution : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a Solution window.
     * @param parent The parent widget (default is nullptr).
     */
    explicit Solution(QWidget *parent = nullptr);

    /**
     * @brief Destroys the Solution window.
     */
    ~Solution();

    /**
     * @brief Sets the solution text to be displayed.
     * @param solution The solution string to display in the QTextBrowser.
     */
    void setSolution(const QString &solution);

public slots:
    /**
     * @brief Displays the solution window.
     *
     * This slot shows the window containing the mathematical solution.
     */
    void slot_show();

private:
    Ui::Solution *ui; ///< Pointer to the UI form.

    /**
     * @brief The function text that was solved.
     */
    QString functionText;

    /**
     * @brief The interval over which the function was solved.
     */
    QString intervalText;

    /**
     * @brief The method used to solve the equation.
     */
    QString methodText;

    /**
     * @brief The computed answer/solution.
     */
    QString answer;

    /**
     * @brief The tolerance/precision used in the solution.
     */
    double tolerance;

    /**
     * @brief The maximum number of iterations used.
     */
    int maxIterations;
};

#endif // SOLUTION_H