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

MainServer::MainServer(QWidget *parent) :                                             /*ServerForm 생성자*/
    QWidget(parent),
    ui(new Ui::MainServer), totalSize(0), byteReceived(0)
{
    ui->setupUi(this);

//------------------------------------------------------- 서버 생성 및 포트 연결 -----------------------------------------------------//
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
//----------------------------------------------------------- 시그널 슬롯 ---------------------------------------------------------------//
//    connect(receiveData(), SIGNAL(Get_Patient_Info(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString),
//                                  Send_Patient_Info(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString));
}
//------------------------------------------------------------- 생성자 끝 ---------------------------------------------------------------//
MainServer::~MainServer()                                                               /*ServerForm 소멸자*/
{
    delete ui;

    chatServer->close( );
    fileServer->close( );                                                               // 채팅서버와 파일 서버 닫음
}



void MainServer::clientConnect()
{                                                       /* clientConnect 슬롯 */
    QTcpSocket *clientConnection = chatServer->nextPendingConnection( );                // 소켓 생성
    connect(clientConnection, SIGNAL(readyRead( )), SLOT(receiveData( )));              // 소켓에서 읽을 준비가 되면 reciveData 슬롯 발생
    connect(clientConnection, SIGNAL(disconnected( )), SLOT(removeClient()));           // 연결이 끊어지면 removeClient 슬롯 발생
    qDebug("new connection is established...");
}

