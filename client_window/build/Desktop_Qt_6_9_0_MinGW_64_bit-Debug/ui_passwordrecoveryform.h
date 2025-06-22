/********************************************************************************
** Form generated from reading UI file 'passwordrecoveryform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDRECOVERYFORM_H
#define UI_PASSWORDRECOVERYFORM_H

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

class Ui_passwordrecoveryform
{
public:
    QLabel *labelPasswordRecovery;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *labelLogin;
    QLabel *labelPassword;
    QLabel *labelPasswordCheck;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditLogin;
    QLineEdit *lineEditPassword;
    QLineEdit *lineEditPasswordCheck;
    QPushButton *pushButtonConfirm;
    QPushButton *pushButtonRecover;
    QHBoxLayout *horizontalLayout;
    QLabel *labelCode;
    QLineEdit *lineEditCode;

    void setupUi(QDialog *passwordrecoveryform)
    {
        if (passwordrecoveryform->objectName().isEmpty())
            passwordrecoveryform->setObjectName("passwordrecoveryform");
        passwordrecoveryform->resize(1000, 600);
        QPalette palette;
        QBrush brush(QColor(89, 62, 69, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        QBrush brush1(QColor(107, 118, 139, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush1);
        QBrush brush2(QColor(59, 70, 89, 255));
        brush2.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Highlight, brush2);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Highlight, brush2);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush1);
        passwordrecoveryform->setPalette(palette);
        labelPasswordRecovery = new QLabel(passwordrecoveryform);
        labelPasswordRecovery->setObjectName("labelPasswordRecovery");
        labelPasswordRecovery->setGeometry(QRect(80, 30, 849, 78));
        QFont font;
        font.setFamilies({QString::fromUtf8("Gilroy")});
        font.setPointSize(36);
        font.setBold(true);
        labelPasswordRecovery->setFont(font);
        layoutWidget = new QWidget(passwordrecoveryform);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(310, 220, 571, 229));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        labelLogin = new QLabel(layoutWidget);
        labelLogin->setObjectName("labelLogin");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Gilroy")});
        font1.setPointSize(22);
        font1.setBold(true);
        labelLogin->setFont(font1);

        verticalLayout->addWidget(labelLogin);

        labelPassword = new QLabel(layoutWidget);
        labelPassword->setObjectName("labelPassword");
        labelPassword->setFont(font1);

        verticalLayout->addWidget(labelPassword);

        labelPasswordCheck = new QLabel(layoutWidget);
        labelPasswordCheck->setObjectName("labelPasswordCheck");
        labelPasswordCheck->setFont(font1);

        verticalLayout->addWidget(labelPasswordCheck);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        lineEditLogin = new QLineEdit(layoutWidget);
        lineEditLogin->setObjectName("lineEditLogin");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Gilroy")});
        font2.setPointSize(22);
        font2.setBold(false);
        lineEditLogin->setFont(font2);

        verticalLayout_2->addWidget(lineEditLogin);

        lineEditPassword = new QLineEdit(layoutWidget);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setFont(font2);

        verticalLayout_2->addWidget(lineEditPassword);

        lineEditPasswordCheck = new QLineEdit(layoutWidget);
        lineEditPasswordCheck->setObjectName("lineEditPasswordCheck");
        lineEditPasswordCheck->setFont(font2);

        verticalLayout_2->addWidget(lineEditPasswordCheck);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        pushButtonConfirm = new QPushButton(layoutWidget);
        pushButtonConfirm->setObjectName("pushButtonConfirm");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Gilroy")});
        font3.setPointSize(18);
        font3.setBold(true);
        pushButtonConfirm->setFont(font3);

        verticalLayout_3->addWidget(pushButtonConfirm);

        pushButtonRecover = new QPushButton(layoutWidget);
        pushButtonRecover->setObjectName("pushButtonRecover");
        pushButtonRecover->setFont(font3);

        verticalLayout_3->addWidget(pushButtonRecover);


        formLayout->setLayout(0, QFormLayout::ItemRole::LabelRole, verticalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        labelCode = new QLabel(layoutWidget);
        labelCode->setObjectName("labelCode");
        labelCode->setFont(font1);

        horizontalLayout->addWidget(labelCode);

        lineEditCode = new QLineEdit(layoutWidget);
        lineEditCode->setObjectName("lineEditCode");
        lineEditCode->setFont(font2);

        horizontalLayout->addWidget(lineEditCode);


        formLayout->setLayout(0, QFormLayout::ItemRole::FieldRole, horizontalLayout);


        retranslateUi(passwordrecoveryform);

        QMetaObject::connectSlotsByName(passwordrecoveryform);
    } // setupUi

    void retranslateUi(QDialog *passwordrecoveryform)
    {
        passwordrecoveryform->setWindowTitle(QCoreApplication::translate("passwordrecoveryform", "Dialog", nullptr));
        labelPasswordRecovery->setText(QCoreApplication::translate("passwordrecoveryform", "<html><head/><body><p><span style=\" font-size:48pt;\">\320\222\320\236\320\241\320\241\320\242\320\220\320\235\320\236\320\222\320\233\320\225\320\235\320\230\320\225 \320\237\320\220\320\240\320\236\320\233\320\257</span></p></body></html>", nullptr));
        labelLogin->setText(QCoreApplication::translate("passwordrecoveryform", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        labelPassword->setText(QCoreApplication::translate("passwordrecoveryform", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        labelPasswordCheck->setText(QCoreApplication::translate("passwordrecoveryform", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        pushButtonConfirm->setText(QCoreApplication::translate("passwordrecoveryform", "\320\237\320\236\320\224\320\242\320\222\320\225\320\240\320\224\320\226\320\230\320\242\320\254", nullptr));
        pushButtonRecover->setText(QCoreApplication::translate("passwordrecoveryform", "\320\222\320\236\320\241\320\241\320\242\320\220\320\235\320\236\320\222\320\230\320\242\320\254", nullptr));
        labelCode->setText(QCoreApplication::translate("passwordrecoveryform", "\320\232\320\276\320\264", nullptr));
        lineEditCode->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class passwordrecoveryform: public Ui_passwordrecoveryform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDRECOVERYFORM_H
