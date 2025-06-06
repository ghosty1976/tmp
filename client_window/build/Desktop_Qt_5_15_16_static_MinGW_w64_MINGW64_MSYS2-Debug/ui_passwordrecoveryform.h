/********************************************************************************
** Form generated from reading UI file 'passwordrecoveryform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDRECOVERYFORM_H
#define UI_PASSWORDRECOVERYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_passwordrecoveryform
{
public:
    QLabel *labelPasswordRecovery;
    QPushButton *pushButtonNext;
    QPushButton *pushButtonSave;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditLogin;
    QLineEdit *lineEditPassword;
    QLineEdit *lineEditPasswordCheck;
    QVBoxLayout *verticalLayout;
    QLabel *labelLogin;
    QLabel *labelPassword;
    QLabel *labelPasswordCheck;
    QHBoxLayout *horizontalLayout;
    QLabel *labelCode;
    QLineEdit *lineEditCode;

    void setupUi(QDialog *passwordrecoveryform)
    {
        if (passwordrecoveryform->objectName().isEmpty())
            passwordrecoveryform->setObjectName(QString::fromUtf8("passwordrecoveryform"));
        passwordrecoveryform->resize(818, 485);
        QPalette palette;
        QBrush brush(QColor(89, 62, 69, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush1(QColor(107, 118, 139, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(59, 70, 89, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        passwordrecoveryform->setPalette(palette);
        labelPasswordRecovery = new QLabel(passwordrecoveryform);
        labelPasswordRecovery->setObjectName(QString::fromUtf8("labelPasswordRecovery"));
        labelPasswordRecovery->setGeometry(QRect(0, 10, 431, 71));
        pushButtonNext = new QPushButton(passwordrecoveryform);
        pushButtonNext->setObjectName(QString::fromUtf8("pushButtonNext"));
        pushButtonNext->setGeometry(QRect(350, 280, 80, 24));
        pushButtonSave = new QPushButton(passwordrecoveryform);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));
        pushButtonSave->setGeometry(QRect(450, 280, 80, 24));
        gridLayoutWidget = new QWidget(passwordrecoveryform);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(260, 120, 421, 121));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEditLogin = new QLineEdit(gridLayoutWidget);
        lineEditLogin->setObjectName(QString::fromUtf8("lineEditLogin"));

        verticalLayout_2->addWidget(lineEditLogin);

        lineEditPassword = new QLineEdit(gridLayoutWidget);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));

        verticalLayout_2->addWidget(lineEditPassword);

        lineEditPasswordCheck = new QLineEdit(gridLayoutWidget);
        lineEditPasswordCheck->setObjectName(QString::fromUtf8("lineEditPasswordCheck"));

        verticalLayout_2->addWidget(lineEditPasswordCheck);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelLogin = new QLabel(gridLayoutWidget);
        labelLogin->setObjectName(QString::fromUtf8("labelLogin"));

        verticalLayout->addWidget(labelLogin);

        labelPassword = new QLabel(gridLayoutWidget);
        labelPassword->setObjectName(QString::fromUtf8("labelPassword"));

        verticalLayout->addWidget(labelPassword);

        labelPasswordCheck = new QLabel(gridLayoutWidget);
        labelPasswordCheck->setObjectName(QString::fromUtf8("labelPasswordCheck"));

        verticalLayout->addWidget(labelPasswordCheck);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelCode = new QLabel(gridLayoutWidget);
        labelCode->setObjectName(QString::fromUtf8("labelCode"));

        horizontalLayout->addWidget(labelCode);

        lineEditCode = new QLineEdit(gridLayoutWidget);
        lineEditCode->setObjectName(QString::fromUtf8("lineEditCode"));

        horizontalLayout->addWidget(lineEditCode);


        gridLayout->addLayout(horizontalLayout, 0, 2, 1, 1);


        retranslateUi(passwordrecoveryform);

        QMetaObject::connectSlotsByName(passwordrecoveryform);
    } // setupUi

    void retranslateUi(QDialog *passwordrecoveryform)
    {
        passwordrecoveryform->setWindowTitle(QCoreApplication::translate("passwordrecoveryform", "Dialog", nullptr));
        labelPasswordRecovery->setText(QCoreApplication::translate("passwordrecoveryform", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700;\">\320\222\320\236\320\241\320\241\320\242\320\220\320\235\320\236\320\222\320\233\320\225\320\235\320\230\320\225 \320\237\320\220\320\240\320\236\320\233\320\257</span></p></body></html>", nullptr));
        pushButtonNext->setText(QCoreApplication::translate("passwordrecoveryform", "\320\224\320\220\320\233\320\225\320\225", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("passwordrecoveryform", "\320\241\320\236\320\245\320\240\320\220\320\235\320\230\320\242\320\254", nullptr));
        labelLogin->setText(QCoreApplication::translate("passwordrecoveryform", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        labelPassword->setText(QCoreApplication::translate("passwordrecoveryform", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        labelPasswordCheck->setText(QCoreApplication::translate("passwordrecoveryform", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        labelCode->setText(QCoreApplication::translate("passwordrecoveryform", "\320\232\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class passwordrecoveryform: public Ui_passwordrecoveryform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDRECOVERYFORM_H
