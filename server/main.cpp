#include <QCoreApplication>
#include "mytcpserver.h"
#include "dbsingleton.h"
#include "userutils.h"
#include "equationssolver.h"
#include <QSslSocket>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "QSslSocket::supportsSsl():" << QSslSocket::supportsSsl();
    qDebug() << "QSslSocket::sslLibraryBuildVersionString():" << QSslSocket::sslLibraryBuildVersionString();
    qDebug() << "QSslSocket::sslLibraryVersionString():" << QSslSocket::sslLibraryVersionString();

    QSqlDatabase& db = DbSingleton::instance().database();
    UserUtils userUtils(db);
    EquationsSolver eqSolver;
    MyTcpServer myserv(&userUtils, &eqSolver);

    return a.exec();
}