void MainServer::receiveData( )                                                         /*receiveData 슬롯*/
{
    QTcpSocket *clientConnection = dynamic_cast<QTcpSocket *>(sender( ));
    QByteArray bytearray;
    Patient_Info type;
    char data[11][1020];

    for(int i = 0; i < 11; i++)
    {
        if(i == 0)
        {
            bytearray = clientConnection->read(BLOCK_SIZE);
            memset(data[i], 0, 1020);
            QDataStream in(&bytearray, QIODevice::ReadOnly);                                            // 바이트어레이를 읽기전용으로 설정

            in.device()->seek(0);                                                                       // 처음 위치로 감
            in >> type;                                                                                 // 소켓으로 부터 타입을 읽음
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
    emit Get_Patient_Info(QString(data[0]), QString(data[1]), QString(data[2]), QString(data[3]), QString(data[4]), QString(data[5]),
                            QString(data[6]), QString(data[7]), QString(data[8]), QString(data[9]), QString(data[10]));
}

void MainServer::Send_Patient_Info(QString Patient_Name, QString Patient_Birthday, QString Chart_Number, QString Patient_Gender,
                                   QString First_Visit, QString Last_Visit, QString Patient_Mobile, QString Patient_Phone, QString Patient_Email,
                                   QString Patient_Address, QString Patient_Detail_Address)
{
//------------------------------>> 데이터베이스로 전송하는 슬롯
}

/* 파일 전송을 위한 소켓 생성 */
//void MainServer::acceptConnection()                                                                         /*acceptConnection 슬롯*/
//{
//    qDebug("Connected, preparing to receive files!");

//    QTcpSocket* receivedSocket = fileServer->nextPendingConnection();
//    connect(receivedSocket, SIGNAL(readyRead()), this, SLOT(readClient()));                                 // 소켓에서 읽을 준비가 되면 readClient 슬롯 발생
//}

///* 파일 전송 */
//void MainServer::readClient()                                                                               /*readClient 슬롯*/
//{
//    qDebug("Receiving file ...");
//    QTcpSocket* receivedSocket = dynamic_cast<QTcpSocket *>(sender( ));
//    QString filename, name;

//    if (byteReceived == 0) {                                                                                // 받은 데이터 크기가 0이면
//        progressDialog->reset();                                                                            // 리셋하고 띄움
//        progressDialog->show();                                                                             // progress 다이얼로그 띄움

//        QString ip = receivedSocket->peerAddress().toString();
//        quint16 port = receivedSocket->peerPort();
//        qDebug() << ip << " : " << port;

//        QDataStream in(receivedSocket);
//        in >> totalSize >> byteReceived >> filename >> name;                                                // 파일 전체크기, 받은 데이터, 파일명, 이름 입력
//        progressDialog->setMaximum(totalSize);                                                              // 다이얼로그 전체 크기 파일 전체 크기로 설정

//        QTreeWidgetItem* item = new QTreeWidgetItem(ui->messageTreeWidget);
//        item->setText(0, ip);
//        item->setText(1, QString::number(port));
//        item->setText(2, QString::number(clientIDHash[name]));
//        item->setText(3, name);
//        item->setText(4, filename);
//        item->setText(5, QDateTime::currentDateTime().toString());
//        item->setToolTip(4, filename);                                                                     // ip, 포트번호, 고객id, 이름, 파일명, 시간을 씀

//        /* 컨텐츠의 길이로 QTreeWidget의 헤더의 크기를 고정 */
//        for(int i = 0; i < ui->messageTreeWidget->columnCount(); i++)
//            ui->messageTreeWidget->resizeColumnToContents(i);                                              // 내용에 따른 열 크기 설정

//        ui->messageTreeWidget->addTopLevelItem(item);                                                      // 탑레벨로 옮김
//        logThread->appendData(item);                                                                 // 스레드의 appendData에 ip, 포트번호, 고객id, 이름, 파일명, 시간 삽입

//        QFileInfo info(filename);
//        QString currentFileName = info.fileName();
//        file = new QFile(currentFileName);
//        file->open(QFile::WriteOnly);                                                                     // 파일을 쓰기모드로 오픈
//    } else {                                                                                              // 데이터를 받고 있다면
//        inBlock = receivedSocket->readAll();

//        byteReceived += inBlock.size();                                                                 // 받은 데이터 전체 크기에 파싱해서 받은 데이터의 크기를 더함
//        file->write(inBlock);                                                                           // 받은 파일 소켓으로 보냄
//        file->flush();
//    }

//    progressDialog->setValue(byteReceived);

//    if (byteReceived == totalSize) {                                                                      // 파일 다 읽으면
//        qDebug() << QString("%1 receive completed").arg(filename);

//        inBlock.clear();
//        byteReceived = 0;                                                                                 // 받은 데이터 초기화
//        totalSize = 0;                                                                                    // 전체 크기 초기화
//        progressDialog->reset();                                                                          // 다이얼로그 리셋
//        progressDialog->hide();                                                                           // 다이얼로그 숨김

//        file->close();
//        delete file;                                                                                      // 파일객체 삭제
//    }
//}

//void Doctor::goOnSend(qint64 numBytes)                                                    /*goOnSend 슬롯*/
//{
//    byteToWrite -= numBytes;                                                                    // 남은 파일 용량으로 보낼 용량을 계속해서 뺌
//    outBlock = file->read(qMin(byteToWrite, numBytes));                                         // 보낼 용량만큼 파일을 읽어서 outBlock 변수에 저장
//    fileClient->write(outBlock);                                                                // 파싱한 파일을 소켓으로 보냄

//    progressDialog->setMaximum(totalSize);                                                      // progressDialog의 맥시멈 값을 totalSize로 설정
//    progressDialog->setValue(totalSize-byteToWrite);                                            // progressDialog의 값은 totalSize에서 남은 데이터 수를 뺌

//    if (byteToWrite == 0) {                                                                     // 파일전송이 끝난 경우
//        qDebug("File sending completed!");
//        progressDialog->reset();                                                                // progressDialog 리셋
//    }
//}

//void Doctor::sendFile()                                                                   /*sendFile 슬롯*/
//{
//    loadSize = 0;
//    byteToWrite = 0;
//    totalSize = 0;
//    outBlock.clear();                                                                           // 남은 파일 용량, 파일 전체 용량, 보낼 파일 0으로 초기화

//    QString filename = QFileDialog::getOpenFileName(this);
//    if(filename.length()) {
//        file = new QFile(filename);                                                             // 파일생성
//        file->open(QFile::ReadOnly);                                                            // 파일 읽기전용으로 오픈

//        qDebug() << QString("file %1 is opened").arg(filename);
//        progressDialog->setValue(0);                                                            // progressDialog 0으로 세팅

//        if (!isSent) {                                                                          // 파일을 처음 보내는 경우
//            fileClient->connectToHost(ui->serverAddress->text( ),                               // 소켓을 연결하고 isSent를 false에서 true로 바꿈
//                                      ui->serverPort->text( ).toInt( ) + 1);
//            isSent = true;
//        }

//        byteToWrite = totalSize = file->size();                                                 // 남은 파일 용량
//        loadSize = 1024;

//        QDataStream out(&outBlock, QIODevice::WriteOnly);                                       // 파싱해서 보낼 파일을 쓰기모드로 설정
//        out << qint64(0) << qint64(0) << filename << ui->name->text();                          // 파싱해서 보낼 파일에 파일전체용량(0), 남은 용량(0), 파일명, 이름 넣음

//        totalSize += outBlock.size();                                                           // 전체 파일크기에 보낼 파일 크기를 더함
//        byteToWrite += outBlock.size();                                                         // 남은 파일크기에 보낼 파일 크기를 더함

//        out.device()->seek(0);                                                                  // 처음 위치로 감
//        out << totalSize << qint64(outBlock.size());                                            // 보낼 파일에 전체 크기와 보낼 파일의 용량을 씀

//        fileClient->write(outBlock);                                                            // 소켓으로 파싱한 파일 보냄

//        progressDialog->setMaximum(totalSize);                                                  // progressDialog 최대값 totalSize로 설정
//        progressDialog->setValue(totalSize-byteToWrite);                                        // progressDialog 값 totalSize에서 남은 용량을 뺀 값으로 설정
//        progressDialog->show();                                                                 // progressDialog 표시
//    }
//    qDebug() << QString("Sending file %1").arg(filename);
//}
