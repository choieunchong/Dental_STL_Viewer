#include "CustomInteractorStyle.h"
#include <QDebug>
#include <TriMesh.h>

CustomInteractorStyle::CustomInteractorStyle()
{
	overCount = 0;
	lastSize = 1;
	pickCount = 0;
	size = 0;
	INF = 100000000;
	location = 0;
	findLocation = false;
	dsize = 0;
}

CustomInteractorStyle::~CustomInteractorStyle()
{

}

void CustomInteractorStyle::OnRightButtonDown()
{
	__super::OnLeftButtonDown();
}

void CustomInteractorStyle::OnRightButtonUp()
{
	__super::OnLeftButtonUp();
}

void CustomInteractorStyle::OnLeftButtonDown()
{
	int* pos = GetInteractor()->GetEventPosition();                                         // ���� ��ǥ ��

	vtkSmartPointer<vtkCellPicker>cellPicker = vtkSmartPointer<vtkCellPicker>::New();       // ����Ŀ ����
	cellPicker->SetTolerance(0.00001);                                                         // ��ŷ�� ������ ����?

	// Pick from this location
	cellPicker->Pick(pos[0], pos[1], 0, this->GetCurrentRenderer());                        // ����Ŀ ����

	double* worldPosition = cellPicker->GetPickPosition();                                  // �� ��Ŀ���� ���� ��ǥ ������

	if (cellPicker->GetCellId() != -1)
	{
		vtkNew<vtkNamedColors> colors;

		// Create a sphere
		vtkNew<vtkSphereSource> sphereSource;
		sphereSource->SetCenter(worldPosition[0], worldPosition[1], worldPosition[2]);
		sphereSource->SetRadius(0.3);
		// Make the surface smooth.
		sphereSource->SetPhiResolution(100);
		sphereSource->SetThetaResolution(100);                                                      // ���� ��ǥ���� �� ����

		OpenMesh::Vec3d pickingPosition(worldPosition[0], worldPosition[1], worldPosition[2]);      // ���� ��ǥ�� ���� ����

		vtkNew<vtkPolyDataMapper> mapper;                                                           // ���ۿ� �� ����
		mapper->SetInputConnection(sphereSource->GetOutputPort());
		vtkNew<vtkActor> mActor;                                                                    // ���Ϳ��� �� ����
		mActor->SetMapper(mapper);
		mActor->GetProperty()->SetColor(colors->GetColor3d("Red").GetData());

		mObserver->func(mActor);                                                                    // �������� �������� ����

		// ��Ŀ�� ���Ϳ��� ���������� ���� �ٿ�ĳ��Ʈ�ؼ� ���������� ����
		vtkSmartPointer<vtkPolyData> polyData = vtkPolyDataMapper::SafeDownCast(cellPicker->GetActor()->GetMapper())->GetInput();

		TriMesh triMesh = convertToMesh(polyData);              // ���������� �޽�ȭ
		double min;
		int flag = 0;
		OpenMesh::Vec3d minVec;

		// for�� �̿��ؼ� �� vertex�� ���Ѵ��� start vertex, end vertex�� ����. ���ͽ�Ʈ�� �̿��ؼ� �� �׸��� 
		for (TriMesh::FaceVertexIter fv_iter = triMesh.fv_begin(TriMesh::FaceHandle(cellPicker->GetCellId()));
			fv_iter != triMesh.fv_end(TriMesh::FaceHandle(cellPicker->GetCellId())); fv_iter++)
			// ���� ���� ���ؽ�(3��)��ŭ for�� ����
		{
			OpenMesh::Vec3d point = triMesh.point(fv_iter);         // point ��ȯ , ������ǥ���� ���� ����� vertex �Ÿ� ���
			OpenMesh::Vec3d diff = point - pickingPosition;         // ù��° ����Ʈ�� ��ŷ�� ��ġ������ ����
			double distance = diff.length();                        // ������ ����, �Ÿ��� ���� ���� vertex�� ���ؾ��Ѵ�.

			if (flag == 0)
			{
				min = distance;
				minVec = point;
			}
			else if (flag == 1)
			{
				if (min > distance)
				{
					minVec = point;
				}
			}
			flag = 1;
		}

		int minId;													// ��ŷ�� �������� ����� ���� ���̵�
		shortPointHash[pickCount] = minVec;							// ��ŷ�� �������� ����� ���� ����
		pickCount++;												// ��ŷ�� Ƚ��

		// (linearly) iterate over all vertices
		if (pickCount == 2)
		{
			pickCount = 0;
			overVector[0] = shortPointHash[0];
			for (TriMesh::VertexIter v_it = triMesh.vertices_sbegin(); v_it != triMesh.vertices_end(); ++v_it)
			{
				if (shortPointHash[0][0] == triMesh.point(*v_it)[0] && shortPointHash[0][1] == triMesh.point(*v_it)[1] && shortPointHash[0][2] == triMesh.point(*v_it)[2])
				{
					minId = v_it.handle().idx();                            // ��ŷ�� �������� ����� ���� ���̵� ����(ù ��° ���� ��)
					idHash[size] = minId;                                   // ��ŷ�� ���� ���̵�
					size++;
					break;
				}
			}
			for (TriMesh::VertexVertexIter vv_it = triMesh.vv_iter(OpenMesh::VertexHandle(minId)); vv_it.is_valid(); ++vv_it)
			{
				if (triMesh.point(*vv_it) != shortPointHash[0])
				{
					idHash[size] = vv_it.handle().idx();                        // ��ŷ�� ���� �ֺ����� ���̵�
					overVector[size] = (triMesh.point(*vv_it));                 // �ֺ� ����
					size++;                                                     // �ؽ��� ��ü ũ��
					overCount++;                                                // ������ ����
					if (triMesh.point(*vv_it)[0] == shortPointHash[1][0] && triMesh.point(*vv_it)[1] == shortPointHash[1][1] && triMesh.point(*vv_it)[2] == shortPointHash[1][2])
					{
						location = 0;
						findLocation = true;
						break;
					}
				}
			}
			nodeCount[idHash[0]] = overCount;                               // ù��° �� �ֺ� ��� ����
			vertexHash[idHash[0]] = overVector;   
			
			bool findDuplicate;
			while (findLocation == false)								// �ֺ����� �ֺ��� ���ϱ�
			{
				for (int i = 0; i < overCount; i++)         // �������� ������ ���ϱ�
				{
					int count = 0;
					for (TriMesh::VertexVertexIter vv_it = triMesh.vv_iter(OpenMesh::VertexHandle(idHash[lastSize + i])); vv_it.is_valid(); ++vv_it)
					{
						for (int j = 0; j < size; j++)						// �ߺ��� �˻�
						{
							if (vv_it.handle().idx() == idHash[j])
							{
								findDuplicate = true;
								break;
							}
							else
								findDuplicate = false;
						}
						if (findDuplicate == false)										// �ߺ� �ȵǴ� ��츸
						{
							idHash[size] = vv_it.handle().idx();
							overVector[size] = (triMesh.point(*vv_it));                // �ֺ� ����
							size++;
							count++;
							if (triMesh.point(*vv_it)[0] == shortPointHash[1][0] && triMesh.point(*vv_it)[1] == shortPointHash[1][1] && triMesh.point(*vv_it)[2] == shortPointHash[1][2])
							{
								findLocation = true;
								location = lastSize + i;
								break;
							}
						}
					}
					nodeCount[idHash[lastSize + i]] = count;                               // �ֺ����� �ֺ� ��� ����
					vertexHash[idHash[lastSize + i]] = overVector;                             // �ֺ����� �ֺ� ����
					if (findLocation == true) 
						break;
				}
				if (findLocation == true)
					break;
				lastSize = lastSize + overCount;
				overCount = size - lastSize;
			}       // ��λ��� ��� �����ϱ�

			qDebug() << lastSize << size;
			/*qDebug() << idHash;*/
			qDebug() << location;
			
			for (int i = 0; i < size; i++)
				d[idHash[i]] = INF;
			for (int i = 0; i < size; i++)
				parent[idHash[i]] = -1;

			int j = 1;
			for (int i = 0; i <= location; i++)
			{
				int count = 1;
				while (1)
				{
					if ((count <= nodeCount[idHash[i]]))
					{
						distance = (overVector[i] - vertexHash[idHash[i]][j]).length();
						vertexInfo[idHash[i]].push_back(make_pair(idHash[j], distance));
						//qDebug() << "(" << vertexHash[idHash[i]][j][0] << vertexHash[idHash[i]][j][1] << vertexHash[idHash[i]][j][2] << ")";
						if (vertexHash[idHash[i]][j][0] == shortPointHash[1][0] && vertexHash[idHash[i]][j][1] == shortPointHash[1][1] && vertexHash[idHash[i]][j][2] == shortPointHash[1][2])
							break;
						j++;
						count++;
					}
					else
						break;
				}
			}
			
			dijkstra(idHash[0]);

			vector<int> roadVec;
			int num = idHash[size - 1];
			while (num != 0)
			{
				roadVec.push_back(num);
				num = parent[num];
			}
			for (int i = roadVec.size() - 2; i >= 0; i--)
			{
				for (TriMesh::VertexIter v_it = triMesh.vertices_sbegin(); v_it != triMesh.vertices_end(); ++v_it)
				{
					if (v_it.handle().idx() == roadVec[i])
					{
						outputHash[dsize] = triMesh.point(*v_it);
						dsize++;
						break;
					}
				}
				qDebug() << "roadVec : " << roadVec[i] << " ";
			}
			for (int i = 0; i < dsize; i++)
			{
				vtkNew<vtkSphereSource> sphereSource2;
				sphereSource2->SetCenter(outputHash[i][0], outputHash[i][1], outputHash[i][2]);
				sphereSource2->SetRadius(0.2);
				// Make the surface smooth.
				sphereSource2->SetPhiResolution(100);
				sphereSource2->SetThetaResolution(100);                                                      // ���� ��ǥ���� �� ����

				vtkNew<vtkPolyDataMapper> mapper2;                                                           // ���ۿ� �� ����
				mapper2->SetInputConnection(sphereSource2->GetOutputPort());
				vtkNew<vtkActor> mActor2;                                                                    // ���Ϳ��� �� ����
				mActor2->SetMapper(mapper2);
				mActor2->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());

				mObserver->func(mActor2);
			}
			qDebug() << j;
			qDebug() << shortPointHash[1][0] << shortPointHash[1][1] << shortPointHash[1][2];
		}

		vtkNew<vtkSphereSource> sphereSource1;
		sphereSource1->SetCenter(minVec[0], minVec[1], minVec[2]);
		sphereSource1->SetRadius(0.3);
		// Make the surface smooth.
		sphereSource1->SetPhiResolution(100);
		sphereSource1->SetThetaResolution(100);                                                      // ���� ��ǥ���� �� ����

		vtkNew<vtkPolyDataMapper> mapper1;                                                           // ���ۿ� �� ����
		mapper1->SetInputConnection(sphereSource1->GetOutputPort());
		vtkNew<vtkActor> mActor1;                                                                    // ���Ϳ��� �� ����
		mActor1->SetMapper(mapper1);
		mActor1->GetProperty()->SetColor(colors->GetColor3d("Blue").GetData());

		mObserver->func(mActor1);

		//for (int i = 0; i < triMesh.n_vertices() / 2; i++)
		//{
		//    triMesh.delete_vertex(OpenMesh::VertexHandle(i));
		//}

		//triMesh.delete_face(OpenMesh::FaceHandle(cellPicker->GetCellId()));         // ��ŷ�� �� ����??
		qDebug() << "delete Cell ID : " << cellPicker->GetCellId();
		triMesh.garbage_collection();                                               // �޽� ������Ʈ

		vtkSmartPointer<vtkPolyData> meshToPoly = convertToPolyData(triMesh);       // �޽� ������ ���� �����ͷ� �ٲ�
		vtkPolyDataMapper::SafeDownCast(cellPicker->GetActor()->GetMapper())->SetInputData(meshToPoly);
		vtkPolyDataMapper::SafeDownCast(cellPicker->GetActor()->GetMapper())->Modified();           // ���ۿ� ������Ʈ
	}
}

