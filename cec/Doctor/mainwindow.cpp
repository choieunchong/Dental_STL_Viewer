#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "doctor.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // this->setStyleSheet("background-color:#003458;");
    QToolBar tool;
    this->setStyleSheet("QToolBar{ background-color:#666666;}"
                        "QToolButton:hover {background: #5d7180; border: 1px groove #293843;}"
                       );

    this->resize(1920,1080);
    doctor = new Doctor(ui->widget);

//    doctor->loadDB();
}

MainWindow::~MainWindow()
{
    delete ui;
}

