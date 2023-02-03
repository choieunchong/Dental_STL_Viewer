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
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
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
    QAction *actionDoctor;
    QAction *actionStlViewer;
    QAction *actionOpen;
    QAction *actionColor;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QMdiArea *mdiArea;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menuMenu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(848, 533);
        actionManage = new QAction(MainWindow);
        actionManage->setObjectName(QString::fromUtf8("actionManage"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/manager.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionManage->setIcon(icon);
        action3D = new QAction(MainWindow);
        action3D->setObjectName(QString::fromUtf8("action3D"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("image/3D.png"), QSize(), QIcon::Normal, QIcon::Off);
        action3D->setIcon(icon1);
        actionManage_2 = new QAction(MainWindow);
        actionManage_2->setObjectName(QString::fromUtf8("actionManage_2"));
        action3D_2 = new QAction(MainWindow);
        action3D_2->setObjectName(QString::fromUtf8("action3D_2"));
        actionDoctor = new QAction(MainWindow);
        actionDoctor->setObjectName(QString::fromUtf8("actionDoctor"));
        actionDoctor->setIcon(icon);
        actionStlViewer = new QAction(MainWindow);
        actionStlViewer->setObjectName(QString::fromUtf8("actionStlViewer"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/3D.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStlViewer->setIcon(icon2);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionColor = new QAction(MainWindow);
        actionColor->setObjectName(QString::fromUtf8("actionColor"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("image/palette.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionColor->setIcon(icon3);
        QFont font;
        font.setPointSize(20);
        actionColor->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setEnabled(true);
        mdiArea->setFocusPolicy(Qt::NoFocus);
        mdiArea->setLayoutDirection(Qt::LeftToRight);
        mdiArea->setActivationOrder(QMdiArea::CreationOrder);
        mdiArea->setViewMode(QMdiArea::TabbedView);
        mdiArea->setDocumentMode(true);

        verticalLayout->addWidget(mdiArea);

        MainWindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setEnabled(true);
        toolBar->setMinimumSize(QSize(0, 0));
        toolBar->setAutoFillBackground(true);
        toolBar->setMovable(false);
        toolBar->setIconSize(QSize(100, 100));
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 848, 17));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        MainWindow->setMenuBar(menuBar);

        toolBar->addAction(actionDoctor);
        toolBar->addSeparator();
        toolBar->addAction(actionStlViewer);
        toolBar->addSeparator();
        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionOpen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "One View", nullptr));
        actionManage->setText(QCoreApplication::translate("MainWindow", "Manage", nullptr));
        action3D->setText(QCoreApplication::translate("MainWindow", "3D", nullptr));
        actionManage_2->setText(QCoreApplication::translate("MainWindow", "Manage", nullptr));
        action3D_2->setText(QCoreApplication::translate("MainWindow", "3D", nullptr));
        actionDoctor->setText(QCoreApplication::translate("MainWindow", "menager", nullptr));
        actionStlViewer->setText(QCoreApplication::translate("MainWindow", "3D", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionColor->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
