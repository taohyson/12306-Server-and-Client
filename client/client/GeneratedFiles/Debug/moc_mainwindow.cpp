/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../大一暑/c++/大作业/client (3)/client/client/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 3),
QT_MOC_LITERAL(2, 15, 0),
QT_MOC_LITERAL(3, 16, 1),
QT_MOC_LITERAL(4, 18, 10),
QT_MOC_LITERAL(5, 29, 10),
QT_MOC_LITERAL(6, 40, 17),
QT_MOC_LITERAL(7, 58, 19),
QT_MOC_LITERAL(8, 78, 15),
QT_MOC_LITERAL(9, 94, 8),
QT_MOC_LITERAL(10, 103, 9),
QT_MOC_LITERAL(11, 113, 3),
QT_MOC_LITERAL(12, 117, 6),
QT_MOC_LITERAL(13, 124, 6),
QT_MOC_LITERAL(14, 131, 13),
QT_MOC_LITERAL(15, 145, 11),
QT_MOC_LITERAL(16, 157, 15),
QT_MOC_LITERAL(17, 173, 11)
    },
    "MainWindow\0pay\0\0x\0triggerPay\0triggerBuy\0"
    "triggerBuyStudent\0triggerReturnTicket\0"
    "triggerBuyOther\0payCheck\0askDetail\0"
    "row\0column\0logout\0onForceLogout\0"
    "exitProgram\0setupTicketInfo\0searchTrain\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       4,    0,   82,    2, 0x08,
       5,    0,   83,    2, 0x08,
       6,    0,   84,    2, 0x08,
       7,    0,   85,    2, 0x08,
       8,    0,   86,    2, 0x08,
       9,    0,   87,    2, 0x08,
      10,    2,   88,    2, 0x08,
      13,    0,   93,    2, 0x0a,
      14,    0,   94,    2, 0x0a,
      15,    0,   95,    2, 0x0a,
      16,    0,   96,    2, 0x0a,
      17,    0,   97,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->pay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->triggerPay(); break;
        case 2: _t->triggerBuy(); break;
        case 3: _t->triggerBuyStudent(); break;
        case 4: _t->triggerReturnTicket(); break;
        case 5: _t->triggerBuyOther(); break;
        case 6: _t->payCheck(); break;
        case 7: _t->askDetail((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->logout(); break;
        case 9: _t->onForceLogout(); break;
        case 10: _t->exitProgram(); break;
        case 11: _t->setupTicketInfo(); break;
        case 12: _t->searchTrain(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::pay)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::pay(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
