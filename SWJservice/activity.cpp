#include "activity.h"
#include "newactivity.h"

Activity::Activity()
{

}

QString Activity::title() const
{
    return m_title;
}

void Activity::setTitle(const QString &title)
{
    m_title = title;
}

QString Activity::time() const
{
    return m_time;
}

void Activity::setTime(const QString &time)
{
    m_time = time;
}

QString Activity::label() const
{
    return m_label;
}

void Activity::setLabel(const QString &label)
{
    m_label = label;
}

QString Activity::content() const
{
    return m_content;
}

void Activity::setContent(const QString &content)
{
    m_content = content;
}

void Activity::setNewActivity(QString title, QString time, QString label, QString content)
{
    _newActivity.push_back(new NewActivity(title, time, label, content));
}

std::vector<NewActivity *> Activity::newActivity()
{
    return _newActivity;
}
