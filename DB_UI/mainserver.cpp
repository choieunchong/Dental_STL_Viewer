#include "mainserver.h"
#include "ui_mainservcer.h"

MainServcer::MainServcer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainServcer)
{
    ui->setupUi(this);
}

MainServcer::~MainServcer()
{
    delete ui;
}
