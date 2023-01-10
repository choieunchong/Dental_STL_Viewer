#ifndef DOCTOR_H
#define DOCTOR_H

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

typedef enum {
    Send_Info,
    Get_Info,
    Request_Info,
} Patient_Info;

typedef enum {
    nurse,
    doctor,
} From_Who;

class Doctor : public QWidget, public vtkInteractorStyleTrackballCamera
{
    Q_OBJECT

public:
    Doctor(QWidget *parent = nullptr);
    ~Doctor();

    //const int PORT_NUMBER = 8000;
    void loadDB();

private slots:
    void on_patientNewpushButton_clicked();
    void on_patientGenderMalepushButton_clicked();
    void on_patientGenderFemalepushButton_clicked();
    void on_patientGenderNonepushButton_clicked();
    void receiveData( );                                            // 서버에서 데이터가 올 때
    void sendData( );                                               // 서버로 데이터를 보낼 때
//    void acceptConnection();
//    void readClient();
    void goOnSend(qint64 numBytes);
    void sendFile();


private:
    Ui::Doctor *ui;
    int makeChartNo();                                                  // 차트번호 생성
    QString patientFirstVisitDate, patientLastVisitDate;                // 환자 첫 방문, 마지막 방문
    QString patientName, patientGender, patientMobile, patientPhone;    // 환자 이름, 성별, 전화번호, 핸드폰 번호
    QString patientEmail, patientAddress, patientDetailAddress;         // 환자 이메일, 주소, 상세주소
    QString patientBirth, patient_last_visit;                           // 환자 생년원일, 마지막 진료일
    int patientChartNumber;                                             // 차트번호
    QSqlTableModel *patientModel;

    QProgressDialog* progressDialog;                                // 파일 진행 확인
    QFile* file;                                                    // 서버로 보내는 파일
    qint64 loadSize;                                                // 파일의 크기
    qint64 byteToWrite;                                             // 보내는 파일의 크기
    qint64 totalSize;                                               // 전체 파일의 크기
    QByteArray outBlock;                                            // 전송을 위한 데이터
    bool isSent;                                                    // 파일 서버에 접속되었는지 확인

    void closeEvent(QCloseEvent*) override;
    QTcpSocket *clientSocket;                                       // 클라이언트용 소켓
    QTcpSocket *fileClient;


    void loadSTL();

    // STL Reader
    vtkSmartPointer<vtkSTLReader> mUpperReader;
    vtkSmartPointer<vtkSTLReader> mLowerReader;
    vtkSmartPointer<vtkSTLReader> mOcclusionReader;

    // VTK Renderer
    vtkSmartPointer<vtkRenderer> mUpperRenderer;
    vtkSmartPointer<vtkRenderer> mLowerRenderer;
    vtkSmartPointer<vtkRenderer> mOcclusionRenderer;

    // VTK Render Window
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> mUpperWindow;
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> mLowerWindow;
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> mOcclusionWindow;

    // VTK Interactor
    vtkSmartPointer<QVTKInteractor> mUpperInteractor;
    vtkSmartPointer<QVTKInteractor> mLowerInteractor;
    vtkSmartPointer<QVTKInteractor> mOcclusionInteractor;

    // VTK Mapper
    //vtkSmartPointer<vtkPolyDataMapper> mUpperMapper;
    //vtkSmartPointer<vtkPolyDataMapper> mLowerMapper;
    //vtkSmartPointer<vtkPolyDataMapper> mOcclusionMapper;

    // VTK Actor
    //vtkSmartPointer<vtkActor> mUpperActor;
    //vtkSmartPointer<vtkActor> mLowerActor;
    //vtkSmartPointer<vtkActor> mOcclusionActor;
};
#endif // DOCTOR_H
