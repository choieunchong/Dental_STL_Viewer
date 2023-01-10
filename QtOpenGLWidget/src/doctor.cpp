#include "doctor.h"
#include "ui_doctor.h"
#include <QDebug>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QDataStream>
#include <QTcpSocket>
#include <QApplication>
#include <QThread>
#include <QMessageBox>
#include <QSettings>
#include <QProgressDialog>
#include <QFileDialog>
#include <vtkInteractorStyleTrackballCamera.h>
#include "CustomVTKWidget.h"

#define BLOCK_SIZE      1024

Doctor::Doctor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Doctor),
    mLowerWindow(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New()),
    mLowerRenderer(vtkSmartPointer<vtkRenderer>::New()),
    mLowerInteractor(vtkSmartPointer<QVTKInteractor>::New()),
    mLowerReader(vtkSmartPointer<vtkSTLReader>::New()),  
    mUpperWindow(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New()),
    mUpperRenderer(vtkSmartPointer<vtkRenderer>::New()),
    mUpperInteractor(vtkSmartPointer<QVTKInteractor>::New()),
    mUpperReader(vtkSmartPointer<vtkSTLReader>::New()), 
    mOcclusionWindow(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New()),
    mOcclusionRenderer(vtkSmartPointer<vtkRenderer>::New()),
    mOcclusionInteractor(vtkSmartPointer<QVTKInteractor>::New()),
    mOcclusionReader(vtkSmartPointer<vtkSTLReader>::New())
{
    ui->setupUi(this);

    // Set Up the Rendering
    mUpperWindow->AddRenderer(mUpperRenderer);
    mLowerWindow->AddRenderer(mLowerRenderer);
    mOcclusionWindow->AddRenderer(mOcclusionRenderer);
    ui->patientDataupperopenGLWidget->setRenderWindow(mUpperWindow);
    ui->patientDataloweropenGLWidget->setRenderWindow(mLowerWindow);
    ui->patientDataocclusionopenGLWidget->setRenderWindow(mOcclusionWindow);

    clientSocket = new QTcpSocket(this);                                                        // 채팅을 위한 소켓 생성
    connect(clientSocket, &QAbstractSocket::errorOccurred,
            [=]{ qDebug( ) << clientSocket->errorString( ); });                                 // 에러 발생 시 에러메세지
    connect(clientSocket, SIGNAL(readyRead( )), SLOT(receiveData( )));                          // 읽을 준비가 되면 receiveData 슬롯
    connect(clientSocket, SIGNAL(disconnected( )), SLOT(disconnect( )));                        // 연결 종료시 disconnect 슬롯
    connect(ui->patientNewpushButton, SIGNAL(clicked( )), SLOT(sendData( ))); 

    fileClient = new QTcpSocket(this);                                                          // 파일전송을 위한 소켓 생성
    connect(fileClient, SIGNAL(bytesWritten(qint64)), SLOT(goOnSend(qint64)));                  // 파일소켓에 데이터를 쓸 때 goOnSend 슬롯 발생
//    connect(ui->fileButton, SIGNAL(clicked( )), SLOT(sendFile( )));                             // fileButton 누르면 sendFile 슬롯 발생
    progressDialog = new QProgressDialog(0);                                                    // progressDialog 생성 후 0으로 초기화
    progressDialog->setAutoClose(true);                                                         // 파일전송이 끝나면 progressDialog 자동종료
    progressDialog->reset();
    setWindowTitle(tr("Chat Client"));
    // 상악,하악,교합 위젯에 STL 파일 띄우기
    loadSTL();
}

Doctor::~Doctor()
{
    delete ui;
    clientSocket->close( );                                                                     // 소켓 닫음
}

void Doctor::loadDB()                   // DB에 저장된 환자 정보 받아오기
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","Patient");
    db.setDatabaseName("patient.db");
    if(db.open()) {
        QSqlQuery query(db);
        query.exec("create table if not exists patient(\
                   PA_NAME             varchar2(20),\
                   PA_BIRTH            date,\
                   PA_CHART_NO_PK      number(10),\
                   PA_GENDER           varchar2(20),\
                   PA_FIRST_VISIT      date,\
                   PA_LAST_VISIT       date,\
                   PA_PHONE_NUM        varchar2(20),\
                   PA_EMAIL            varchar2(20),\
                   PA_ADDRESS          varchar2(20),\
                   PA_DETAIL_ADDRESS   varchar2(20),\
                   PA_STL_PATH         varchar2(20));");

        patientModel = new QSqlTableModel(this,db);
        patientModel->setTable("patient");
        patientModel->select();
        patientModel->setHeaderData(0, Qt::Horizontal, QObject::tr("PA_CHART_NO_PK"));
        patientModel->setHeaderData(1, Qt::Horizontal, QObject::tr("PA_NAME"));
        patientModel->setHeaderData(2, Qt::Horizontal, QObject::tr("PA_BIRTH"));
        patientModel->setHeaderData(3, Qt::Horizontal, QObject::tr("PA_GENDER"));
        patientModel->setHeaderData(4, Qt::Horizontal, QObject::tr("PA_FIRST_VISIT"));
        patientModel->setHeaderData(5, Qt::Horizontal, QObject::tr("PA_LAST_VISIT"));

        ui->patientlistView->setModel(patientModel);
    }
}

