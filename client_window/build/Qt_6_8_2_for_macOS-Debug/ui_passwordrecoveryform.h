/********************************************************************************
** Form generated from reading UI file 'passwordrecoveryform.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDRECOVERYFORM_H
#define UI_PASSWORDRECOVERYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_passwordrecoveryform
{
public:
    QLabel *labelEmailExplanation;
    QPushButton *buttonSendCode;
    QPushButton *buttonConfirmCode;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditEmail;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEditCode;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLineEdit *lineEditNewPassword;
    QLineEdit *lineEditRepeatPassword;
    QPushButton *buttonConfirmNewPassword;
    QLabel *label;

    void setupUi(QDialog *passwordrecoveryform)
    {
        if (passwordrecoveryform->objectName().isEmpty())
            passwordrecoveryform->setObjectName("passwordrecoveryform");
        passwordrecoveryform->resize(433, 325);
        labelEmailExplanation = new QLabel(passwordrecoveryform);
        labelEmailExplanation->setObjectName("labelEmailExplanation");
        labelEmailExplanation->setGeometry(QRect(20, 130, 411, 20));
        buttonSendCode = new QPushButton(passwordrecoveryform);
        buttonSendCode->setObjectName("buttonSendCode");
        buttonSendCode->setGeometry(QRect(170, 80, 112, 41));
        buttonConfirmCode = new QPushButton(passwordrecoveryform);
        buttonConfirmCode->setObjectName("buttonConfirmCode");
        buttonConfirmCode->setGeometry(QRect(170, 160, 112, 41));
        horizontalLayoutWidget = new QWidget(passwordrecoveryform);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 90, 127, 23));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEditEmail = new QLineEdit(horizontalLayoutWidget);
        lineEditEmail->setObjectName("lineEditEmail");

        horizontalLayout->addWidget(lineEditEmail);

        horizontalLayoutWidget_2 = new QWidget(passwordrecoveryform);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(20, 170, 127, 23));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEditCode = new QLineEdit(horizontalLayoutWidget_2);
        lineEditCode->setObjectName("lineEditCode");

        horizontalLayout_2->addWidget(lineEditCode);

        formLayoutWidget = new QWidget(passwordrecoveryform);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(20, 220, 131, 54));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        lineEditNewPassword = new QLineEdit(formLayoutWidget);
        lineEditNewPassword->setObjectName("lineEditNewPassword");

        formLayout->setWidget(0, QFormLayout::SpanningRole, lineEditNewPassword);

        lineEditRepeatPassword = new QLineEdit(formLayoutWidget);
        lineEditRepeatPassword->setObjectName("lineEditRepeatPassword");

        formLayout->setWidget(1, QFormLayout::SpanningRole, lineEditRepeatPassword);

        buttonConfirmNewPassword = new QPushButton(passwordrecoveryform);
        buttonConfirmNewPassword->setObjectName("buttonConfirmNewPassword");
        buttonConfirmNewPassword->setGeometry(QRect(170, 220, 241, 41));
        label = new QLabel(passwordrecoveryform);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 10, 431, 71));

        retranslateUi(passwordrecoveryform);

        QMetaObject::connectSlotsByName(passwordrecoveryform);
    } // setupUi

    void retranslateUi(QDialog *passwordrecoveryform)
    {
        passwordrecoveryform->setWindowTitle(QCoreApplication::translate("passwordrecoveryform", "Dialog", nullptr));
        labelEmailExplanation->setText(QCoreApplication::translate("passwordrecoveryform", "\320\243\320\275\320\270\320\272\320\260\320\273\321\214\320\275\321\213\320\271 \320\272\320\276\320\264 \320\276\321\202\320\277\321\200\320\260\320\262\320\273\320\265\320\275 \320\275\320\260 \320\222\320\260\321\210\321\203 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\275\320\275\321\203\321\216 \320\277\320\276\321\207\321\202\321\203.", nullptr));
        buttonSendCode->setText(QCoreApplication::translate("passwordrecoveryform", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
        buttonConfirmCode->setText(QCoreApplication::translate("passwordrecoveryform", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
        buttonConfirmNewPassword->setText(QCoreApplication::translate("passwordrecoveryform", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214 \320\275\320\276\320\262\321\213\320\271 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        label->setText(QCoreApplication::translate("passwordrecoveryform", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700;\">\320\222\320\236\320\241\320\241\320\242\320\220\320\235\320\236\320\222\320\233\320\225\320\235\320\230\320\225 \320\237\320\220\320\240\320\236\320\233\320\257</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class passwordrecoveryform: public Ui_passwordrecoveryform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDRECOVERYFORM_H
