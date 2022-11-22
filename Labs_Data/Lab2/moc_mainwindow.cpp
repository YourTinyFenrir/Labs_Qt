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
    QByteArrayData data[15];
    char stringdata0[386];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 36), // "on_action_createConnection_tr..."
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 35), // "on_action_closeConnection_tri..."
QT_MOC_LITERAL(4, 85, 31), // "on_action_createTable_triggered"
QT_MOC_LITERAL(5, 117, 29), // "on_action_dropTable_triggered"
QT_MOC_LITERAL(6, 147, 30), // "on_action_insertInto_triggered"
QT_MOC_LITERAL(7, 178, 30), // "on_action_printTable_triggered"
QT_MOC_LITERAL(8, 209, 34), // "on_action_initTableModel_trig..."
QT_MOC_LITERAL(9, 244, 27), // "on_action_doQuery_triggered"
QT_MOC_LITERAL(10, 272, 31), // "on_action_selectTable_triggered"
QT_MOC_LITERAL(11, 304, 30), // "on_action_insertRows_triggered"
QT_MOC_LITERAL(12, 335, 30), // "on_action_removeRows_triggered"
QT_MOC_LITERAL(13, 366, 12), // "slot_getData"
QT_MOC_LITERAL(14, 379, 6) // "MyRect"

    },
    "MainWindow\0on_action_createConnection_triggered\0"
    "\0on_action_closeConnection_triggered\0"
    "on_action_createTable_triggered\0"
    "on_action_dropTable_triggered\0"
    "on_action_insertInto_triggered\0"
    "on_action_printTable_triggered\0"
    "on_action_initTableModel_triggered\0"
    "on_action_doQuery_triggered\0"
    "on_action_selectTable_triggered\0"
    "on_action_insertRows_triggered\0"
    "on_action_removeRows_triggered\0"
    "slot_getData\0MyRect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    1,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_action_createConnection_triggered(); break;
        case 1: _t->on_action_closeConnection_triggered(); break;
        case 2: _t->on_action_createTable_triggered(); break;
        case 3: _t->on_action_dropTable_triggered(); break;
        case 4: _t->on_action_insertInto_triggered(); break;
        case 5: _t->on_action_printTable_triggered(); break;
        case 6: _t->on_action_initTableModel_triggered(); break;
        case 7: _t->on_action_doQuery_triggered(); break;
        case 8: _t->on_action_selectTable_triggered(); break;
        case 9: _t->on_action_insertRows_triggered(); break;
        case 10: _t->on_action_removeRows_triggered(); break;
        case 11: _t->slot_getData((*reinterpret_cast< MyRect(*)>(_a[1]))); break;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
