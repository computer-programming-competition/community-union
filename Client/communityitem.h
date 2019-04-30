#ifndef COMMUNITYITEM_H
#define COMMUNITYITEM_H
#include <vector>
#include <QObject>
#include "community.h"
#include <QJsonArray>
#include <QList>
class communityItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<MyCommunity*> communitylist READ communitylist  WRITE setCommunitylist  NOTIFY communitylistChanged)
public:
    communityItem();
    QList<MyCommunity*> communitylist() const;
    void setCommunitylist(QList<MyCommunity*> s);
     Q_INVOKABLE QString nowCName(int i);
     Q_INVOKABLE QString nowCIntroduce(int i);


signals:
    void communitylistChanged();


private:
    QList<MyCommunity*> m_communitylist;
    int m_number;

};



#endif // COMMUNITYITEM_H
