/********************************************************************************
** Form generated from reading UI file 'doctor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTOR_H
#define UI_DOCTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Doctor
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_5;
    QPushButton *patientNewpushButton;
    QPushButton *patientEditpushButton;
    QPushButton *patientDeletepushButton;
    QFrame *line_2;
    QTreeWidget *patienttreeWidget;
    QLabel *label;
    QFrame *line_3;
    QWidget *Patient_Data_widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *Patient_Data_label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *fileButton;
    QHBoxLayout *horizontalLayout_13;
    QOpenGLWidget *patientDataupperopenGLWidget;
    QOpenGLWidget *patientDataloweropenGLWidget;
    QOpenGLWidget *patientDataocclusionopenGLWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_12;
    QLabel *PatintInfo_label;
    QComboBox *patientcomboBox;
    QPushButton *pushButton;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_11;
    QLabel *Patlent_DetailAddress_label;
    QLineEdit *patientDetailAddresslineEdit;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *Patlent_Address_label;
    QLineEdit *patientAddresslineEdit;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *Patlent_phone_label;
    QLineEdit *patientPhonelineEdit;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *Patlent_Email_label;
    QLineEdit *patientEmaillineEdit;
    QLabel *label_12;
    QLineEdit *patientEmaillineEdit2;
    QComboBox *Patient_comboBox;
    QFrame *line;
    QWidget *widget5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *Patlent_Mobile_label;
    QLineEdit *patientMobilelineEdit;
    QLineEdit *patientBirthdatlineEdit;
    QWidget *widget6;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *Patlent_Name_label;
    QLabel *Patlent_ChartNumber_label;
    QLabel *Patlent_Birthday_label;
    QLabel *Patlent_Gender_label;
    QLabel *Patlent_FirstVist_label;
    QLabel *Patlent_LastVist_label;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *patientNamelineEdit;
    QLineEdit *patientChartNumberlineEdit;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *patientGenderMaleradioButton;
    QRadioButton *patientGenderFemaleradioButton;
    QRadioButton *patientGenderNoneradioButton;
    QDateEdit *patientFirstVistdateEdit;
    QDateEdit *patientLastVistdateEdit;

    void setupUi(QWidget *Doctor)
    {
        if (Doctor->objectName().isEmpty())
            Doctor->setObjectName(QString::fromUtf8("Doctor"));
        Doctor->resize(1325, 943);
        Doctor->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border: 2px solid rgb(133, 149, 255);\n"
"    border-radius: 10px;\n"
"    padding: 10 8px;\n"
"    background: #fff;\n"
"    selection-background-color: darkgray;\n"
"}"));
        layoutWidget = new QWidget(Doctor);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(1070, 10, 239, 26));
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

        line_2 = new QFrame(Doctor);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(400, 20, 16, 929));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        patienttreeWidget = new QTreeWidget(Doctor);
        patienttreeWidget->setObjectName(QString::fromUtf8("patienttreeWidget"));
        patienttreeWidget->setGeometry(QRect(2, 33, 391, 411));
        label = new QLabel(Doctor);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(2, 11, 52, 16));
        line_3 = new QFrame(Doctor);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(850, 40, 20, 301));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        Patient_Data_widget = new QWidget(Doctor);
        Patient_Data_widget->setObjectName(QString::fromUtf8("Patient_Data_widget"));
        Patient_Data_widget->setGeometry(QRect(419, 400, 761, 441));
        verticalLayout_2 = new QVBoxLayout(Patient_Data_widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Patient_Data_label = new QLabel(Patient_Data_widget);
        Patient_Data_label->setObjectName(QString::fromUtf8("Patient_Data_label"));

        horizontalLayout->addWidget(Patient_Data_label);

        horizontalSpacer_2 = new QSpacerItem(788, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        fileButton = new QPushButton(Patient_Data_widget);
        fileButton->setObjectName(QString::fromUtf8("fileButton"));

        horizontalLayout->addWidget(fileButton);

        horizontalLayout->setStretch(2, 1);

        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        patientDataupperopenGLWidget = new QOpenGLWidget(Patient_Data_widget);
        patientDataupperopenGLWidget->setObjectName(QString::fromUtf8("patientDataupperopenGLWidget"));

        horizontalLayout_13->addWidget(patientDataupperopenGLWidget);

        patientDataloweropenGLWidget = new QOpenGLWidget(Patient_Data_widget);
        patientDataloweropenGLWidget->setObjectName(QString::fromUtf8("patientDataloweropenGLWidget"));

        horizontalLayout_13->addWidget(patientDataloweropenGLWidget);

        patientDataocclusionopenGLWidget = new QOpenGLWidget(Patient_Data_widget);
        patientDataocclusionopenGLWidget->setObjectName(QString::fromUtf8("patientDataocclusionopenGLWidget"));

        horizontalLayout_13->addWidget(patientDataocclusionopenGLWidget);


        verticalLayout_2->addLayout(horizontalLayout_13);

        verticalLayout_2->setStretch(1, 1);
        widget = new QWidget(Doctor);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(440, 10, 242, 26));
        horizontalLayout_12 = new QHBoxLayout(widget);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        PatintInfo_label = new QLabel(widget);
        PatintInfo_label->setObjectName(QString::fromUtf8("PatintInfo_label"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        PatintInfo_label->setFont(font);

        horizontalLayout_12->addWidget(PatintInfo_label);

        patientcomboBox = new QComboBox(widget);
        patientcomboBox->setObjectName(QString::fromUtf8("patientcomboBox"));

        horizontalLayout_12->addWidget(patientcomboBox);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_12->addWidget(pushButton);

        widget1 = new QWidget(Doctor);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(870, 270, 211, 44));
        horizontalLayout_11 = new QHBoxLayout(widget1);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        Patlent_DetailAddress_label = new QLabel(widget1);
        Patlent_DetailAddress_label->setObjectName(QString::fromUtf8("Patlent_DetailAddress_label"));

        horizontalLayout_11->addWidget(Patlent_DetailAddress_label);

        patientDetailAddresslineEdit = new QLineEdit(widget1);
        patientDetailAddresslineEdit->setObjectName(QString::fromUtf8("patientDetailAddresslineEdit"));

        horizontalLayout_11->addWidget(patientDetailAddresslineEdit);

        widget2 = new QWidget(Doctor);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(860, 220, 176, 44));
        horizontalLayout_10 = new QHBoxLayout(widget2);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        Patlent_Address_label = new QLabel(widget2);
        Patlent_Address_label->setObjectName(QString::fromUtf8("Patlent_Address_label"));

        horizontalLayout_10->addWidget(Patlent_Address_label);

        patientAddresslineEdit = new QLineEdit(widget2);
        patientAddresslineEdit->setObjectName(QString::fromUtf8("patientAddresslineEdit"));

        horizontalLayout_10->addWidget(patientAddresslineEdit);

        widget3 = new QWidget(Doctor);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(890, 110, 168, 44));
        horizontalLayout_8 = new QHBoxLayout(widget3);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        Patlent_phone_label = new QLabel(widget3);
        Patlent_phone_label->setObjectName(QString::fromUtf8("Patlent_phone_label"));

        horizontalLayout_8->addWidget(Patlent_phone_label);

        patientPhonelineEdit = new QLineEdit(widget3);
        patientPhonelineEdit->setObjectName(QString::fromUtf8("patientPhonelineEdit"));

        horizontalLayout_8->addWidget(patientPhonelineEdit);

        widget4 = new QWidget(Doctor);
        widget4->setObjectName(QString::fromUtf8("widget4"));
        widget4->setGeometry(QRect(870, 170, 416, 44));
        horizontalLayout_9 = new QHBoxLayout(widget4);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        Patlent_Email_label = new QLabel(widget4);
        Patlent_Email_label->setObjectName(QString::fromUtf8("Patlent_Email_label"));

        horizontalLayout_9->addWidget(Patlent_Email_label);

        patientEmaillineEdit = new QLineEdit(widget4);
        patientEmaillineEdit->setObjectName(QString::fromUtf8("patientEmaillineEdit"));

        horizontalLayout_9->addWidget(patientEmaillineEdit);

        label_12 = new QLabel(widget4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_9->addWidget(label_12);

        patientEmaillineEdit2 = new QLineEdit(widget4);
        patientEmaillineEdit2->setObjectName(QString::fromUtf8("patientEmaillineEdit2"));

        horizontalLayout_9->addWidget(patientEmaillineEdit2);

        Patient_comboBox = new QComboBox(widget4);
        Patient_comboBox->addItem(QString());
        Patient_comboBox->addItem(QString());
        Patient_comboBox->setObjectName(QString::fromUtf8("Patient_comboBox"));

        horizontalLayout_9->addWidget(Patient_comboBox);

        line = new QFrame(widget4);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_9->addWidget(line);

        widget5 = new QWidget(Doctor);
        widget5->setObjectName(QString::fromUtf8("widget5"));
        widget5->setGeometry(QRect(890, 60, 171, 44));
        horizontalLayout_7 = new QHBoxLayout(widget5);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        Patlent_Mobile_label = new QLabel(widget5);
        Patlent_Mobile_label->setObjectName(QString::fromUtf8("Patlent_Mobile_label"));

        horizontalLayout_7->addWidget(Patlent_Mobile_label);

        patientMobilelineEdit = new QLineEdit(widget5);
        patientMobilelineEdit->setObjectName(QString::fromUtf8("patientMobilelineEdit"));

        horizontalLayout_7->addWidget(patientMobilelineEdit);

        patientBirthdatlineEdit = new QLineEdit(Doctor);
        patientBirthdatlineEdit->setObjectName(QString::fromUtf8("patientBirthdatlineEdit"));
        patientBirthdatlineEdit->setGeometry(QRect(690, 10, 126, 42));
        widget6 = new QWidget(Doctor);
        widget6->setObjectName(QString::fromUtf8("widget6"));
        widget6->setGeometry(QRect(422, 62, 426, 251));
        horizontalLayout_4 = new QHBoxLayout(widget6);
        horizontalLayout_4->setSpacing(11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Patlent_Name_label = new QLabel(widget6);
        Patlent_Name_label->setObjectName(QString::fromUtf8("Patlent_Name_label"));

        verticalLayout->addWidget(Patlent_Name_label);

        Patlent_ChartNumber_label = new QLabel(widget6);
        Patlent_ChartNumber_label->setObjectName(QString::fromUtf8("Patlent_ChartNumber_label"));

        verticalLayout->addWidget(Patlent_ChartNumber_label);

        Patlent_Birthday_label = new QLabel(widget6);
        Patlent_Birthday_label->setObjectName(QString::fromUtf8("Patlent_Birthday_label"));

        verticalLayout->addWidget(Patlent_Birthday_label);

        Patlent_Gender_label = new QLabel(widget6);
        Patlent_Gender_label->setObjectName(QString::fromUtf8("Patlent_Gender_label"));

        verticalLayout->addWidget(Patlent_Gender_label);

        Patlent_FirstVist_label = new QLabel(widget6);
        Patlent_FirstVist_label->setObjectName(QString::fromUtf8("Patlent_FirstVist_label"));

        verticalLayout->addWidget(Patlent_FirstVist_label);

        Patlent_LastVist_label = new QLabel(widget6);
        Patlent_LastVist_label->setObjectName(QString::fromUtf8("Patlent_LastVist_label"));

        verticalLayout->addWidget(Patlent_LastVist_label);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        patientNamelineEdit = new QLineEdit(widget6);
        patientNamelineEdit->setObjectName(QString::fromUtf8("patientNamelineEdit"));
        patientNamelineEdit->setEnabled(true);
        patientNamelineEdit->setBaseSize(QSize(50, 40));
        patientNamelineEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
" width:50px;\n"
" height:15px;\n"
"}"));

        verticalLayout_3->addWidget(patientNamelineEdit);

        patientChartNumberlineEdit = new QLineEdit(widget6);
        patientChartNumberlineEdit->setObjectName(QString::fromUtf8("patientChartNumberlineEdit"));
        patientChartNumberlineEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
" height: 10px;\n"
"}"));

        verticalLayout_3->addWidget(patientChartNumberlineEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        comboBox = new QComboBox(widget6);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_3->addWidget(comboBox);

        comboBox_2 = new QComboBox(widget6);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout_3->addWidget(comboBox_2);

        comboBox_3 = new QComboBox(widget6);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        horizontalLayout_3->addWidget(comboBox_3);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        patientGenderMaleradioButton = new QRadioButton(widget6);
        patientGenderMaleradioButton->setObjectName(QString::fromUtf8("patientGenderMaleradioButton"));
        patientGenderMaleradioButton->setEnabled(true);
        patientGenderMaleradioButton->setStyleSheet(QString::fromUtf8("QRadioButton\n"
"{\n"
"	background-color:#fff;\n"
"	width: 100px;\n"
"    height: 30px;\n"
"}\n"
"\n"
"QRadioButton::indicator \n"
"{\n"
"    background-color: ff3399;\n"
"    border-style: outset;\n"
"    width: 0px;\n"
"    height: 0px;\n"
"}\n"
"\n"
"QRadioButton::checked {\n"
"   background:#006 ;\n"
" color:#fff;\n"
"}\n"
"\n"
"QRadioButton::hover {\n"
"  background:#006 ;\n"
" color:#fff;\n"
"}"));
        patientGenderMaleradioButton->setCheckable(true);
        patientGenderMaleradioButton->setChecked(false);

        horizontalLayout_2->addWidget(patientGenderMaleradioButton);

        patientGenderFemaleradioButton = new QRadioButton(widget6);
        patientGenderFemaleradioButton->setObjectName(QString::fromUtf8("patientGenderFemaleradioButton"));
        patientGenderFemaleradioButton->setStyleSheet(QString::fromUtf8("QRadioButton\n"
"{\n"
"	background-color:#fff;\n"
"	width: 100px;\n"
"    height: 30px;\n"
"}\n"
"\n"
"QRadioButton::indicator \n"
"{\n"
"    background-color: ff3399;\n"
"    border-style: outset;\n"
"    width: 0px;\n"
"    height: 0px;\n"
"}\n"
"\n"
"QRadioButton::checked {\n"
"   background:#006 ;\n"
" color:#fff;\n"
"}\n"
"\n"
"QRadioButton::hover {\n"
"  background:#006 ;\n"
" color:#fff;\n"
"}"));

        horizontalLayout_2->addWidget(patientGenderFemaleradioButton);

        patientGenderNoneradioButton = new QRadioButton(widget6);
        patientGenderNoneradioButton->setObjectName(QString::fromUtf8("patientGenderNoneradioButton"));
        patientGenderNoneradioButton->setStyleSheet(QString::fromUtf8("QRadioButton\n"
"{\n"
"	background-color:#fff;\n"
"	width: 100px;\n"
"    height: 30px;\n"
"}\n"
"\n"
"QRadioButton::indicator \n"
"{\n"
"    background-color: ff3399;\n"
"    border-style: outset;\n"
"    width: 0px;\n"
"    height: 0px;\n"
"}\n"
"\n"
"QRadioButton::checked {\n"
"   background:#006 ;\n"
" color:#fff;\n"
"}\n"
"\n"
"QRadioButton::hover {\n"
"  background:#006 ;\n"
" color:#fff;\n"
"}"));

        horizontalLayout_2->addWidget(patientGenderNoneradioButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        patientFirstVistdateEdit = new QDateEdit(widget6);
        patientFirstVistdateEdit->setObjectName(QString::fromUtf8("patientFirstVistdateEdit"));
        patientFirstVistdateEdit->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"	border: 2px solid lightgray;\n"
"	border-radius: 10px;\n"
"    width:190px;\n"
"    height:40px;\n"
"}"));
        patientFirstVistdateEdit->setCalendarPopup(true);
        patientFirstVistdateEdit->setTimeSpec(Qt::UTC);

        verticalLayout_3->addWidget(patientFirstVistdateEdit);

        patientLastVistdateEdit = new QDateEdit(widget6);
        patientLastVistdateEdit->setObjectName(QString::fromUtf8("patientLastVistdateEdit"));
        patientLastVistdateEdit->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"	border: 2px solid lightgray;\n"
"	border-radius: 10px;\n"
"    width:190px;\n"
"    height:40px;\n"
"}"));
        patientLastVistdateEdit->setMinimumDateTime(QDateTime(QDate(1758, 9, 12), QTime(12, 0, 0)));
        patientLastVistdateEdit->setCalendarPopup(true);

        verticalLayout_3->addWidget(patientLastVistdateEdit);


        horizontalLayout_4->addLayout(verticalLayout_3);

        layoutWidget->raise();
        layoutWidget->raise();
        line_2->raise();
        patienttreeWidget->raise();
        label->raise();
        line_3->raise();
        comboBox->raise();
        comboBox_2->raise();
        comboBox_3->raise();

        retranslateUi(Doctor);

        QMetaObject::connectSlotsByName(Doctor);
    } // setupUi

    void retranslateUi(QWidget *Doctor)
    {
        Doctor->setWindowTitle(QCoreApplication::translate("Doctor", "Doctor", nullptr));
        patientNewpushButton->setText(QCoreApplication::translate("Doctor", "New", nullptr));
        patientEditpushButton->setText(QCoreApplication::translate("Doctor", "Edit", nullptr));
        patientDeletepushButton->setText(QCoreApplication::translate("Doctor", "Delete", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = patienttreeWidget->headerItem();
        ___qtreewidgetitem->setText(9, QCoreApplication::translate("Doctor", "Addr", nullptr));
        ___qtreewidgetitem->setText(8, QCoreApplication::translate("Doctor", "Email", nullptr));
        ___qtreewidgetitem->setText(7, QCoreApplication::translate("Doctor", "Phone", nullptr));
        ___qtreewidgetitem->setText(6, QCoreApplication::translate("Doctor", "Mobile", nullptr));
        ___qtreewidgetitem->setText(5, QCoreApplication::translate("Doctor", "First Visit", nullptr));
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("Doctor", "Birth", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("Doctor", "Last Visit", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("Doctor", "Gender", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("Doctor", "Name", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("Doctor", "Chart No.", nullptr));
        label->setText(QCoreApplication::translate("Doctor", "\355\231\230\354\236\220 \354\240\225\353\263\264", nullptr));
        Patient_Data_label->setText(QCoreApplication::translate("Doctor", "Data", nullptr));
        fileButton->setText(QCoreApplication::translate("Doctor", "+", nullptr));
        PatintInfo_label->setText(QCoreApplication::translate("Doctor", "Patlent Info", nullptr));
        pushButton->setText(QCoreApplication::translate("Doctor", "PushButton", nullptr));
        Patlent_DetailAddress_label->setText(QCoreApplication::translate("Doctor", "Detail Address", nullptr));
        patientDetailAddresslineEdit->setText(QString());
        patientDetailAddresslineEdit->setPlaceholderText(QCoreApplication::translate("Doctor", "Detail Address", nullptr));
        Patlent_Address_label->setText(QCoreApplication::translate("Doctor", "Address", nullptr));
        patientAddresslineEdit->setText(QString());
        patientAddresslineEdit->setPlaceholderText(QCoreApplication::translate("Doctor", "Address", nullptr));
        Patlent_phone_label->setText(QCoreApplication::translate("Doctor", "Phone", nullptr));
        patientPhonelineEdit->setText(QString());
        patientPhonelineEdit->setPlaceholderText(QCoreApplication::translate("Doctor", "Phone", nullptr));
        Patlent_Email_label->setText(QCoreApplication::translate("Doctor", "E-mail", nullptr));
        patientEmaillineEdit->setText(QString());
        patientEmaillineEdit->setPlaceholderText(QCoreApplication::translate("Doctor", "E-mail", nullptr));
        label_12->setText(QCoreApplication::translate("Doctor", "@", nullptr));
        Patient_comboBox->setItemText(0, QCoreApplication::translate("Doctor", "naver.com", nullptr));
        Patient_comboBox->setItemText(1, QCoreApplication::translate("Doctor", "gmail.com", nullptr));

        Patlent_Mobile_label->setText(QCoreApplication::translate("Doctor", "Mobile", nullptr));
        patientMobilelineEdit->setText(QString());
        patientMobilelineEdit->setPlaceholderText(QCoreApplication::translate("Doctor", "Mobile", nullptr));
        patientBirthdatlineEdit->setText(QString());
        patientBirthdatlineEdit->setPlaceholderText(QCoreApplication::translate("Doctor", "Birthday", nullptr));
        Patlent_Name_label->setText(QCoreApplication::translate("Doctor", "Name", nullptr));
        Patlent_ChartNumber_label->setText(QCoreApplication::translate("Doctor", "Chart Number", nullptr));
        Patlent_Birthday_label->setText(QCoreApplication::translate("Doctor", "Birthday", nullptr));
        Patlent_Gender_label->setText(QCoreApplication::translate("Doctor", "Gender", nullptr));
        Patlent_FirstVist_label->setText(QCoreApplication::translate("Doctor", "First Vist", nullptr));
        Patlent_LastVist_label->setText(QCoreApplication::translate("Doctor", "Last Vist", nullptr));
        patientNamelineEdit->setText(QString());
        patientNamelineEdit->setPlaceholderText(QCoreApplication::translate("Doctor", "Name", nullptr));
        patientChartNumberlineEdit->setText(QString());
        patientChartNumberlineEdit->setPlaceholderText(QCoreApplication::translate("Doctor", "Chart Number", nullptr));
        patientGenderMaleradioButton->setText(QCoreApplication::translate("Doctor", "Male", nullptr));
        patientGenderFemaleradioButton->setText(QCoreApplication::translate("Doctor", "Female", nullptr));
        patientGenderNoneradioButton->setText(QCoreApplication::translate("Doctor", "None", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Doctor: public Ui_Doctor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTOR_H
