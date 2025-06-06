#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void slotServerRead();

private:
    QTcpSocket *mTcpSocket = nullptr;
    bool connectToDatabase();

    // Основные обработчики для всех команд
    void handleRegister(const QString& login, const QString& password, const QString& email);
    void handleLogin(const QString& login, const QString& password);
    void handleCheckEmail(const QString& email);
    void handleCheckLogin(const QString& login);
    void handleRecovery(const QString& identifier); // email или login
    void handleVerifyCode(const QString& code);
    void handleChangePassword(const QString& password);
    void handleSolve(const QString& functionText, double a, double b, int methodIndex);

    // (если понадобится — для SOLUTION)
    QVector<double> parsePoly(const QString& functionText);
    double evalPoly(const QVector<double>& coeffs, double x);
    bool findRootDichotomy(double a, double b, const QVector<double>& coeffs, double& root);
    bool findRootIteration(double a, double b, const QVector<double>& coeffs, double& root);
};

#endif // MYTCPSERVER_H
