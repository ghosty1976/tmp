/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *labelFunction_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelFunction;
    QLineEdit *lineEditFunction;
    QLabel *labelInterval;
    QLineEdit *lineEditInterval;
    QLabel *labelMethod;
    QComboBox *comboBoxMethod;
    QLabel *labelTolerance;
    QLineEdit *lineEditTolerance;
    QLineEdit *lineEditMaxIterations;
    QLabel *labelMaxIterations;
    QPushButton *pushButtonSolve;
    QTextBrowser *textBrowser;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 600);
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
        MainWindow->setPalette(palette);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        labelFunction_2 = new QLabel(centralwidget);
        labelFunction_2->setObjectName("labelFunction_2");
        labelFunction_2->setGeometry(QRect(0, 30, 1001, 78));
        QFont font;
        font.setFamilies({QString::fromUtf8("Gilroy")});
        font.setPointSize(28);
        font.setBold(true);
        labelFunction_2->setFont(font);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(15, 180, 481, 283));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelFunction = new QLabel(layoutWidget);
        labelFunction->setObjectName("labelFunction");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Gilroy")});
        font1.setPointSize(22);
        font1.setBold(true);
        labelFunction->setFont(font1);

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelFunction);

        lineEditFunction = new QLineEdit(layoutWidget);
        lineEditFunction->setObjectName("lineEditFunction");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Gilroy")});
        font2.setPointSize(22);
        lineEditFunction->setFont(font2);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEditFunction);

        labelInterval = new QLabel(layoutWidget);
        labelInterval->setObjectName("labelInterval");
        labelInterval->setFont(font1);

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelInterval);

        lineEditInterval = new QLineEdit(layoutWidget);
        lineEditInterval->setObjectName("lineEditInterval");
        lineEditInterval->setFont(font2);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEditInterval);

        labelMethod = new QLabel(layoutWidget);
        labelMethod->setObjectName("labelMethod");
        labelMethod->setFont(font1);

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelMethod);

        comboBoxMethod = new QComboBox(layoutWidget);
        comboBoxMethod->setObjectName("comboBoxMethod");
        comboBoxMethod->setFont(font2);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, comboBoxMethod);

        labelTolerance = new QLabel(layoutWidget);
        labelTolerance->setObjectName("labelTolerance");
        labelTolerance->setFont(font1);

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, labelTolerance);

        lineEditTolerance = new QLineEdit(layoutWidget);
        lineEditTolerance->setObjectName("lineEditTolerance");
        lineEditTolerance->setFont(font2);

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, lineEditTolerance);

        lineEditMaxIterations = new QLineEdit(layoutWidget);
        lineEditMaxIterations->setObjectName("lineEditMaxIterations");
        lineEditMaxIterations->setFont(font2);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, lineEditMaxIterations);

        labelMaxIterations = new QLabel(layoutWidget);
        labelMaxIterations->setObjectName("labelMaxIterations");
        labelMaxIterations->setFont(font1);

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, labelMaxIterations);


        verticalLayout->addLayout(formLayout);

        pushButtonSolve = new QPushButton(layoutWidget);
        pushButtonSolve->setObjectName("pushButtonSolve");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Gilroy")});
        font3.setPointSize(18);
        font3.setBold(true);
        pushButtonSolve->setFont(font3);

        verticalLayout->addWidget(pushButtonSolve);

        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(560, 180, 421, 281));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelFunction_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">\320\235\320\220\320\245\320\236\320\226\320\224\320\225\320\235\320\230\320\225 \320\232\320\236\320\240\320\235\320\257 \320\244\320\243\320\235\320\232\320\246\320\230\320\230 </span></p></body></html>", nullptr));
        labelFunction->setText(QCoreApplication::translate("MainWindow", "\320\244\321\203\320\275\320\272\321\206\320\270\321\217 f(x):     ", nullptr));
        labelInterval->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\200\320\265\320\267\320\276\320\272 [a, b]:   ", nullptr));
        labelMethod->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264:", nullptr));
        labelTolerance->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214:", nullptr));
        labelMaxIterations->setText(QCoreApplication::translate("MainWindow", "\320\247\320\270\321\201\320\273\320\276 \320\270\321\202\320\265\321\200\320\260\321\206\320\270\320\271:", nullptr));
        pushButtonSolve->setText(QCoreApplication::translate("MainWindow", "\320\240\320\225\320\250\320\230\320\242\320\254", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><title>\320\240\321\203\320\272\320\276\320\262\320\276\320\264\321\201\321\202\320\262\320\276 \320\277\320\276 \321\200\320\265\321\210\320\265\320\275\320\270\321\216 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\271</title><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\" bgcolor=\"#f8f9fa\">\n"
"<h1 align=\"center\" style=\" margin-top:30px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-size:xx-l"
                        "arge; font-weight:700; color:#2c3e50;\">\320\240\320\265\321\210\320\265\320\275\320\270\320\265 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\271 \320\262 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-size:xx-large; font-weight:700; color:#333333;\"> </span></h1>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\">\320\255\321\202\320\260 \320\270\320\275\321\201\321\202\321\200\321\203\320\272\321\206\320\270\321\217 \320\277\320\276\320\274\320\276\320\266\320\265\321\202 \320\262\320\260\320\274 \320\277\321\200\320\260\320\262\320\270\320\273\321\214\320\275\320\276 \320\262\320\262\320\276\320\264\320\270\321\202\321\214 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320"
                        "\270\321\217 \320\270 \320\277\320\276\320\275\320\270\320\274\320\260\321\202\321\214 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213 \320\270\321\205 \321\200\320\265\321\210\320\265\320\275\320\270\321\217. </span></p>\n"
"<h2 style=\" margin-top:30px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#ffffff;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-size:x-large; font-weight:700; color:#2c3e50; background-color:#ffffff;\">\320\232\320\260\320\272 \320\262\320\262\320\276\320\264\320\270\321\202\321\214 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\321\217</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-size:x-large; font-weight:700; color:#333333;\"> </span></h2>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; li"
                        "ne-height:160%; background-color:#ffffff;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\">\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \321\200\320\265\321\210\320\260\320\265\321\202 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\321\217 \320\262\320\270\320\264\320\260 </span><span style=\" font-family:'Courier New','monospace'; color:#333333; background-color:#eeeeee;\">f(x) = 0</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\">. \320\224\320\273\321\217 \321\200\320\265\321\210\320\265\320\275\320\270\321\217 \320\262\320\260\320\274 \320\275\321\203\320\266\320\275\320\276: </span></p>\n"
"<ol style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\">\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\" style=\" marg"
                        "in-top:12px; margin-bottom:0px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">\320\222\320\262\320\265\321\201\321\202\320\270 \321\204\321\203\320\275\320\272\321\206\320\270\321\216 <span style=\" font-family:'Courier New','monospace'; background-color:#eeeeee;\">f(x)</span> </li>\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">\320\243\320\272\320\260\320\267\320\260\321\202\321\214 \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273 \320\277\320\276\320\270\321\201\320\272\320\260 \320\272\320\276\321\200\320\275\321\217 <span style=\" font-family:'Courier New','monospace'; background-color:#eeeeee;\">[a, b]</span> </li>\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#f"
                        "fffff;\" style=\" margin-top:0px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\274\320\265\321\202\320\276\320\264 \321\200\320\265\321\210\320\265\320\275\320\270\321\217 </li></ol>\n"
"<h2 style=\" margin-top:30px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-size:x-large; font-weight:700; color:#2c3e50;\">1. \320\244\320\276\321\200\320\274\320\260\321\202 \321\204\321\203\320\275\320\272\321\206\320\270\320\270</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-size:x-large; font-weight:700; color:#333333;\"> </span></h2>\n"
"<p style=\" margin-top:20px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#fffff"
                        "f;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#333333;\">\342\234\205 \320\237\321\200\320\260\320\262\320\270\320\273\321\214\320\275\321\213\320\271 \320\262\320\262\320\276\320\264:</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\">\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">\320\230\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\271\321\202\320\265 \321\202\320\276\320\273\321\214\320\272\320\276 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\203\321\216 <span style=\" font-family:'Courier New','monospace'; background-c"
                        "olor:#eeeeee;\">x</span> </li>\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">\320\224\320\276\320\277\321\203\321\201\321\202\320\270\320\274\321\213\320\265 \320\276\320\277\320\265\321\200\320\260\321\202\320\276\321\200\321\213: <span style=\" font-family:'Courier New','monospace'; background-color:#eeeeee;\">+</span>, <span style=\" font-family:'Courier New','monospace'; background-color:#eeeeee;\">-</span>, <span style=\" font-family:'Courier New','monospace'; background-color:#eeeeee;\">*</span>, <span style=\" font-family:'Courier New','monospace'; background-color:#eeeeee;\">/</span>, <span style=\" font-family:'Courier New','monospace'; background-color:#eeeeee;\">^</span> </li>\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-col"
                        "or:#ffffff;\" style=\" margin-top:0px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">\320\224\320\276\320\277\321\203\321\201\321\202\320\270\320\274\321\213\320\265 \321\204\321\203\320\275\320\272\321\206\320\270\320\270: \n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 2;\">\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:148px; margin-right:148px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Courier New','monospace'; background-color:#eeeeee;\">sin(x)</span>, <span style=\" font-family:'Courier New','monospace'; background-color:#eeeeee;\">cos(x)</span>, <span style=\" font-family:'Courier New','monospace'; background-color:#eeeeee;\">tan(x)</span> </li>\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva',"
                        "'Verdana','sans-serif'; color:#333333; background-color:#ffffff;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:148px; margin-right:148px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Courier New','monospace'; background-color:#eeeeee;\">exp(x)</span> (\321\215\320\272\321\201\320\277\320\276\320\275\320\265\320\275\321\202\320\260) </li>\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:148px; margin-right:148px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Courier New','monospace'; background-color:#eeeeee;\">log(x)</span> (\320\275\320\260\321\202\321\203\321\200\320\260\320\273\321\214\320\275\321\213\320\271 \320\273\320\276\320\263\320\260\321\200\320\270\321\204\320\274) </li>\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-co"
                        "lor:#ffffff;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:148px; margin-right:148px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Courier New','monospace'; background-color:#eeeeee;\">abs(x)</span> (\320\274\320\276\320\264\321\203\320\273\321\214) </li></ul></li></ul>\n"
"<p style=\" margin-top:20px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#ffffff;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#333333;\">\342\235\214 \320\235\320\265\320\277\321\200\320\260\320\262\320\270\320\273\321\214\320\275\321\213\320\271 \320\262\320\262\320\276\320\264:</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\">\n"
"<li style=\" font-family:'Segoe UI','T"
                        "ahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">\320\224\321\200\321\203\320\263\320\270\320\265 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\213\320\265 \320\272\321\200\320\276\320\274\320\265 <span style=\" font-family:'Courier New','monospace'; background-color:#eeeeee;\">x</span> </li>\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">\320\241\320\270\320\274\320\262\320\276\320\273\321\213: <span style=\" font-family:'Courier New','monospace'; background-color:#eeeeee;\">|x|</span> (\320\262\320\274\320\265\321\201\321\202\320\276 \321\215\321\202\320\276\320\263\320\276 \320\270\321\201\320\277\320\276"
                        "\320\273\321\214\320\267\321\203\320\271\321\202\320\265 <span style=\" font-family:'Courier New','monospace'; background-color:#eeeeee;\">abs(x)</span>) </li>\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">\320\224\320\262\320\276\320\271\320\275\321\213\320\265 \320\267\320\262\320\265\320\267\320\264\320\276\321\207\320\272\320\270: <span style=\" font-family:'Courier New','monospace'; background-color:#eeeeee;\">x**2</span> (\320\262\320\274\320\265\321\201\321\202\320\276 \321\215\321\202\320\276\320\263\320\276 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\271\321\202\320\265 <span style=\" font-family:'Courier New','monospace'; background-color:#eeeeee;\">x^2</span>) </li>\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; "
                        "background-color:#ffffff;\" style=\" margin-top:0px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">\320\235\320\265\321\217\320\262\320\275\321\213\320\265 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\321\217: <span style=\" font-family:'Courier New','monospace'; background-color:#eeeeee;\">x = cos(x)</span> </li></ul>\n"
"<h2 style=\" margin-top:30px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-size:x-large; font-weight:700; color:#2c3e50;\">2. \320\230\320\275\321\202\320\265\321\200\320\262\320\260\320\273 \320\277\320\276\320\270\321\201\320\272\320\260 [a, b]</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-size:x-large; font-weight:700; color:#333333;\"> </span></h2>\n"
"<p style=\" margin-top:20px; margin-bottom:12px; margi"
                        "n-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#ffffff;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\">\320\230\320\275\321\202\320\265\321\200\320\262\320\260\320\273 \320\264\320\276\320\273\320\266\320\265\320\275 \321\203\320\264\320\276\320\262\320\273\320\265\321\202\320\262\320\276\321\200\321\217\321\202\321\214 \321\203\321\201\320\273\320\276\320\262\320\270\321\217\320\274:</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\">\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span sty"
                        "le=\" font-family:'Courier New','monospace'; background-color:#eeeeee;\">a &lt; b</span> (\320\273\320\265\320\262\320\260\321\217 \320\263\321\200\320\260\320\275\320\270\321\206\320\260 \320\274\320\265\320\275\321\214\321\210\320\265 \320\277\321\200\320\260\320\262\320\276\320\271) </li>\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">\320\244\321\203\320\275\320\272\321\206\320\270\321\217 \320\264\320\276\320\273\320\266\320\275\320\260 \320\274\320\265\320\275\321\217\321\202\321\214 \320\267\320\275\320\260\320\272 \320\275\320\260 \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273\320\265: <span style=\" font-family:'Courier New','monospace'; background-color:#eeeeee;\">f(a) * f(b) &lt; 0</span> </li>\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-se"
                        "rif'; color:#333333; background-color:#ffffff;\" style=\" margin-top:0px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">\320\244\321\203\320\275\320\272\321\206\320\270\321\217 \320\264\320\276\320\273\320\266\320\275\320\260 \320\261\321\213\321\202\321\214 \320\275\320\265\320\277\321\200\320\265\321\200\321\213\320\262\320\275\320\276\320\271 \320\275\320\260 \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273\320\265 </li></ul>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#ffffff;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#333333;\">\320\237\321\200\320\270\320\274\320\265\321\200 \320\277\321\200\320\260\320\262\320\270\320\273\321\214\320\275\320\276\320\263\320\276 \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273\320\260:</span><sp"
                        "an style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span><span style=\" font-family:'Courier New','monospace'; color:#333333; background-color:#eeeeee;\">1,2</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> \320\270\320\273\320\270 </span><span style=\" font-family:'Courier New','monospace'; color:#333333; background-color:#eeeeee;\">-1.5, 3.2</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span></p>\n"
"<h2 style=\" margin-top:30px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-size:x-large; font-weight:700; color:#2c3e50;\">3. \320\234\320\265\321\202\320\276\320\264\321\213 \321\200\320\265\321\210\320\265\320\275\320\270\321\217</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','"
                        "sans-serif'; font-size:x-large; font-weight:700; color:#333333;\"> </span></h2>\n"
"<table border=\"0\" style=\" margin-top:20px; margin-bottom:20px; margin-left:37px; margin-right:37px; border-collapse:collapse;\" cellspacing=\"2\" cellpadding=\"0\">\n"
"<tr>\n"
"<td bgcolor=\"#e3f2fd\" style=\" padding-left:12; padding-right:12; padding-top:12; padding-bottom:12; border-top:1px; border-right:1px; border-bottom:1px; border-left:1px; border-top-color:#dddddd; border-right-color:#dddddd; border-bottom-color:#dddddd; border-left-color:#dddddd; border-top-style:solid; border-right-style:solid; border-bottom-style:solid; border-left-style:solid;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#e3f2fd;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:600; color:#333333; background-color:#e3f2fd;\">\320\234\320\265\321\202\320\276\320\264</span></p></td>\n"
"<t"
                        "d bgcolor=\"#e3f2fd\" style=\" padding-left:12; padding-right:12; padding-top:12; padding-bottom:12; border-top:1px; border-right:1px; border-bottom:1px; border-left:1px; border-top-color:#dddddd; border-right-color:#dddddd; border-bottom-color:#dddddd; border-left-color:#dddddd; border-top-style:solid; border-right-style:solid; border-bottom-style:solid; border-left-style:solid;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#e3f2fd;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:600; color:#333333; background-color:#e3f2fd;\">\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265</span></p></td>\n"
"<td bgcolor=\"#e3f2fd\" style=\" padding-left:12; padding-right:12; padding-top:12; padding-bottom:12; border-top:1px; border-right:1px; border-bottom:1px; border-left:1px; border-top-color:#dddddd; border-right-color:#dddddd; border-bottom-colo"
                        "r:#dddddd; border-left-color:#dddddd; border-top-style:solid; border-right-style:solid; border-bottom-style:solid; border-left-style:solid;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#e3f2fd;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:600; color:#333333; background-color:#e3f2fd;\">\320\232\320\276\320\263\320\264\320\260 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\321\214</span></p></td></tr>\n"
"<tr>\n"
"<td style=\" padding-left:12; padding-right:12; padding-top:12; padding-bottom:12; border-top:1px; border-right:1px; border-bottom:1px; border-left:1px; border-top-color:#dddddd; border-right-color:#dddddd; border-bottom-color:#dddddd; border-left-color:#dddddd; border-top-style:solid; border-right-style:solid; border-bottom-style:solid; border-left-style:solid;\">\n"
"<p style=\" margin-top:0px; m"
                        "argin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#333333;\">\320\224\320\270\321\205\320\276\321\202\320\276\320\274\320\270\321\217</span></p></td>\n"
"<td style=\" padding-left:12; padding-right:12; padding-top:12; padding-bottom:12; border-top:1px; border-right:1px; border-bottom:1px; border-left:1px; border-top-color:#dddddd; border-right-color:#dddddd; border-bottom-color:#dddddd; border-left-color:#dddddd; border-top-style:solid; border-right-style:solid; border-bottom-style:solid; border-left-style:solid;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\">\320\224\320\265\320\273\320\270\321\202 \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320"
                        "\273 \320\277\320\276\320\277\320\276\320\273\320\260\320\274 \320\275\320\260 \320\272\320\260\320\266\320\264\320\276\320\274 \321\210\320\260\320\263\320\265</span></p></td>\n"
"<td style=\" padding-left:12; padding-right:12; padding-top:12; padding-bottom:12; border-top:1px; border-right:1px; border-bottom:1px; border-left:1px; border-top-color:#dddddd; border-right-color:#dddddd; border-bottom-color:#dddddd; border-left-color:#dddddd; border-top-style:solid; border-right-style:solid; border-bottom-style:solid; border-left-style:solid;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\">\320\224\320\273\321\217 \320\273\321\216\320\261\321\213\321\205 \320\275\320\265\320\277\321\200\320\265\321\200\321\213\320\262\320\275\321\213\321\205 \321\204\321\203\320\275\320\272\321\206\320\270\320\271, \321\201\320\260\320\274"
                        "\321\213\320\271 \320\275\320\260\320\264\320\265\320\266\320\275\321\213\320\271 \320\274\320\265\321\202\320\276\320\264</span></p></td></tr>\n"
"<tr>\n"
"<td style=\" padding-left:12; padding-right:12; padding-top:12; padding-bottom:12; border-top:1px; border-right:1px; border-bottom:1px; border-left:1px; border-top-color:#dddddd; border-right-color:#dddddd; border-bottom-color:#dddddd; border-left-color:#dddddd; border-top-style:solid; border-right-style:solid; border-bottom-style:solid; border-left-style:solid;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#333333;\">\320\230\321\202\320\265\321\200\320\260\321\206\320\270\321\217</span></p></td>\n"
"<td style=\" padding-left:12; padding-right:12; padding-top:12; padding-bottom:12; border-top:1px; border-right:1px; border-bottom:1px; border-left:1px; borde"
                        "r-top-color:#dddddd; border-right-color:#dddddd; border-bottom-color:#dddddd; border-left-color:#dddddd; border-top-style:solid; border-right-style:solid; border-bottom-style:solid; border-left-style:solid;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\">\320\230\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\265\321\202 \320\277\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \320\277\321\200\320\270\320\261\320\273\320\270\320\266\320\265\320\275\320\270\321\217</span></p></td>\n"
"<td style=\" padding-left:12; padding-right:12; padding-top:12; padding-bottom:12; border-top:1px; border-right:1px; border-bottom:1px; border-left:1px; border-top-color:#dddddd; border-right-color:#dddddd; border-bottom-color:#dddddd; border-left-color:#d"
                        "ddddd; border-top-style:solid; border-right-style:solid; border-bottom-style:solid; border-left-style:solid;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\">\320\224\320\273\321\217 \321\204\321\203\320\275\320\272\321\206\320\270\320\271 \321\201 \321\205\320\276\321\200\320\276\321\210\320\265\320\271 \321\201\321\205\320\276\320\264\320\270\320\274\320\276\321\201\321\202\321\214\321\216, \321\200\320\260\320\261\320\276\321\202\320\260\320\265\321\202 \320\261\321\213\321\201\321\202\321\200\320\265\320\265</span></p></td></tr></table>\n"
"<h2 style=\" margin-top:30px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-size:x-large; font-weight:700; color:#2c3e50;\">4. "
                        "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\202\320\276\321\207\320\275\320\276\321\201\321\202\320\270</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-size:x-large; font-weight:700; color:#333333;\"> </span></h2>\n"
"<p style=\" margin-top:20px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#fff8e1;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#fff8e1;\">\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\265\321\202 \320\276\320\277\321\202\320\270\320\274\320\260\320\273\321\214\320\275\321\213\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \321\202\320\276\321\207\320\275\320\276\321\201\321\202\320\270 \320\277\320\276 \321\203\320\274\320\276\320\273\321\207"
                        "\320\260\320\275\320\270\321\216:</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span></p>\n"
"<p style=\" margin-top:20px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#ffffff;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#333333;\">\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214: 0.0001</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#ffffff;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\">\320\255\321\202\320\276 \320\274\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275"
                        "\320\260\321\217 \320\264\320\276\320\277\321\203\321\201\321\202\320\270\320\274\320\260\321\217 \320\277\320\276\320\263\321\200\320\265\321\210\320\275\320\276\321\201\321\202\321\214 \321\200\320\265\321\210\320\265\320\275\320\270\321\217. \320\247\320\265\320\274 \320\274\320\265\320\275\321\214\321\210\320\265 \321\215\321\202\320\276 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265, \321\202\320\265\320\274 \321\202\320\276\321\207\320\275\320\265\320\265 \320\261\321\203\320\264\320\265\321\202 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202, \320\275\320\276 \321\202\320\265\320\274 \320\261\320\276\320\273\321\214\321\210\320\265 \320\262\321\200\320\265\320\274\320\265\320\275\320\270 \320\267\320\260\320\271\320\274\320\265\321\202 \320\262\321\213\321\207\320\270\321\201\320\273\320\265\320\275\320\270\320\265.</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span></p>\n"
"<p style=\" margin-top:12px"
                        "; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#ffffff;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-style:italic; color:#333333;\">\320\237\320\276\321\207\320\265\320\274\321\203 0.0001?</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> \320\255\321\202\320\276 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\276\320\261\320\265\321\201\320\277\320\265\321\207\320\270\320\262\320\260\320\265\321\202 \320\261\320\260\320\273\320\260\320\275\321\201 \320\274\320\265\320\266\320\264\321\203 \321\202\320\276\321\207\320\275\320\276\321\201\321\202\321\214\321\216 \320\270 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214\321\216 \320\262\321\213\321\207\320\270\321\201\320\273\320\265\320\275\320\270\320\271 \320\264\320\273\321\217 \320\261\320\276\320\273\321\214\321\210\320\270\320\275\321\201\321"
                        "\202\320\262\320\260 \320\277\321\200\320\260\320\272\321\202\320\270\321\207\320\265\321\201\320\272\320\270\321\205 \320\267\320\260\320\264\320\260\321\207. </span></p>\n"
"<p style=\" margin-top:20px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#ffffff;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#333333;\">\320\234\320\260\320\272\321\201\320\270\320\274\321\203\320\274 \320\270\321\202\320\265\321\200\320\260\321\206\320\270\320\271: 100</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#ffffff;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\">\320\255\321\202\320"
                        "\276 \320\274\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\210\320\260\320\263\320\276\320\262, \320\272\320\276\321\202\320\276\321\200\321\213\320\265 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \321\201\320\264\320\265\320\273\320\260\320\265\321\202 \320\262 \320\277\320\276\320\270\321\201\320\272\320\260\321\205 \321\200\320\265\321\210\320\265\320\275\320\270\321\217.</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#ffffff;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-style:italic; color:#333333;\">\320\237\320\276\321\207\320\265\320\274\321\203 100?</span><span style=\" font-fami"
                        "ly:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> \320\224\320\273\321\217 \320\261\320\276\320\273\321\214\321\210\320\270\320\275\321\201\321\202\320\262\320\260 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\271 \321\215\321\202\320\276\320\263\320\276 \320\264\320\276\321\201\321\202\320\260\321\202\320\276\321\207\320\275\320\276 \321\207\321\202\320\276\320\261\321\213 \320\264\320\276\321\201\321\202\320\270\321\207\321\214 \320\267\320\260\320\264\320\260\320\275\320\275\320\276\320\271 \321\202\320\276\321\207\320\275\320\276\321\201\321\202\320\270. \320\225\321\201\320\273\320\270 \321\200\320\265\321\210\320\265\320\275\320\270\320\265 \320\275\320\265 \320\275\320\260\320\271\320\264\320\265\320\275\320\276 \320\267\320\260 100 \321\210\320\260\320\263\320\276\320\262, \320\262\320\265\321\200\320\276\321\217\321\202\320\275\320\276, \320\265\320\263\320\276 \320\275\320\265\321\202 \320\275\320\260 \321\215\321\202\320\276\320\274 \320\270\320\275\321"
                        "\202\320\265\321\200\320\262\320\260\320\273\320\265 \320\270\320\273\320\270 \320\262\321\213\320\261\321\200\320\260\320\275\321\213 \320\275\320\265\320\277\320\276\320\264\321\205\320\276\320\264\321\217\321\211\320\270\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213. </span></p>\n"
"<h2 style=\" margin-top:30px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-size:x-large; font-weight:700; color:#2c3e50;\">5. \320\237\321\200\320\270\320\274\320\265\321\200\321\213 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\271</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-size:x-large; font-weight:700; color:#333333;\"> </span></h2>\n"
"<p style=\" margin-top:15px; margin-bottom:0px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:16"
                        "0%; background-color:#e8f5e9;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#2c3e50; background-color:#e8f5e9;\">\320\237\321\200\320\270\320\274\320\265\321\200 1: \320\237\321\200\320\276\321\201\321\202\320\276\320\265 \320\272\320\262\320\260\320\264\321\200\320\260\321\202\320\275\320\276\320\265 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#e8f5e9;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#333333;\">\320\243\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265:</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> x\302\262"
                        " - 4 = 0 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#e8f5e9;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#333333;\">\320\244\321\203\320\275\320\272\321\206\320\270\321\217:</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span><span style=\" font-family:'Courier New','monospace'; color:#333333; background-color:#eeeeee;\">x^2 - 4</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#e8f5e9;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#333333;\">\320\230\320\275\321\202\320\265\321\200"
                        "\320\262\320\260\320\273:</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span><span style=\" font-family:'Courier New','monospace'; color:#333333; background-color:#eeeeee;\">1,3</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#e8f5e9;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#333333;\">\320\236\320\266\320\270\320\264\320\260\320\265\320\274\320\276\320\265 \321\200\320\265\321\210\320\265\320\275\320\270\320\265:</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> x \342\211\210 2.000 </span></p>\n"
"<p style=\" margin-top:15px; margin-bottom:0px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-in"
                        "dent:0px; line-height:160%; background-color:#e8f5e9;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#2c3e50; background-color:#e8f5e9;\">\320\237\321\200\320\270\320\274\320\265\321\200 2: \320\242\321\200\320\270\320\263\320\276\320\275\320\276\320\274\320\265\321\202\321\200\320\270\321\207\320\265\321\201\320\272\320\276\320\265 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#e8f5e9;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#333333;\">\320\243\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265:</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-seri"
                        "f'; color:#333333;\"> sin(x) = 0.5 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#e8f5e9;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#333333;\">\320\244\321\203\320\275\320\272\321\206\320\270\321\217:</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span><span style=\" font-family:'Courier New','monospace'; color:#333333; background-color:#eeeeee;\">sin(x) - 0.5</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#e8f5e9;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#333333;\">\320\230\320"
                        "\275\321\202\320\265\321\200\320\262\320\260\320\273:</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span><span style=\" font-family:'Courier New','monospace'; color:#333333; background-color:#eeeeee;\">0,1</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#e8f5e9;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#333333;\">\320\236\320\266\320\270\320\264\320\260\320\265\320\274\320\276\320\265 \321\200\320\265\321\210\320\265\320\275\320\270\320\265:</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> x \342\211\210 0.5236 (\317\200/6) </span></p>\n"
"<p style=\" margin-top:15px; margin-bottom:0px; margin-left:37px; marg"
                        "in-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#e8f5e9;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#2c3e50; background-color:#e8f5e9;\">\320\237\321\200\320\270\320\274\320\265\321\200 3: \320\255\320\272\321\201\320\277\320\276\320\275\320\265\320\275\321\206\320\270\320\260\320\273\321\214\320\275\320\276\320\265 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#e8f5e9;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#333333;\">\320\243\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265:</span><span style=\" font-family:'Segoe UI','Tahoma','Ge"
                        "neva','Verdana','sans-serif'; color:#333333;\"> e\313\243 = 10 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#e8f5e9;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#333333;\">\320\244\321\203\320\275\320\272\321\206\320\270\321\217:</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span><span style=\" font-family:'Courier New','monospace'; color:#333333; background-color:#eeeeee;\">exp(x) - 10</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#e8f5e9;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700;"
                        " color:#333333;\">\320\230\320\275\321\202\320\265\321\200\320\262\320\260\320\273:</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span><span style=\" font-family:'Courier New','monospace'; color:#333333; background-color:#eeeeee;\">2,3</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#e8f5e9;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#333333;\">\320\236\320\266\320\270\320\264\320\260\320\265\320\274\320\276\320\265 \321\200\320\265\321\210\320\265\320\275\320\270\320\265:</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> x \342\211\210 2.3026 </span></p>\n"
"<p style=\" margin-top:15px; margin-bottom:0px; margi"
                        "n-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#e8f5e9;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#2c3e50; background-color:#e8f5e9;\">\320\237\321\200\320\270\320\274\320\265\321\200 4: \320\243\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265 \321\201 \320\274\320\276\320\264\321\203\320\273\320\265\320\274</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#e8f5e9;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#333333;\">\320\243\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265:</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\""
                        "> |x - 2| = 1 </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#e8f5e9;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#333333;\">\320\244\321\203\320\275\320\272\321\206\320\270\321\217:</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span><span style=\" font-family:'Courier New','monospace'; color:#333333; background-color:#eeeeee;\">abs(x-2) - 1</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#e8f5e9;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#333333;\">\320\230\320\275\321\202\320\265"
                        "\321\200\320\262\320\260\320\273:</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span><span style=\" font-family:'Courier New','monospace'; color:#333333; background-color:#eeeeee;\">0,2</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#e8f5e9;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-weight:700; color:#333333;\">\320\236\320\266\320\270\320\264\320\260\320\265\320\274\320\276\320\265 \321\200\320\265\321\210\320\265\320\275\320\270\320\265:</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333;\"> x \342\211\210 1.000 </span></p>\n"
"<h2 style=\" margin-top:30px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:"
                        "0; text-indent:0px; line-height:160%;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-size:x-large; font-weight:700; color:#2c3e50;\">\320\241\320\276\320\262\320\265\321\202\321\213 \320\277\320\276 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\320\275\320\270\321\216</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-size:x-large; font-weight:700; color:#333333;\"> </span></h2>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\">\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\" style=\" margin-top:20px; margin-bottom:0px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">\320\235\320\260\321\207\320\270\320\275\320\260\320\271\321\202\320\265 \321\201 \320\277\321\200\320\276\321\201\321\202\321\213\321\205 \321\203\321"
                        "\200\320\260\320\262\320\275\320\265\320\275\320\270\320\271 \320\264\320\273\321\217 \320\277\321\200\320\276\320\262\320\265\321\200\320\272\320\270 \321\200\320\260\320\261\320\276\321\202\321\213 </li>\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">\320\225\321\201\320\273\320\270 \320\275\320\265 \320\275\320\260\320\271\320\264\320\265\320\275\320\276 \321\200\320\265\321\210\320\265\320\275\320\270\320\265 - \321\200\320\260\321\201\321\210\320\270\321\200\321\214\321\202\320\265 \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273 </li>\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; lin"
                        "e-height:160%;\">\320\230\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\271\321\202\320\265 \320\274\320\265\321\202\320\276\320\264 \320\264\320\270\321\205\320\276\321\202\320\276\320\274\320\270\320\270 \320\264\320\273\321\217 \320\275\320\260\320\264\320\265\320\266\320\275\320\276\321\201\321\202\320\270 </li>\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">\320\224\320\273\321\217 \321\202\321\200\320\270\320\263\320\276\320\275\320\276\320\274\320\265\321\202\321\200\320\270\321\207\320\265\321\201\320\272\320\270\321\205 \321\204\321\203\320\275\320\272\321\206\320\270\320\271 \321\203\320\272\320\260\320\267\321\213\320\262\320\260\320\271\321\202\320\265 \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273 \320\262 \321\200\320\260\320\264\320\270\320\260\320\275"
                        "\320\260\321\205 </li>\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\" style=\" margin-top:0px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">\320\243\320\261\320\265\320\264\320\270\321\202\320\265\321\201\321\214, \321\207\321\202\320\276 \320\275\320\260 \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273\320\265 \320\275\320\265\321\202 \321\200\320\260\320\267\321\200\321\213\320\262\320\276\320\262 \321\204\321\203\320\275\320\272\321\206\320\270\320\270 </li></ul>\n"
"<h3 style=\" margin-top:30px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%; background-color:#ffffff;\"><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-size:large; font-weight:700; color:#2c3e50; background-color:#ffffff;\">\320\247\321\202\320\276 \320\264\320\265\320\273\320\260\321"
                        "\202\321\214, \320\265\321\201\320\273\320\270 \321\200\320\265\321\210\320\265\320\275\320\270\320\265 \320\275\320\265 \320\275\320\260\320\271\320\264\320\265\320\275\320\276?</span><span style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; font-size:large; font-weight:700; color:#333333;\"> </span></h3>\n"
"<ol style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\">\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">\320\237\321\200\320\276\320\262\320\265\321\200\321\214\321\202\320\265 \320\277\321\200\320\260\320\262\320\270\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\275\320\260\320\277\320\270\321\201\320\260\320\275\320\270\321\217 \321\204\321\203\320\275\320\272\321\206\320\270\320\270 </li>\n"
"<li styl"
                        "e=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">\320\243\320\261\320\265\320\264\320\270\321\202\320\265\321\201\321\214, \321\207\321\202\320\276 f(a) \320\270 f(b) \320\270\320\274\320\265\321\216\321\202 \321\200\320\260\320\267\320\275\321\213\320\265 \320\267\320\275\320\260\320\272\320\270 </li>\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">\320\240\320\260\321\201\321\210\320\270\321\200\321\214\321\202\320\265 \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273 \320\277\320\276\320\270\321\201\320\272\320\260 </li>\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verd"
                        "ana','sans-serif'; color:#333333; background-color:#ffffff;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">\320\237\320\276\320\277\321\200\320\276\320\261\321\203\320\271\321\202\320\265 \320\264\321\200\321\203\320\263\320\276\320\271 \320\274\320\265\321\202\320\276\320\264 \321\200\320\265\321\210\320\265\320\275\320\270\321\217 </li>\n"
"<li style=\" font-family:'Segoe UI','Tahoma','Geneva','Verdana','sans-serif'; color:#333333; background-color:#ffffff;\" style=\" margin-top:0px; margin-bottom:12px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; line-height:160%;\">\320\237\321\200\320\276\320\262\320\265\321\200\321\214\321\202\320\265, \321\201\321\203\321\211\320\265\321\201\321\202\320\262\321\203\320\265\321\202 \320\273\320\270 \320\272\320\276\321\200\320\265\320\275\321\214 \320\275\320\260 \321\215\321\202\320\276\320\274 \320\270\320\275\321\202\320\265\321\200\320\262\320\260"
                        "\320\273\320\265 </li></ol></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
