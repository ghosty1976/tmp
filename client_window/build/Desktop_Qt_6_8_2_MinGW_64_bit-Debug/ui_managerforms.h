/********************************************************************************
** Form generated from reading UI file 'managerforms.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERFORMS_H
#define UI_MANAGERFORMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthRegForms
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AuthRegForms)
    {
        if (AuthRegForms->objectName().isEmpty())
            AuthRegForms->setObjectName("AuthRegForms");
        AuthRegForms->resize(800, 600);
        centralwidget = new QWidget(AuthRegForms);
        centralwidget->setObjectName("centralwidget");
        AuthRegForms->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AuthRegForms);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        AuthRegForms->setMenuBar(menubar);
        statusbar = new QStatusBar(AuthRegForms);
        statusbar->setObjectName("statusbar");
        AuthRegForms->setStatusBar(statusbar);

        retranslateUi(AuthRegForms);

        QMetaObject::connectSlotsByName(AuthRegForms);
    } // setupUi

    void retranslateUi(QMainWindow *AuthRegForms)
    {
        AuthRegForms->setWindowTitle(QCoreApplication::translate("AuthRegForms", "AuthRegForms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthRegForms: public Ui_AuthRegForms {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERFORMS_H
