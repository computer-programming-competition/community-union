//author: duHongpeng
//time: 19.4.18
//time: 19.4.19
#ifndef ACTIVITY_H
#define ACTIVITY_H
#include <QObject>
#include <string>
#include <iostream>
#include <vector>

class NewActivity;

class Activity : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString time READ time WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY labelChanged)
    Q_PROPERTY(QString content READ content WRITE setContent NOTIFY contentChanged)
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

    Q_INVOKABLE void setNewActivity(QString title, QString time, QString label, QString content);      //tian jia xin fa bu de huo dong
    std::vector<NewActivity *> newActivity() const;    //ke yi zhao dao gai yong hu suo you fa bu de huo dong

signals:
    void titleChanged();
    void timeChanged();
    void labelChanged();
    void contentChanged();
private:
    QString m_title;  //huodong zhuti
    QString m_time;   //huo dong shi jian
    QString m_label;  //huo dong biao qian
    QString m_content; //huo dong nei rong
    std::vector<NewActivity*> _newActivity;
};

#endif // ACTIVITY_H
