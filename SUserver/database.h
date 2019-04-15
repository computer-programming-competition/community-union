#ifndef DATABASE_H
#define DATABASE_H
//蒋富豪 2019-4-15
//服务器连接的数据库操作
#include <QSql>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <vector>
#include <QSqlError>
#include <QDebug>
#include <QSqlRecord>
#include <string>
class database
{
public:
    database();
    void startconnect();  //开始连接数据库
    void createtable();   //创建用户数据表

    bool verifyaccout(std::string name,std::string password); //验证账户

    ~database(){
         dbconn.close();
    }
//    std::vector<QString> setnamelist();
private:
    QSqlDatabase dbconn;    //数据库操作
    std::vector<QString> namelist;
};

#endif // DATABASE_H
