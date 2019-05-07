//蒋富豪 2018-1-5
#ifndef DATABASE_H
#define DATABASE_H

#include <QSql>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <vector>
#include <QSqlError>
#include <QDebug>
#include <QSqlRecord>
#include <string>
#include "activity.h"

class database
{
public:
    database();
    void startconnect();
    void createtable();
    void createActivityTable();        //chuang jian huo dong biao
    void insertvideo();
//    void insertActivity(QString username, QString title, QString time, QString label, QString content);                              //cha ru yi ge xin de huo dong

    bool verifyaccout(QString name,QString password);

    ~database(){
         dbconn.close();
    }

    //xie ru shu ju ku
    void activityToDatabase(QString username, QString title, QString time, QString label, QString content);

    //
    void setActivity();    
    Activity* activity();

private:
    QSqlDatabase dbconn;
    std::vector<QString> namelist;
    Activity* _activity;
};

#endif // DATABASE_H
