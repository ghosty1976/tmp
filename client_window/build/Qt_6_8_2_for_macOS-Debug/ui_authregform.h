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
#include <QtWidgets/QLabel>
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
    QLineEdit *lineEditMail;
    QLineEdit *lineEditLogin;
    QLineEdit *lineEditPasswordCheck;
    QLineEdit *lineEditPassword;
    QPushButton *pushButtonForgotPassword;
    QLabel *labelHelp;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonAuth;
    QPushButton *pushButtonChange;
    QPushButton *pushButtonReg;

    void setupUi(QDialog *AuthRegForm)
    {
        if (AuthRegForm->objectName().isEmpty())
            AuthRegForm->setObjectName("AuthRegForm");
        AuthRegForm->resize(362, 396);
        formLayoutWidget = new QWidget(AuthRegForm);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(120, 60, 135, 121));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        lineEditMail = new QLineEdit(formLayoutWidget);
        lineEditMail->setObjectName("lineEditMail");

        formLayout->setWidget(0, QFormLayout::SpanningRole, lineEditMail);

        lineEditLogin = new QLineEdit(formLayoutWidget);
        lineEditLogin->setObjectName("lineEditLogin");

        formLayout->setWidget(1, QFormLayout::SpanningRole, lineEditLogin);

        lineEditPasswordCheck = new QLineEdit(formLayoutWidget);
        lineEditPasswordCheck->setObjectName("lineEditPasswordCheck");

        formLayout->setWidget(3, QFormLayout::SpanningRole, lineEditPasswordCheck);

        lineEditPassword = new QLineEdit(formLayoutWidget);
        lineEditPassword->setObjectName("lineEditPassword");

        formLayout->setWidget(2, QFormLayout::SpanningRole, lineEditPassword);

        pushButtonForgotPassword = new QPushButton(AuthRegForm);
        pushButtonForgotPassword->setObjectName("pushButtonForgotPassword");
        pushButtonForgotPassword->setGeometry(QRect(100, 290, 165, 32));
        labelHelp = new QLabel(AuthRegForm);
        labelHelp->setObjectName("labelHelp");
        labelHelp->setGeometry(QRect(-50, 330, 481, 20));
        verticalLayoutWidget = new QWidget(AuthRegForm);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(70, 180, 236, 100));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonAuth = new QPushButton(verticalLayoutWidget);
        pushButtonAuth->setObjectName("pushButtonAuth");

        verticalLayout->addWidget(pushButtonAuth);

        pushButtonChange = new QPushButton(verticalLayoutWidget);
        pushButtonChange->setObjectName("pushButtonChange");

        verticalLayout->addWidget(pushButtonChange);

        pushButtonReg = new QPushButton(verticalLayoutWidget);
        pushButtonReg->setObjectName("pushButtonReg");

        verticalLayout->addWidget(pushButtonReg);


        retranslateUi(AuthRegForm);

        QMetaObject::connectSlotsByName(AuthRegForm);
    } // setupUi

    void retranslateUi(QDialog *AuthRegForm)
    {
        AuthRegForm->setWindowTitle(QCoreApplication::translate("AuthRegForm", "Dialog", nullptr));
        lineEditMail->setText(QString());
        lineEditLogin->setText(QString());
        lineEditPasswordCheck->setText(QString());
        pushButtonForgotPassword->setText(QCoreApplication::translate("AuthRegForm", "\320\235\320\225 \320\234\320\236\320\226\320\225\320\242\320\225 \320\222\320\236\320\231\320\242\320\230?", nullptr));
        labelHelp->setText(QCoreApplication::translate("AuthRegForm", "<html><head/><body><p align=\"center\"><span style=\" font-size:8pt;\">\320\225\321\201\320\273\320\270 \321\203 \320\262\320\260\321\201 \320\275\320\265 \320\277\320\276\320\273\321\203\321\207\320\260\320\265\321\202\321\201\321\217 \320\262\320\276\320\271\321\202\320\270, \320\262\321\213 \320\274\320\276\320\266\320\265\321\202\320\265 \320\262\320\276\321\201\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214.</span></p></body></html>", nullptr));
        pushButtonAuth->setText(QCoreApplication::translate("AuthRegForm", "\320\222\320\245\320\236\320\224", nullptr));
        pushButtonChange->setText(QCoreApplication::translate("AuthRegForm", "\320\241\320\236\320\227\320\224\320\220\320\242\320\254 \320\220\320\232\320\232\320\220\320\243\320\235\320\242", nullptr));
        pushButtonReg->setText(QCoreApplication::translate("AuthRegForm", "\320\241\320\236\320\227\320\224\320\220\320\242\320\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthRegForm: public Ui_AuthRegForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHREGFORM_H
