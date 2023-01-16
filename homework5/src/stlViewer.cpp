#include "stlViewer.h"
#include <QDebug>
CustomInteractorStyle::CustomInteractorStyle()
{
    LastPickedActor = NULL;
    LastPickedActor1 = NULL;
    LastPickedActor2 = NULL;
    LastPickedProperty = vtkProperty::New();
    id = 0;
    flag1 = 0;
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
    vtkNew<vtkNamedColors> colors;
    int* clickPos = this->GetInteractor()->GetEventPosition();                          // 클릭된 위치
    vtkNew<vtkPropPicker> picker;
    picker->Pick(clickPos[0], clickPos[1], 0, this->GetCurrentRenderer());              // 피커에 현재 좌표값 설정, 피커는 렌더러

    if (this->LastPickedActor)                                                          // 처음에는 동작안함 null이라서
    {
        if (flag1 == 0)
        {
            this->LastPickedActor->GetProperty()->DeepCopy(this->LastPickedProperty);
            this->LastPickedActor->GetProperty()->EdgeVisibilityOff();
        }
        else
        {
            this->LastPickedProperty->DeepCopy(this->LastPickedActor->GetProperty());
            this->LastPickedActor->GetProperty()->DeepCopy(this->LastPickedProperty);       // 라스트 픽 프로퍼티 값을 액터 값으로 설정
            this->LastPickedActor->GetProperty()->EdgeVisibilityOff();
            flag1 = 0;
        }
    }
    this->LastPickedActor = picker->GetActor();                                         // 피커에서 액터 꺼내서 설정
    if (this->LastPickedActor)
    {
        this->LastPickedProperty->DeepCopy(this->LastPickedActor->GetProperty());       // 액터에서 프로퍼티 설정
        this->LastPickedActor2 = this->LastPickedActor;
        this->LastPickedActor->GetProperty()->SetColor(colors->GetColor3d("Red").GetData());
        this->LastPickedActor->GetProperty()->SetDiffuse(1.0);
        this->LastPickedActor->GetProperty()->SetSpecular(0.0);
        this->LastPickedActor->GetProperty()->EdgeVisibilityOn();
        //hash[id] = this->LastPickedActor;
        //id++;
    }
    else
    {
        this->LastPickedActor = this->LastPickedActor2;
        this->LastPickedActor->GetProperty()->DeepCopy(this->LastPickedProperty);
    }
    vtkInteractorStyleTrackballCamera::OnLeftButtonDown();
}

void CustomInteractorStyle::OnLeftButtonUp()
{

}

vtkActor* CustomInteractorStyle::OutputActor()
{
    return this->LastPickedActor;
}

void CustomInteractorStyle::GetFlag(int flag)
{
    flag1 = flag;
}