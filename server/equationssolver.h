#ifndef EQUATIONSSOLVER_H
#define EQUATIONSSOLVER_H

#include <QString>
#include <QList>

/**
 * @brief Класс для решения уравнений различными методами
 * 
 * Предоставляет функционал для нахождения корней уравнений
 * методами дихотомии и итераций, а также вычисления значений выражений.
 */
class EquationsSolver
{
public:
    /**
     * @brief Нахождение всех корней методом дихотомии
     * @param func Строка с функцией (например, "x^2 - 4")
     * @param a Левая граница интервала поиска
     * @param b Правая граница интервала поиска
     * @param step Шаг поиска корней
     * @param tol Точность вычислений
     * @param maxIter Максимальное количество итераций
     * @return Список найденных корней
     */
    QList<double> findAllRootsDichotomy(const QString& func, double a, double b, double step, double tol, int maxIter);

    /**
     * @brief Нахождение всех корней методом итераций
     * @param func Строка с функцией (например, "x^2 - 4")
     * @param a Левая граница интервала поиска
     * @param b Правая граница интервала поиска
     * @param tol Точность вычислений
     * @param maxIter Максимальное количество итераций
     * @param nStarts Количество начальных точек для поиска
     * @return Список найденных корней
     */
    QList<double> findAllRootsIteration(const QString& func, double a, double b, double tol, int maxIter, int nStarts);

    /**
     * @brief Вычисление значения выражения
     * @param exprStr Строка с выражением (например, "x^2 + 2*x")
     * @param x Значение переменной x
     * @return Результат вычисления выражения
     */
    double evalExpression(const QString& exprStr, double x);

    /**
     * @brief Нахождение корня методом дихотомии
     * @param func Строка с функцией
     * @param a Левая граница интервала
     * @param b Правая граница интервала
     * @param[out] root Найденный корень
     * @param tol Точность вычислений
     * @param maxIter Максимальное количество итераций
     * @param[out] iters Количество выполненных итераций
     * @return true если корень найден, false в противном случае
     */
    bool findRootDichotomyExpr(const QString& func, double a, double b, double& root, double tol, int maxIter, int& iters);

    /**
     * @brief Нахождение корня методом итераций
     * @param func Строка с функцией
     * @param a Левая граница интервала
     * @param b Правая граница интервала
     * @param[out] root Найденный корень
     * @param tol Точность вычислений
     * @param maxIter Максимальное количество итераций
     * @param[out] iters Количество выполненных итераций
     * @return true если корень найден, false в противном случае
     */
    bool findRootIterationExpr(const QString& func, double a, double b, double& root, double tol, int maxIter, int& iters);
};

#endif // EQUATIONSSOLVER_H