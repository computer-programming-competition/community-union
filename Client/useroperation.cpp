#include "useroperation.h"

UserOperation::UserOperation()
{
    m_name = "蒋富豪";//从数据库中读取
    m_community = "篮球社";


}

QString UserOperation::name() const
{
    return m_name;
}

void UserOperation::setName(const QString &name)
{
    m_name = name;
}

QString UserOperation::community() const
{
    return m_community;
}

 void UserOperation::setCommunity(const QString &c)
{
    m_community = c;
}

QString UserOperation::personalS() const
{
    return m_personalS;
}

void UserOperation::setPersonalS(const QString &personalS)
{
    m_personalS = personalS;
}

QList<QString> UserOperation::activity() const
{
    return m_activity;
}

void UserOperation::setActivity(const QList<QString> &ac)
{
    m_activity = ac;
}
