#include "newuser.h"

NewUser::NewUser(QString n,QString c):_name(n),_community(c)
{

}

QString NewUser::name() const
{
    return  _name;
}

void NewUser::setName(const QString &n)
{
    _name = n;
}

void NewUser::setCommunity(const QString &c)
{
    _community = c;
}

QString NewUser::community() const
{
    return _community;
}
