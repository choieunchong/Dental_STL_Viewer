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
    QGridLayout *gridLayout;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label;
    QTreeWidget *patienttreeWidget;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_12;
    QLabel *PatintInfo_label;
    QComboBox *patientcomboBox;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_5;
    QPushButton *patientNewpushButton;
    QPushButton *patientEditpushButton;
    QPushButton *patientDeletepushButton;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_7;
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
    QComboBox *patientBirthYcomboBox;
    QComboBox *patienBirthMcomboBox;
    QComboBox *patienBirthDcomboBox;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *patientGenderMaleradioButton;
    QRadioButton *patientGenderFemaleradioButton;
    QRadioButton *patientGenderNoneradioButton;
    QDateEdit *patientFirstVistdateEdit;
    QDateEdit *patientLastVistdateEdit;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *Patlent_Mobile_label;
    QLabel *Patlent_phone_label;
    QLabel *Patlent_Email_label;
    QLabel *Patlent_Address_label;
    QLabel *Patlent_DetailAddress_label;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *patientMobilelineEdit;
    QLineEdit *patientPhonelineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *patientEmaillineEdit;
    QLabel *label_12;
    QLineEdit *patientEmaillineEdit2;
    QComboBox *Patient_comboBox;
    QLineEdit *patientAddresslineEdit;
    QLineEdit *patientDetailAddresslineEdit;
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

    void setupUi(QWidget *Doctor)
    {
        if (Doctor->objectName().isEmpty())
            Doctor->setObjectName(QString::fromUtf8("Doctor"));
        Doctor->resize(1442, 943);
        Doctor->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border: 2px solid rgb(133, 149, 255);\n"
"    border-radius: 10px;\n"
"    padding: 10 8px;\n"
"    background: #fff;\n"
"    selection-background-color: darkgray;\n"
"}"));
        gridLayout = new QGridLayout(Doctor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        line_2 = new QFrame(Doctor);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 0, 1, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label = new QLabel(Doctor);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("HY\352\262\254\352\263\240\353\224\225"));
        font.setPointSize(10);
        label->setFont(font);

        verticalLayout_7->addWidget(label);

        patienttreeWidget = new QTreeWidget(Doctor);
        patienttreeWidget->setObjectName(QString::fromUtf8("patienttreeWidget"));

        verticalLayout_7->addWidget(patienttreeWidget);


        gridLayout->addLayout(verticalLayout_7, 0, 0, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        PatintInfo_label = new QLabel(Doctor);
        PatintInfo_label->setObjectName(QString::fromUtf8("PatintInfo_label"));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        PatintInfo_label->setFont(font1);

        horizontalLayout_12->addWidget(PatintInfo_label);

        patientcomboBox = new QComboBox(Doctor);
        patientcomboBox->setObjectName(QString::fromUtf8("patientcomboBox"));

        horizontalLayout_12->addWidget(patientcomboBox);

        pushButton = new QPushButton(Doctor);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_12->addWidget(pushButton);


        horizontalLayout_8->addLayout(horizontalLayout_12);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        patientNewpushButton = new QPushButton(Doctor);
        patientNewpushButton->setObjectName(QString::fromUtf8("patientNewpushButton"));
        patientNewpushButton->setCheckable(false);
        patientNewpushButton->setChecked(false);

        gridLayout_5->addWidget(patientNewpushButton, 0, 0, 1, 1);

        patientEditpushButton = new QPushButton(Doctor);
        patientEditpushButton->setObjectName(QString::fromUtf8("patientEditpushButton"));
        patientEditpushButton->setCheckable(false);
        patientEditpushButton->setChecked(false);

        gridLayout_5->addWidget(patientEditpushButton, 0, 1, 1, 1);

        patientDeletepushButton = new QPushButton(Doctor);
        patientDeletepushButton->setObjectName(QString::fromUtf8("patientDeletepushButton"));
        patientDeletepushButton->setCheckable(false);
        patientDeletepushButton->setChecked(false);

        gridLayout_5->addWidget(patientDeletepushButton, 0, 2, 1, 1);


        horizontalLayout_8->addLayout(gridLayout_5);


        verticalLayout_8->addLayout(horizontalLayout_8);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Patlent_Name_label = new QLabel(Doctor);
        Patlent_Name_label->setObjectName(QString::fromUtf8("Patlent_Name_label"));

        verticalLayout->addWidget(Patlent_Name_label);

        Patlent_ChartNumber_label = new QLabel(Doctor);
        Patlent_ChartNumber_label->setObjectName(QString::fromUtf8("Patlent_ChartNumber_label"));

        verticalLayout->addWidget(Patlent_ChartNumber_label);

        Patlent_Birthday_label = new QLabel(Doctor);
        Patlent_Birthday_label->setObjectName(QString::fromUtf8("Patlent_Birthday_label"));

        verticalLayout->addWidget(Patlent_Birthday_label);

        Patlent_Gender_label = new QLabel(Doctor);
        Patlent_Gender_label->setObjectName(QString::fromUtf8("Patlent_Gender_label"));

        verticalLayout->addWidget(Patlent_Gender_label);

        Patlent_FirstVist_label = new QLabel(Doctor);
        Patlent_FirstVist_label->setObjectName(QString::fromUtf8("Patlent_FirstVist_label"));

        verticalLayout->addWidget(Patlent_FirstVist_label);

        Patlent_LastVist_label = new QLabel(Doctor);
        Patlent_LastVist_label->setObjectName(QString::fromUtf8("Patlent_LastVist_label"));

        verticalLayout->addWidget(Patlent_LastVist_label);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        patientNamelineEdit = new QLineEdit(Doctor);
        patientNamelineEdit->setObjectName(QString::fromUtf8("patientNamelineEdit"));
        patientNamelineEdit->setEnabled(true);
        patientNamelineEdit->setBaseSize(QSize(50, 40));
        patientNamelineEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
" width:50px;\n"
" height:15px;\n"
"}"));

        verticalLayout_3->addWidget(patientNamelineEdit);

        patientChartNumberlineEdit = new QLineEdit(Doctor);
        patientChartNumberlineEdit->setObjectName(QString::fromUtf8("patientChartNumberlineEdit"));
        patientChartNumberlineEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
