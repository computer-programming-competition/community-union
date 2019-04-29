#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H
#include <QTcpSocket>
#include <QObject>
#include "tcpserver.h"
#include <QMutex>

class TcpServer;

class TcpClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    TcpClientSocket(QObject *parent=0);
    void linkServer(TcpServer* tcpserver)
    {
        _tcpserver = tcpserver;
        //test
    }

    void sendActivity();
    void clearActiviy();

signals:
    void disconnected(qintptr);
    void doFlushActivity();

private slots:
    void dataReceived();
    void slotDisconnected();
private:
    TcpServer* _tcpserver;

    QMutex mutex;
    QMutex motionMutex;
    QByteArray m_buffer;    //缓存上一次或多次的未处理的数据
    qint64 totalBytes;      //一个数据包MSG部分的完整大小
    qint64 recvdBytes;      //已经收到的字节数
    qint64 serverCmd;       //接受数据包的类型
    QByteArray inBlock;     //接受缓冲
};

#endif // TCPCLIENTSOCKET_H
