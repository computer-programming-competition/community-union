//蒋富豪 2018-1-5
#include "database.h"
#include <QSqlError>
#include <QDebug>
#include <QSqlRecord>
#include <vector>

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
    bool success=query.exec("CREATE TABLE account (username VARCHAR(10) NOT NULL, Password VARCHAR(10) NOT NULL,community varchar(20), PRIMARY KEY (username))");
    //QString s =             "CREATE TABLE activity (username varchar(20), title varchar(20), time varchar(20), label varchar(10), content varchar(100))";
    query.exec("insert into account values('jiangfuhao', '666666', 'basketball')");
    if(success)
        qDebug()<<QObject::tr("数据库表创建成功！\n");
    else
        qDebug()<<QObject::tr("数据库表创建失败！\n");

}

void database::createActivityTable()
{
    QSqlQuery query;
    bool success = query.exec("CREATE TABLE activity (username varchar(20), title varchar(20), time varchar(20), label varchar(10), content varchar(100))");
    query.exec("insert into activity values('0', '点燃五四之火', '2019.05.9～2019.05.24', '思想成长', 'balabalabala')");
    //bool success = query.exec("CREATE TABLE account12 (username varchar(10),password varchar(20))");
    if(success)
        qDebug()<<QObject::tr("数据库huodong表创建成功！\n");
    else
        qDebug()<<QObject::tr("数据库huodong表创建失败！\n");
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


        s = "select * from account where username='"+name+"' and Password='"+password+"'";
        //bool suc = query.exec(s);


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
    bool success = query.exec(s);
    QSqlRecord rec = query.record();
    if(query.next())
    {
        return "账户存在";
    }
    else
    {
        //qDebug()<<QObject::tr("失败！\n");
        s = "insert into account values('" + name +"','"+password+"','')";
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




void database::activityToDatabase(QString username, QString title, QString time, QString label, QString content)
{
    QSqlQuery query;
    QString a = "insert into activity values('" + username +"','"+title+"','"+time+"','"+label+"','"+content+"')";
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
        _activity->setNewActivity(query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString());
    }
}

Activity* database::activity()
{
    return _activity;
}

//std::vector<QString> database::setnamelist()
//{

//}
