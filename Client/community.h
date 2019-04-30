#ifndef COMMUNITY_H
#define COMMUNITY_H
#include<QObject>
#include<vector>
class MyCommunity :public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

    Q_PROPERTY(QString presentation READ presentation WRITE setPresentation NOTIFY presentationChanged)
public:
    MyCommunity();
    QString name() const;
    QString presentation() const;  //

    void setName(const QString &n);
    void setPresentation(const QString &p);

    Q_INVOKABLE  QString number();


signals:
    void nameChanged();
    void presentationChanged();


private:
    QString c_name;//社团名
    QString c_presentation;//社团简介
    std::vector<QString> c_number;//社团成员
    std::vector<QString> c_activty;//社团活动

};

#endif // COMMUNITY_H
