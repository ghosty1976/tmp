#ifndef EQUATIONSSOLVER_H
#define EQUATIONSSOLVER_H

#include <QString>
#include <QList>

class EquationsSolver
{
public:
    QList<double> findAllRootsDichotomy(const QString& func, double a, double b, double step, double tol, int maxIter);
    QList<double> findAllRootsIteration(const QString& func, double a, double b, double tol, int maxIter, int nStarts);
    double evalExpression(const QString& exprStr, double x);
    bool findRootDichotomyExpr(const QString& func, double a, double b, double& root, double tol, int maxIter, int& iters);
    bool findRootIterationExpr(const QString& func, double a, double b, double& root, double tol, int maxIter, int& iters);
};

#endif // EQUATIONSSOLVER_H
