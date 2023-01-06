/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QListView *patientlistView;
    QLabel *PatintInfo_label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_5;
    QPushButton *patientNewpushButton;
    QPushButton *patientEditpushButton;
    QPushButton *patientDeletepushButton;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QLabel *Patlent_Mobile_label;
    QLineEdit *patientMobilelineEdit;
    QLabel *Patlent_phone_label;
    QLineEdit *patientPhonelineEdit;
    QLabel *Patlent_Email_label;
    QLineEdit *patientEmaillineEdit;
    QLabel *label_12;
    QLineEdit *patientEmaillineEdit2;
    QComboBox *Patient_comboBox;
    QGridLayout *gridLayout_3;
    QLabel *Patlent_Address_label;
    QLineEdit *patientAddresslineEdit;
    QLineEdit *patientDetailAddresslineEdit;
    QLabel *Patlent_DetailAddress_label;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QDateEdit *patientFirstVistdateEdit;
    QLabel *Patlent_Gender_label;
    QDateEdit *patientLastVistdateEdit;
    QPushButton *patientGenderNonepushButton;
    QLabel *Patlent_FirstVist_label;
    QLabel *Patlent_LastVist_label;
    QLabel *Patlent_ChartNumber_label;
    QPushButton *patientGenderFemalepushButton;
    QLineEdit *patientBirthdatlineEdit;
    QLineEdit *patientNamelineEdit;
    QPushButton *patientGenderMalepushButton;
    QLabel *Patlent_Birthday_label;
    QLabel *Patlent_Name_label;
    QLineEdit *patientChartNumberlineEdit;
    QFrame *line;
    QWidget *Patient_Data_widget;
    QLabel *Patient_Data_label;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QOpenGLWidget *patientDataupperopenGLWidget;
    QOpenGLWidget *patientDataloweropenGLWidget;
    QOpenGLWidget *patientDataocclusionopenGLWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1763, 987);
        patientlistView = new QListView(Widget);
        patientlistView->setObjectName(QString::fromUtf8("patientlistView"));
        patientlistView->setGeometry(QRect(10, 20, 731, 831));
        PatintInfo_label = new QLabel(Widget);
        PatintInfo_label->setObjectName(QString::fromUtf8("PatintInfo_label"));
        PatintInfo_label->setGeometry(QRect(770, 10, 121, 31));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        PatintInfo_label->setFont(font);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(1420, 10, 295, 31));
        gridLayout_5 = new QGridLayout(layoutWidget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        patientNewpushButton = new QPushButton(layoutWidget);
        patientNewpushButton->setObjectName(QString::fromUtf8("patientNewpushButton"));
        patientNewpushButton->setCheckable(false);
        patientNewpushButton->setChecked(false);

        gridLayout_5->addWidget(patientNewpushButton, 0, 0, 1, 1);

        patientEditpushButton = new QPushButton(layoutWidget);
        patientEditpushButton->setObjectName(QString::fromUtf8("patientEditpushButton"));
        patientEditpushButton->setCheckable(false);
        patientEditpushButton->setChecked(false);

        gridLayout_5->addWidget(patientEditpushButton, 0, 1, 1, 1);

        patientDeletepushButton = new QPushButton(layoutWidget);
        patientDeletepushButton->setObjectName(QString::fromUtf8("patientDeletepushButton"));
        patientDeletepushButton->setCheckable(false);
        patientDeletepushButton->setChecked(false);

        gridLayout_5->addWidget(patientDeletepushButton, 0, 2, 1, 1);

        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(1209, 50, 511, 341));
        gridLayout_4 = new QGridLayout(layoutWidget1);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        Patlent_Mobile_label = new QLabel(layoutWidget1);
        Patlent_Mobile_label->setObjectName(QString::fromUtf8("Patlent_Mobile_label"));

        gridLayout_2->addWidget(Patlent_Mobile_label, 0, 0, 1, 1);

        patientMobilelineEdit = new QLineEdit(layoutWidget1);
        patientMobilelineEdit->setObjectName(QString::fromUtf8("patientMobilelineEdit"));

        gridLayout_2->addWidget(patientMobilelineEdit, 0, 1, 1, 5);

        Patlent_phone_label = new QLabel(layoutWidget1);
        Patlent_phone_label->setObjectName(QString::fromUtf8("Patlent_phone_label"));

        gridLayout_2->addWidget(Patlent_phone_label, 1, 0, 1, 2);

        patientPhonelineEdit = new QLineEdit(layoutWidget1);
        patientPhonelineEdit->setObjectName(QString::fromUtf8("patientPhonelineEdit"));

        gridLayout_2->addWidget(patientPhonelineEdit, 1, 2, 1, 4);

        Patlent_Email_label = new QLabel(layoutWidget1);
        Patlent_Email_label->setObjectName(QString::fromUtf8("Patlent_Email_label"));

        gridLayout_2->addWidget(Patlent_Email_label, 2, 0, 1, 2);

        patientEmaillineEdit = new QLineEdit(layoutWidget1);
        patientEmaillineEdit->setObjectName(QString::fromUtf8("patientEmaillineEdit"));

        gridLayout_2->addWidget(patientEmaillineEdit, 2, 2, 1, 1);

        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 2, 3, 1, 1);

        patientEmaillineEdit2 = new QLineEdit(layoutWidget1);
        patientEmaillineEdit2->setObjectName(QString::fromUtf8("patientEmaillineEdit2"));

        gridLayout_2->addWidget(patientEmaillineEdit2, 2, 4, 1, 1);

        Patient_comboBox = new QComboBox(layoutWidget1);
        Patient_comboBox->addItem(QString());
        Patient_comboBox->addItem(QString());
        Patient_comboBox->setObjectName(QString::fromUtf8("Patient_comboBox"));

        gridLayout_2->addWidget(Patient_comboBox, 2, 5, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        Patlent_Address_label = new QLabel(layoutWidget1);
        Patlent_Address_label->setObjectName(QString::fromUtf8("Patlent_Address_label"));

        gridLayout_3->addWidget(Patlent_Address_label, 0, 0, 1, 1);

        patientAddresslineEdit = new QLineEdit(layoutWidget1);
        patientAddresslineEdit->setObjectName(QString::fromUtf8("patientAddresslineEdit"));

        gridLayout_3->addWidget(patientAddresslineEdit, 0, 1, 1, 1);

        patientDetailAddresslineEdit = new QLineEdit(layoutWidget1);
        patientDetailAddresslineEdit->setObjectName(QString::fromUtf8("patientDetailAddresslineEdit"));

        gridLayout_3->addWidget(patientDetailAddresslineEdit, 1, 1, 1, 1);

        Patlent_DetailAddress_label = new QLabel(layoutWidget1);
        Patlent_DetailAddress_label->setObjectName(QString::fromUtf8("Patlent_DetailAddress_label"));

        gridLayout_3->addWidget(Patlent_DetailAddress_label, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 1, 0, 1, 1);

        layoutWidget2 = new QWidget(Widget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(754, 50, 399, 341));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        patientFirstVistdateEdit = new QDateEdit(layoutWidget2);
        patientFirstVistdateEdit->setObjectName(QString::fromUtf8("patientFirstVistdateEdit"));

        gridLayout->addWidget(patientFirstVistdateEdit, 4, 1, 1, 3);

        Patlent_Gender_label = new QLabel(layoutWidget2);
        Patlent_Gender_label->setObjectName(QString::fromUtf8("Patlent_Gender_label"));

        gridLayout->addWidget(Patlent_Gender_label, 3, 0, 1, 1);

        patientLastVistdateEdit = new QDateEdit(layoutWidget2);
        patientLastVistdateEdit->setObjectName(QString::fromUtf8("patientLastVistdateEdit"));

        gridLayout->addWidget(patientLastVistdateEdit, 5, 1, 1, 3);

        patientGenderNonepushButton = new QPushButton(layoutWidget2);
        patientGenderNonepushButton->setObjectName(QString::fromUtf8("patientGenderNonepushButton"));

        gridLayout->addWidget(patientGenderNonepushButton, 3, 3, 1, 1);

        Patlent_FirstVist_label = new QLabel(layoutWidget2);
        Patlent_FirstVist_label->setObjectName(QString::fromUtf8("Patlent_FirstVist_label"));

        gridLayout->addWidget(Patlent_FirstVist_label, 4, 0, 1, 1);

        Patlent_LastVist_label = new QLabel(layoutWidget2);
        Patlent_LastVist_label->setObjectName(QString::fromUtf8("Patlent_LastVist_label"));

        gridLayout->addWidget(Patlent_LastVist_label, 5, 0, 1, 1);

        Patlent_ChartNumber_label = new QLabel(layoutWidget2);
        Patlent_ChartNumber_label->setObjectName(QString::fromUtf8("Patlent_ChartNumber_label"));

        gridLayout->addWidget(Patlent_ChartNumber_label, 2, 0, 1, 1);

        patientGenderFemalepushButton = new QPushButton(layoutWidget2);
        patientGenderFemalepushButton->setObjectName(QString::fromUtf8("patientGenderFemalepushButton"));

        gridLayout->addWidget(patientGenderFemalepushButton, 3, 2, 1, 1);

        patientBirthdatlineEdit = new QLineEdit(layoutWidget2);
        patientBirthdatlineEdit->setObjectName(QString::fromUtf8("patientBirthdatlineEdit"));

        gridLayout->addWidget(patientBirthdatlineEdit, 1, 1, 1, 3);

        patientNamelineEdit = new QLineEdit(layoutWidget2);
        patientNamelineEdit->setObjectName(QString::fromUtf8("patientNamelineEdit"));

        gridLayout->addWidget(patientNamelineEdit, 0, 1, 1, 3);

        patientGenderMalepushButton = new QPushButton(layoutWidget2);
        patientGenderMalepushButton->setObjectName(QString::fromUtf8("patientGenderMalepushButton"));
        patientGenderMalepushButton->setCheckable(false);
        patientGenderMalepushButton->setChecked(false);

        gridLayout->addWidget(patientGenderMalepushButton, 3, 1, 1, 1);

        Patlent_Birthday_label = new QLabel(layoutWidget2);
        Patlent_Birthday_label->setObjectName(QString::fromUtf8("Patlent_Birthday_label"));

        gridLayout->addWidget(Patlent_Birthday_label, 1, 0, 1, 1);

        Patlent_Name_label = new QLabel(layoutWidget2);
        Patlent_Name_label->setObjectName(QString::fromUtf8("Patlent_Name_label"));

        gridLayout->addWidget(Patlent_Name_label, 0, 0, 1, 1);

        patientChartNumberlineEdit = new QLineEdit(layoutWidget2);
        patientChartNumberlineEdit->setObjectName(QString::fromUtf8("patientChartNumberlineEdit"));

        gridLayout->addWidget(patientChartNumberlineEdit, 2, 1, 1, 3);

        line = new QFrame(Widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(1163, 60, 20, 331));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        Patient_Data_widget = new QWidget(Widget);
        Patient_Data_widget->setObjectName(QString::fromUtf8("Patient_Data_widget"));
        Patient_Data_widget->setGeometry(QRect(740, 430, 961, 31));
        Patient_Data_label = new QLabel(Patient_Data_widget);
        Patient_Data_label->setObjectName(QString::fromUtf8("Patient_Data_label"));
        Patient_Data_label->setGeometry(QRect(10, 0, 81, 31));
        layoutWidget3 = new QWidget(Widget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(761, 511, 911, 331));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        patientDataupperopenGLWidget = new QOpenGLWidget(layoutWidget3);
        patientDataupperopenGLWidget->setObjectName(QString::fromUtf8("patientDataupperopenGLWidget"));

        horizontalLayout->addWidget(patientDataupperopenGLWidget);

        patientDataloweropenGLWidget = new QOpenGLWidget(layoutWidget3);
        patientDataloweropenGLWidget->setObjectName(QString::fromUtf8("patientDataloweropenGLWidget"));

        horizontalLayout->addWidget(patientDataloweropenGLWidget);

        patientDataocclusionopenGLWidget = new QOpenGLWidget(layoutWidget3);
        patientDataocclusionopenGLWidget->setObjectName(QString::fromUtf8("patientDataocclusionopenGLWidget"));

        horizontalLayout->addWidget(patientDataocclusionopenGLWidget);

        layoutWidget3->raise();
        layoutWidget3->raise();
        Patient_Data_widget->raise();
        patientlistView->raise();
        PatintInfo_label->raise();
        layoutWidget3->raise();
        layoutWidget3->raise();
        line->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        PatintInfo_label->setText(QCoreApplication::translate("Widget", "Patlent Info", nullptr));
        patientNewpushButton->setText(QCoreApplication::translate("Widget", "New", nullptr));
        patientEditpushButton->setText(QCoreApplication::translate("Widget", "Edit", nullptr));
        patientDeletepushButton->setText(QCoreApplication::translate("Widget", "Delete", nullptr));
        Patlent_Mobile_label->setText(QCoreApplication::translate("Widget", "Mobile", nullptr));
        Patlent_phone_label->setText(QCoreApplication::translate("Widget", "Phone", nullptr));
        Patlent_Email_label->setText(QCoreApplication::translate("Widget", "E-mail", nullptr));
        label_12->setText(QCoreApplication::translate("Widget", "@", nullptr));
        Patient_comboBox->setItemText(0, QCoreApplication::translate("Widget", "naver.com", nullptr));
        Patient_comboBox->setItemText(1, QCoreApplication::translate("Widget", "gmail.com", nullptr));

        Patlent_Address_label->setText(QCoreApplication::translate("Widget", "Address", nullptr));
        Patlent_DetailAddress_label->setText(QCoreApplication::translate("Widget", "Detail Address", nullptr));
        Patlent_Gender_label->setText(QCoreApplication::translate("Widget", "Gender", nullptr));
        patientGenderNonepushButton->setText(QCoreApplication::translate("Widget", "None", nullptr));
        Patlent_FirstVist_label->setText(QCoreApplication::translate("Widget", "First Vist", nullptr));
        Patlent_LastVist_label->setText(QCoreApplication::translate("Widget", "Last Vist", nullptr));
        Patlent_ChartNumber_label->setText(QCoreApplication::translate("Widget", "Chart Number", nullptr));
        patientGenderFemalepushButton->setText(QCoreApplication::translate("Widget", "Female", nullptr));
        patientGenderMalepushButton->setText(QCoreApplication::translate("Widget", "Male", nullptr));
        Patlent_Birthday_label->setText(QCoreApplication::translate("Widget", "Birthday", nullptr));
        Patlent_Name_label->setText(QCoreApplication::translate("Widget", "Name", nullptr));
        Patient_Data_label->setText(QCoreApplication::translate("Widget", "Data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
