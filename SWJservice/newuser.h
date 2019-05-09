#ifndef NEWUSER_H
#define NEWUSER_H

#include<QString>
#include<iostream>
#include<vector>
class NewUser
{
public:
    NewUser(QString n,QString c);
    QString name() const;
    void setName(const QString &n);
    void setCommunity(const QString &c);
    QString community() const;

private:
    QString _name;
    QString _community;
};

#endif // NEWUSER_H
