#pragma once
#include <QVTKOpenGLNativeWidget.h>
#include <QVTKInteractorAdapter.h>

class CustomVTKWidget : public QVTKOpenGLNativeWidget 
{
public:
    CustomVTKWidget();
	CustomVTKWidget(QWidget* parent);
	~CustomVTKWidget();

protected:
    // VTK Renderer
    vtkSmartPointer<vtkRenderer> mRenderer; 

    // VTK Render Window
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> mRenderWindow; 
    vtkSmartPointer<QVTKInteractor> mInteractor;
    QVTKInteractorAdapter* mvtkInteractorAdapter;
};