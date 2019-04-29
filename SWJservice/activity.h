//author: duHongpeng
//time: 19.4.22
#ifndef ACTIVITY_H
#define ACTIVITY_H
#include <string>
#include <QString>
#include <iostream>
#include <vector>
#include <QList>

class NewActivity;

class Activity
{
public:
    Activity();
    QString title() const;
    void setTitle(const QString &title);

    QString time() const;
    void setTime(const QString &time);

    QString label() const;
    void setLabel(const QString &label);

    QString content() const;
    void setContent(const QString &content);

    void setNewActivity(QString title, QString time, QString label, QString content);      //tian jia xin fa bu de huo dong
    std::vector<NewActivity *> newActivity();    //ke yi zhao dao gai yong hu suo you fa bu de huo dong
    QList<QString> getMessageList();
    std::vector<NewActivity*> _newActivity;
private:
    QString m_title;  //huodong zhuti
    QString m_time;   //huo dong shi jian
    QString m_label;  //huo dong biao qian
    QString m_content; //huo dong nei rong    
};

#endif // ACTIVITY_H
