#include "communityitem.h"
#include "community.h"
#include <QDebug>
communityItem::communityItem()
{
    MyCommunity *one = new MyCommunity();
    QString intr="篮球社成立于2014年，旨在聚集篮球爱好者一起锻炼身体、交流篮球技巧，提高篮球技术。";
    one->setName("篮球");
    one->setPresentation(intr);
    MyCommunity *two =new MyCommunity();
    two->setName("围棋");
    intr="围棋社成立于2011年，旨在聚集篮球围棋爱好者一起锻炼智力、交流围棋技巧，提高围棋技术。";
    two->setPresentation(intr);
    MyCommunity *three =new MyCommunity();
    three->setName("电子商务");
    intr="电子商务社成立于2011年，旨在聚集电子商务爱好者一起锻炼智力、交流围棋技巧，提高围棋技术。";
    three->setPresentation(intr);
    MyCommunity *four =new MyCommunity();
    four->setName("街舞");
    intr="街舞社成立于2011年，旨在聚集街舞爱好者一起锻炼智力、交流围棋技巧，提高围棋技术。";
    four->setPresentation(intr);
    m_communitylist.append(one);
    m_communitylist.append(three);
    m_communitylist.append(four);
    m_communitylist.append(two);




}

QList<MyCommunity*> communityItem::communitylist() const
{
    return m_communitylist;
}

void communityItem::setCommunitylist(QList<MyCommunity *> s)
{
    m_communitylist = s;
}

QString communityItem::nowCName(int i)
{
    return m_communitylist[i]->name();
}

QString communityItem::nowCIntroduce(int i)
{
    return m_communitylist[i]->presentation();
}

