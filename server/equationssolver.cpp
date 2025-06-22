#include "equationssolver.h"
#include <QJSEngine>
#include <QRegularExpression>
#include <cmath>
#include <map>
#include <functional>
#include <limits>

double EquationsSolver::evalExpression(const QString& exprStr, double x)
{
    QString expr = exprStr;
    expr.replace(" ", "");
    expr.replace(QRegularExpression("\\bx\\b"), QString::number(x, 'g', 15));
    std::map<QString, std::function<double(double)>> functions = {
        {"sin", [](double v){ return sin(v); }},
        {"cos", [](double v){ return cos(v); }},
        {"tan", [](double v){ return tan(v); }},
        {"abs", [](double v){ return fabs(v); }},
        {"log", [](double v){ return log10(v); }},
        {"ln",  [](double v){ return log(v); }},
        {"sqrt",[](double v){ return sqrt(v); }},
        {"exp", [](double v){ return exp(v); }}
    };
    for (const auto& [name, func] : functions) {
        QRegularExpression re(name + "\\(([^\\(\\)]*)\\)");
        QRegularExpressionMatch match;
        while ((match = re.match(expr)).hasMatch()) {
            QString inside = match.captured(1);
            double innerVal = evalExpression(inside, x);
            double val = func(innerVal);
            expr.replace(match.captured(0), QString::number(val, 'g', 15));
        }
    }
    QRegularExpression powRe("(\\-?\\d+(?:\\.\\d+)?)[\\^](\\-?\\d+(?:\\.\\d+)?)");
    QRegularExpressionMatch match;
    while ((match = powRe.match(expr)).hasMatch()) {
        double base = match.captured(1).toDouble();
        double expn = match.captured(2).toDouble();
        double result = pow(base, expn);
        expr.replace(match.captured(0), QString::number(result, 'g', 15));
    }
    QJSEngine engine;
    QJSValue res = engine.evaluate(expr);

    if (res.isError() || !res.isNumber())
        return std::numeric_limits<double>::quiet_NaN();
    return res.toNumber();
}

QList<double> EquationsSolver::findAllRootsDichotomy(const QString& func, double a, double b, double step, double tol, int maxIter)
{
    QList<double> roots;
    for (double x = a; x < b; x += step) {
        double f1 = evalExpression(func, x);
        double f2 = evalExpression(func, x + step);
        if (std::isnan(f1) || std::isnan(f2)) continue;
        if (f1 * f2 < 0) {
            double root = 0;
            int iters = 0;
            if (findRootDichotomyExpr(func, x, x + step, root, tol, maxIter, iters)) {
                bool isNew = true;
                for (double r : roots) {
                    if (fabs(r - root) < tol * 10)
                        isNew = false;
                }
                if (isNew)
                    roots.append(root);
            }
        }
    }
    return roots;
}

bool EquationsSolver::findRootDichotomyExpr(const QString& func, double a, double b, double& root, double tol, int maxIter, int& iters) {
    double fa = evalExpression(func, a);
    double fb = evalExpression(func, b);
    if (std::isnan(fa) || std::isnan(fb) || fa * fb > 0) return false;
    double mid = 0;
    iters = 0;
    for (; iters < maxIter; ++iters) {
        mid = 0.5 * (a + b);
        double fmid = evalExpression(func, mid);
        if (std::isnan(fmid)) return false;
        if (fabs(fmid) < tol || fabs(b - a) < tol)
            break;
        if (fa * fmid < 0) {
            b = mid;
            fb = fmid;
        } else {
            a = mid;
            fa = fmid;
        }
    }
    root = 0.5 * (a + b);
    return true;
}

QList<double> EquationsSolver::findAllRootsIteration(const QString& func, double a, double b, double tol, int maxIter, int nStarts)
{
    QList<double> roots;
    for (int i = 0; i < nStarts; ++i) {
        double start = a + (b - a) * i / (nStarts - 1);
        double root = 0;
        int iters = 0;
        if (findRootIterationExpr(func, start, b, root, tol, maxIter, iters)) {
            bool isNew = true;
            for (double r : roots)
                if (fabs(r - root) < tol * 10) isNew = false;
            if (isNew && root >= a && root <= b)
                roots.append(root);
        }
    }
    return roots;
}

bool EquationsSolver::findRootIterationExpr(const QString& func, double a, double b, double& root, double tol, int maxIter, int& iters)
{
    double x0 = (a + b) / 2.0;
    double x1 = x0;
    iters = 0;
    const double h = 1e-6;

    for (; iters < maxIter; ++iters) {
        double fx = evalExpression(func, x0);
        if (std::isnan(fx)) return false;

        double dfx = (evalExpression(func, x0 + h) - evalExpression(func, x0 - h)) / (2.0 * h);
        if (fabs(dfx) < 1e-10) return false;

        x1 = x0 - fx / dfx;

        if (x1 < a || x1 > b) {
            x1 = (x1 + x0) / 2.0;
        }

        if (fabs(x1 - x0) < tol)
            break;

        x0 = x1;
    }

    root = x1;
    double froot = evalExpression(func, root);
    return std::fabs(froot) < tol;
}
