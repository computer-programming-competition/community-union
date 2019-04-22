#include "newactivity.h"

NewActivity::NewActivity(QString title, QString time, QString label, QString content):m_title(title), m_time(time), m_label(label), m_content(content)
{

}

QString NewActivity::title() const
{
    return m_title;
}

void NewActivity::setTitle(const QString &title)
{
    m_title = title;
}

QString NewActivity::time() const
{
    return m_time;
}

void NewActivity::setTime(const QString &time)
{
    m_time = time;
}

QString NewActivity::label() const
{
    return m_label;
}

void NewActivity::setLabel(const QString &label)
{
    m_label = label;
}

QString NewActivity::content() const
{
    return m_content;
}

void NewActivity::setContent(const QString &content)
{
    m_content = content;
}
