#include "client.h"
#include <algorithm>
#include <iostream>
//#include "json/json.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include "cmd.h"
//io_service service;     //必有的io——service对象
//ip::tcp::endpoint ep(boost::asio::ip::address::from_string("127.0.0.1"),6688);
//ip::tcp::socket sock(service);
Client::Client()
{
    tcpConnected();
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(dataReceived()));
}

void Client::sendActivity(QString title, QString time, QString label, QString content)
{
    QJsonObject activityList;
    activityList.insert("title", title);
    activityList.insert("time", time);
    activityList.insert("label", label);
    activityList.insert("content", content);

    QString msg = QString(QJsonDocument(activityList).toJson());  /////////

    //构造数据包
    qint64 totalBytes = 0;
    QByteArray block;
    QDataStream output(&block,QIODevice::WriteOnly);
    output.setVersion(QDataStream::Qt_5_2);
    totalBytes = msg.toUtf8().size();


    //向缓冲区写入文件头
    output<<qint64(totalBytes)<<qint64(ReleaseActivity);
    totalBytes += block.size();
    output.device()->seek(0);
    output<<totalBytes;
    tcpSocket->write(block);
    block.resize(0);
    for(int i=0;i<10000;i++)

        block = msg.toUtf8();
    tcpSocket->write(block);
    block.resize(0);
}

void Client::flushActivity()
{
    QString msg = "flush activiy";  /////////

    //构造数据包
    qint64 totalBytes = 0;
    QByteArray block;
    QDataStream output(&block,QIODevice::WriteOnly);
    output.setVersion(QDataStream::Qt_5_2);
    totalBytes = msg.toUtf8().size();


    //向缓冲区写入文件头
    output<<qint64(totalBytes)<<qint64(FlushActivity);
    totalBytes += block.size();
    output.device()->seek(0);
    output<<totalBytes;
    tcpSocket->write(block);
    block.resize(0);
    for(int i=0;i<10000;i++)

        block = msg.toUtf8();
    tcpSocket->write(block);
    block.resize(0);
}

void Client::login(QString name, QString ps)
{
    qDebug() << "lllll";
    QJsonObject account;
    account.insert("name",name);
    account.insert("password",ps);
     QString msg = QString(QJsonDocument(account).toJson());

     qint64 totalBytes = 0;
     QByteArray block;
     QDataStream output(&block,QIODevice::WriteOnly);
     output.setVersion(QDataStream::Qt_5_2);
     totalBytes = msg.toUtf8().size();


     //向缓冲区写入文件头
     output<<qint64(totalBytes)<<qint64(Login);
     totalBytes += block.size();
     output.device()->seek(0);
     output<<totalBytes;
     tcpSocket->write(block);
     block.resize(0);
     for(int i=0;i<10000;i++)

         block = msg.toUtf8();
     tcpSocket->write(block);
     block.resize(0);
}

bool Client::loginok()
{
    return m_loginging;
}

void Client::setLoginok(bool s)
{
    m_loginging = s;
}



QString Client::userName()
{
    return m_userName;
}

void Client::setUserName(QString name)
{
    m_userName = name;
    emit userNameChanged();
}

QString Client::userPassword()
{
    return m_userPassword;
}

void Client::setUserPassword(QString password)
{
    m_userPassword = password;
    emit userPasswordChanged();
}

void Client::dataReceived()
{
    if(tcpSocket->bytesAvailable() <= 0)
    {
        return;
    }

    //从缓存区中去除数据，但是不确定取出来的字节数
    QByteArray  buffer;
    buffer = tcpSocket->readAll();
    m_buffer.append(buffer);
    unsigned int totalLen = m_buffer.size();
    //这边确实需要利用长度做while循环，因为有可能一下子读取到两条以上的完整记录，就需要进行循环处理了
    //超过一条完整小于第二条完整记录时，如果已经达到包头长度就先把包头保存下来，整个过程循环往复
    while (totalLen) {
        //与QDataStream绑定，方便操作
        QDataStream  packet(m_buffer);
        packet.setVersion(QDataStream::Qt_5_2);
        //不够包头长度的不处理，结束while循环
        if(totalLen < 2*sizeof(qint64))
            break;
        //将包头读入了进来按照定义的协议 先读命令长度，再读命令的类型
        packet>>totalBytes>>serverCmd;
        //缓存中的内容长度没有达到命令的长度，那就先结束，等足够了再来解析
        if(totalLen<totalBytes)
            break;
        //足够长了就开始解析
        switch(serverCmd)
        {
        case Activity_send:
        {
            QString rec;
            //
            QByteArray datas = m_buffer.mid(2*sizeof(qint64), totalBytes-2*sizeof(qint64));
            rec.prepend(datas);
            //

            QJsonDocument jsonDocument = QJsonDocument::fromJson(rec.toLocal8Bit().data());
            QJsonObject jsonObject = jsonDocument.object();
//            QString test1 = jsonObject.value("title").toString();
//            QString test2 = jsonObject.value("time").toString();
//            QString test3 = jsonObject.value("label").toString();
//            QString test4 = jsonObject.value("content").toString();
            emit releaseActivity(jsonObject.value("title").toString(), jsonObject.value("time").toString(), jsonObject.value("label").toString(), jsonObject.value("content").toString());

            break;
        }
        case Clear_activity:
        {
            emit clearActivity();
            break;
        }
        case LoginOk :
        {
            QString rec;
            //
            QByteArray datas = m_buffer.mid(2*sizeof(qint64), totalBytes-2*sizeof(qint64));
            rec.prepend(datas);
            //

            QJsonDocument jsonDocument = QJsonDocument::fromJson(rec.toLocal8Bit().data());
            QJsonObject jsonObject = jsonDocument.object();
            QVariant tempValue=jsonObject.value("yorn").toString();
            m_loginging =  tempValue.toBool();
            emit loginn();
            break;
        }
        }
        //缓存多余的数据
        buffer = m_buffer.right(totalLen - totalBytes); //截取下一个数据包的数据，留作下次读取
        totalLen = buffer.size();
        //更新多余的数据
        m_buffer = buffer;
    }
}

void Client::sureConnected()
{
    qDebug() << "have connected";
}

void Client::tcpConnected()
{
    tcpSocket = new QTcpSocket(this);
    serverIP =new QHostAddress();
    serverIP->setAddress("127.0.0.1");  //连接IP
    //    tcpSocket->connectToHost();
    tcpSocket->connectToHost(*serverIP, 6688);

    connect(tcpSocket, SIGNAL(connected()), this, SLOT(sureConnected()));
}
