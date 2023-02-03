/********************************************************************************
** Form generated from reading UI file 'db.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DB_H
#define UI_DB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_patienttreeWidget_2
{
public:
    QGridLayout *gridLayout;
    QTreeWidget *patienttreeWidget;

    void setupUi(QWidget *patienttreeWidget_2)
    {
        if (patienttreeWidget_2->objectName().isEmpty())
            patienttreeWidget_2->setObjectName(QString::fromUtf8("patienttreeWidget_2"));
        patienttreeWidget_2->resize(1005, 587);
        gridLayout = new QGridLayout(patienttreeWidget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        patienttreeWidget = new QTreeWidget(patienttreeWidget_2);
        patienttreeWidget->setObjectName(QString::fromUtf8("patienttreeWidget"));

        gridLayout->addWidget(patienttreeWidget, 0, 0, 1, 1);


        retranslateUi(patienttreeWidget_2);

        QMetaObject::connectSlotsByName(patienttreeWidget_2);
    } // setupUi

    void retranslateUi(QWidget *patienttreeWidget_2)
    {
        patienttreeWidget_2->setWindowTitle(QCoreApplication::translate("patienttreeWidget_2", "Form", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = patienttreeWidget->headerItem();
        ___qtreewidgetitem->setText(9, QCoreApplication::translate("patienttreeWidget_2", "Addr", nullptr));
        ___qtreewidgetitem->setText(8, QCoreApplication::translate("patienttreeWidget_2", "Email", nullptr));
        ___qtreewidgetitem->setText(7, QCoreApplication::translate("patienttreeWidget_2", "Phone", nullptr));
        ___qtreewidgetitem->setText(6, QCoreApplication::translate("patienttreeWidget_2", "Mobile", nullptr));
        ___qtreewidgetitem->setText(5, QCoreApplication::translate("patienttreeWidget_2", "First Visit", nullptr));
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("patienttreeWidget_2", "Birth", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("patienttreeWidget_2", "Last Visit", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("patienttreeWidget_2", "Gender", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("patienttreeWidget_2", "Name", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("patienttreeWidget_2", "Chart No.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class patienttreeWidget_2: public Ui_patienttreeWidget_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DB_H
