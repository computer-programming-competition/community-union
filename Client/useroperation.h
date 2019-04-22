#ifndef USEROPERATION_H
#define USEROPERATION_H
#include <QObject>
#include <vector>
#include <string>

class UserOperation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString personalS READ  personalS WRITE setPersonalS NOTIFY personalSChanged)
public:
    UserOperation();
    QString name() const;
    void setName(const QString &name);

    QString personalS() const;
    void setPersonalS(const QString &personalS);

signals:
    void nameChanged();
    void personalSChanged();
private:
    QString m_id;
    QString m_name;
    QString m_personalS;


};

#endif // USEROPERATION_H
