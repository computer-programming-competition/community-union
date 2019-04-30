#ifndef USEROPERATION_H
#define USEROPERATION_H
#include <QObject>
#include <vector>
#include <string>
#include <QList>
class UserOperation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString community READ community WRITE setCommunity NOTIFY communityChanged)
    Q_PROPERTY(QList<QString> activity READ activity WRITE setActivity NOTIFY activityChanged)
    Q_PROPERTY(QString personalS READ  personalS WRITE setPersonalS NOTIFY personalSChanged)
public:
    UserOperation();
    QString name() const;
    Q_INVOKABLE void setName(const QString &name);

    QString community() const;
    Q_INVOKABLE void setCommunity(const QString &c);

    QString personalS() const;
    Q_INVOKABLE void setPersonalS(const QString &personalS);

    QList<QString> activity() const;
    Q_INVOKABLE void setActivity(const QList<QString> &ac);

signals:
    void nameChanged();
    void personalSChanged();
    void communityChanged();
    void activityChanged();
private:
    QString m_id;
    QString m_name;
    QString m_personalS;
    QString m_community;
    QList<QString> m_activity;


};

#endif // USEROPERATION_H
