#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <QTcpServer>
#include <QObject>
#include "database.h"
#include <QtSql/QSqlQuery>
#include <vector>
#include <QMutex>
#include <iostream>
#include <string>

class TcpClientSocket;

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    TcpServer(QObject *parent=0,quint16 port=6688);


    void incomingConnection(qintptr socketDescriptor);
public slots:
    //接受要广播的聊天信息
    void doFlushActivity();
    void loginOk(bool s);
    //接收断开连接的信息
    void slotDisconnection(qintptr);

    void clientConnect();
    database* getDatabase();
private:
    QList<TcpClientSocket*> tcpClientSocketList;
    database* _database;                 //初始数据库

    QMutex mutex;
    QMutex motionMutex;
    QByteArray m_buffer;    //缓存上一次或多次的未处理的数据
    qint64 totalBytes;      //一个数据包MSG部分的完整大小
    qint64 recvdBytes;      //已经收到的字节数
    qint64 serverCmd;       //接受数据包的类型
    QByteArray inBlock;     //接受缓冲
protected:

};

#endif // TCPSERVER_H
