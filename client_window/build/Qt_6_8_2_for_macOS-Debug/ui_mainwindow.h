/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButtonSolve;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLineEdit *lineEditInterval;
    QLabel *labelMethod;
    QComboBox *comboBoxMethod;
    QLabel *labelInterval;
    QLineEdit *lineEditFunction;
    QLabel *labelFunction;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(822, 399);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButtonSolve = new QPushButton(centralwidget);
        pushButtonSolve->setObjectName("pushButtonSolve");
        pushButtonSolve->setGeometry(QRect(60, 250, 281, 41));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(50, 130, 301, 101));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        lineEditInterval = new QLineEdit(formLayoutWidget);
        lineEditInterval->setObjectName("lineEditInterval");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditInterval);

        labelMethod = new QLabel(formLayoutWidget);
        labelMethod->setObjectName("labelMethod");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelMethod);

        comboBoxMethod = new QComboBox(formLayoutWidget);
        comboBoxMethod->setObjectName("comboBoxMethod");

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBoxMethod);

        labelInterval = new QLabel(formLayoutWidget);
        labelInterval->setObjectName("labelInterval");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelInterval);

        lineEditFunction = new QLineEdit(formLayoutWidget);
        lineEditFunction->setObjectName("lineEditFunction");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditFunction);

        labelFunction = new QLabel(formLayoutWidget);
        labelFunction->setObjectName("labelFunction");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelFunction);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonSolve->setText(QCoreApplication::translate("MainWindow", "\320\240\320\225\320\250\320\230\320\242\320\254", nullptr));
        labelMethod->setText(QCoreApplication::translate("MainWindow", " \320\234\320\265\321\202\320\276\320\264:                ", nullptr));
        labelInterval->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\200\320\265\320\267\320\276\320\272 [a, b]:   ", nullptr));
        labelFunction->setText(QCoreApplication::translate("MainWindow", "\320\244\321\203\320\275\320\272\321\206\320\270\321\217 f(x):     ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
