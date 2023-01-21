/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionManage;
    QAction *action3D;
    QAction *actionManage_2;
    QAction *action3D_2;
    QAction *actionmenager;
    QAction *action3D_3;
    QAction *actionDB;
    QAction *actionDB_2;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(848, 533);
        actionManage = new QAction(MainWindow);
        actionManage->setObjectName(QString::fromUtf8("actionManage"));
        action3D = new QAction(MainWindow);
        action3D->setObjectName(QString::fromUtf8("action3D"));
        actionManage_2 = new QAction(MainWindow);
        actionManage_2->setObjectName(QString::fromUtf8("actionManage_2"));
        action3D_2 = new QAction(MainWindow);
        action3D_2->setObjectName(QString::fromUtf8("action3D_2"));
        actionmenager = new QAction(MainWindow);
        actionmenager->setObjectName(QString::fromUtf8("actionmenager"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../build-Doctor-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug/manager.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionmenager->setIcon(icon);
        action3D_3 = new QAction(MainWindow);
        action3D_3->setObjectName(QString::fromUtf8("action3D_3"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../build-Doctor-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug/3D.png"), QSize(), QIcon::Normal, QIcon::Off);
        action3D_3->setIcon(icon1);
        actionDB = new QAction(MainWindow);
        actionDB->setObjectName(QString::fromUtf8("actionDB"));
        actionDB_2 = new QAction(MainWindow);
        actionDB_2->setObjectName(QString::fromUtf8("actionDB_2"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../build-Doctor-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug/DB.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDB_2->setIcon(icon2);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setEnabled(true);
        toolBar->setMinimumSize(QSize(0, 0));
        toolBar->setAutoFillBackground(true);
        toolBar->setMovable(false);
        toolBar->setIconSize(QSize(100, 100));
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar);

        toolBar->addAction(actionmenager);
        toolBar->addSeparator();
        toolBar->addAction(action3D_3);
        toolBar->addSeparator();
        toolBar->addAction(actionDB_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionManage->setText(QCoreApplication::translate("MainWindow", "Manage", nullptr));
        action3D->setText(QCoreApplication::translate("MainWindow", "3D", nullptr));
        actionManage_2->setText(QCoreApplication::translate("MainWindow", "Manage", nullptr));
        action3D_2->setText(QCoreApplication::translate("MainWindow", "3D", nullptr));
        actionmenager->setText(QCoreApplication::translate("MainWindow", "menager", nullptr));
        action3D_3->setText(QCoreApplication::translate("MainWindow", "3D", nullptr));
        actionDB->setText(QCoreApplication::translate("MainWindow", "DB", nullptr));
        actionDB_2->setText(QCoreApplication::translate("MainWindow", "DB", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
