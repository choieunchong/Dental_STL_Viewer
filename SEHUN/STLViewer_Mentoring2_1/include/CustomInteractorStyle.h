#pragma once

#include <QWidget> 
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>
#include <QVTKInteractor.h>
#include <vtkInteractorStyle.h> 
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkParallelCoordinatesInteractorStyle.h>
#include <vtkPolyData.h>
#include <vtkCellPicker.h>
#include <vtkIdTypeArray.h>
#include <vtkSelectionNode.h>
#include <vtkSelection.h>
#include <vtkExtractSelection.h>
#include <vtkNamedColors.h>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkTriangle.h>
#include "observer.h"
#include "TriMesh.h"
#include <vtkDijkstraGraphGeodesicPath.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class CustomInteractorStyle : public vtkInteractorStyleTrackballCamera
{
public:
	CustomInteractorStyle();
	~CustomInteractorStyle();
	
	void GetPolyData(vtkSmartPointer<vtkPolyData>);
	void GetSphere(vtkSmartPointer<vtkSphereSource>);
	void GetActor(vtkSmartPointer<vtkActor>);
	void dijkstra(int start);
	std::vector<int> dijkstra(int startIdx, int endIdx, const TriMesh& triMesh);

	void addObserver(Observer*);

protected:
	virtual void OnRightButtonDown() override;
	virtual void OnRightButtonUp() override;
	virtual void OnLeftButtonDown() override;
	virtual void OnLeftButtonUp() override;

	virtual void OnMouseWheelForward() override;
	virtual void OnMouseWheelBackward() override;

	TriMesh convertToMesh(vtkSmartPointer<vtkPolyData>);
	vtkSmartPointer<vtkPolyData> convertToPolyData(TriMesh);
	 
private:
	vtkSmartPointer<vtkPolyData> mPolyData;
	vtkSmartPointer<vtkSphereSource> mSphere;
	vtkSmartPointer<vtkActor> mActor;
	int pickCount;
	int overCount;
	int lastSize;
	int size;
	int INF;
	int start;
	bool findLocation;
	int location;
	int dsize;
	double distance;
	double d[100000];
	int parent[100000];
	vector<pair<int, double>> vertexInfo[100000];
	QHash<int, OpenMesh::Vec3d> overVector;
	QHash<int, int> idHash;
	QHash<int, OpenMesh::Vec3d> shortPointHash;
	QHash<int, QHash<int, OpenMesh::Vec3d>> vertexHash;
	QHash<int, int> nodeCount;
	QHash<int, OpenMesh::Vec3d> outputHash;
	Observer* mObserver;
};
