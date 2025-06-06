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
    QComboBox *comboBoxMethod;
    QLabel *labelMaxIterations;
    QLabel *labelTolerance;
    QLabel *labelMethod;
    QLineEdit *lineEditMaxIterations;
    QLineEdit *lineEditTolerance;
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
        layoutWidget->setGeometry(QRect(40, 180, 436, 283));
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

        comboBoxMethod = new QComboBox(layoutWidget);
        comboBoxMethod->setObjectName("comboBoxMethod");
        comboBoxMethod->setFont(font2);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, comboBoxMethod);

        labelMaxIterations = new QLabel(layoutWidget);
        labelMaxIterations->setObjectName("labelMaxIterations");
        labelMaxIterations->setFont(font1);

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, labelMaxIterations);

        labelTolerance = new QLabel(layoutWidget);
        labelTolerance->setObjectName("labelTolerance");
        labelTolerance->setFont(font1);

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, labelTolerance);

        labelMethod = new QLabel(layoutWidget);
        labelMethod->setObjectName("labelMethod");
        labelMethod->setFont(font1);

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelMethod);

        lineEditMaxIterations = new QLineEdit(layoutWidget);
        lineEditMaxIterations->setObjectName("lineEditMaxIterations");
        lineEditMaxIterations->setFont(font2);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, lineEditMaxIterations);

        lineEditTolerance = new QLineEdit(layoutWidget);
        lineEditTolerance->setObjectName("lineEditTolerance");
        lineEditTolerance->setFont(font2);

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, lineEditTolerance);


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
        textBrowser->setGeometry(QRect(530, 180, 431, 281));
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
        labelMaxIterations->setText(QCoreApplication::translate("MainWindow", "\320\247\320\270\321\201\320\273\320\276 \320\270\321\202\320\265\321\200\320\260\321\206\320\270\320\271:", nullptr));
        labelTolerance->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214:", nullptr));
        labelMethod->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264:", nullptr));
        pushButtonSolve->setText(QCoreApplication::translate("MainWindow", "\320\240\320\225\320\250\320\230\320\242\320\254", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><title>\320\234\320\265\321\202\320\276\320\264\320\270\321\207\320\272\320\260 \320\277\320\276 \320\262\320\262\320\276\320\264\321\203 \320\264\320\260\320\275\320\275\321\213\321\205</title><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\" bgcolor=\"#f9f9f9\">\n"
"<h3 style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial','sans-serif'; font-size:large; font-weight:700; color:#4caf50;\">\320\234\320\265\321\202\320\276\320\264\320\270\321\207\320\272\320\260 \320\277\320\276"
                        " \320\262\320\262\320\276\320\264\321\203 \320\264\320\260\320\275\320\275\321\213\321\205</span><span style=\" font-family:'Arial','sans-serif'; font-size:large; font-weight:700; color:#333333;\"> </span></h3>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial','sans-serif'; font-size:14px; font-weight:700; color:#d32f2f;\">\320\244\321\203\320\275\320\272\321\206\320\270\321\217:</span><span style=\" font-family:'Arial','sans-serif'; font-size:14px; color:#333333;\"> \320\243\320\272\320\260\320\266\320\270\321\202\320\265 \321\204\321\203\320\275\320\272\321\206\320\270\321\216, \320\272\320\276\321\202\320\276\321\200\320\260\321\217 \320\261\321\203\320\264\320\265\321\202 \321\200\320\265\321\210\320\260\321\202\321\214\321\201\321\217 \320\275\320\260 \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273\320\265. \320\244\321\203\320\275\320\272\321\206\320\270\321\217 \320\274\320\276"
                        "\320\266\320\265\321\202 \321\201\320\276\320\264\320\265\321\200\320\266\320\260\321\202\321\214 \320\273\320\260\321\202\320\270\320\275\321\201\320\272\320\270\320\265 \320\261\321\203\320\272\320\262\321\213, \321\206\320\270\321\204\321\200\321\213, \320\274\320\260\321\202\320\265\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \320\276\320\277\320\265\321\200\320\260\321\202\320\276\321\200\321\213 \320\270 \321\201\320\272\320\276\320\261\320\272\320\270.</span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\">\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#333333;\" style=\" margin-top:12px; margin-bottom:10px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-weight:700; color:#d32f2f;\">\320\237\321\200\320\270\320\274\320\265\321\200:</span> <span style=\" font-style:italic; color:#2196f3;\">x^2 - 4</span>, <span style=\" font-st"
                        "yle:italic; color:#2196f3;\">cos(x)</span>, <span style=\" font-style:italic; color:#2196f3;\">3x + 2</span> </li>\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#333333;\" style=\" margin-top:10px; margin-bottom:10px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-weight:700; color:#ff5722;\">\320\222\320\260\320\266\320\275\320\276:</span> \320\235\320\265 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\271\321\202\320\265 \321\200\321\203\321\201\321\201\320\272\320\270\320\265 \320\261\321\203\320\272\320\262\321\213 \320\270\320\273\320\270 \321\201\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\321\213\320\265 \321\201\320\270\320\274\320\262\320\276\320\273\321\213, \321\202\320\260\320\272\320\270\320\265 \320\272\320\260\320\272 <span style=\" font-style:italic; color:#2196f3;\">@, $, #</span>. </li>\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#333333;\" style=\" margin-top:10p"
                        "x; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-weight:700; color:#d32f2f;\">\320\235\320\265\320\264\320\276\320\277\321\203\321\201\321\202\320\270\320\274\320\276:</span> \320\230\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\321\214 \320\277\321\200\320\276\320\261\320\265\320\273\321\213 \320\274\320\265\320\266\320\264\321\203 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\320\276\320\271 \320\270 \320\276\320\277\320\265\321\200\320\260\321\202\320\276\321\200\320\276\320\274, \320\275\320\260\320\277\321\200\320\270\320\274\320\265\321\200, <span style=\" font-style:italic; color:#2196f3;\">x + 2</span>. </li></ul>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial','sans-serif'; font-size:14px; font-weight:700; color:#d32f2f;\">\320\230\320\275\321\202\320\265"
                        "\321\200\320\262\320\260\320\273:</span><span style=\" font-family:'Arial','sans-serif'; font-size:14px; color:#333333;\"> \320\243\320\272\320\260\320\266\320\270\321\202\320\265 \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273, \320\275\320\260 \320\272\320\276\321\202\320\276\321\200\320\276\320\274 \320\261\321\203\320\264\320\265\321\202 \321\200\320\265\321\210\320\260\321\202\321\214\321\201\321\217 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265.</span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\">\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#333333;\" style=\" margin-top:12px; margin-bottom:10px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-weight:700; color:#d32f2f;\">\320\237\321\200\320\270\320\274\320\265\321\200:</span> <span style=\" font-style:italic; color:#2196f3;\">2, 3</span>, <span style=\" font-style"
                        ":italic; color:#2196f3;\">1.5, 4.7</span> </li>\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#333333;\" style=\" margin-top:10px; margin-bottom:10px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-weight:700; color:#ff5722;\">\320\222\320\260\320\266\320\275\320\276:</span> \320\230\320\275\321\202\320\265\321\200\320\262\320\260\320\273 \320\264\320\276\320\273\320\266\320\265\320\275 \320\261\321\213\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\320\260\320\275 \320\262 \321\204\320\276\321\200\320\274\320\260\321\202\320\265, \320\275\320\260\320\277\321\200\320\270\320\274\320\265\321\200, <span style=\" font-style:italic; color:#2196f3;\">a, b</span>, \320\263\320\264\320\265 a \320\270 b \342\200\224 \321\215\321\202\320\276 \321\207\320\270\321\201\320\273\320\260. <br />\320\235\320\265 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\271\321\202\320\265 \320\272\320\262\320\260\320\264\321\200\320"
                        "\260\321\202\320\275\321\213\320\265 \321\201\320\272\320\276\320\261\320\272\320\270, \321\202\320\260\320\272\320\270\320\265 \320\272\320\260\320\272 <span style=\" font-style:italic; color:#2196f3;\">[2, 3]</span>. </li>\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#333333;\" style=\" margin-top:10px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-weight:700; color:#d32f2f;\">\320\235\320\265\320\264\320\276\320\277\321\203\321\201\321\202\320\270\320\274\320\276:</span> \320\230\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\321\214 \320\277\321\200\320\276\320\261\320\265\320\273\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 \321\207\320\270\321\201\320\265\320\273, \320\270\320\273\320\270 \320\277\320\270\321\201\320\260\321\202\321\214 \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273 \320\272\320\260\320\272 <span style=\" font-style:italic; color"
                        ":#2196f3;\">(2,3)</span> \320\270\320\273\320\270 <span style=\" font-style:italic; color:#2196f3;\">2 3</span>. </li></ul>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial','sans-serif'; font-size:14px; font-weight:700; color:#d32f2f;\">\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214:</span><span style=\" font-family:'Arial','sans-serif'; font-size:14px; color:#333333;\"> \320\243\320\272\320\260\320\266\320\270\321\202\320\265 \321\202\320\276\321\207\320\275\320\276\321\201\321\202\321\214, \321\201 \320\272\320\276\321\202\320\276\321\200\320\276\320\271 \320\261\321\203\320\264\320\265\321\202 \320\275\320\260\320\271\320\264\320\265\320\275 \320\272\320\276\321\200\320\265\320\275\321\214 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\321\217.</span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: "
                        "1;\">\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#333333;\" style=\" margin-top:12px; margin-bottom:10px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-weight:700; color:#d32f2f;\">\320\237\321\200\320\270\320\274\320\265\321\200:</span> <span style=\" font-style:italic; color:#2196f3;\">0.001</span>, <span style=\" font-style:italic; color:#2196f3;\">0.01</span>, <span style=\" font-style:italic; color:#2196f3;\">0.0001</span> </li>\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#333333;\" style=\" margin-top:10px; margin-bottom:10px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-weight:700; color:#ff5722;\">\320\222\320\260\320\266\320\275\320\276:</span> \320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \320\264\320\276\320\273\320\266\320\275\320\260 \320\261\321\213\321\202\321\214 \320\277\320\276\320\273\320\276\320\266\320\270\321\202"
                        "\320\265\320\273\321\214\320\275\321\213\320\274 \321\207\320\270\321\201\320\273\320\276\320\274, \320\275\320\260\320\277\321\200\320\270\320\274\320\265\321\200, <span style=\" font-style:italic; color:#2196f3;\">0.001</span> \320\270\320\273\320\270 <span style=\" font-style:italic; color:#2196f3;\">0.01</span>. </li>\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#333333;\" style=\" margin-top:10px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-weight:700; color:#d32f2f;\">\320\235\320\265\320\264\320\276\320\277\321\203\321\201\321\202\320\270\320\274\320\276:</span> \320\243\320\272\320\260\320\267\321\213\320\262\320\260\321\202\321\214 \321\202\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \320\261\320\276\320\273\321\214\321\210\320\265 <span style=\" font-style:italic; color:#2196f3;\">0.1</span>, \320\260 \321\202\320\260\320\272\320\266\320\265 \320\270\321\201\320\277\320\276\320\273\321\214\320"
                        "\267\320\276\320\262\320\260\321\202\321\214 \320\275\320\276\320\273\321\214 \320\270\320\273\320\270 \320\276\321\202\321\200\320\270\321\206\320\260\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \321\207\320\270\321\201\320\273\320\260. </li></ul>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial','sans-serif'; font-size:14px; font-weight:700; color:#d32f2f;\">\320\247\320\270\321\201\320\273\320\276 \320\270\321\202\320\265\321\200\320\260\321\206\320\270\320\271:</span><span style=\" font-family:'Arial','sans-serif'; font-size:14px; color:#333333;\"> \320\243\320\272\320\260\320\266\320\270\321\202\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\210\320\260\320\263\320\276\320\262, \320\272\320\276\321\202\320\276\321\200\320\276\320\265 \320\261\321\203\320\264\320\265\321\202 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275"
                        "\320\276 \320\264\320\273\321\217 \320\275\320\260\321\205\320\276\320\266\320\264\320\265\320\275\320\270\321\217 \320\272\320\276\321\200\320\275\321\217.</span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\">\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#333333;\" style=\" margin-top:12px; margin-bottom:10px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-weight:700; color:#d32f2f;\">\320\237\321\200\320\270\320\274\320\265\321\200:</span> <span style=\" font-style:italic; color:#2196f3;\">50</span>, <span style=\" font-style:italic; color:#2196f3;\">100</span>, <span style=\" font-style:italic; color:#2196f3;\">10</span> </li>\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#333333;\" style=\" margin-top:10px; margin-bottom:10px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-weight:700; co"
                        "lor:#ff5722;\">\320\222\320\260\320\266\320\275\320\276:</span> \320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\270\321\202\320\265\321\200\320\260\321\206\320\270\320\271 \320\264\320\276\320\273\320\266\320\275\320\276 \320\261\321\213\321\202\321\214 \321\206\320\265\320\273\321\213\320\274 \321\207\320\270\321\201\320\273\320\276\320\274 \320\262 \320\277\321\200\320\265\320\264\320\265\320\273\320\260\321\205 \320\276\321\202 <span style=\" font-style:italic; color:#2196f3;\">1</span> \320\264\320\276 <span style=\" font-style:italic; color:#2196f3;\">100</span>. </li>\n"
"<li style=\" font-family:'Arial','sans-serif'; color:#333333;\" style=\" margin-top:10px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:160%;\"><span style=\" font-weight:700; color:#d32f2f;\">\320\235\320\265\320\264\320\276\320\277\321\203\321\201\321\202\320\270\320\274\320\276:</span> \320\243\320\272\320\260\320\267\321\213\320\262\320\260"
                        "\321\202\321\214 \320\276\321\202\321\200\320\270\321\206\320\260\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \321\207\320\270\321\201\320\273\320\260 \320\270\320\273\320\270 \320\261\320\276\320\273\321\214\321\210\320\265 100. \320\235\320\260\320\277\321\200\320\270\320\274\320\265\321\200, <span style=\" font-style:italic; color:#2196f3;\">-10</span> \320\270\320\273\320\270 <span style=\" font-style:italic; color:#2196f3;\">150</span> \342\200\224 \320\276\321\210\320\270\320\261\320\272\320\260. </li></ul>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial','sans-serif'; font-size:14px; color:#333333;\">\320\237\321\200\320\270 \320\262\320\262\320\276\320\264\320\265 \321\204\321\203\320\275\320\272\321\206\320\270\320\270 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\271\321\202\320\265 \321\202\320\276\320\273\321\214\320\272\320\276 \320\273\320\260\321\202"
                        "\320\270\320\275\321\201\320\272\320\270\320\265 \320\261\321\203\320\272\320\262\321\213, \321\206\320\270\321\204\321\200\321\213 \320\270 \320\274\320\260\321\202\320\265\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \320\276\320\277\320\265\321\200\320\260\321\202\320\276\321\200\321\213, \321\202\320\260\320\272\320\270\320\265 \320\272\320\260\320\272 </span><span style=\" font-family:'Arial','sans-serif'; font-size:14px; font-style:italic; color:#2196f3;\">+, -, *, /, ^</span><span style=\" font-family:'Arial','sans-serif'; font-size:14px; color:#333333;\">.</span><span style=\" font-family:'Arial','sans-serif'; color:#333333;\"> </span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
