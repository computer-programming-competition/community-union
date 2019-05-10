#include "tcpserver.h"
#include "tcpclientsocket.h"
#include "cmd.h"
#include <QDataStream>
#include <iostream>
#include <QDebug>

TcpServer::TcpServer(QObject *parent, quint16 port)
    :QTcpServer(parent)
{
    _database = new database();
    if(!listen(QHostAddress::Any,port))
    {
        qDebug() << "do not listen";
    }
    qDebug() << "start\n";
}

//出现一个新的连接时触发

void TcpServer::incomingConnection(qintptr socketDescriptor)
{
    TcpClientSocket *tcpClientSocket = new TcpClientSocket(this);
    tcpClientSocket->linkServer(this);

    connect(tcpClientSocket, SIGNAL(doFlushActivity()), this, SLOT(doFlushActivity()));
    connect(tcpClientSocket, SIGNAL(disconnected(qintptr)), this, SLOT(slotDisconnection(qintptr)));
    connect(tcpClientSocket, SIGNAL(doFlushMemberList()), this, SLOT(doFlushMemberList()));

    tcpClientSocket->setSocketDescriptor(socketDescriptor);

    qDebug() << "connect" ;
    qDebug() << socketDescriptor;

    tcpClientSocketList.append(tcpClientSocket);
}

void TcpServer::doFlushActivity()
{
    for(int i=0; i<tcpClientSocketList.count(); i++){
        TcpClientSocket *item = tcpClientSocketList.at(i);
        item->sendActivity();
    }
}

void TcpServer::doFlushMemberList()
{
    for(int i=0; i<tcpClientSocketList.count(); i++){
        TcpClientSocket *item = tcpClientSocketList.at(i);
        item->clearMenmberList();
        item->sendMember();
    }
}

void TcpServer::loginOk(bool s)
{

}

void TcpServer::clientConnect()
{
    std::cout << "connect\n" << std::endl;
}

database *TcpServer::getDatabase()
{
    return _database;
}

void TcpServer::slotDisconnection(qintptr descriptor)
{
    for(int i=0; i<tcpClientSocketList.count(); i++)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        if(item->socketDescriptor() == descriptor)
        {
            tcpClientSocketList.removeAt(i);
            qDebug() << "remove socket";
            qDebug() << descriptor;
            return;
        }
    }
    return;
}


