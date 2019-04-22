//蒋富豪 2018-1-5
#include "database.h"
#include <QSqlError>
#include <QDebug>
#include <QSqlRecord>
#include <vector>


database::database()
{
    startconnect();//开始连接数据库
    qDebug("database open status: %d\n", dbconn.open());

//    insertvideo();
//    selectvidio();
//    qDebug()<< namelist.size();
//    for (int i= 0; i<namelist.size(); i++)
//    {
//        qDebug()<< namelist[i] << " ";
//    }
}

void database::startconnect()
{
    QString hostName;
    QString dbName;
    QString userName;
    QString password;
    hostName = "localhost";   // 主机名
    dbName = "SWJsql";   // 数据库名称
    userName = "root";   // 用户名
    password = "42584693";   // 密码
    dbconn = QSqlDatabase::addDatabase("QMYSQL");
    dbconn.setHostName(hostName);
    dbconn.setDatabaseName(dbName);
    dbconn.setUserName(userName);
    dbconn.setPassword(password);
    QSqlError error1 = dbconn.lastError();
    qDebug() << error1.text();
}

void database::createtable()
{
    QSqlQuery query;   //运行数据库命令
    bool success=query.exec("CREATE TABLE account (username VARCHAR(10) NOT NULL PRIMARY, Password VARCHAR(10) NOT NULL)");
    if(success)
        qDebug()<<QObject::tr("数据库表创建成功！\n");
    else
        qDebug()<<QObject::tr("数据库表创建失败！\n");

}



bool database::verifyaccout(std::string name, std::string password)
{
    QSqlQuery query;
    std::string s = "select "+name+" from account"; //sql语句
    qDebug() <<QString::fromStdString(s);
    bool success = query.exec(QString::fromStdString(s));
    if(success)
    {
        qDebug()<<QObject::tr("成功！\n");
        return true;
    }
    else
    {
        qDebug()<<QObject::tr("失败！\n");
        s = "insert into account values('" + name +"','"+password+"')";
         qDebug() <<QString::fromStdString(s);
        bool su = query.exec(QString::fromStdString(s));
        if(su)
        {
            qDebug()<<QObject::tr("insert account成功！\n");
            return true;
        }
        else
        {
            qDebug()<<QObject::tr("inster account失败！\n");
            return false;
        }
    }
}




//std::vector<QString> database::setnamelist()
//{

//}
