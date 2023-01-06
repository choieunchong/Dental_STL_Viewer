/********************************************************************************
** Form generated from reading UI file '3DViewform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_3DVIEWFORM_H
#define UI_3DVIEWFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDateEdit *viewExpansiondateEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *viewExpansionSavepushButton;
    QPushButton *viewExpansionCutpushButton;
    QPushButton *viewExpansionBackpushButton;
    QPushButton *viewExpansionReturnpushButton;
    QPushButton *viewExpansionColorpushButton;
    QPushButton *viewExpansionRefreshpushButton;
    QOpenGLWidget *viewExpansionopenGLWidget;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(861, 544);
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(Form);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);


        horizontalLayout_2->addLayout(horizontalLayout);

        viewExpansiondateEdit = new QDateEdit(Form);
        viewExpansiondateEdit->setObjectName(QString::fromUtf8("viewExpansiondateEdit"));

        horizontalLayout_2->addWidget(viewExpansiondateEdit);

        horizontalLayout_2->setStretch(1, 1);

        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        viewExpansionSavepushButton = new QPushButton(Form);
        viewExpansionSavepushButton->setObjectName(QString::fromUtf8("viewExpansionSavepushButton"));

        horizontalLayout_3->addWidget(viewExpansionSavepushButton);

        viewExpansionCutpushButton = new QPushButton(Form);
        viewExpansionCutpushButton->setObjectName(QString::fromUtf8("viewExpansionCutpushButton"));

        horizontalLayout_3->addWidget(viewExpansionCutpushButton);

        viewExpansionBackpushButton = new QPushButton(Form);
        viewExpansionBackpushButton->setObjectName(QString::fromUtf8("viewExpansionBackpushButton"));

        horizontalLayout_3->addWidget(viewExpansionBackpushButton);

        viewExpansionReturnpushButton = new QPushButton(Form);
        viewExpansionReturnpushButton->setObjectName(QString::fromUtf8("viewExpansionReturnpushButton"));

        horizontalLayout_3->addWidget(viewExpansionReturnpushButton);

        viewExpansionColorpushButton = new QPushButton(Form);
        viewExpansionColorpushButton->setObjectName(QString::fromUtf8("viewExpansionColorpushButton"));

        horizontalLayout_3->addWidget(viewExpansionColorpushButton);

        viewExpansionRefreshpushButton = new QPushButton(Form);
        viewExpansionRefreshpushButton->setObjectName(QString::fromUtf8("viewExpansionRefreshpushButton"));

        horizontalLayout_3->addWidget(viewExpansionRefreshpushButton);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        viewExpansionopenGLWidget = new QOpenGLWidget(Form);
        viewExpansionopenGLWidget->setObjectName(QString::fromUtf8("viewExpansionopenGLWidget"));

        gridLayout->addWidget(viewExpansionopenGLWidget, 1, 0, 1, 1);

        gridLayout->setRowMinimumHeight(1, 1);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form", "\355\231\230\354\236\220 \354\235\264\353\246\204", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "\354\204\261\353\263\204", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "\354\210\230\354\240\225\353\202\240\354\247\234(\354\225\204\354\235\264\354\275\230)", nullptr));
        viewExpansionSavepushButton->setText(QCoreApplication::translate("Form", "save", nullptr));
        viewExpansionCutpushButton->setText(QCoreApplication::translate("Form", "cut", nullptr));
        viewExpansionBackpushButton->setText(QCoreApplication::translate("Form", "\354\235\264\354\240\204", nullptr));
        viewExpansionReturnpushButton->setText(QCoreApplication::translate("Form", "\353\220\230\353\217\214\353\246\254\352\270\260", nullptr));
        viewExpansionColorpushButton->setText(QCoreApplication::translate("Form", "color\353\263\200\352\262\275", nullptr));
        viewExpansionRefreshpushButton->setText(QCoreApplication::translate("Form", "\354\203\210\353\241\234\352\263\240\354\271\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_3DVIEWFORM_H
