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
	int* pos = GetInteractor()->GetEventPosition();                                         // 현재 좌표 값

	vtkSmartPointer<vtkCellPicker>cellPicker = vtkSmartPointer<vtkCellPicker>::New();       // 셀피커 선언
	cellPicker->SetTolerance(0.00001);                                                         // 피킹할 면적을 지정?

	// Pick from this location
	cellPicker->Pick(pos[0], pos[1], 0, this->GetCurrentRenderer());                        // 셀피커 정의

	double* worldPosition = cellPicker->GetPickPosition();                                  // 셀 피커에서 월드 좌표 가져옴

	if (cellPicker->GetCellId() != -1)
	{
		vtkNew<vtkNamedColors> colors;

		// Create a sphere
		vtkNew<vtkSphereSource> sphereSource;
		sphereSource->SetCenter(worldPosition[0], worldPosition[1], worldPosition[2]);
		sphereSource->SetRadius(0.3);
		// Make the surface smooth.
		sphereSource->SetPhiResolution(100);
		sphereSource->SetThetaResolution(100);                                                      // 월드 좌표에서 구 생성

		OpenMesh::Vec3d pickingPosition(worldPosition[0], worldPosition[1], worldPosition[2]);      // 월드 좌표로 벡터 생성

		vtkNew<vtkPolyDataMapper> mapper;                                                           // 매퍼에 구 넣음
		mapper->SetInputConnection(sphereSource->GetOutputPort());
		vtkNew<vtkActor> mActor;                                                                    // 액터에서 색 지정
		mActor->SetMapper(mapper);
		mActor->GetProperty()->SetColor(colors->GetColor3d("Red").GetData());

		mObserver->func(mActor);                                                                    // 옵저버로 액터정보 보냄

		// 피커의 액터에서 매퍼정보를 꺼내 다운캐스트해서 폴리데이터 꺼냄
		vtkSmartPointer<vtkPolyData> polyData = vtkPolyDataMapper::SafeDownCast(cellPicker->GetActor()->GetMapper())->GetInput();

		TriMesh triMesh = convertToMesh(polyData);              // 폴리데이터 메쉬화
		double min;
		int flag = 0;
		OpenMesh::Vec3d minVec;

		// for문 이용해서 각 vertex를 구한다음 start vertex, end vertex를 지정. 다익스트라를 이용해서 선 그리기 
		for (TriMesh::FaceVertexIter fv_iter = triMesh.fv_begin(TriMesh::FaceHandle(cellPicker->GetCellId()));
			fv_iter != triMesh.fv_end(TriMesh::FaceHandle(cellPicker->GetCellId())); fv_iter++)
			// 찍은 면의 버텍스(3개)만큼 for문 돌림
		{
			OpenMesh::Vec3d point = triMesh.point(fv_iter);         // point 반환 , 월드좌표에서 가장 가까운 vertex 거리 출력
			OpenMesh::Vec3d diff = point - pickingPosition;         // 첫번째 포인트와 피킹한 위치사이의 벡터
			double distance = diff.length();                        // 벡터의 길이, 거리가 가장 적은 vertex를 구해야한다.

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

		int minId;													// 피킹한 지점에서 가까운 점의 아이디
		shortPointHash[pickCount] = minVec;							// 피킹한 지점에서 가까운 점의 벡터
		pickCount++;												// 피킹한 횟수

		// (linearly) iterate over all vertices
		if (pickCount == 2)
		{
			pickCount = 0;
			overVector[0] = shortPointHash[0];
			for (TriMesh::VertexIter v_it = triMesh.vertices_sbegin(); v_it != triMesh.vertices_end(); ++v_it)
			{
				if (shortPointHash[0][0] == triMesh.point(*v_it)[0] && shortPointHash[0][1] == triMesh.point(*v_it)[1] && shortPointHash[0][2] == triMesh.point(*v_it)[2])
				{
					minId = v_it.handle().idx();                            // 피킹한 지점에서 가까운 점의 아이디 저장(첫 번째 찍은 점)
					idHash[size] = minId;                                   // 피킹한 점의 아이디
					size++;
					break;
				}
			}
			for (TriMesh::VertexVertexIter vv_it = triMesh.vv_iter(OpenMesh::VertexHandle(minId)); vv_it.is_valid(); ++vv_it)
			{
				if (triMesh.point(*vv_it) != shortPointHash[0])
				{
					idHash[size] = vv_it.handle().idx();                        // 피킹한 점의 주변점의 아이디
					overVector[size] = (triMesh.point(*vv_it));                 // 주변 벡터
					size++;                                                     // 해쉬의 전체 크기
					overCount++;                                                // 근접점 개수
					if (triMesh.point(*vv_it)[0] == shortPointHash[1][0] && triMesh.point(*vv_it)[1] == shortPointHash[1][1] && triMesh.point(*vv_it)[2] == shortPointHash[1][2])
					{
						location = 0;
						findLocation = true;
						break;
					}
				}
			}
			nodeCount[idHash[0]] = overCount;                               // 첫번째 점 주변 노드 개수
			vertexHash[idHash[0]] = overVector;   
			
			bool findDuplicate;
			while (findLocation == false)								// 주변점의 주변점 구하기
			{
				for (int i = 0; i < overCount; i++)         // 근접점의 근접점 구하기
				{
					int count = 0;
					for (TriMesh::VertexVertexIter vv_it = triMesh.vv_iter(OpenMesh::VertexHandle(idHash[lastSize + i])); vv_it.is_valid(); ++vv_it)
					{
						for (int j = 0; j < size; j++)						// 중복점 검사
						{
							if (vv_it.handle().idx() == idHash[j])
							{
								findDuplicate = true;
								break;
							}
							else
								findDuplicate = false;
						}
						if (findDuplicate == false)										// 중복 안되는 경우만
						{
							idHash[size] = vv_it.handle().idx();
							overVector[size] = (triMesh.point(*vv_it));                // 주변 벡터
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
					nodeCount[idHash[lastSize + i]] = count;                               // 주변점의 주변 노드 개수
					vertexHash[idHash[lastSize + i]] = overVector;                             // 주변점의 주변 벡터
					if (findLocation == true) 
						break;
				}
				if (findLocation == true)
					break;
				lastSize = lastSize + overCount;
				overCount = size - lastSize;
			}       // 경로상의 모든 점구하기

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
				sphereSource2->SetThetaResolution(100);                                                      // 월드 좌표에서 구 생성

				vtkNew<vtkPolyDataMapper> mapper2;                                                           // 매퍼에 구 넣음
				mapper2->SetInputConnection(sphereSource2->GetOutputPort());
				vtkNew<vtkActor> mActor2;                                                                    // 액터에서 색 지정
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
		sphereSource1->SetThetaResolution(100);                                                      // 월드 좌표에서 구 생성

		vtkNew<vtkPolyDataMapper> mapper1;                                                           // 매퍼에 구 넣음
		mapper1->SetInputConnection(sphereSource1->GetOutputPort());
		vtkNew<vtkActor> mActor1;                                                                    // 액터에서 색 지정
		mActor1->SetMapper(mapper1);
		mActor1->GetProperty()->SetColor(colors->GetColor3d("Blue").GetData());

		mObserver->func(mActor1);

		//for (int i = 0; i < triMesh.n_vertices() / 2; i++)
		//{
		//    triMesh.delete_vertex(OpenMesh::VertexHandle(i));
		//}

		//triMesh.delete_face(OpenMesh::FaceHandle(cellPicker->GetCellId()));         // 피킹한 면 삭제??
		qDebug() << "delete Cell ID : " << cellPicker->GetCellId();
		triMesh.garbage_collection();                                               // 메쉬 업데이트

		vtkSmartPointer<vtkPolyData> meshToPoly = convertToPolyData(triMesh);       // 메쉬 데이터 폴리 데이터로 바꿈
		vtkPolyDataMapper::SafeDownCast(cellPicker->GetActor()->GetMapper())->SetInputData(meshToPoly);
		vtkPolyDataMapper::SafeDownCast(cellPicker->GetActor()->GetMapper())->Modified();           // 매퍼에 업데이트
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

TriMesh CustomInteractorStyle::convertToMesh(vtkSmartPointer<vtkPolyData> polyData)         // 폴리 데이터를 메쉬로 바꿈
{
	int nPoints = polyData->GetNumberOfPoints();                                            // 점의 개수
	int nCells = polyData->GetNumberOfCells();                                              // 면의 개수

	TriMesh triMesh;                                                                        // 메쉬 

	for (int vertexId = 0; vertexId < nPoints; ++vertexId)                                  // 모든 점의 개수 만큼
	{
		double* point = polyData->GetPoint(vertexId);                                       // 버텍스 아이디에 해당하는 점을 포인터에 저장
		triMesh.add_vertex(OpenMesh::Vec3d(point[0], point[1], point[2]));                  // 배열에 점의 벡터정보 추가
	}

	for (int cellId = 0; cellId < nCells; ++cellId)                                         // 모든 면의 개수 만큼
	{
		int vertexId0 = polyData->GetCell(cellId)->GetPointIds()->GetId(0);                 // 면의 버텍스 아이디 저장
		int vertexId1 = polyData->GetCell(cellId)->GetPointIds()->GetId(1);
		int vertexId2 = polyData->GetCell(cellId)->GetPointIds()->GetId(2);

		OpenMesh::VertexHandle vertexHandle0(vertexId0);                                    // 점을 다루는 핸들러
		OpenMesh::VertexHandle vertexHandle1(vertexId1);
		OpenMesh::VertexHandle vertexHandle2(vertexId2);
		triMesh.add_face({ vertexHandle0, vertexHandle1, vertexHandle2 });                  // 면의 정보를 배열에 담음
	}

	return triMesh;                         // 점 + 면 정보, (점의 벡터정보 + 면에 해당하는 점의 아이디)
}

vtkSmartPointer<vtkPolyData> CustomInteractorStyle::convertToPolyData(TriMesh triMesh)      // 메쉬데이터를 폴리 데이터로 바꾸는 함수
{
	vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();
	vtkSmartPointer<vtkPoints>   points = vtkSmartPointer<vtkPoints>::New();
	int vid = 0;

	for (TriMesh::VertexIter vertexItr = triMesh.vertices_begin(); vertexItr != triMesh.vertices_end(); ++vertexItr, ++vid)
	{                               // 점의 개수 만큼
		OpenMesh::Vec3d from = triMesh.point(*vertexItr);                           // 모든 점의 벡터 저장
		double* coords = from.data();                                               // coords에 점의 좌표 저장

		while (vid < vertexItr->idx())                                              // 모든 점의 개수 만큼 point를 0으로 초기화
		{
			vid++;
			points->InsertNextPoint(0, 0, 0);
		}
		points->InsertNextPoint(coords[0], coords[1], coords[2]);                   // 모든 점에 x,y,z값 할당              
	}
	polyData->SetPoints(points);                                                    // 폴리데이터에 점 정보

	vtkSmartPointer<vtkCellArray> cellArray = vtkSmartPointer<vtkCellArray>::New();
	for (TriMesh::FaceIter faceItr = triMesh.faces_begin(); faceItr != triMesh.faces_end(); ++faceItr)          // 3번 돌음
	{
		TriMesh::FaceVertexIter   faceVertexItr;
		faceVertexItr = triMesh.cfv_iter(*faceItr);
		int   v0 = (faceVertexItr++).handle().idx();
		int   v1 = (faceVertexItr++).handle().idx();
		int   v2 = faceVertexItr.handle().idx();                                                            // 각 점의 아이디 저장

		vtkSmartPointer<vtkTriangle> triangle = vtkSmartPointer<vtkTriangle>::New();
		triangle->GetPointIds()->SetId(0, v0);
		triangle->GetPointIds()->SetId(1, v1);
		triangle->GetPointIds()->SetId(2, v2);
		cellArray->InsertNextCell(triangle);                                                                // 면정보 배열에 넣음
	}
	polyData->SetPolys(cellArray);                                                          // 폴리데이터에 면정보 넣음
	polyData->Modified();

	return polyData;                            // 폴리데이터 = 점 좌표 + 면 정보
}

void CustomInteractorStyle::dijkstra(int start)
{
	d[start] = 0;
	priority_queue<pair<int, int> > pq;         // 힙구조, 값이 큰 순서대로 정렬됨
	pq.push(make_pair(start, 0));

	while (!pq.empty())
	{
		int current = pq.top().first;
		int distance1 = -pq.top().second;         // 크기가 가장 큰 값이 나오지만 반대로 하기 위해 일부러 값에 -값을 붙임
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