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
    password = "2241699du";   // 密码
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
    bool success=query.exec("CREATE TABLE account (username VARCHAR(10) NOT NULL PRIMARY, Password VARCHAR(10) NOT NULL)");
    if(success)
        qDebug()<<QObject::tr("数据库表创建成功！\n");
    else
        qDebug()<<QObject::tr("数据库表创建失败！\n");

}

void database::createActivityTable()
{
    QSqlQuery query;
    bool success = query.exec("CREATE TABLE activity (username varchar(20) primary key, title varchar(20), time varchar(20), label varchar(10), content varchar(100))");
    query.exec("insert into activity values(0, '点燃五四之火', '2019.05.9～2019.05.24', '思想成长', 'balabalabala')");
    //bool success = query.exec("CREATE TABLE account12 (username varchar(10),password varchar(20))");
    if(success)
        qDebug()<<QObject::tr("数据库huodong表创建成功！\n");
    else
        qDebug()<<QObject::tr("数据库huodong表创建失败！\n");
}

void database::insertvideo()
{
     QSqlQuery query;
    query.exec("insert into videopath values( 0,'1.mkv')");
    bool success = query.exec("insert into videopath values( 0,'2.mkv')");
    if(success)
        qDebug()<<QObject::tr("insert成功！\n");
    else
        qDebug()<<QObject::tr("inster失败！\n");

    query.exec("insert into videopath values( 0,'3.mkv')");
}

bool database::verifyaccout(std::string name, std::string password)
{
    QSqlQuery query;
    std::string s = "select "+name+" from account";
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


std::vector<QString> database::selectvidio()
{
    QSqlQuery query;

    query.exec( "select * from videopath");// 执行查询操作
    QSqlRecord rec = query.record();
//    qDebug() << "exec next() : ";

    while(query.next())
    // 开始就先执行一次next() 函数，那么query 指向结果集的第一条记录
    {
            int rowNum = query.at();
            // 获取query 所指向的记录在结果集中的编号

            int columnNum = rec.count();
            // 获取每条记录中属性（即列）的个数
            int fieldNo = query.record().indexOf( "name");
            // 获取 " name "属性所在列的编号，列从左向右编号，最左边的编号为 0
            int id = query.value(0).toInt();
            // 获取id 属性的值，并转换为int 型
           QString name = query.value(fieldNo).toString();
            // 获取name 属性的值
            qDebug() << "rowNum is : " << rowNum // 将结果输出
                    << " id is : " << id
                    << " name is : " << name
                    << " columnNum is : " << columnNum;
            namelist.push_back(name);

    }
//        for (int i= 0; i<namelist.size(); i++)
//        {
//            qDebug()<< namelist[i] << " ";
//        }
    return namelist;
//    qDebug() << "exec seek(2) : ";
//    if(query.seek(2))
//    // 定位到结果集中编号为2 的记录，即第三条记录，因为第一条记录的编号为 0
//    {
//            qDebug() << "rowNum is : " << query.at()
//                    << " id is : " << query.value(0).toInt()
//                    << " name is : " << query.value(1).toString();
//    }
//    qDebug() << "exec last() : ";
//    if(query.last())
//    // 定位到结果集中最后一条记录

//    {
//            qDebug() << "rowNum is : " << query.at()
//                    << " id is : " << query.value(0).toInt()
//                    << " name is : " << query.value(1).toString();
//    }


}

void database::setActivity()
{
    for(auto &temp : _activity._newActivity){
        delete temp;
    }
    _activity._newActivity.clear();

    QSqlQuery query;
    query.exec( "select * from activity");// 执行查询操作
    while (query.next()) {
        _activity.setNewActivity(query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString());
    }
}

Activity database::activity() const
{
    return _activity;
}

//std::vector<QString> database::setnamelist()
//{

//}
