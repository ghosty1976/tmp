/********************************************************************************
** Form generated from reading UI file 'solution.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOLUTION_H
#define UI_SOLUTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Solution
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QLabel *labelPasswordRecovery;

    void setupUi(QMainWindow *Solution)
    {
        if (Solution->objectName().isEmpty())
            Solution->setObjectName("Solution");
        Solution->resize(1000, 600);
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
        Solution->setPalette(palette);
        centralwidget = new QWidget(Solution);
        centralwidget->setObjectName("centralwidget");
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(260, 160, 471, 301));
        QFont font;
        font.setFamilies({QString::fromUtf8("Gilroy")});
        font.setPointSize(22);
        font.setBold(true);
        textBrowser->setFont(font);
        labelPasswordRecovery = new QLabel(centralwidget);
        labelPasswordRecovery->setObjectName("labelPasswordRecovery");
        labelPasswordRecovery->setGeometry(QRect(0, 20, 1001, 78));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Gilroy")});
        font1.setPointSize(36);
        font1.setBold(true);
        labelPasswordRecovery->setFont(font1);
        Solution->setCentralWidget(centralwidget);

        retranslateUi(Solution);

        QMetaObject::connectSlotsByName(Solution);
    } // setupUi

    void retranslateUi(QMainWindow *Solution)
    {
        Solution->setWindowTitle(QCoreApplication::translate("Solution", "MainWindow", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Solution", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Gilroy'; font-size:22pt; font-weight:700; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:large;\"><br /></p></body></html>", nullptr));
        labelPasswordRecovery->setText(QCoreApplication::translate("Solution", "<html><head/><body><p align=\"center\"><span style=\" font-size:48pt;\">\320\222\320\253\320\222\320\236\320\224 \320\240\320\225\320\227\320\243\320\233\320\254\320\242\320\220\320\242\320\220</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Solution: public Ui_Solution {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOLUTION_H
