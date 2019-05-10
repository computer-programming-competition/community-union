/****************************************************************************
** Meta object code from reading C++ file 'useroperation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Client/useroperation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'useroperation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UserOperation_t {
    QByteArrayData data[17];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserOperation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserOperation_t qt_meta_stringdata_UserOperation = {
    {
QT_MOC_LITERAL(0, 0, 13), // "UserOperation"
QT_MOC_LITERAL(1, 14, 11), // "nameChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 16), // "personalSChanged"
QT_MOC_LITERAL(4, 44, 16), // "communityChanged"
QT_MOC_LITERAL(5, 61, 15), // "activityChanged"
QT_MOC_LITERAL(6, 77, 7), // "setName"
QT_MOC_LITERAL(7, 85, 4), // "name"
QT_MOC_LITERAL(8, 90, 12), // "setCommunity"
QT_MOC_LITERAL(9, 103, 1), // "c"
QT_MOC_LITERAL(10, 105, 12), // "setPersonalS"
QT_MOC_LITERAL(11, 118, 9), // "personalS"
QT_MOC_LITERAL(12, 128, 11), // "setActivity"
QT_MOC_LITERAL(13, 140, 14), // "QList<QString>"
QT_MOC_LITERAL(14, 155, 2), // "ac"
QT_MOC_LITERAL(15, 158, 9), // "community"
QT_MOC_LITERAL(16, 168, 8) // "activity"

    },
    "UserOperation\0nameChanged\0\0personalSChanged\0"
    "communityChanged\0activityChanged\0"
    "setName\0name\0setCommunity\0c\0setPersonalS\0"
    "personalS\0setActivity\0QList<QString>\0"
    "ac\0community\0activity"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserOperation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       4,   70, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       6,    1,   58,    2, 0x02 /* Public */,
       8,    1,   61,    2, 0x02 /* Public */,
      10,    1,   64,    2, 0x02 /* Public */,
      12,    1,   67,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, 0x80000000 | 13,   14,

 // properties: name, type, flags
       7, QMetaType::QString, 0x00495103,
      15, QMetaType::QString, 0x00495103,
      16, 0x80000000 | 13, 0x0049510b,
      11, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       2,
       3,
       1,

       0        // eod
};

void UserOperation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserOperation *_t = static_cast<UserOperation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nameChanged(); break;
        case 1: _t->personalSChanged(); break;
        case 2: _t->communityChanged(); break;
        case 3: _t->activityChanged(); break;
        case 4: _t->setName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->setCommunity((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->setPersonalS((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->setActivity((*reinterpret_cast< const QList<QString>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UserOperation::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserOperation::nameChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UserOperation::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserOperation::personalSChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (UserOperation::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserOperation::communityChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (UserOperation::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserOperation::activityChanged)) {
                *result = 3;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        UserOperation *_t = static_cast<UserOperation *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->community(); break;
        case 2: *reinterpret_cast< QList<QString>*>(_v) = _t->activity(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->personalS(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        UserOperation *_t = static_cast<UserOperation *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setName(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setCommunity(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setActivity(*reinterpret_cast< QList<QString>*>(_v)); break;
        case 3: _t->setPersonalS(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject UserOperation::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UserOperation.data,
      qt_meta_data_UserOperation,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UserOperation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserOperation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserOperation.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UserOperation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void UserOperation::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void UserOperation::personalSChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void UserOperation::communityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void UserOperation::activityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
