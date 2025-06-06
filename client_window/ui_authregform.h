/********************************************************************************
** Form generated from reading UI file 'authregform.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHREGFORM_H
#define UI_AUTHREGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthRegForm
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLineEdit *lineEditLogin;
    QLineEdit *lineEditPassword;
    QPushButton *pushButtonForgotPassword;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonAuth;
    QPushButton *pushButtonReg;

    void setupUi(QDialog *AuthRegForm)
    {
        if (AuthRegForm->objectName().isEmpty())
            AuthRegForm->setObjectName("AuthRegForm");
        AuthRegForm->resize(1024, 524);
        formLayoutWidget = new QWidget(AuthRegForm);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(410, 140, 135, 61));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        lineEditLogin = new QLineEdit(formLayoutWidget);
        lineEditLogin->setObjectName("lineEditLogin");

        formLayout->setWidget(0, QFormLayout::SpanningRole, lineEditLogin);

        lineEditPassword = new QLineEdit(formLayoutWidget);
        lineEditPassword->setObjectName("lineEditPassword");

        formLayout->setWidget(1, QFormLayout::SpanningRole, lineEditPassword);

        pushButtonForgotPassword = new QPushButton(AuthRegForm);
        pushButtonForgotPassword->setObjectName("pushButtonForgotPassword");
        pushButtonForgotPassword->setGeometry(QRect(480, 300, 123, 24));
        verticalLayoutWidget = new QWidget(AuthRegForm);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(440, 260, 82, 26));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonAuth = new QPushButton(verticalLayoutWidget);
        pushButtonAuth->setObjectName("pushButtonAuth");

        verticalLayout->addWidget(pushButtonAuth);

        pushButtonReg = new QPushButton(AuthRegForm);
        pushButtonReg->setObjectName("pushButtonReg");
        pushButtonReg->setGeometry(QRect(380, 300, 90, 24));

        retranslateUi(AuthRegForm);

        QMetaObject::connectSlotsByName(AuthRegForm);
    } // setupUi

    void retranslateUi(QDialog *AuthRegForm)
    {
        AuthRegForm->setWindowTitle(QCoreApplication::translate("AuthRegForm", "Dialog", nullptr));
        lineEditLogin->setText(QString());
        pushButtonForgotPassword->setText(QCoreApplication::translate("AuthRegForm", "\320\235\320\225 \320\234\320\236\320\226\320\225\320\242\320\225 \320\222\320\236\320\231\320\242\320\230?", nullptr));
        pushButtonAuth->setText(QCoreApplication::translate("AuthRegForm", "\320\222\320\245\320\236\320\224", nullptr));
        pushButtonReg->setText(QCoreApplication::translate("AuthRegForm", "\320\240\320\225\320\223\320\230\320\241\320\242\320\240\320\220\320\246\320\230\320\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthRegForm: public Ui_AuthRegForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHREGFORM_H