int Doctor::makeChartNo()               // 차트 번호 만들기
{
    if(patientModel->rowCount() == 0) {
        return 1000;
    } else {
        auto chartNo = patientModel->data(patientModel->index(patientModel->rowCount()-1,0)).toInt();
        return ++chartNo;
    }
}

void Doctor::on_patientNewpushButton_clicked()
{
    int chartNo = makeChartNo();

    /* 환자 관리 UI에서 LineEdit 따오기 */
    patientName = ui->patientNamelineEdit ->text();
    patientChartNumber = chartNo;
    patientBirth = ui->patientBirthdatlineEdit->text();
    patientFirstVisitDate = ui->patientFirstVistdateEdit->text();
    patientLastVisitDate = ui->patientLastVistdateEdit->text();
    patientMobile = ui->patientMobilelineEdit->text();
    patientPhone = ui->patientMobilelineEdit->text();
    patientEmail = ui->patientEmaillineEdit->text() + "@" + ui->patientEmaillineEdit2->text();
    patientAddress = ui->patientAddresslineEdit->text() + ui->patientDetailAddresslineEdit->text();

    QString patient_stl_path = "temp_path";

    QSqlDatabase db = QSqlDatabase::database("Patient");
    QSqlQuery query(db);
    query.prepare("insert into patient values (:PA_NAME, :PA_BIRTH, :PA_CHART_NO_PK,PA_GENDER,PA_FIRST_VISIT,PA_LAST_VISIT\
                  :PA_PHONE_NUM, :PA_EMAIL, :PA_ADDRESS, :PA_DETAIL_ADDRESS, :PA_STL_PATH)");

            query.bindValue(":PA_NAME",patientName);
    query.bindValue(":PA_BIRTH",patientBirth);
    query.bindValue(":PA_CHART_NO_PK",patientChartNumber);
    query.bindValue(":PA_GENDER",patientGender);
    query.bindValue("PA_FIRST_VISIT",patientFirstVisitDate);
    query.bindValue("PA_LAST_VISIT",patientLastVisitDate);
    query.bindValue("PA_PHONE_NUM",patientPhone);
    query.bindValue("PA_EMAIL", patientEmail);
    query.bindValue("PA_ADDRESS", patientAddress);
    query.bindValue("PA_STL_PATH", patient_stl_path);
    query.exec();
}

void Doctor::on_patientGenderMalepushButton_clicked()
{
    patientGender = "Male";
    qDebug() << patientGender;
}


void Doctor::on_patientGenderFemalepushButton_clicked()
{
    patientGender = "Female";
    qDebug() << patientGender;
}


void Doctor::on_patientGenderNonepushButton_clicked()
{
    patientGender = "None";
    qDebug() << patientGender;
}

void Doctor::closeEvent(QCloseEvent*)
{
    clientSocket->disconnectFromHost();                                                         // 소켓 연결 종료
    if(clientSocket->state() != QAbstractSocket::UnconnectedState)
        clientSocket->waitForDisconnected();                                                    // 소켓이 연결되지 않은 상태면 잠시동안 기다림
}

