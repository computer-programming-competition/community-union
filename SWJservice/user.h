#ifndef USER_H
#define USER_H
#include<QString>

class user
{
public:
    user();
    QString name() const;
    void setName(const QString &n);
    void setCommunity(const QString &c);
    QString community() const;
private:
    QString _name;
    QString _community;
};

#endif // USER_H
