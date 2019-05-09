#include "user.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include "newuser.h"
user::user()
{

}

QString user::name() const
{
    return  _name;
}

void user::setName(const QString &n)
{
    _name = n;
}

void user::setCommunity(const QString &c)
{
    _community = c;
}

QString user::community() const
{
    return _community;
}

void user::setNewUser(QString n, QString c)
{
    _newUser.push_back(new NewUser(n,c));
}

std::vector<NewUser *> user::newUser()
{
    return _newUser;
}

QList<QString> user::getAccountList()
{
    QList<QString> msg;
    for(auto temp:_newUser)
    {
        QJsonObject userList;
        userList.insert("name",temp->name());
        userList.insert("community",temp->community());
        msg.append(QString(QJsonDocument(userList).toJson()));
    }
    return msg;

}

