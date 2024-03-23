/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindows
{
public:
    QAction *addrows;
    QAction *delete1;
    QAction *load;
    QAction *Clear;
    QAction *addcolunms;
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menuclearContents;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindows)
    {
        if (MainWindows->objectName().isEmpty())
            MainWindows->setObjectName("MainWindows");
        MainWindows->resize(502, 261);
        MainWindows->setUnifiedTitleAndToolBarOnMac(false);
        addrows = new QAction(MainWindows);
        addrows->setObjectName("addrows");
        delete1 = new QAction(MainWindows);
        delete1->setObjectName("delete1");
        load = new QAction(MainWindows);
        load->setObjectName("load");
        Clear = new QAction(MainWindows);
        Clear->setObjectName("Clear");
        addcolunms = new QAction(MainWindows);
        addcolunms->setObjectName("addcolunms");
        centralwidget = new QWidget(MainWindows);
        centralwidget->setObjectName("centralwidget");
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        if (tableWidget->rowCount() < 3)
            tableWidget->setRowCount(3);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 0, 501, 201));
        tableWidget->setRowCount(3);
        tableWidget->setColumnCount(4);
        tableWidget->horizontalHeader()->setMinimumSectionSize(120);
        tableWidget->horizontalHeader()->setDefaultSectionSize(120);
        tableWidget->verticalHeader()->setDefaultSectionSize(60);
        MainWindows->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindows);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 502, 21));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName("menu_4");
        menuclearContents = new QMenu(menubar);
        menuclearContents->setObjectName("menuclearContents");
        MainWindows->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindows);
        statusbar->setObjectName("statusbar");
        MainWindows->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindows);
        toolBar->setObjectName("toolBar");
        MainWindows->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menuclearContents->menuAction());
        menu->addAction(addrows);
        menu->addAction(addcolunms);
        menu_2->addAction(delete1);
        menu_3->addAction(load);
        menuclearContents->addAction(Clear);

        retranslateUi(MainWindows);

        QMetaObject::connectSlotsByName(MainWindows);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindows)
    {
        MainWindows->setWindowTitle(QCoreApplication::translate("MainWindows", "\345\205\213\345\267\261", nullptr));
        addrows->setText(QCoreApplication::translate("MainWindows", "addrows", nullptr));
        delete1->setText(QCoreApplication::translate("MainWindows", "deleterows", nullptr));
        load->setText(QCoreApplication::translate("MainWindows", "load", nullptr));
        Clear->setText(QCoreApplication::translate("MainWindows", "Clear", nullptr));
        addcolunms->setText(QCoreApplication::translate("MainWindows", "addcolunms", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindows", "\346\267\273\345\212\240", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindows", "\345\210\240\351\231\244", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindows", "\345\212\240\350\275\275", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindows", "\346\227\245\350\256\260", nullptr));
        menuclearContents->setTitle(QCoreApplication::translate("MainWindows", "ClearContents", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindows", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindows: public Ui_MainWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
