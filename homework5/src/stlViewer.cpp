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
    int* clickPos = this->GetInteractor()->GetEventPosition();                          // Ŭ���� ��ġ
    vtkNew<vtkPropPicker> picker;
    picker->Pick(clickPos[0], clickPos[1], 0, this->GetCurrentRenderer());              // ��Ŀ�� ���� ��ǥ�� ����, ��Ŀ�� ������

    if (this->LastPickedActor)                                                          // ó������ ���۾��� null�̶�
    {
        if (flag1 == 0)
        {
            this->LastPickedActor->GetProperty()->DeepCopy(this->LastPickedProperty);
            this->LastPickedActor->GetProperty()->EdgeVisibilityOff();
        }
        else
        {
            this->LastPickedProperty->DeepCopy(this->LastPickedActor->GetProperty());
            this->LastPickedActor->GetProperty()->DeepCopy(this->LastPickedProperty);       // ��Ʈ �� ������Ƽ ���� ���� ������ ����
            this->LastPickedActor->GetProperty()->EdgeVisibilityOff();
            flag1 = 0;
        }
    }
    this->LastPickedActor = picker->GetActor();                                         // ��Ŀ���� ���� ������ ����
    if (this->LastPickedActor)
    {
        this->LastPickedProperty->DeepCopy(this->LastPickedActor->GetProperty());       // ���Ϳ��� ������Ƽ ����
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