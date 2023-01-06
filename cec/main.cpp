#include <vtkAutoInit.h>
#define vtkRenderingCore_AUTOINT \
4(vtkRenderingOpenGL2_AUTOINIT,vtkInteractionStyle,vtkRenderingFreeType,vtkRenderingcontextOpenGL)
#define vtkRenderingVolume_AUTOINIT 1(vtkRenderingVolumeOpenGL)
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include<vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkConeSource.h>
#include <vtkPolyDataNormals.h>
#include <vtkSTLReader.h>
#include <QtWidgets/QApplication>
#include <vtkSTLWriter.h>
#include <vtkDecimatePro.h>
#include <vtkQuadricClustering.h>



void main()
{
	vtkSmartPointer<vtkSTLReader>stlReader =
		vtkSmartPointer<vtkSTLReader>::New();
	stlReader->SetFileName("Body.stl");
	stlReader->Update();

	vtkSmartPointer<vtkDecimatePro>decimarePro =
		vtkSmartPointer<vtkDecimatePro>::New();
	decimarePro->SetInputConnection(stlReader->GetOutputPort());
	decimarePro->SetTargetReduction(0.9);
	decimarePro->PreserveTopologyOn();
	decimarePro->Update();

	vtkSmartPointer<vtkQuadricClustering> qClustering =
		vtkSmartPointer<vtkQuadricClustering>::New();
	qClustering->SetInputConnection(stlReader->GetOutputPort());
	qClustering->SetNumberOfDivisions(10, 10, 10);
	qClustering->Update();

	vtkSmartPointer<vtkPolyDataMapper> mapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();

	mapper->SetInputConnection(decimarePro->GetOutputPort());

	vtkSmartPointer<vtkActor> actor =
		vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);

	vtkSmartPointer<vtkRenderer> renderer =
		vtkSmartPointer<vtkRenderer>::New();
	renderer->AddActor(actor);
	renderer->SetBackground(.1, .2, .3);
	renderer->ResetCamera();


	vtkSmartPointer<vtkRenderWindow> m_vtkWindow =
		vtkSmartPointer<vtkRenderWindow>::New();
	m_vtkWindow->AddRenderer(renderer);
	m_vtkWindow->Render();

	vtkSmartPointer<vtkRenderWindowInteractor>interactor = vtkSmartPointer< vtkRenderWindowInteractor>::New();
	interactor->SetRenderWindow(m_vtkWindow);
	interactor->Start();

}


