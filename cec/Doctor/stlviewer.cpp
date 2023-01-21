#include "stlviewer.h"
#include "ui_stlviewer.h"

STLViewer::STLViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::STLViewer)
{
    ui->setupUi(this);
}

STLViewer::~STLViewer()
{
    delete ui;
}