void CustomInteractorStyle::OnLeftButtonUp()
{

}

void CustomInteractorStyle::OnMouseWheelForward()
{
	__super::OnMouseWheelForward();
}

void CustomInteractorStyle::OnMouseWheelBackward()
{
	__super::OnMouseWheelBackward();
}

void CustomInteractorStyle::GetPolyData(vtkSmartPointer<vtkPolyData> polyData)
{
	mPolyData = polyData;
}

void CustomInteractorStyle::GetSphere(vtkSmartPointer<vtkSphereSource> sphereSource)
{
	mSphere = sphereSource;
}

void CustomInteractorStyle::GetActor(vtkSmartPointer<vtkActor> sphereSource)
{
	mActor = sphereSource;
}

void CustomInteractorStyle::addObserver(Observer* observer)
{
	mObserver = observer;
}

TriMesh CustomInteractorStyle::convertToMesh(vtkSmartPointer<vtkPolyData> polyData)         // ���� �����͸� �޽��� �ٲ�
{
	int nPoints = polyData->GetNumberOfPoints();                                            // ���� ����
	int nCells = polyData->GetNumberOfCells();                                              // ���� ����

	TriMesh triMesh;                                                                        // �޽� 

	for (int vertexId = 0; vertexId < nPoints; ++vertexId)                                  // ��� ���� ���� ��ŭ
	{
		double* point = polyData->GetPoint(vertexId);                                       // ���ؽ� ���̵� �ش��ϴ� ���� �����Ϳ� ����
		triMesh.add_vertex(OpenMesh::Vec3d(point[0], point[1], point[2]));                  // �迭�� ���� �������� �߰�
	}

	for (int cellId = 0; cellId < nCells; ++cellId)                                         // ��� ���� ���� ��ŭ
	{
		int vertexId0 = polyData->GetCell(cellId)->GetPointIds()->GetId(0);                 // ���� ���ؽ� ���̵� ����
		int vertexId1 = polyData->GetCell(cellId)->GetPointIds()->GetId(1);
		int vertexId2 = polyData->GetCell(cellId)->GetPointIds()->GetId(2);

		OpenMesh::VertexHandle vertexHandle0(vertexId0);                                    // ���� �ٷ�� �ڵ鷯
		OpenMesh::VertexHandle vertexHandle1(vertexId1);
		OpenMesh::VertexHandle vertexHandle2(vertexId2);
		triMesh.add_face({ vertexHandle0, vertexHandle1, vertexHandle2 });                  // ���� ������ �迭�� ����
	}

	return triMesh;                         // �� + �� ����, (���� �������� + �鿡 �ش��ϴ� ���� ���̵�)
}

