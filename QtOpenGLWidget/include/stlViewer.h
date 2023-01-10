#pragma once

#include <doctor.h>
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
	~CustomInteractorStyle();
	
protected:
	virtual void OnRightButtonDown() override;
	virtual void OnRightButtonUp() override;
	virtual void OnLeftButtonDown() override;
	virtual void OnLeftButtonUp() override;
};
