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

Mainserver::Mainserver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mainserver), totalSize(0), byteReceived(0)
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

Mainserver::~Mainserver()
{
    delete ui;

    chatServer->close( );
    fileServer->close( );                                                               // 채팅서버와 파일 서버 닫음
}



void Mainserver::clientConnect()
{
    QTcpSocket *clientConnection = chatServer->nextPendingConnection( );                // 소켓 생성
    connect(clientConnection, SIGNAL(readyRead( )), this, SLOT(receiveData( )));              // 소켓에서 읽을 준비가 되면 reciveData 슬롯 발생
    connect(clientConnection, SIGNAL(disconnected( )), SLOT(removeClient()));           // 연결이 끊어지면 removeClient 슬롯 발생
    qDebug("new connection is established...");
}

void Mainserver::receiveData( )
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

void Mainserver::acceptConnection()
{

}

void Mainserver::removeClient()
{

}