void Doctor::receiveData( )                                                               // 채팅자 끼리 채팅 주고 받기
{
    QTcpSocket *clientSocket = dynamic_cast<QTcpSocket *>(sender( ));                           //
    //if (clientSocket->bytesAvailable( ) > BLOCK_SIZE) return;
    QByteArray bytearray;                                                                 // 소켓으로 부터 읽은 데이터를 바이트어레이에 저장
    Patient_Info type;
    char data[11][1020];

    for(int i = 0; i < 11; i++)
    {
        if(i == 0)
        {
            bytearray = clientSocket->read(BLOCK_SIZE);
            memset(data[i], 0, 1020);
            QDataStream in(&bytearray, QIODevice::ReadOnly);                                            // 바이트어레이를 읽기전용으로 설정

            in.device()->seek(0);                                                                       // 처음 위치로 감
            in >> type;                                                                                 // 소켓으로 부터 타입을 읽음
            in.readRawData(data[i], 1020);
        }
        else
        {
            bytearray = clientSocket->read(BLOCK_SIZE - 4);
            memset(data[i], 0, 1020);
            QDataStream in(&bytearray, QIODevice::ReadOnly);                                            // 바이트어레이를 읽기전용으로 설정
            in.readRawData(data[i], 1020);
        }
    }

    if(type == Get_Info)
    {
        ui->patientNamelineEdit->setText(data[0]);
        ui->patientBirthdatlineEdit->setText(data[1]);
        ui->patientChartNumberlineEdit->setText(data[2]);

//        ui->patientBirthdatlineEdit->setText(data[3]);

        ui->patientFirstVistdateEdit->setDisplayFormat(data[4]);
        ui->patientLastVistdateEdit->setDisplayFormat(data[5]);
        ui->patientMobilelineEdit->setText(data[6]);
        ui->patientPhonelineEdit->setText(data[7]);
        ui->patientEmaillineEdit->setText(data[8]);
        ui->patientAddresslineEdit->setText(data[9]);
        ui->patientDetailAddresslineEdit->setText(data[10]);
    }
}

void Doctor::sendData()
{
    QByteArray dataArray;
    QDataStream out(&dataArray, QIODevice::WriteOnly);                                          // 바이트어레이를 쓰기전용으로 설정
    out.device()->seek(0);
    dataArray.clear();

    out << doctor;
    out << Send_Info;
    out.writeRawData(dataArray.append(ui->patientNamelineEdit->text().toStdString().data()), 1020);
    out.writeRawData(dataArray.append(ui->patientBirthdatlineEdit->text().toStdString().data()), 1020);
    out.writeRawData(dataArray.append(ui->patientChartNumberlineEdit->text().toStdString().data()), 1020);
    out.writeRawData(dataArray.append(patientGender.toStdString().data()), 1020);
    out.writeRawData(dataArray.append(ui->patientFirstVistdateEdit->text().toStdString().data()), 1020);
    out.writeRawData(dataArray.append(ui->patientLastVistdateEdit->text().toStdString().data()), 1020);
    out.writeRawData(dataArray.append(ui->patientMobilelineEdit->text().toStdString().data()), 1020);
    out.writeRawData(dataArray.append(ui->patientPhonelineEdit->text().toStdString().data()), 1020);
    out.writeRawData(dataArray.append(ui->patientEmaillineEdit ->text().toStdString().data()), 1020);
    out.writeRawData(dataArray.append(ui->patientAddresslineEdit->text().toStdString().data()), 1020);
    out.writeRawData(dataArray.append(ui->patientDetailAddresslineEdit->text().toStdString().data()), 1020);
    clientSocket->write(dataArray);
    clientSocket->flush();
    while(clientSocket->waitForBytesWritten());
}

// 파일전송
void Doctor::goOnSend(qint64 numBytes)                                                 
{
    byteToWrite -= numBytes;                                                                    // 남은 파일 용량으로 보낼 용량을 계속해서 뺌
    outBlock = file->read(qMin(byteToWrite, numBytes));                                         // 보낼 용량만큼 파일을 읽어서 outBlock 변수에 저장
    fileClient->write(outBlock);                                                                // 파싱한 파일을 소켓으로 보냄

    progressDialog->setMaximum(totalSize);                                                      // progressDialog의 맥시멈 값을 totalSize로 설정
    progressDialog->setValue(totalSize-byteToWrite);                                            // progressDialog의 값은 totalSize에서 남은 데이터 수를 뺌

    if (byteToWrite == 0) {                                                                     // 파일전송이 끝난 경우
        qDebug("File sending completed!");
        progressDialog->reset();                                                                // progressDialog 리셋
    }
}

