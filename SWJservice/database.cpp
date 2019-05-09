//蒋富豪 2018-1-5
#include "database.h"
#include <QSqlError>
#include <QDebug>
#include <QSqlRecord>
#include <vector>
#include <user.h>
database::database()
{
    startconnect();//连接数据库

    qDebug("database open status: %d\n", dbconn.open());
    createActivityTable();
    createtable();
    QString n,p;

    _activity = new Activity();
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
    hostName = "127.0.0.1";   // 主机名
    dbName = "SWJsql";   // 数据库名称
    userName = "root";   // 用户名
    password = "root";   // 密码
    dbconn = QSqlDatabase::addDatabase("QMYSQL");
    dbconn.setHostName(hostName);
    dbconn.setDatabaseName(dbName);
    dbconn.setUserName(userName);
    dbconn.setPassword(password);
    QSqlError error1 = dbconn.lastError();
    qDebug() << error1.text();
    // qDebug() << error1.text();
}

void database::createtable()
{
    QSqlQuery query;
    bool success=query.exec("CREATE TABLE account (id int(5) NOT NULL auto_increment ,communityid int(5) NOT NULL,username VARCHAR(10) NOT NULL, Password VARCHAR(10) NOT NULL,PRIMARY KEY(id))");

    //query.exec("insert into account values('','','jiangfuhao', '666666')");
    QString s= "insert into community values('','basketball','篮球社成立于2014年，旨在聚集篮球爱好者一起锻炼身体、交流篮球技巧，提高篮球技术。')";
    if(success)
        qDebug()<<QObject::tr("数据库表创建成功！\n");
    else
        qDebug()<<QObject::tr("数据库表创建失败！\n");

}

void database::createActivityTable()
{
    QSqlQuery query;
    bool success = query.exec("CREATE TABLE activity (id int(5) NOT NULL auto_increment,communityname varchar(20) NOT NULL, title varchar(20), time varchar(20), label varchar(10), content varchar(100),PRIMARY KEY (id))");
    //query.exec("insert into activity values('', 1,'点燃五四之火', '2019.05.9～2019.05.24', '思想成长', 'balabalabala')");
    //bool success = query.exec("CREATE TABLE account12 (username varchar(10),password varchar(20))");
    if(success)
        qDebug()<<QObject::tr("数据库huodong表创建成功！\n");
    else
        qDebug()<<QObject::tr("数据库huodong表创建失败！\n");
}

bool database::joinCommunity(QString c,QString n)
{
    QString j = "update community set community = '"+c+"' where username = '"+n+"'";
    QSqlQuery query;
    bool s = query.exec(j);
    if(s)
    {
        return true;
    }else
    {
        return false;
    }
}

void database::getUserInformation(QString name)
{

}

void database::getCommunityInformation(int id)
{

}

void database::getActivityMember(int id)
{
    QSqlQuery query;
    query.exec("select * from account_activity where activityid = 1");
    while(query.next())
    {

    }

}


bool database::verifyaccout(QString name, QString password)
{
    QSqlQuery query;
    QString s = "select * from account where username='"+name+"' and Password='"+password+"'";
    qDebug() << s;
    bool success = query.exec(s);
    QSqlRecord rec = query.record();
    if(query.next())
    {
        _user = new user();
        _user->setName(query.value(2).toString());
        QString cid  = query.value(1).toString();
        qDebug() << "id:"+cid;
        s = "select * from community where id ="+cid;
        query.exec(s);
        QSqlRecord rec = query.record();
        if(query.next())
        {
            qDebug()<< "databese:"+query.value(1).toString();
            _user->setCommunity(query.value(1).toString());
        }


        return true;
    }else
    {
        return false;
    }

}

QString database::signupaccount(QString name, QString password)
{
    QSqlQuery query;
    QString s = "select * from account where username='"+name+"' and Password='"+password+"'";
    qDebug() << s;
     query.exec(s);
    QSqlRecord rec = query.record();
    if(query.next())
    {
        return "账户存在";
    }
    else
    {
        //qDebug()<<QObject::tr("失败！\n");
        s = "insert into account values('','','" + name +"','"+password+"')";
         qDebug() <<s;
        bool su = query.exec(s);
        if(su)
        {
            qDebug()<<QObject::tr("insert account成功！\n");
            return "sign up succes";
        }
        else
        {
            qDebug()<<QObject::tr("inster account失败！\n");
            return "sign up losed";
        }
    }
}

QString database::PostActivityVerify(QString id, QString name)
{
    QSqlQuery query;
    QString s = "select * from community where id='"+id+"' and name='"+name+"'";
    qDebug() << s;
     query.exec(s);
    QSqlRecord rec = query.record();
    if(query.next())
    {
        return "true";
    }
    else
    {
       return "false";
    }
}

void database::activityToDatabase(QString cname, QString title, QString time, QString label, QString content)
{
    QSqlQuery query;
    QString a = "insert into activity values('','" + cname +"','"+title+"','"+time+"','"+label+"','"+content+"')";
    query.exec(a);
}

void database::setActivity()
{
    for(auto &temp : _activity->newActivity()){
        delete temp;
    }
    _activity->_newActivity.clear();

    QSqlQuery query;
    query.exec( "select * from activity");// 执行查询操作
    while (query.next()) {
        _activity->setNewActivity(query.value(2).toString(), query.value(3).toString(), query.value(4).toString(), query.value(5).toString());
    }
}

Activity* database::activity()
{
    return _activity;
}

user *database::myuser()
{
    return _user;
}

