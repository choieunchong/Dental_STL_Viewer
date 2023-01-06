#ifndef MAINSERVER_H
#define MAINSERVER_H

#include <QWidget>
#include <QList>
#include <QHash>
#include <QMenu>

class QLabel;
class QTcpServer;
class QTcpSocket;
class QFile;
class QProgressDialog;
class LogThread;

namespace Ui {
class Mainserver;
}

typedef enum {
    Send_Info,
    Get_Info,
} Patient_Info;

class Mainserver : public QWidget
{
    Q_OBJECT

public:
    explicit Mainserver(QWidget *parent = nullptr);
    ~Mainserver();

private:
    const int BLOCK_SIZE = 1024;
    const int PORT_NUMBER = 8000;

    Ui::Mainserver *ui;
    QTcpServer *chatServer;
    QTcpServer *fileServer;
    QHash<quint16, QString> clientNameHash;
    QHash<QString, QTcpSocket*> clientSocketHash;
    QHash<QString, int> clientIDHash;
    QMenu* menu;
    QFile* file;
    QProgressDialog* progressDialog;
    qint64 totalSize;
    qint64 byteReceived;
    QByteArray inBlock;
    LogThread* logThread;

private slots:
    void acceptConnection();

    void clientConnect( );
    void receiveData( );
    void removeClient( );

signals:
    void Get_Patient_Info(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString);
};

#endif // MAINSERVER_H
