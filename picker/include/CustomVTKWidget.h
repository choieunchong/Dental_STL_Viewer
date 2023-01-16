#pragma once
#include <QVTKOpenGLNativeWidget.h>
#include <QVTKInteractorAdapter.h>
#include <vtkActor.h>
#include "stlViewer.h"

class CustomInteractorStyle;

class CustomVTKWidget : public QVTKOpenGLNativeWidget 
{
public:
    CustomVTKWidget();
	CustomVTKWidget(QWidget* parent);
	~CustomVTKWidget();
    void addActor(vtkSmartPointer<vtkActor>);
    vtkActor* OutputActor();
    CustomInteractorStyle* customInteractorStyle;
    void GetFlag(int flag);

protected:
    // VTK Renderer
    vtkSmartPointer<vtkRenderer> mRenderer; 

    // VTK Render Window
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> mRenderWindow; 
    vtkSmartPointer<QVTKInteractor> mInteractor;
    QVTKInteractorAdapter* mvtkInteractorAdapter;

private:
    QColor color1;
};