/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[355];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "on_pb_start_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 18), // "on_pb_kill_clicked"
QT_MOC_LITERAL(4, 51, 27), // "on_pb_startDetached_clicked"
QT_MOC_LITERAL(5, 79, 33), // "on_pb_startDetachedParams_cli..."
QT_MOC_LITERAL(6, 113, 21), // "on_pb_execute_clicked"
QT_MOC_LITERAL(7, 135, 27), // "on_pb_executeParams_clicked"
QT_MOC_LITERAL(8, 163, 21), // "on_pb_toChild_clicked"
QT_MOC_LITERAL(9, 185, 10), // "afterStart"
QT_MOC_LITERAL(10, 196, 10), // "afterError"
QT_MOC_LITERAL(11, 207, 22), // "QProcess::ProcessError"
QT_MOC_LITERAL(12, 230, 11), // "afterFinish"
QT_MOC_LITERAL(13, 242, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(14, 263, 13), // "readFromChild"
QT_MOC_LITERAL(15, 277, 26), // "on_pb_createShared_clicked"
QT_MOC_LITERAL(16, 304, 25), // "on_pb_writeShared_clicked"
QT_MOC_LITERAL(17, 330, 24) // "on_pb_readShared_clicked"

    },
    "MainWindow\0on_pb_start_clicked\0\0"
    "on_pb_kill_clicked\0on_pb_startDetached_clicked\0"
    "on_pb_startDetachedParams_clicked\0"
    "on_pb_execute_clicked\0on_pb_executeParams_clicked\0"
    "on_pb_toChild_clicked\0afterStart\0"
    "afterError\0QProcess::ProcessError\0"
    "afterFinish\0QProcess::ExitStatus\0"
    "readFromChild\0on_pb_createShared_clicked\0"
    "on_pb_writeShared_clicked\0"
    "on_pb_readShared_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    1,   92,    2, 0x08 /* Private */,
      12,    2,   95,    2, 0x08 /* Private */,
      14,    0,  100,    2, 0x08 /* Private */,
      15,    0,  101,    2, 0x08 /* Private */,
      16,    0,  102,    2, 0x08 /* Private */,
      17,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 13,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pb_start_clicked(); break;
        case 1: _t->on_pb_kill_clicked(); break;
        case 2: _t->on_pb_startDetached_clicked(); break;
        case 3: _t->on_pb_startDetachedParams_clicked(); break;
        case 4: _t->on_pb_execute_clicked(); break;
        case 5: _t->on_pb_executeParams_clicked(); break;
        case 6: _t->on_pb_toChild_clicked(); break;
        case 7: _t->afterStart(); break;
        case 8: _t->afterError((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        case 9: _t->afterFinish((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 10: _t->readFromChild(); break;
        case 11: _t->on_pb_createShared_clicked(); break;
        case 12: _t->on_pb_writeShared_clicked(); break;
        case 13: _t->on_pb_readShared_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
