#pragma once

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <vtkSTLReader.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>
#include <QVTKInteractor.h>
#include <vtkInteractorStyle.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h> 
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkParallelCoordinatesInteractorStyle.h>
#include <vtkNamedColors.h>
#include <vtkMinimalStandardRandomSequence.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkObjectFactory.h>
#include <vtkPolyDataMapper.h>
#include <vtkPropPicker.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSphereSource.h>
#include "mainwindow.h"
#include <QHash>

QT_BEGIN_NAMESPACE
namespace Ui { class Doctor; }
QT_END_NAMESPACE

class QTextEdit;
class QLineEdit;
class QTcpSocket;
class QPushButton;
class QFile;
class QProgressDialog;

class CustomInteractorStyle : public vtkInteractorStyleTrackballCamera
{
public:
	CustomInteractorStyle();
	virtual ~CustomInteractorStyle();
	//static CustomInteractorStyle* New();
	vtkActor* OutputActor();
	void GetFlag(int flag);

protected:
	virtual void OnRightButtonDown() override;
	virtual void OnRightButtonUp() override;
	virtual void OnLeftButtonDown() override;
	virtual void OnLeftButtonUp() override;

private:
	vtkActor* LastPickedActor;                                                  // 액터
	vtkActor* LastPickedActor1;
	vtkActor* LastPickedActor2;
	vtkProperty* LastPickedProperty;                                            // 프로퍼티
	vtkProperty* LastPickedProperty2;
	QColor color1;
	QHash<int, vtkActor*> hash;
	int id;
	int flag1;
};
