/********************************************************************************
** Form generated from reading UI file 'mainservcer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSERVCER_H
#define UI_MAINSERVCER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainServcer
{
public:

    void setupUi(QWidget *MainServcer)
    {
        if (MainServcer->objectName().isEmpty())
            MainServcer->setObjectName(QString::fromUtf8("MainServcer"));
        MainServcer->resize(400, 300);

        retranslateUi(MainServcer);

        QMetaObject::connectSlotsByName(MainServcer);
    } // setupUi

    void retranslateUi(QWidget *MainServcer)
    {
        MainServcer->setWindowTitle(QCoreApplication::translate("MainServcer", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainServcer: public Ui_MainServcer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSERVCER_H
