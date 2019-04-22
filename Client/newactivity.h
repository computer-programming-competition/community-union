//author: duHongpeng
//time: 19.4.19
#ifndef NEWACTIVITY_H
#define NEWACTIVITY_H
#include <QString>
#include <iostream>

class NewActivity
{
public:
    NewActivity(QString title, QString time, QString label, QString content);


    QString title() const;
    void setTitle(const QString &title);

    QString time() const;
    void setTime(const QString &time);

    QString label() const;
    void setLabel(const QString &label);

    QString content() const;
    void setContent(const QString &content);

private:
    QString m_title;
    QString m_time;
    QString m_label;
    QString m_content;
};

#endif // NEWACTIVITY_H