" height: 10px;\n"
"}"));

        verticalLayout_3->addWidget(patientChartNumberlineEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        patientBirthYcomboBox = new QComboBox(Doctor);
        patientBirthYcomboBox->setObjectName(QString::fromUtf8("patientBirthYcomboBox"));

        horizontalLayout_3->addWidget(patientBirthYcomboBox);

        patienBirthMcomboBox = new QComboBox(Doctor);
        patienBirthMcomboBox->setObjectName(QString::fromUtf8("patienBirthMcomboBox"));

        horizontalLayout_3->addWidget(patienBirthMcomboBox);

        patienBirthDcomboBox = new QComboBox(Doctor);
        patienBirthDcomboBox->setObjectName(QString::fromUtf8("patienBirthDcomboBox"));

        horizontalLayout_3->addWidget(patienBirthDcomboBox);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        patientGenderMaleradioButton = new QRadioButton(Doctor);
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

        patientGenderFemaleradioButton = new QRadioButton(Doctor);
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

        patientGenderNoneradioButton = new QRadioButton(Doctor);
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

        patientFirstVistdateEdit = new QDateEdit(Doctor);
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

        patientLastVistdateEdit = new QDateEdit(Doctor);
        patientLastVistdateEdit->setObjectName(QString::fromUtf8("patientLastVistdateEdit"));
        patientLastVistdateEdit->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"	border: 2px solid lightgray;\n"
"	border-radius: 10px;\n"
"    width:190px;\n"
"    height:40px;\n"
"}"));
        patientLastVistdateEdit->setMinimumDateTime(QDateTime(QDate(1758, 9, 11), QTime(0, 0, 0)));
        patientLastVistdateEdit->setCalendarPopup(true);

        verticalLayout_3->addWidget(patientLastVistdateEdit);


        horizontalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_7->addLayout(horizontalLayout_4);

        line_3 = new QFrame(Doctor);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_7->addWidget(line_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        Patlent_Mobile_label = new QLabel(Doctor);
        Patlent_Mobile_label->setObjectName(QString::fromUtf8("Patlent_Mobile_label"));

        verticalLayout_5->addWidget(Patlent_Mobile_label);

        Patlent_phone_label = new QLabel(Doctor);
        Patlent_phone_label->setObjectName(QString::fromUtf8("Patlent_phone_label"));

        verticalLayout_5->addWidget(Patlent_phone_label);

        Patlent_Email_label = new QLabel(Doctor);
        Patlent_Email_label->setObjectName(QString::fromUtf8("Patlent_Email_label"));

        verticalLayout_5->addWidget(Patlent_Email_label);

        Patlent_Address_label = new QLabel(Doctor);
        Patlent_Address_label->setObjectName(QString::fromUtf8("Patlent_Address_label"));

        verticalLayout_5->addWidget(Patlent_Address_label);

        Patlent_DetailAddress_label = new QLabel(Doctor);
        Patlent_DetailAddress_label->setObjectName(QString::fromUtf8("Patlent_DetailAddress_label"));

        verticalLayout_5->addWidget(Patlent_DetailAddress_label);


        horizontalLayout_6->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        patientMobilelineEdit = new QLineEdit(Doctor);
        patientMobilelineEdit->setObjectName(QString::fromUtf8("patientMobilelineEdit"));

        verticalLayout_4->addWidget(patientMobilelineEdit);

        patientPhonelineEdit = new QLineEdit(Doctor);
        patientPhonelineEdit->setObjectName(QString::fromUtf8("patientPhonelineEdit"));

        verticalLayout_4->addWidget(patientPhonelineEdit);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        patientEmaillineEdit = new QLineEdit(Doctor);
        patientEmaillineEdit->setObjectName(QString::fromUtf8("patientEmaillineEdit"));

        horizontalLayout_5->addWidget(patientEmaillineEdit);

        label_12 = new QLabel(Doctor);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_5->addWidget(label_12);

        patientEmaillineEdit2 = new QLineEdit(Doctor);
        patientEmaillineEdit2->setObjectName(QString::fromUtf8("patientEmaillineEdit2"));

        horizontalLayout_5->addWidget(patientEmaillineEdit2);

        Patient_comboBox = new QComboBox(Doctor);
        Patient_comboBox->addItem(QString());
        Patient_comboBox->addItem(QString());
        Patient_comboBox->setObjectName(QString::fromUtf8("Patient_comboBox"));

        horizontalLayout_5->addWidget(Patient_comboBox);


        verticalLayout_4->addLayout(horizontalLayout_5);

        patientAddresslineEdit = new QLineEdit(Doctor);
        patientAddresslineEdit->setObjectName(QString::fromUtf8("patientAddresslineEdit"));

        verticalLayout_4->addWidget(patientAddresslineEdit);

        patientDetailAddresslineEdit = new QLineEdit(Doctor);
        patientDetailAddresslineEdit->setObjectName(QString::fromUtf8("patientDetailAddresslineEdit"));

        verticalLayout_4->addWidget(patientDetailAddresslineEdit);


        horizontalLayout_6->addLayout(verticalLayout_4);


        horizontalLayout_7->addLayout(horizontalLayout_6);


        verticalLayout_6->addLayout(horizontalLayout_7);

        Patient_Data_widget = new QWidget(Doctor);
        Patient_Data_widget->setObjectName(QString::fromUtf8("Patient_Data_widget"));
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
        fileButton->setMaximumSize(QSize(50, 16777215));

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

        verticalLayout_6->addWidget(Patient_Data_widget);


        verticalLayout_8->addLayout(verticalLayout_6);


        gridLayout->addLayout(verticalLayout_8, 0, 2, 1, 1);


        retranslateUi(Doctor);

        QMetaObject::connectSlotsByName(Doctor);
    } // setupUi

    void retranslateUi(QWidget *Doctor)
    {
        Doctor->setWindowTitle(QCoreApplication::translate("Doctor", "Doctor", nullptr));
        label->setText(QCoreApplication::translate("Doctor", "\355\231\230\354\236\220 \354\240\225\353\263\264", nullptr));
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
        PatintInfo_label->setText(QCoreApplication::translate("Doctor", "Patlent Info", nullptr));
        pushButton->setText(QCoreApplication::translate("Doctor", "PushButton", nullptr));
        patientNewpushButton->setText(QCoreApplication::translate("Doctor", "New", nullptr));
        patientEditpushButton->setText(QCoreApplication::translate("Doctor", "Edit", nullptr));
        patientDeletepushButton->setText(QCoreApplication::translate("Doctor", "Delete", nullptr));
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
        Patlent_Mobile_label->setText(QCoreApplication::translate("Doctor", "Mobile", nullptr));
        Patlent_phone_label->setText(QCoreApplication::translate("Doctor", "Phone", nullptr));
        Patlent_Email_label->setText(QCoreApplication::translate("Doctor", "E-mail", nullptr));
        Patlent_Address_label->setText(QCoreApplication::translate("Doctor", "Address", nullptr));
        Patlent_DetailAddress_label->setText(QString());
        patientMobilelineEdit->setText(QString());
        patientMobilelineEdit->setPlaceholderText(QCoreApplication::translate("Doctor", "Mobile", nullptr));
        patientPhonelineEdit->setText(QString());
        patientPhonelineEdit->setPlaceholderText(QCoreApplication::translate("Doctor", "Phone", nullptr));
        patientEmaillineEdit->setText(QString());
        patientEmaillineEdit->setPlaceholderText(QCoreApplication::translate("Doctor", "E-mail", nullptr));
        label_12->setText(QCoreApplication::translate("Doctor", "@", nullptr));
        Patient_comboBox->setItemText(0, QCoreApplication::translate("Doctor", "naver.com", nullptr));
        Patient_comboBox->setItemText(1, QCoreApplication::translate("Doctor", "gmail.com", nullptr));

        patientAddresslineEdit->setText(QString());
        patientAddresslineEdit->setPlaceholderText(QCoreApplication::translate("Doctor", "Address", nullptr));
        patientDetailAddresslineEdit->setText(QString());
        patientDetailAddresslineEdit->setPlaceholderText(QCoreApplication::translate("Doctor", "Detail Address", nullptr));
        Patient_Data_label->setText(QCoreApplication::translate("Doctor", "Data", nullptr));
        fileButton->setText(QCoreApplication::translate("Doctor", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Doctor: public Ui_Doctor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTOR_H
