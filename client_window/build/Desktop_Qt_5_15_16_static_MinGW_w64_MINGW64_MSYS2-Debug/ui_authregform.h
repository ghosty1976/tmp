/********************************************************************************
** Form generated from reading UI file 'authregform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHREGFORM_H
#define UI_AUTHREGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthRegForm
{
public:
    QPushButton *pushButtonForgotPassword;
    QPushButton *pushButtonReg;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelLogin;
    QLabel *labelPassword;
    QFormLayout *formLayout;
    QLineEdit *lineEditLogin;
    QLineEdit *lineEditPassword;
    QPushButton *pushButtonAuth;

    void setupUi(QDialog *AuthRegForm)
    {
        if (AuthRegForm->objectName().isEmpty())
            AuthRegForm->setObjectName(QString::fromUtf8("AuthRegForm"));
        AuthRegForm->resize(818, 485);
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
        AuthRegForm->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Gilroy"));
        font.setPointSize(22);
        font.setBold(false);
        AuthRegForm->setFont(font);
        pushButtonForgotPassword = new QPushButton(AuthRegForm);
        pushButtonForgotPassword->setObjectName(QString::fromUtf8("pushButtonForgotPassword"));
        pushButtonForgotPassword->setGeometry(QRect(420, 310, 152, 26));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Gilroy"));
        font1.setPointSize(11);
        font1.setBold(true);
        pushButtonForgotPassword->setFont(font1);
        pushButtonReg = new QPushButton(AuthRegForm);
        pushButtonReg->setObjectName(QString::fromUtf8("pushButtonReg"));
        pushButtonReg->setGeometry(QRect(250, 310, 152, 26));
        pushButtonReg->setFont(font1);
        horizontalLayoutWidget = new QWidget(AuthRegForm);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(160, 140, 371, 98));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, 15, 0);
        labelLogin = new QLabel(horizontalLayoutWidget);
        labelLogin->setObjectName(QString::fromUtf8("labelLogin"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelLogin->sizePolicy().hasHeightForWidth());
        labelLogin->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Gilroy"));
        font2.setPointSize(22);
        font2.setBold(true);
        labelLogin->setFont(font2);

        verticalLayout_2->addWidget(labelLogin);

        labelPassword = new QLabel(horizontalLayoutWidget);
        labelPassword->setObjectName(QString::fromUtf8("labelPassword"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(6);
        sizePolicy1.setHeightForWidth(labelPassword->sizePolicy().hasHeightForWidth());
        labelPassword->setSizePolicy(sizePolicy1);
        labelPassword->setFont(font2);

        verticalLayout_2->addWidget(labelPassword);


        horizontalLayout->addLayout(verticalLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldGrowthPolicy::AllNonFixedFieldsGrow);
        formLayout->setRowWrapPolicy(QFormLayout::RowWrapPolicy::WrapAllRows);
        formLayout->setVerticalSpacing(12);
        formLayout->setContentsMargins(0, -1, 0, -1);
        lineEditLogin = new QLineEdit(horizontalLayoutWidget);
        lineEditLogin->setObjectName(QString::fromUtf8("lineEditLogin"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEditLogin->sizePolicy().hasHeightForWidth());
        lineEditLogin->setSizePolicy(sizePolicy2);
        lineEditLogin->setSizeIncrement(QSize(0, 0));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Gilroy"));
        font3.setPointSize(22);
        font3.setBold(false);
        font3.setStrikeOut(false);
        lineEditLogin->setFont(font3);

        formLayout->setWidget(0, QFormLayout::SpanningRole, lineEditLogin);

        lineEditPassword = new QLineEdit(horizontalLayoutWidget);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEditPassword->sizePolicy().hasHeightForWidth());
        lineEditPassword->setSizePolicy(sizePolicy3);
        lineEditPassword->setMinimumSize(QSize(0, 0));
        lineEditPassword->setSizeIncrement(QSize(0, 0));
        lineEditPassword->setFont(font3);
        lineEditPassword->setMouseTracking(true);
        lineEditPassword->setCursorMoveStyle(Qt::CursorMoveStyle::VisualMoveStyle);

        formLayout->setWidget(1, QFormLayout::SpanningRole, lineEditPassword);


        horizontalLayout->addLayout(formLayout);

        pushButtonAuth = new QPushButton(AuthRegForm);
        pushButtonAuth->setObjectName(QString::fromUtf8("pushButtonAuth"));
        pushButtonAuth->setGeometry(QRect(298, 250, 231, 44));
        QPalette palette1;
        QBrush brush3(QColor(255, 255, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        QBrush brush4(QColor(70, 68, 86, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush4);
        QBrush brush5(QColor(79, 66, 82, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        pushButtonAuth->setPalette(palette1);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Gilroy"));
        font4.setPointSize(18);
        font4.setBold(true);
        pushButtonAuth->setFont(font4);

        retranslateUi(AuthRegForm);

        QMetaObject::connectSlotsByName(AuthRegForm);
    } // setupUi

    void retranslateUi(QDialog *AuthRegForm)
    {
        AuthRegForm->setWindowTitle(QCoreApplication::translate("AuthRegForm", "Dialog", nullptr));
        pushButtonForgotPassword->setText(QCoreApplication::translate("AuthRegForm", "\320\235\320\225 \320\234\320\236\320\226\320\225\320\242\320\225 \320\222\320\236\320\231\320\242\320\230?", nullptr));
        pushButtonReg->setText(QCoreApplication::translate("AuthRegForm", "\320\240\320\225\320\223\320\230\320\241\320\242\320\240\320\220\320\246\320\230\320\257", nullptr));
        labelLogin->setText(QCoreApplication::translate("AuthRegForm", "<html><head/><body><p><span style=\" color:#593e45;\">\320\233\320\236\320\223\320\230\320\235</span></p></body></html>", nullptr));
        labelPassword->setText(QCoreApplication::translate("AuthRegForm", "<html><head/><body><p><span style=\" color:#593e45;\">\320\237\320\220\320\240\320\236\320\233\320\254</span></p></body></html>", nullptr));
        lineEditLogin->setText(QCoreApplication::translate("AuthRegForm", "\320\244\320\243\320\253\320\222\320\244\320\253\320\222", nullptr));
        lineEditPassword->setText(QCoreApplication::translate("AuthRegForm", "\320\244\320\243\320\253\320\222\320\244\320\253\320\222", nullptr));
        pushButtonAuth->setText(QCoreApplication::translate("AuthRegForm", "\320\222\320\245\320\236\320\224", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthRegForm: public Ui_AuthRegForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHREGFORM_H
