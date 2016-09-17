/****************************************************************************
** Meta object code from reading C++ file 'user.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../大一暑/c++/大作业/client (3)/client/client/user.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'user.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_User_t {
    QByteArrayData data[15];
    char stringdata[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_User_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_User_t qt_meta_stringdata_User = {
    {
QT_MOC_LITERAL(0, 0, 4),
QT_MOC_LITERAL(1, 5, 12),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 6),
QT_MOC_LITERAL(4, 26, 3),
QT_MOC_LITERAL(5, 30, 14),
QT_MOC_LITERAL(6, 45, 23),
QT_MOC_LITERAL(7, 69, 24),
QT_MOC_LITERAL(8, 94, 18),
QT_MOC_LITERAL(9, 113, 16),
QT_MOC_LITERAL(10, 130, 3),
QT_MOC_LITERAL(11, 134, 1),
QT_MOC_LITERAL(12, 136, 11),
QT_MOC_LITERAL(13, 148, 16),
QT_MOC_LITERAL(14, 165, 20)
    },
    "User\0returnTicket\0\0column\0row\0"
    "sendReturnInfo\0editPersonalInfoEnabled\0"
    "editPersonalInfoDisabled\0updatePersonalInfo\0"
    "showPersonalInfo\0pay\0x\0sendBuyInfo\0"
    "sendBuyOtherInfo\0extraInfoEditEnabled\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_User[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x0a,
       5,    0,   69,    2, 0x0a,
       6,    0,   70,    2, 0x0a,
       7,    0,   71,    2, 0x0a,
       8,    0,   72,    2, 0x0a,
       9,    0,   73,    2, 0x0a,
      10,    1,   74,    2, 0x0a,
      12,    0,   77,    2, 0x0a,
      13,    0,   78,    2, 0x0a,
      14,    1,   79,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void User::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        User *_t = static_cast<User *>(_o);
        switch (_id) {
        case 0: _t->returnTicket((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->sendReturnInfo(); break;
        case 2: _t->editPersonalInfoEnabled(); break;
        case 3: _t->editPersonalInfoDisabled(); break;
        case 4: _t->updatePersonalInfo(); break;
        case 5: _t->showPersonalInfo(); break;
        case 6: _t->pay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->sendBuyInfo(); break;
        case 8: _t->sendBuyOtherInfo(); break;
        case 9: _t->extraInfoEditEnabled((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject User::staticMetaObject = {
    { &AbstractUser::staticMetaObject, qt_meta_stringdata_User.data,
      qt_meta_data_User,  qt_static_metacall, 0, 0}
};


const QMetaObject *User::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *User::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_User.stringdata))
        return static_cast<void*>(const_cast< User*>(this));
    return AbstractUser::qt_metacast(_clname);
}

int User::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractUser::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
