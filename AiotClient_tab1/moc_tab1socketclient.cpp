/****************************************************************************
** Meta object code from reading C++ file 'tab1socketclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tab1socketclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tab1socketclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tab1SocketClient_t {
    QByteArrayData data[7];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tab1SocketClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tab1SocketClient_t qt_meta_stringdata_Tab1SocketClient = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Tab1SocketClient"
QT_MOC_LITERAL(1, 17, 11), // "ledWriteSig"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 27), // "on_pPBServerConnect_clicked"
QT_MOC_LITERAL(4, 58, 7), // "checked"
QT_MOC_LITERAL(5, 66, 20), // "socketRecvUpdateSlot"
QT_MOC_LITERAL(6, 87, 24) // "on_pPBSendButton_clicked"

    },
    "Tab1SocketClient\0ledWriteSig\0\0"
    "on_pPBServerConnect_clicked\0checked\0"
    "socketRecvUpdateSlot\0on_pPBSendButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tab1SocketClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   37,    2, 0x08 /* Private */,
       5,    1,   40,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void Tab1SocketClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Tab1SocketClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ledWriteSig((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pPBServerConnect_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->socketRecvUpdateSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_pPBSendButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Tab1SocketClient::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tab1SocketClient::ledWriteSig)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Tab1SocketClient::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Tab1SocketClient.data,
    qt_meta_data_Tab1SocketClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Tab1SocketClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tab1SocketClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tab1SocketClient.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Tab1SocketClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Tab1SocketClient::ledWriteSig(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE