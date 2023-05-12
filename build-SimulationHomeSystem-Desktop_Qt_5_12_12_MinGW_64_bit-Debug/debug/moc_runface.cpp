/****************************************************************************
** Meta object code from reading C++ file 'runface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SimulationHomeSystem/runface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'runface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_runface_t {
    QByteArrayData data[14];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_runface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_runface_t qt_meta_stringdata_runface = {
    {
QT_MOC_LITERAL(0, 0, 7), // "runface"
QT_MOC_LITERAL(1, 8, 15), // "recHeatCapacity"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 9), // "recPower1"
QT_MOC_LITERAL(4, 35, 15), // "recCoolCapacity"
QT_MOC_LITERAL(5, 51, 13), // "recTemprature"
QT_MOC_LITERAL(6, 65, 12), // "recAirVolumn"
QT_MOC_LITERAL(7, 78, 9), // "recPower2"
QT_MOC_LITERAL(8, 88, 16), // "recaveTemprature"
QT_MOC_LITERAL(9, 105, 9), // "recPower3"
QT_MOC_LITERAL(10, 115, 12), // "rechumidity1"
QT_MOC_LITERAL(11, 128, 9), // "recPower4"
QT_MOC_LITERAL(12, 138, 12), // "rechumidity2"
QT_MOC_LITERAL(13, 151, 9) // "recPower5"

    },
    "runface\0recHeatCapacity\0\0recPower1\0"
    "recCoolCapacity\0recTemprature\0"
    "recAirVolumn\0recPower2\0recaveTemprature\0"
    "recPower3\0rechumidity1\0recPower4\0"
    "rechumidity2\0recPower5"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_runface[] = {

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
       1,    1,   74,    2, 0x08 /* Private */,
       3,    1,   77,    2, 0x08 /* Private */,
       4,    1,   80,    2, 0x08 /* Private */,
       5,    1,   83,    2, 0x08 /* Private */,
       6,    1,   86,    2, 0x08 /* Private */,
       7,    1,   89,    2, 0x08 /* Private */,
       8,    1,   92,    2, 0x08 /* Private */,
       9,    1,   95,    2, 0x08 /* Private */,
      10,    1,   98,    2, 0x08 /* Private */,
      11,    1,  101,    2, 0x08 /* Private */,
      12,    1,  104,    2, 0x08 /* Private */,
      13,    1,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void runface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<runface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->recHeatCapacity((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->recPower1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->recCoolCapacity((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->recTemprature((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->recAirVolumn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->recPower2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->recaveTemprature((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->recPower3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->rechumidity1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->recPower4((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->rechumidity2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->recPower5((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject runface::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_runface.data,
    qt_meta_data_runface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *runface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *runface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_runface.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int runface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
