//author: duHongpeng
//time: 19.4.26
#ifndef CLIENT_H
#define CLIENT_H

#include <QHostAddress>
#include <QTcpSocket>
#include <QObject>
//#include <boost/asio.hpp>
//#include <boost/thread.hpp>
#include <string>
#include <iostream>
//#include "json/json.h"
#include <QList>
#include <QMutex>
//using namespace boost::asio;
using std::cout;            using std::endl;
using std::string;          using std::vector;
//typedef boost::shared_ptr<ip::tcp::socket> socket_ptr; //简化定义
class Client:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    Q_PROPERTY(QString userPassword READ userPassword WRITE setUserPassword NOTIFY userPasswordChanged)

public:
    Client();
    Q_INVOKABLE void sendActivity(QString title, QString time, QString label, QString content);
    Q_INVOKABLE void flushActivity();
//    Q_INVOKABLE void StartConnect();
//    Q_INVOKABLE void logining(QString name,QString password);
//    void Readvideo();  //接受服务器的video消息
//    void ReceiveActivity();    //jie shou lai si fuwuqi de huodong xiaoxi
//    void sendaccount();

    //用户帐号
    QString userName();
    void setUserName(QString name);
    QString userPassword();
    void setUserPassword(QString password);
signals:
    void userNameChanged();
    void userPasswordChanged();
    void clearActivity();
    void releaseActivity(QString title, QString time, QString label, QString content);
private slots:
    void dataReceived();
    void sureConnected();
private:
    //用户帐号
    QString m_userName;
    QString m_userPassword;
    bool m_loginging = false;
    QList<QString> _namelist;

    QHostAddress *serverIP;
    QTcpSocket *tcpSocket;

    void tcpConnected();
    void connected();
    QMutex mutex;
    QMutex motionMutex;
    QByteArray m_buffer;    //缓存上一次或多次的未处理的数据
    qint64 totalBytes;      //一个数据包MSG部分的完整大小
    qint64 recvdBytes;      //已经收到的字节数
    qint64 serverCmd;       //接受数据包的类型
    QByteArray inBlock;     //接受缓冲
};


#endif // CLIENT_H
