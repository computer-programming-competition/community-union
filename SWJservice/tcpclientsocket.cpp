#include "tcpclientsocket.h"
#include "cmd.h"
#include <QDataStream>
#include "tcpserver.h"
//#include "json/json.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QList>

TcpClientSocket::TcpClientSocket(QObject *parent)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(dataReceived()));
    connect(this, SIGNAL(disconnected()), this, SLOT(slotDisconnected()));
}

void TcpClientSocket::sendActivity()
{
    _tcpserver->getDatabase()->setActivity();
    QList<QString> Msg = _tcpserver->getDatabase()->activity()->getMessageList();


    for(int i=0; i<Msg.count(); i++){
        QString msg = Msg.at(i);

        //构造数据包
        qint64 totalBytes = 0;
        QByteArray block;
        QDataStream output(&block,QIODevice::WriteOnly);
        output.setVersion(QDataStream::Qt_5_2);
        totalBytes = msg.toUtf8().size();


        //向缓冲区写入文件头
        output<<qint64(totalBytes)<<qint64(Activity_send);
        totalBytes += block.size();
        output.device()->seek(0);
        output<<totalBytes;
        write(block);
        block.resize(0);
        for(int i=0;i<10000;i++)

        block = msg.toUtf8();
        write(block);
        block.resize(0);
    }
}

void TcpClientSocket::clearActiviy()
{
    QString msg = "clear activiy";

    //构造数据包
    qint64 totalBytes = 0;
    QByteArray block;
    QDataStream output(&block,QIODevice::WriteOnly);
    output.setVersion(QDataStream::Qt_5_2);
    totalBytes = msg.toUtf8().size();


    //向缓冲区写入文件头
    output<<qint64(totalBytes)<<qint64(Clear_activity);
    totalBytes += block.size();
    output.device()->seek(0);
    output<<totalBytes;
    write(block);
    block.resize(0);
    for(int i=0;i<10000;i++)

    block = msg.toUtf8();
    write(block);
    block.resize(0);
}

void TcpClientSocket::dataReceived()
{
    qDebug() << "data received()";
    if(bytesAvailable() <= 0)
    {
        return;
    }

    //从缓存区中去除数据，但是不确定取出来的字节数
    QByteArray  buffer;
    buffer = readAll();
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
        case ReleaseActivity:
        {
            QString rec;
            QByteArray datas = m_buffer.mid(2*sizeof(qint64), totalBytes-2*sizeof(qint64));
            rec.prepend(datas);
            QJsonDocument jsonDocument = QJsonDocument::fromJson(rec.toLocal8Bit().data());
            QJsonObject jsonObject = jsonDocument.object();

            //            QString test1 = jsonObject.value("title").toString();
            //            QString test2 = jsonObject.value("time").toString();
            //            QString test3 = jsonObject.value("label").toString();
            //            QString test4 = jsonObject.value("content").toString();

            _tcpserver->getDatabase()->activityToDatabase(jsonObject.value("cname").toString(),jsonObject.value("title").toString(),jsonObject.value("time").toString(),jsonObject.value("label").toString(),jsonObject.value("content").toString());

            qDebug() << jsonObject.value("cname").toString();
            clearActiviy();
            emit doFlushActivity();


            break;
        }

        case FlushActivity:
        {
            clearActiviy();
            emit doFlushActivity();
            break;
        }
        case Login:
        {

            QString rec;
            QByteArray datas = m_buffer.mid(2*sizeof(qint64), totalBytes-2*sizeof(qint64));
            rec.prepend(datas);
            QJsonDocument jsonDocument = QJsonDocument::fromJson(rec.toLocal8Bit().data());
            QJsonObject jsonObject = jsonDocument.object();
            bool success = _tcpserver->getDatabase()->verifyaccout(jsonObject.value("name").toString(),jsonObject.value("password").toString());
            if(!success)
            {
                //返回登录失败
                QJsonObject yorn;

                QString msg1 = QString::number(success);
                yorn.insert("yorn",msg1);
                QString msg=QString(QJsonDocument(yorn).toJson());
                //构造数据包
                qint64 totalBytes = 0;
                QByteArray block;
                QDataStream output(&block,QIODevice::WriteOnly);
                output.setVersion(QDataStream::Qt_5_2);
                totalBytes = msg.toUtf8().size();


                //向缓冲区写入文件头
                output<<qint64(totalBytes)<<qint64(LoginOk);
                totalBytes += block.size();
                output.device()->seek(0);
                output<<totalBytes;
                write(block);
                block.resize(0);
                for(int i=0;i<10000;i++)

                block = msg.toUtf8();
                write(block);
                block.resize(0);
                break;
            }else{
                //返回登录成功并传回用户信息

                QJsonObject yorn;
                QString msg1 = QString::number(success);
                yorn.insert("yorn",msg1);
                yorn.insert("name",_tcpserver->getDatabase()->myuser()->name());
                yorn.insert("community",_tcpserver->getDatabase()->myuser()->community());

                QString msg=QString(QJsonDocument(yorn).toJson());
                //构造数据包
                qint64 totalBytes = 0;
                QByteArray block;
                QDataStream output(&block,QIODevice::WriteOnly);
                output.setVersion(QDataStream::Qt_5_2);
                totalBytes = msg.toUtf8().size();


                //向缓冲区写入文件头
                output<<qint64(totalBytes)<<qint64(LoginOk);
                totalBytes += block.size();
                output.device()->seek(0);
                output<<totalBytes;
                write(block);
                block.resize(0);
                for(int i=0;i<10000;i++)

                block = msg.toUtf8();
                write(block);
                block.resize(0);
                break;
            }


        }
        case SignUp:
        {
            qDebug() << "注册开始/n";
            QString rec;
            QByteArray datas = m_buffer.mid(2*sizeof(qint64), totalBytes-2*sizeof(qint64));
            rec.prepend(datas);
            QJsonDocument jsonDocument = QJsonDocument::fromJson(rec.toLocal8Bit().data());
            QJsonObject jsonObject = jsonDocument.object();
            QString signup = _tcpserver->getDatabase()->signupaccount(jsonObject.value("name").toString(),jsonObject.value("password").toString());

            QJsonObject signyorn;
            signyorn.insert("yorn",signup);
            QString msg=QString(QJsonDocument(signyorn).toJson());
            //构造数据包
            qint64 totalBytes = 0;
            QByteArray block;
            QDataStream output(&block,QIODevice::WriteOnly);
            output.setVersion(QDataStream::Qt_5_2);
            totalBytes = msg.toUtf8().size();


            //向缓冲区写入文件头
            output<<qint64(totalBytes)<<qint64(SignUpOK);
            totalBytes += block.size();
            output.device()->seek(0);
            output<<totalBytes;
            write(block);
            block.resize(0);
            for(int i=0;i<10000;i++)

            block = msg.toUtf8();
            write(block);
            block.resize(0);
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



void TcpClientSocket::slotDisconnected()
{
    emit disconnected(this->socketDescriptor());
}
