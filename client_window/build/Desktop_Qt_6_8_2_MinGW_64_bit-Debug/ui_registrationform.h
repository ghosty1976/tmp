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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistrationForm
{
public:
    QLabel *labelPasswordRecovery;
    QPushButton *pushButtonBackToAuth;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_5;
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
    QPushButton *pushButtonNext;
    QPushButton *pushButtonCreateAccount;
    QHBoxLayout *horizontalLayout;
    QLabel *labelCode;
    QLineEdit *lineEditCode;

    void setupUi(QDialog *RegistrationForm)
    {
        if (RegistrationForm->objectName().isEmpty())
            RegistrationForm->setObjectName("RegistrationForm");
        RegistrationForm->resize(1000, 600);
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
        RegistrationForm->setPalette(palette);
        labelPasswordRecovery = new QLabel(RegistrationForm);
        labelPasswordRecovery->setObjectName("labelPasswordRecovery");
        labelPasswordRecovery->setGeometry(QRect(0, 20, 1001, 78));
        QFont font;
        font.setFamilies({QString::fromUtf8("Gilroy")});
        font.setPointSize(36);
        font.setBold(true);
        labelPasswordRecovery->setFont(font);
        pushButtonBackToAuth = new QPushButton(RegistrationForm);
        pushButtonBackToAuth->setObjectName("pushButtonBackToAuth");
        pushButtonBackToAuth->setGeometry(QRect(370, 470, 261, 26));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Gilroy")});
        font1.setPointSize(11);
        font1.setBold(true);
        pushButtonBackToAuth->setFont(font1);
        layoutWidget = new QWidget(RegistrationForm);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(310, 190, 551, 282));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lineEditMail = new QLineEdit(layoutWidget);
        lineEditMail->setObjectName("lineEditMail");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Gilroy")});
        font2.setPointSize(22);
        font2.setBold(false);
        lineEditMail->setFont(font2);

        verticalLayout->addWidget(lineEditMail);

        lineEditLogin = new QLineEdit(layoutWidget);
        lineEditLogin->setObjectName("lineEditLogin");
        lineEditLogin->setFont(font2);

        verticalLayout->addWidget(lineEditLogin, 0, Qt::AlignmentFlag::AlignHCenter);

        lineEditPassword = new QLineEdit(layoutWidget);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setFont(font2);

        verticalLayout->addWidget(lineEditPassword);

        lineEditPasswordCheck = new QLineEdit(layoutWidget);
        lineEditPasswordCheck->setObjectName("lineEditPasswordCheck");
        lineEditPasswordCheck->setFont(font2);

        verticalLayout->addWidget(lineEditPasswordCheck);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        labelMail = new QLabel(layoutWidget);
        labelMail->setObjectName("labelMail");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Gilroy")});
        font3.setPointSize(22);
        font3.setBold(true);
        labelMail->setFont(font3);

        verticalLayout_2->addWidget(labelMail);

        labelLogin = new QLabel(layoutWidget);
        labelLogin->setObjectName("labelLogin");
        labelLogin->setFont(font3);

        verticalLayout_2->addWidget(labelLogin);

        labelPassword = new QLabel(layoutWidget);
        labelPassword->setObjectName("labelPassword");
        labelPassword->setFont(font3);

        verticalLayout_2->addWidget(labelPassword);

        labelPasswordCheck = new QLabel(layoutWidget);
        labelPasswordCheck->setObjectName("labelPasswordCheck");
        labelPasswordCheck->setFont(font3);

        verticalLayout_2->addWidget(labelPasswordCheck);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        verticalLayout_5->addLayout(gridLayout);

        pushButtonNext = new QPushButton(layoutWidget);
        pushButtonNext->setObjectName("pushButtonNext");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Gilroy")});
        font4.setPointSize(18);
        font4.setBold(true);
        pushButtonNext->setFont(font4);

        verticalLayout_5->addWidget(pushButtonNext);

        pushButtonCreateAccount = new QPushButton(layoutWidget);
        pushButtonCreateAccount->setObjectName("pushButtonCreateAccount");
        pushButtonCreateAccount->setFont(font4);

        verticalLayout_5->addWidget(pushButtonCreateAccount);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        labelCode = new QLabel(layoutWidget);
        labelCode->setObjectName("labelCode");
        labelCode->setFont(font3);

        horizontalLayout->addWidget(labelCode);

        lineEditCode = new QLineEdit(layoutWidget);
        lineEditCode->setObjectName("lineEditCode");
        lineEditCode->setMinimumSize(QSize(0, 0));
        lineEditCode->setFont(font2);

        horizontalLayout->addWidget(lineEditCode);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);


        retranslateUi(RegistrationForm);

        QMetaObject::connectSlotsByName(RegistrationForm);
    } // setupUi

    void retranslateUi(QDialog *RegistrationForm)
    {
        RegistrationForm->setWindowTitle(QCoreApplication::translate("RegistrationForm", "Dialog", nullptr));
        labelPasswordRecovery->setText(QCoreApplication::translate("RegistrationForm", "<html><head/><body><p align=\"center\"><span style=\" font-size:48pt;\">\320\240\320\225\320\223\320\230\320\241\320\242\320\240\320\220\320\246\320\230\320\257</span></p></body></html>", nullptr));
        pushButtonBackToAuth->setText(QCoreApplication::translate("RegistrationForm", "\320\220\320\222\320\242\320\236\320\240\320\230\320\227\320\220\320\246\320\230\320\257", nullptr));
        labelMail->setText(QCoreApplication::translate("RegistrationForm", "\320\237\320\276\321\207\321\202\320\260", nullptr));
        labelLogin->setText(QCoreApplication::translate("RegistrationForm", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        labelPassword->setText(QCoreApplication::translate("RegistrationForm", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        labelPasswordCheck->setText(QCoreApplication::translate("RegistrationForm", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        pushButtonNext->setText(QCoreApplication::translate("RegistrationForm", "\320\224\320\220\320\233\320\225\320\225", nullptr));
        pushButtonCreateAccount->setText(QCoreApplication::translate("RegistrationForm", "\320\241\320\236\320\227\320\224\320\220\320\242\320\254", nullptr));
        labelCode->setText(QCoreApplication::translate("RegistrationForm", "\320\232\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrationForm: public Ui_RegistrationForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONFORM_H
