#include "mainserver.h"
#include "ui_mainserver.h"

#include <QPushButton>
#include <QBoxLayout>
#include <QTcpServer>
#include <QTcpSocket>
#include <QApplication>
#include <QMessageBox>
#include <QScrollBar>
#include <QDateTime>
#include <QDebug>
#include <QMenu>
#include <QFile>
#include <QFileInfo>
#include <QProgressDialog>

MainServer::MainServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainServer)
{
    ui->setupUi(this);

    chatServer = new QTcpServer(this);                                                 // 채팅을 위한 TCP서버 생성
    connect(chatServer, SIGNAL(newConnection( )), SLOT(clientConnect( )));             // 서버연결이 되면 clientConnect 슬롯 발생
    if (!chatServer->listen(QHostAddress::Any, PORT_NUMBER)) {
        QMessageBox::critical(this, tr("Chatting Server"),\
                              tr("Unable to start the server: %1.")\
                              .arg(chatServer->errorString( )));                       // ip주소와 포트번호를 통한 서버 연결에 실패할 경우 에러메세지 띄움
        close( );
        return;
    }

    fileServer = new QTcpServer(this);                                                 // 파일 전송을 위한 TCP서버 생성
    connect(fileServer, SIGNAL(newConnection()), SLOT(acceptConnection()));            // 서버연결이 되면 acceptConnection 슬롯 발생
    if (!fileServer->listen(QHostAddress::Any, PORT_NUMBER+1)) {
        QMessageBox::critical(this, tr("Chatting Server"), \
                              tr("Unable to start the server: %1.") \
                              .arg(fileServer->errorString( )));                       // ip주소와 포트번호를 통한 서버 연결에 실패하면 에러메세지 띄움
        close( );
        return;
    }
    qDebug("Start listening ...");
}

MainServer::~MainServer()
{
    delete ui;

    chatServer->close( );
    fileServer->close( );                                                               // 채팅서버와 파일 서버 닫음
}

void MainServer::clientConnect()
{
    QTcpSocket* clientConnection = chatServer->nextPendingConnection();
    connect(clientConnection, SIGNAL(readyRead()), SLOT(receiveData()));
    qDebug("new connection is established....");
}

void MainServer::receiveData()
{
    QTcpSocket *clientConnection = dynamic_cast<QTcpSocket *>(sender( ));
    QByteArray bytearray;
    From_Who type1;
    Patient_Info type2;
    char data[11][1020];

    for(int i = 0; i < 11; i++)
    {
        if(i == 0)
        {
            bytearray = clientConnection->read(BLOCK_SIZE);
            memset(data[i], 0, 1020);
            QDataStream in(&bytearray, QIODevice::ReadOnly);                                            // 바이트어레이를 읽기전용으로 설정

            in.device()->seek(0);                                                                       // 처음 위치로 감
            in >> type2;                                                                                 // 소켓으로 부터 타입을 읽음
            in.readRawData(data[i], 1020);
        }
        else
        {
            bytearray = clientConnection->read(BLOCK_SIZE - 4);
            memset(data[i], 0, 1020);
            QDataStream in(&bytearray, QIODevice::ReadOnly);                                            // 바이트어레이를 읽기전용으로 설정
            in.readRawData(data[i], 1020);
        }
    }

    switch(type2){
    case Send_Info:
        socketHash[type1] = clientConnection;
        // 데이터베이스에 저장
        break;
    case Request_Info:
        if(type1 == nurse)
        {
            socketHash[type1] = clientConnection;
            // 데이터베이스에서 정보 가져옴

            QByteArray sendArray;
            sendArray.clear();
            QDataStream out(&sendArray, QIODevice::WriteOnly);                                       // 바이트어레이를 쓰기모드로 설정
            out << Get_Info;                                                                        // 보낼 타입을 chat_talk로 씀
            out.writeRawData(sendArray.append(patientName.toStdString().data()), 1020);
            out.writeRawData(sendArray.append(patientBirthday.toStdString().data()), 1020);
            out.writeRawData(sendArray.append(patientChartNumber.toStdString().data()), 1020);
            out.writeRawData(sendArray.append(patientGender.toStdString().data()), 1020);
            out.writeRawData(sendArray.append(patientFirstVisitdate.toStdString().data()), 1020);
            out.writeRawData(sendArray.append(patientLastVisitdate.toStdString().data()), 1020);
            out.writeRawData(sendArray.append(patientMobile.toStdString().data()), 1020);
            out.writeRawData(sendArray.append(patientPhone.toStdString().data()), 1020);
            out.writeRawData(sendArray.append(patientEmail.toStdString().data()), 1020);
            out.writeRawData(sendArray.append(patientAddress.toStdString().data()), 1020);
            out.writeRawData(sendArray.append(patientDetailAddress.toStdString().data()), 1020);
            clientConnection->write(sendArray);                                                                  // 소켓으로 데이터 보냄
            qDebug() << clientConnection->peerPort();
            break;
        }
        else if(type1 == doctor)
        {
            socketHash[type1] = clientConnection;
            // 데이터베이스에서 정보 가져옴

            if()
            QByteArray sendArray;
            sendArray.clear();
            QDataStream out(&sendArray, QIODevice::WriteOnly);                                       // 바이트어레이를 쓰기모드로 설정
            out << Get_Info;                                                                        // 보낼 타입을 chat_talk로 씀
            out.writeRawData(sendArray.append(patientName.toStdString().data()), 1020);
            out.writeRawData(sendArray.append(patientBirthday.toStdString().data()), 1020);
            out.writeRawData(sendArray.append(patientChartNumber.toStdString().data()), 1020);
            out.writeRawData(sendArray.append(patientGender.toStdString().data()), 1020);
            out.writeRawData(sendArray.append(patientFirstVisitdate.toStdString().data()), 1020);
            out.writeRawData(sendArray.append(patientLastVisitdate.toStdString().data()), 1020);
            out.writeRawData(sendArray.append(patientMobile.toStdString().data()), 1020);
            out.writeRawData(sendArray.append(patientPhone.toStdString().data()), 1020);
            out.writeRawData(sendArray.append(patientEmail.toStdString().data()), 1020);
            out.writeRawData(sendArray.append(patientAddress.toStdString().data()), 1020);
            out.writeRawData(sendArray.append(patientDetailAddress.toStdString().data()), 1020);
            clientConnection->write(sendArray);                                                                  // 소켓으로 데이터 보냄
            qDebug() << clientConnection->peerPort();
            break;
        }

    }
}

