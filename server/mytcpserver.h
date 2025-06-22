#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include "userutils.h"
#include "equationssolver.h"

class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyTcpServer(UserUtils* userUtils, EquationsSolver* eqSolver, QObject *parent = nullptr);
    ~MyTcpServer();

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void slotServerRead();

private:
    QTcpSocket *mTcpSocket = nullptr;
    UserUtils* m_userUtils;
    EquationsSolver* m_eqSolver;

    void handleRegister(const QString& login, const QString& password, const QString& email);
    void handleLogin(const QString& login, const QString& password);
    void handleCheckEmail(const QString& email);
    void handleCheckLogin(const QString& login);
    void handleRegisterCode(const QString& email);
    void handleRecoveryCode(const QString& login);
    void handleChangePassword(const QString& login, const QString& password);
    void handleSolve(const QString& functionText, double a, double b, int methodIndex, double tolerance, int maxIterations);
};

#endif // MYTCPSERVER_H