vtkSmartPointer<vtkPolyData> CustomInteractorStyle::convertToPolyData(TriMesh triMesh)      // �޽������͸� ���� �����ͷ� �ٲٴ� �Լ�
{
	vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();
	vtkSmartPointer<vtkPoints>   points = vtkSmartPointer<vtkPoints>::New();
	int vid = 0;

	for (TriMesh::VertexIter vertexItr = triMesh.vertices_begin(); vertexItr != triMesh.vertices_end(); ++vertexItr, ++vid)
	{                               // ���� ���� ��ŭ
		OpenMesh::Vec3d from = triMesh.point(*vertexItr);                           // ��� ���� ���� ����
		double* coords = from.data();                                               // coords�� ���� ��ǥ ����

		while (vid < vertexItr->idx())                                              // ��� ���� ���� ��ŭ point�� 0���� �ʱ�ȭ
		{
			vid++;
			points->InsertNextPoint(0, 0, 0);
		}
		points->InsertNextPoint(coords[0], coords[1], coords[2]);                   // ��� ���� x,y,z�� �Ҵ�              
	}
	polyData->SetPoints(points);                                                    // ���������Ϳ� �� ����

	vtkSmartPointer<vtkCellArray> cellArray = vtkSmartPointer<vtkCellArray>::New();
	for (TriMesh::FaceIter faceItr = triMesh.faces_begin(); faceItr != triMesh.faces_end(); ++faceItr)          // 3�� ����
	{
		TriMesh::FaceVertexIter   faceVertexItr;
		faceVertexItr = triMesh.cfv_iter(*faceItr);
		int   v0 = (faceVertexItr++).handle().idx();
		int   v1 = (faceVertexItr++).handle().idx();
		int   v2 = faceVertexItr.handle().idx();                                                            // �� ���� ���̵� ����

		vtkSmartPointer<vtkTriangle> triangle = vtkSmartPointer<vtkTriangle>::New();
		triangle->GetPointIds()->SetId(0, v0);
		triangle->GetPointIds()->SetId(1, v1);
		triangle->GetPointIds()->SetId(2, v2);
		cellArray->InsertNextCell(triangle);                                                                // ������ �迭�� ����
	}
	polyData->SetPolys(cellArray);                                                          // ���������Ϳ� ������ ����
	polyData->Modified();

	return polyData;                            // ���������� = �� ��ǥ + �� ����
}

void CustomInteractorStyle::dijkstra(int start)
{
	d[start] = 0;
	priority_queue<pair<int, int> > pq;         // ������, ���� ū ������� ���ĵ�
	pq.push(make_pair(start, 0));

	while (!pq.empty())
	{
		int current = pq.top().first;
		int distance1 = -pq.top().second;         // ũ�Ⱑ ���� ū ���� �������� �ݴ�� �ϱ� ���� �Ϻη� ���� -���� ����
		pq.pop();

		if (d[current] < distance1)
			continue;

		for (int i = 0; i < vertexInfo[current].size(); i++)
		{
			int next = vertexInfo[current][i].first;
			double nextDistance = distance1 + vertexInfo[current][i].second;

			if (nextDistance <= d[next])
			{
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
				parent[next] = current;
			}
		}
	}
}