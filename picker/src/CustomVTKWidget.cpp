#include "CustomVTKWidget.h"
#include <vtkGenericOpenGLRenderWindow.h>

#include <QVTKInteractor.h>
#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkCellArray.h>
#include <vtkFloatArray.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPointData.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>


CustomVTKWidget::CustomVTKWidget()
{

}

CustomVTKWidget::CustomVTKWidget(QWidget* parent)
	: QVTKOpenGLNativeWidget(parent)
{
	mRenderer = vtkSmartPointer<vtkRenderer>::New();
	mRenderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	setRenderWindow(mRenderWindow);
	mRenderWindow->AddRenderer(mRenderer);
	customInteractorStyle = new CustomInteractorStyle;
	//customInteractorStyle->SetDefaultRenderer(mRenderer);
	mInteractor = vtkSmartPointer<QVTKInteractor>::New();
	mRenderWindow->SetInteractor(mInteractor);
	mInteractor->Initialize();
	customInteractorStyle->SetCurrentRenderer(mRenderer);
	mInteractor->SetInteractorStyle(customInteractorStyle);
	mInteractor->Start();
	customInteractorStyle->Delete();
	
	mvtkInteractorAdapter = new QVTKInteractorAdapter(this);
}

CustomVTKWidget::~CustomVTKWidget()
{
	vtkSmartPointer<vtkActor> mUpperActor = vtkSmartPointer<vtkActor>::New();
}

void CustomVTKWidget::addActor(vtkSmartPointer<vtkActor> actor)
{
	mRenderer->AddActor(actor);
}

vtkActor* CustomVTKWidget::OutputActor()
{
	return customInteractorStyle->OutputActor();
}

void CustomVTKWidget::GetFlag(int flag)
{
	customInteractorStyle->GetFlag(flag);
}