// 파일전송
void MainServer::acceptConnection()
{
    QTcpSocket* receivedSocket = fileServer->nextPendingConnection();
    connect(receivedSocket, SIGNAL(readyRead()), this, SLOT(readClient()));
    qDebug("file connection is established....");
}

void MainServer::readClient()
{
    qDebug("Receiving file ...");
    QTcpSocket* receivedSocket = dynamic_cast<QTcpSocket *>(sender( ));                                  // 소켓 받아옴
    QString filename, name;

    if (byteReceived == 0) {                                                                             // 파일전송 시작할 경우
        progressDialog->reset();
        progressDialog->show();                                                                          // progress다이얼로그 띄움

        QString ip = receivedSocket->peerAddress().toString();                                           // 현재 ip주소
        quint16 port = receivedSocket->peerPort();                                                       // 현재 포트번호
        qDebug() << ip << " : " << port;

        QDataStream in(receivedSocket);
        in >> totalSize >> byteReceived >> filename >> name;                                             // 파일 전체크기, 받은 데이터, 파일명, 이름 받음
        progressDialog->setMaximum(totalSize);                                                           // 다이얼로그의 전체 크기를 파일 전체 크기로 설정

        QFileInfo info(filename);                                                                        // 파일정보
        QString currentFileName = info.fileName();                                                       // 파일이름
        file = new QFile(currentFileName);                                                               // 파일 생성
        file->open(QFile::WriteOnly);                                                                    // 파일 쓰기모드로 설정
    } else {
        inBlock = receivedSocket->readAll();                                                             // 소켓으로부터 모두 읽음

        byteReceived += inBlock.size();                                                                  // 지금까지 받은 데이터 크기에 방금 받은 데이터 크기 더함
        file->write(inBlock);                                                                            // 받은 데이터를 파일에 저장
        file->flush();
    }

    progressDialog->setValue(byteReceived);

    if (byteReceived == totalSize) {                                                                     // 파일 전송을 완료한 경우
        qDebug() << QString("%1 receive completed").arg(filename);

        inBlock.clear();                                                                                 // 받은 데이터 저장소 비움
        byteReceived = 0;                                                                                // 누적 받은 데이터 크기 0으로 설정
        totalSize = 0;                                                                                   // 전체크기 0으로 설정
        progressDialog->reset();                                                                         // 다이얼로그 리셋
        progressDialog->hide();                                                                          // 다이얼로그 숨김

        file->close();                                                                                   // 파일 닫음
        delete file;
    }
}

//------------------------------------------------------------------------

void MainServer::goOnSend(qint64 numBytes)
{
    byteToWrite -= numBytes;                                                                    // 남은 파일 용량으로 보낼 용량을 계속해서 뺌
    outBlock = file->read(qMin(byteToWrite, numBytes));                                         // 보낼 용량만큼 파일을 읽어서 outBlock 변수에 저장
    socketHash[type]->write(outBlock);                                                                // 파싱한 파일을 소켓으로 보냄
}

void MainServer::sendFile()
{
    byteToWrite = 0;
    totalSize = 0;
    outBlock.clear();                                                                           // 남은 파일 용량, 파일 전체 용량, 보낼 파일 0으로 초기화

    QString filename = QFileDialog::getOpenFileName(this);
    if(filename.length()) {
        file = new QFile(filename);                                                             // 파일생성
        file->open(QFile::ReadOnly);                                                            // 파일 읽기전용으로 오픈

        qDebug() << QString("file %1 is opened").arg(filename);
        progressDialog->setValue(0);                                                            // progressDialog 0으로 세팅

        if (!isSent) {                                                                          // 파일을 처음 보내는 경우
            fileClient->connectToHost(ui->serverAddress->text( ),                               // 소켓을 연결하고 isSent를 false에서 true로 바꿈
                                      ui->serverPort->text( ).toInt( ) + 1);
            isSent = true;
        }

        byteToWrite = totalSize = file->size();                                                 // 남은 파일 용량

        QDataStream out(&outBlock, QIODevice::WriteOnly);                                       // 파싱해서 보낼 파일을 쓰기모드로 설정
        out << qint64(0) << qint64(0) << filename << ui->name->text();                          // 파싱해서 보낼 파일에 파일전체용량(0), 남은 용량(0), 파일명, 이름 넣음

        totalSize += outBlock.size();                                                           // 전체 파일크기에 보낼 파일 크기를 더함
        byteToWrite += outBlock.size();                                                         // 남은 파일크기에 보낼 파일 크기를 더함

        out.device()->seek(0);                                                                  // 처음 위치로 감
        out << totalSize << qint64(outBlock.size());                                            // 보낼 파일에 전체 크기와 보낼 파일의 용량을 씀
        fileClient->write(outBlock);                                                            // 소켓으로 파싱한 파일 보냄                                                            // progressDialog 표시
    }
    qDebug() << QString("Sending file %1").arg(filename);
}
