/********************************************************************************
** Form generated from reading UI file 'registrationform.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONFORM_H
#define UI_REGISTRATIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistrationForm
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditMail;
    QLineEdit *lineEditLogin;
    QLineEdit *lineEditPassword;
    QLineEdit *lineEditPasswordCheck;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelMail;
    QLabel *labelLogin;
    QLabel *labelPassword;
    QLabel *labelPasswordCheck;
    QLineEdit *lineEditCode;
    QLabel *labelCode;
    QPushButton *pushButtonNext;
    QPushButton *pushButtonCreateAccount;
    QPushButton *pushButtonBackToAuth;

    void setupUi(QDialog *RegistrationForm)
    {
        if (RegistrationForm->objectName().isEmpty())
            RegistrationForm->setObjectName("RegistrationForm");
        RegistrationForm->resize(1024, 600);
        gridLayoutWidget = new QWidget(RegistrationForm);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(340, 110, 302, 118));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lineEditMail = new QLineEdit(gridLayoutWidget);
        lineEditMail->setObjectName("lineEditMail");

        verticalLayout->addWidget(lineEditMail);

        lineEditLogin = new QLineEdit(gridLayoutWidget);
        lineEditLogin->setObjectName("lineEditLogin");

        verticalLayout->addWidget(lineEditLogin);

        lineEditPassword = new QLineEdit(gridLayoutWidget);
        lineEditPassword->setObjectName("lineEditPassword");

        verticalLayout->addWidget(lineEditPassword);

        lineEditPasswordCheck = new QLineEdit(gridLayoutWidget);
        lineEditPasswordCheck->setObjectName("lineEditPasswordCheck");

        verticalLayout->addWidget(lineEditPasswordCheck);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        labelMail = new QLabel(gridLayoutWidget);
        labelMail->setObjectName("labelMail");

        verticalLayout_2->addWidget(labelMail);

        labelLogin = new QLabel(gridLayoutWidget);
        labelLogin->setObjectName("labelLogin");

        verticalLayout_2->addWidget(labelLogin);

        labelPassword = new QLabel(gridLayoutWidget);
        labelPassword->setObjectName("labelPassword");

        verticalLayout_2->addWidget(labelPassword);

        labelPasswordCheck = new QLabel(gridLayoutWidget);
        labelPasswordCheck->setObjectName("labelPasswordCheck");

        verticalLayout_2->addWidget(labelPasswordCheck);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        lineEditCode = new QLineEdit(gridLayoutWidget);
        lineEditCode->setObjectName("lineEditCode");
        lineEditCode->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(lineEditCode, 0, 3, 1, 1);

        labelCode = new QLabel(gridLayoutWidget);
        labelCode->setObjectName("labelCode");

        gridLayout->addWidget(labelCode, 0, 2, 1, 1);

        pushButtonNext = new QPushButton(RegistrationForm);
        pushButtonNext->setObjectName("pushButtonNext");
        pushButtonNext->setGeometry(QRect(450, 300, 80, 24));
        pushButtonCreateAccount = new QPushButton(RegistrationForm);
        pushButtonCreateAccount->setObjectName("pushButtonCreateAccount");
        pushButtonCreateAccount->setGeometry(QRect(450, 300, 80, 24));
        pushButtonBackToAuth = new QPushButton(RegistrationForm);
        pushButtonBackToAuth->setObjectName("pushButtonLogin");
        pushButtonBackToAuth->setGeometry(QRect(433, 330, 111, 24));

        retranslateUi(RegistrationForm);

        QMetaObject::connectSlotsByName(RegistrationForm);
    } // setupUi

    void retranslateUi(QDialog *RegistrationForm)
    {
        RegistrationForm->setWindowTitle(QCoreApplication::translate("RegistrationForm", "Dialog", nullptr));
        labelMail->setText(QCoreApplication::translate("RegistrationForm", "\320\237\320\276\321\207\321\202\320\260", nullptr));
        labelLogin->setText(QCoreApplication::translate("RegistrationForm", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        labelPassword->setText(QCoreApplication::translate("RegistrationForm", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        labelPasswordCheck->setText(QCoreApplication::translate("RegistrationForm", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        labelCode->setText(QCoreApplication::translate("RegistrationForm", "\320\232\320\276\320\264", nullptr));
        pushButtonNext->setText(QCoreApplication::translate("RegistrationForm", "\320\224\320\220\320\233\320\225\320\225", nullptr));
        pushButtonCreateAccount->setText(QCoreApplication::translate("RegistrationForm", "\320\241\320\236\320\227\320\224\320\220\320\242\320\254", nullptr));
        pushButtonBackToAuth->setText(QCoreApplication::translate("RegistrationForm", "\320\220\320\222\320\242\320\236\320\240\320\230\320\227\320\220\320\246\320\230\320\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrationForm: public Ui_RegistrationForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONFORM_H
