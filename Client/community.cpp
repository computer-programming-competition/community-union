

#include "community.h"

MyCommunity::MyCommunity()
{
    c_name = "篮球社";
    c_presentation = "篮球社成立于2014年，旨在聚集篮球爱好者一起锻炼身体、交流篮球技巧，提高篮球技术。";
}

QString MyCommunity::name() const
{
    return c_name;

}

QString MyCommunity::presentation() const
{
    return c_presentation;
}

void MyCommunity::setName(const QString &n)
{
    c_name = n;
}

void MyCommunity::setPresentation(const QString &p)
{
    c_presentation = p;
}

QString MyCommunity::number()
{
    return c_name;
}

