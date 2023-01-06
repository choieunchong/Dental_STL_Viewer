/********************************************************************************
** Form generated from reading UI file '3Dmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_3DMAINWINDOW_H
#define UI_3DMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionsave;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QOpenGLWidget *viewocclusionModifiedopenGLWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *viewNamelabel;
    QLabel *viewGenderlabel;
    QDateEdit *dateEdit;
    QLabel *View_label;
    QDateEdit *viewModifieddateEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *viewsaveButton;
    QOpenGLWidget *viewlowerModifiedopenGLWidget;
    QOpenGLWidget *viewupperModifiedopenGLWidget;
    QOpenGLWidget *viewocclusionopenGLWidget;
    QOpenGLWidget *viewloweropenGLWidget;
    QOpenGLWidget *viewupperopenGLWidget;
    QMenuBar *menubar;
    QMenu *menu3Dview;
    QMenu *menudeign;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1124, 667);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        actionsave = new QAction(MainWindow);
        actionsave->setObjectName(QString::fromUtf8("actionsave"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        viewocclusionModifiedopenGLWidget = new QOpenGLWidget(centralwidget);
        viewocclusionModifiedopenGLWidget->setObjectName(QString::fromUtf8("viewocclusionModifiedopenGLWidget"));

        gridLayout->addWidget(viewocclusionModifiedopenGLWidget, 2, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        viewNamelabel = new QLabel(centralwidget);
        viewNamelabel->setObjectName(QString::fromUtf8("viewNamelabel"));

        horizontalLayout->addWidget(viewNamelabel);

        viewGenderlabel = new QLabel(centralwidget);
        viewGenderlabel->setObjectName(QString::fromUtf8("viewGenderlabel"));

        horizontalLayout->addWidget(viewGenderlabel);

        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        horizontalLayout->addWidget(dateEdit);

        View_label = new QLabel(centralwidget);
        View_label->setObjectName(QString::fromUtf8("View_label"));

        horizontalLayout->addWidget(View_label);

        viewModifieddateEdit = new QDateEdit(centralwidget);
        viewModifieddateEdit->setObjectName(QString::fromUtf8("viewModifieddateEdit"));

        horizontalLayout->addWidget(viewModifieddateEdit);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(608, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        viewsaveButton = new QPushButton(centralwidget);
        viewsaveButton->setObjectName(QString::fromUtf8("viewsaveButton"));

        horizontalLayout_2->addWidget(viewsaveButton);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 3);

        viewlowerModifiedopenGLWidget = new QOpenGLWidget(centralwidget);
        viewlowerModifiedopenGLWidget->setObjectName(QString::fromUtf8("viewlowerModifiedopenGLWidget"));

        gridLayout->addWidget(viewlowerModifiedopenGLWidget, 2, 1, 1, 1);

        viewupperModifiedopenGLWidget = new QOpenGLWidget(centralwidget);
        viewupperModifiedopenGLWidget->setObjectName(QString::fromUtf8("viewupperModifiedopenGLWidget"));

        gridLayout->addWidget(viewupperModifiedopenGLWidget, 2, 0, 1, 1);

        viewocclusionopenGLWidget = new QOpenGLWidget(centralwidget);
        viewocclusionopenGLWidget->setObjectName(QString::fromUtf8("viewocclusionopenGLWidget"));

        gridLayout->addWidget(viewocclusionopenGLWidget, 1, 2, 1, 1);

        viewloweropenGLWidget = new QOpenGLWidget(centralwidget);
        viewloweropenGLWidget->setObjectName(QString::fromUtf8("viewloweropenGLWidget"));

        gridLayout->addWidget(viewloweropenGLWidget, 1, 1, 1, 1);

        viewupperopenGLWidget = new QOpenGLWidget(centralwidget);
        viewupperopenGLWidget->setObjectName(QString::fromUtf8("viewupperopenGLWidget"));

        gridLayout->addWidget(viewupperopenGLWidget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1124, 17));
        menu3Dview = new QMenu(menubar);
        menu3Dview->setObjectName(QString::fromUtf8("menu3Dview"));
        menudeign = new QMenu(menubar);
        menudeign->setObjectName(QString::fromUtf8("menudeign"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu3Dview->menuAction());
        menubar->addAction(menudeign->menuAction());
        menu3Dview->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionsave->setText(QCoreApplication::translate("MainWindow", "save", nullptr));
        viewNamelabel->setText(QCoreApplication::translate("MainWindow", "\355\231\230\354\236\220 \354\235\264\353\246\204", nullptr));
        viewGenderlabel->setText(QCoreApplication::translate("MainWindow", "\354\204\261\353\263\204", nullptr));
        View_label->setText(QCoreApplication::translate("MainWindow", "\354\210\230\354\240\225\353\202\240\354\247\234(\354\225\204\354\235\264\354\275\230)", nullptr));
        viewsaveButton->setText(QCoreApplication::translate("MainWindow", "save", nullptr));
        menu3Dview->setTitle(QCoreApplication::translate("MainWindow", "3Dview", nullptr));
        menudeign->setTitle(QCoreApplication::translate("MainWindow", "design", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_3DMAINWINDOW_H
