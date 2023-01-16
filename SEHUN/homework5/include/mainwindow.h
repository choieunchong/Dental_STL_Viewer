#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <vtkSTLReader.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include "CustomVTKWidget.h"
#include <vtkProperty.h>
#include <QColorDialog>
#include <QWidget>
#include <QColorDialog>
#include "wheel.h"
#include "stlViewer.h"
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QColorDialogTester;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();


public slots:
    void on_open_triggered();
    void on_color_triggered();
    void getColor(QColor);

private:
    Ui::MainWindow* ui;

    vtkSmartPointer<vtkSTLReader> reader;
    vtkSmartPointer<vtkPolyData> polydata;
    vtkSmartPointer<vtkPolyData> loadStl(QString filename);
    
    QColorDialog* test;
    vtkSmartPointer<vtkActor> actor;

signals:
    void send_key(int);
};
#endif // MAINWINDOW_H
