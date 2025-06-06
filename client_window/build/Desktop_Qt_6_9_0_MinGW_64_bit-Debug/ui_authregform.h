/********************************************************************************
** Form generated from reading UI file 'authregform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHREGFORM_H
#define UI_AUTHREGFORM_H

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

class Ui_AuthRegForm
{
public:
    QLabel *labelLogin_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelLogin;
    QLabel *labelPassword;
    QFormLayout *formLayout;
    QLineEdit *lineEditLogin;
    QLineEdit *lineEditPassword;
    QPushButton *pushButtonReg;
    QPushButton *pushButtonAuth;
    QPushButton *pushButtonForgotPassword;

    void setupUi(QDialog *AuthRegForm)
    {
        if (AuthRegForm->objectName().isEmpty())
            AuthRegForm->setObjectName("AuthRegForm");
        AuthRegForm->resize(1000, 600);
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
        AuthRegForm->setPalette(palette);
        QFont font;
        font.setFamilies({QString::fromUtf8("Gilroy")});
        font.setPointSize(22);
        font.setBold(false);
        AuthRegForm->setFont(font);
        labelLogin_2 = new QLabel(AuthRegForm);
        labelLogin_2->setObjectName("labelLogin_2");
        labelLogin_2->setGeometry(QRect(280, 20, 450, 78));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelLogin_2->sizePolicy().hasHeightForWidth());
        labelLogin_2->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Gilroy")});
        font1.setPointSize(22);
        font1.setBold(true);
        labelLogin_2->setFont(font1);
        layoutWidget = new QWidget(AuthRegForm);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(300, 240, 403, 175));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        horizontalLayout->setContentsMargins(-1, -1, 0, -1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(-1, -1, 15, 0);
        labelLogin = new QLabel(layoutWidget);
        labelLogin->setObjectName("labelLogin");
        sizePolicy.setHeightForWidth(labelLogin->sizePolicy().hasHeightForWidth());
        labelLogin->setSizePolicy(sizePolicy);
        labelLogin->setFont(font1);

        verticalLayout_2->addWidget(labelLogin);

        labelPassword = new QLabel(layoutWidget);
        labelPassword->setObjectName("labelPassword");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(6);
        sizePolicy1.setHeightForWidth(labelPassword->sizePolicy().hasHeightForWidth());
        labelPassword->setSizePolicy(sizePolicy1);
        labelPassword->setFont(font1);

        verticalLayout_2->addWidget(labelPassword);


        horizontalLayout->addLayout(verticalLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldGrowthPolicy::AllNonFixedFieldsGrow);
        formLayout->setRowWrapPolicy(QFormLayout::RowWrapPolicy::WrapAllRows);
        formLayout->setVerticalSpacing(12);
        formLayout->setContentsMargins(0, -1, 0, -1);
        lineEditLogin = new QLineEdit(layoutWidget);
        lineEditLogin->setObjectName("lineEditLogin");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEditLogin->sizePolicy().hasHeightForWidth());
        lineEditLogin->setSizePolicy(sizePolicy2);
        lineEditLogin->setSizeIncrement(QSize(0, 0));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Gilroy")});
        font2.setPointSize(22);
        font2.setBold(false);
        font2.setStrikeOut(false);
        lineEditLogin->setFont(font2);

        formLayout->setWidget(0, QFormLayout::ItemRole::SpanningRole, lineEditLogin);

        lineEditPassword = new QLineEdit(layoutWidget);
        lineEditPassword->setObjectName("lineEditPassword");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEditPassword->sizePolicy().hasHeightForWidth());
        lineEditPassword->setSizePolicy(sizePolicy3);
        lineEditPassword->setMinimumSize(QSize(0, 0));
        lineEditPassword->setSizeIncrement(QSize(0, 0));
        lineEditPassword->setFont(font2);
        lineEditPassword->setMouseTracking(true);
        lineEditPassword->setCursorMoveStyle(Qt::CursorMoveStyle::VisualMoveStyle);

        formLayout->setWidget(1, QFormLayout::ItemRole::SpanningRole, lineEditPassword);


        horizontalLayout->addLayout(formLayout);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        pushButtonReg = new QPushButton(layoutWidget);
        pushButtonReg->setObjectName("pushButtonReg");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Gilroy")});
        font3.setPointSize(11);
        font3.setBold(true);
        pushButtonReg->setFont(font3);

        gridLayout->addWidget(pushButtonReg, 2, 0, 1, 1);

        pushButtonAuth = new QPushButton(layoutWidget);
        pushButtonAuth->setObjectName("pushButtonAuth");
        QPalette palette1;
        QBrush brush3(QColor(255, 255, 255, 255));
        brush3.setStyle(Qt::BrushStyle::SolidPattern);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush3);
        QBrush brush4(QColor(70, 68, 86, 255));
        brush4.setStyle(Qt::BrushStyle::SolidPattern);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush4);
        QBrush brush5(QColor(79, 66, 82, 255));
        brush5.setStyle(Qt::BrushStyle::SolidPattern);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Highlight, brush5);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush3);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush4);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Highlight, brush5);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush4);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush4);
        pushButtonAuth->setPalette(palette1);
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Gilroy")});
        font4.setPointSize(18);
        font4.setBold(true);
        pushButtonAuth->setFont(font4);

        gridLayout->addWidget(pushButtonAuth, 1, 0, 1, 2);

        pushButtonForgotPassword = new QPushButton(layoutWidget);
        pushButtonForgotPassword->setObjectName("pushButtonForgotPassword");
        pushButtonForgotPassword->setFont(font3);

        gridLayout->addWidget(pushButtonForgotPassword, 2, 1, 1, 1);


        retranslateUi(AuthRegForm);

        QMetaObject::connectSlotsByName(AuthRegForm);
    } // setupUi

    void retranslateUi(QDialog *AuthRegForm)
    {
        AuthRegForm->setWindowTitle(QCoreApplication::translate("AuthRegForm", "Dialog", nullptr));
        labelLogin_2->setText(QCoreApplication::translate("AuthRegForm", "<html><head/><body><p><span style=\" font-size:48pt;\">\320\220\320\222\320\242\320\236\320\240\320\230\320\227\320\220\320\246\320\230\320\257</span></p></body></html>", nullptr));
        labelLogin->setText(QCoreApplication::translate("AuthRegForm", "<html><head/><body><p><span style=\" color:#593e45;\">\320\233\320\236\320\223\320\230\320\235</span></p></body></html>", nullptr));
        labelPassword->setText(QCoreApplication::translate("AuthRegForm", "<html><head/><body><p><span style=\" color:#593e45;\">\320\237\320\220\320\240\320\236\320\233\320\254</span></p></body></html>", nullptr));
        lineEditLogin->setText(QString());
        lineEditPassword->setText(QString());
        pushButtonReg->setText(QCoreApplication::translate("AuthRegForm", "\320\240\320\225\320\223\320\230\320\241\320\242\320\240\320\220\320\246\320\230\320\257", nullptr));
        pushButtonAuth->setText(QCoreApplication::translate("AuthRegForm", "\320\222\320\245\320\236\320\224", nullptr));
        pushButtonForgotPassword->setText(QCoreApplication::translate("AuthRegForm", "\320\235\320\225 \320\234\320\236\320\226\320\225\320\242\320\225 \320\222\320\236\320\231\320\242\320\230?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthRegForm: public Ui_AuthRegForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHREGFORM_H
