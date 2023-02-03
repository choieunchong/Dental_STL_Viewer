/********************************************************************************
** Form generated from reading UI file 'stlviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STLVIEWER_H
#define UI_STLVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_STLViewer
{
public:
    QGridLayout *gridLayout;
    QOpenGLWidget *openGLWidget;

    void setupUi(QWidget *STLViewer)
    {
        if (STLViewer->objectName().isEmpty())
            STLViewer->setObjectName(QString::fromUtf8("STLViewer"));
        STLViewer->resize(659, 565);
        gridLayout = new QGridLayout(STLViewer);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        openGLWidget = new QOpenGLWidget(STLViewer);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setMinimumSize(QSize(0, 200));

        gridLayout->addWidget(openGLWidget, 0, 0, 1, 1);


        retranslateUi(STLViewer);

        QMetaObject::connectSlotsByName(STLViewer);
    } // setupUi

    void retranslateUi(QWidget *STLViewer)
    {
        STLViewer->setWindowTitle(QCoreApplication::translate("STLViewer", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class STLViewer: public Ui_STLViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STLVIEWER_H
