#include "useroperation.h"

UserOperation::UserOperation()
{

}

QString UserOperation::name() const
{
    return m_name;
}

void UserOperation::setName(const QString &name)
{
    m_name = name;
}

QString UserOperation::personalS() const
{
    return m_personalS;
}

void UserOperation::setPersonalS(const QString &personalS)
{
    m_personalS = personalS;
}
