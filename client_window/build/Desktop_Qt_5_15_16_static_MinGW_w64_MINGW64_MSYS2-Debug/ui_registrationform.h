/********************************************************************************
** Form generated from reading UI file 'registrationform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
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
    QLabel *labelCode;
    QLineEdit *lineEditCode;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelMail;
    QLabel *labelLogin;
    QLabel *labelPassword;
    QLabel *labelPasswordCheck;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditMail;
    QLineEdit *lineEditLogin;
    QLineEdit *lineEditPassword;
    QLineEdit *lineEditPasswordCheck;
    QPushButton *pushButtonNext;
    QPushButton *pushButtonBackToAuth;

    void setupUi(QDialog *RegistrationForm)
    {
        if (RegistrationForm->objectName().isEmpty())
            RegistrationForm->setObjectName(QString::fromUtf8("RegistrationForm"));
        RegistrationForm->resize(818, 485);
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
        gridLayoutWidget = new QWidget(RegistrationForm);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(230, 130, 302, 118));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelCode = new QLabel(gridLayoutWidget);
        labelCode->setObjectName(QString::fromUtf8("labelCode"));

        gridLayout->addWidget(labelCode, 0, 2, 1, 1);

        lineEditCode = new QLineEdit(gridLayoutWidget);
        lineEditCode->setObjectName(QString::fromUtf8("lineEditCode"));
        lineEditCode->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(lineEditCode, 0, 3, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labelMail = new QLabel(gridLayoutWidget);
        labelMail->setObjectName(QString::fromUtf8("labelMail"));

        verticalLayout_2->addWidget(labelMail);

        labelLogin = new QLabel(gridLayoutWidget);
        labelLogin->setObjectName(QString::fromUtf8("labelLogin"));

        verticalLayout_2->addWidget(labelLogin);

        labelPassword = new QLabel(gridLayoutWidget);
        labelPassword->setObjectName(QString::fromUtf8("labelPassword"));

        verticalLayout_2->addWidget(labelPassword);

        labelPasswordCheck = new QLabel(gridLayoutWidget);
        labelPasswordCheck->setObjectName(QString::fromUtf8("labelPasswordCheck"));

        verticalLayout_2->addWidget(labelPasswordCheck);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEditMail = new QLineEdit(gridLayoutWidget);
        lineEditMail->setObjectName(QString::fromUtf8("lineEditMail"));

        verticalLayout->addWidget(lineEditMail);

        lineEditLogin = new QLineEdit(gridLayoutWidget);
        lineEditLogin->setObjectName(QString::fromUtf8("lineEditLogin"));

        verticalLayout->addWidget(lineEditLogin);

        lineEditPassword = new QLineEdit(gridLayoutWidget);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));

        verticalLayout->addWidget(lineEditPassword);

        lineEditPasswordCheck = new QLineEdit(gridLayoutWidget);
        lineEditPasswordCheck->setObjectName(QString::fromUtf8("lineEditPasswordCheck"));

        verticalLayout->addWidget(lineEditPasswordCheck);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        pushButtonNext = new QPushButton(RegistrationForm);
        pushButtonNext->setObjectName(QString::fromUtf8("pushButtonNext"));
        pushButtonNext->setGeometry(QRect(330, 310, 80, 24));
        pushButtonBackToAuth = new QPushButton(RegistrationForm);
        pushButtonBackToAuth->setObjectName(QString::fromUtf8("pushButtonBackToAuth"));
        pushButtonBackToAuth->setGeometry(QRect(320, 350, 111, 24));

        retranslateUi(RegistrationForm);

        QMetaObject::connectSlotsByName(RegistrationForm);
    } // setupUi

    void retranslateUi(QDialog *RegistrationForm)
    {
        RegistrationForm->setWindowTitle(QCoreApplication::translate("RegistrationForm", "Dialog", nullptr));
        labelCode->setText(QCoreApplication::translate("RegistrationForm", "\320\232\320\276\320\264", nullptr));
        labelMail->setText(QCoreApplication::translate("RegistrationForm", "\320\237\320\276\321\207\321\202\320\260", nullptr));
        labelLogin->setText(QCoreApplication::translate("RegistrationForm", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        labelPassword->setText(QCoreApplication::translate("RegistrationForm", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        labelPasswordCheck->setText(QCoreApplication::translate("RegistrationForm", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        pushButtonNext->setText(QCoreApplication::translate("RegistrationForm", "\320\224\320\220\320\233\320\225\320\225", nullptr));
        pushButtonBackToAuth->setText(QCoreApplication::translate("RegistrationForm", "\320\220\320\222\320\242\320\236\320\240\320\230\320\227\320\220\320\246\320\230\320\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrationForm: public Ui_RegistrationForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONFORM_H