void Doctor::sendFile()                                                                
{
    loadSize = 0;
    byteToWrite = 0;
    totalSize = 0;
    outBlock.clear();                                                                           // 남은 파일 용량, 파일 전체 용량, 보낼 파일 0으로 초기화

    QString filename = QFileDialog::getOpenFileName(this);
    if(filename.length()) {
        file = new QFile(filename);                                                             // 파일생성
        file->open(QFile::ReadOnly);                                                            // 파일 읽기전용으로 오픈

        qDebug() << QString("file %1 is opened").arg(filename);
        progressDialog->setValue(0);                                                            // progressDialog 0으로 세팅

//        if (!isSent) {                                                                          // 파일을 처음 보내는 경우
//            fileClient->connectToHost(ui->serverAddress->text( ),                               // 소켓을 연결하고 isSent를 false에서 true로 바꿈
//                                      ui->serverPort->text( ).toInt( ) + 1);
//            isSent = true;
//        }

        byteToWrite = totalSize = file->size();                                                 // 남은 파일 용량
        loadSize = 1024;

        QDataStream out(&outBlock, QIODevice::WriteOnly);                                       // 파싱해서 보낼 파일을 쓰기모드로 설정
        out << qint64(0) << qint64(0) << filename;                          // 파싱해서 보낼 파일에 파일전체용량(0), 남은 용량(0), 파일명, 이름 넣음

        totalSize += outBlock.size();                                                           // 전체 파일크기에 보낼 파일 크기를 더함
        byteToWrite += outBlock.size();                                                         // 남은 파일크기에 보낼 파일 크기를 더함

        out.device()->seek(0);                                                                  // 처음 위치로 감
        out << totalSize << qint64(outBlock.size());                                            // 보낼 파일에 전체 크기와 보낼 파일의 용량을 씀

        fileClient->write(outBlock);                                                            // 소켓으로 파싱한 파일 보냄

        progressDialog->setMaximum(totalSize);                                                  // progressDialog 최대값 totalSize로 설정
        progressDialog->setValue(totalSize-byteToWrite);                                        // progressDialog 값 totalSize에서 남은 용량을 뺀 값으로 설정
        progressDialog->show();                                                                 // progressDialog 표시
    }
    qDebug() << QString("Sending file %1").arg(filename);
}


void Doctor::loadSTL()
{
    std::string lower = "lower.stl";
    std::string upper = "upper.stl";
    std::string occlusion = "cube.stl";

    mUpperReader->SetFileName(lower.c_str());
    mUpperReader->Update();
    mLowerReader->SetFileName(upper.c_str());
    mLowerReader->Update();
    mOcclusionReader->SetFileName(occlusion.c_str());
    mOcclusionReader->Update();

    // Create Mapper and Actor
    vtkSmartPointer<vtkPolyDataMapper> mUpperMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    vtkSmartPointer<vtkPolyDataMapper> mLowerMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    vtkSmartPointer<vtkPolyDataMapper> mOcclusionMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mUpperMapper->SetInputConnection(mUpperReader->GetOutputPort());
    mLowerMapper->SetInputConnection(mLowerReader->GetOutputPort());
    mOcclusionMapper->SetInputConnection(mOcclusionReader->GetOutputPort());

    vtkSmartPointer<vtkActor> mUpperActor = vtkSmartPointer<vtkActor>::New();
    vtkSmartPointer<vtkActor> mLowerActor = vtkSmartPointer<vtkActor>::New();
    vtkSmartPointer<vtkActor> mOcclusionActor = vtkSmartPointer<vtkActor>::New();
    mUpperActor->SetMapper(mUpperMapper);
    mLowerActor->SetMapper(mLowerMapper);
    mOcclusionActor->SetMapper(mOcclusionMapper);

    //ui->patientDataupperopenGLWidget->interactor()->GetRenderWindow()->AddRenderer(mUpperRenderer);
    //ui->patientDataloweropenGLWidget->interactor()->GetRenderWindow()->AddRenderer(mLowerRenderer);
    //ui->patientDataocclusionopenGLWidget->interactor()->GetRenderWindow()->AddRenderer(mOcclusionRenderer);

    //ui->patientDataupperopenGLWidget->interactor()->GetRenderWindow()->SetInteractor(mUpperInteractor);
    //ui->patientDataloweropenGLWidget->interactor()->GetRenderWindow()->SetInteractor(mLowerInteractor);
    //ui->patientDataocclusionopenGLWidget->interactor()->GetRenderWindow()->SetInteractor(mOcclusionInteractor);

    ui->patientDataupperopenGLWidget->interactor()->SetRenderWindow(mUpperWindow);
    ui->patientDataloweropenGLWidget->interactor()->SetRenderWindow(mLowerWindow);
    ui->patientDataocclusionopenGLWidget->interactor()->SetRenderWindow(mOcclusionWindow);

    ui->patientDataupperopenGLWidget->interactor()->ProcessEvents();
    ui->patientDataloweropenGLWidget->interactor()->ProcessEvents();
    ui->patientDataocclusionopenGLWidget->interactor()->ProcessEvents();

    mUpperRenderer->AddActor(mUpperActor);
    mLowerRenderer->AddActor(mLowerActor);
    mOcclusionRenderer->AddActor(mOcclusionActor);

    // Render 
    mUpperWindow->Render();
    mLowerWindow->Render();
    mOcclusionWindow->Render();

    ui->patientDataupperopenGLWidget->interactor()->Start();
    ui->patientDataloweropenGLWidget->interactor()->Start();
    ui->patientDataocclusionopenGLWidget->interactor()->Start();

    CustomVTKWidget* customVTKWidget = new CustomVTKWidget(NULL);
    customVTKWidget->show();
}