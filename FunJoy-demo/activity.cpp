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
    if(m_title != title){
        m_title = title;
        emit titleChanged();
    }
}

QString Activity::time() const
{
    return m_time;
}

void Activity::setTime(const QString &time)
{
    if(m_time != time){
        m_time = time;
        emit timeChanged();
    }
}

QString Activity::label() const
{
    return m_label;
}

void Activity::setLabel(const QString &label)
{
    if(m_label != label){
        m_label = label;
        emit labelChanged();
    }
}

QString Activity::content() const
{
    return m_content;
}

void Activity::setContent(const QString &content)
{
    if(m_content != content){
        m_content = content;
        emit contentChanged();
    }
}

void Activity::setNewActivity(QString title, QString time, QString label, QString content)
{
    _newActivity.push_back(new NewActivity(title, time, label, content));
}

std::vector<NewActivity *> Activity::newActivity() const
{
    return _newActivity;
}
