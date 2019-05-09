#include "user.h"

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

