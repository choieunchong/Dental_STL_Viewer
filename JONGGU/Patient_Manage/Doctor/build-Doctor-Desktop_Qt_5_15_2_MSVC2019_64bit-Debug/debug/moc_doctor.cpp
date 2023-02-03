/****************************************************************************
** Meta object code from reading C++ file 'doctor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../Qt1/Doctor/doctor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'doctor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Doctor_t {
    QByteArrayData data[16];
    char stringdata0[319];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Doctor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Doctor_t qt_meta_stringdata_Doctor = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Doctor"
QT_MOC_LITERAL(1, 7, 31), // "on_patientNewpushButton_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 39), // "on_patientGenderMaleradioButt..."
QT_MOC_LITERAL(4, 80, 41), // "on_patientGenderFemaleradioBu..."
QT_MOC_LITERAL(5, 122, 39), // "on_patientGenderNoneradioButt..."
QT_MOC_LITERAL(6, 162, 11), // "receiveData"
QT_MOC_LITERAL(7, 174, 8), // "sendData"
QT_MOC_LITERAL(8, 183, 8), // "goOnSend"
QT_MOC_LITERAL(9, 192, 8), // "numBytes"
QT_MOC_LITERAL(10, 201, 8), // "sendFile"
QT_MOC_LITERAL(11, 210, 13), // "serverConnect"
QT_MOC_LITERAL(12, 224, 29), // "on_yearcomboBox_textActivated"
QT_MOC_LITERAL(13, 254, 4), // "arg1"
QT_MOC_LITERAL(14, 259, 30), // "on_monthcomboBox_textActivated"
QT_MOC_LITERAL(15, 290, 28) // "on_dayComboBox_textActivated"

    },
    "Doctor\0on_patientNewpushButton_clicked\0"
    "\0on_patientGenderMaleradioButton_clicked\0"
    "on_patientGenderFemaleradioButton_clicked\0"
    "on_patientGenderNoneradioButton_clicked\0"
    "receiveData\0sendData\0goOnSend\0numBytes\0"
    "sendFile\0serverConnect\0"
    "on_yearcomboBox_textActivated\0arg1\0"
    "on_monthcomboBox_textActivated\0"
    "on_dayComboBox_textActivated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Doctor[] = {

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
       8,    1,   80,    2, 0x08 /* Private */,
      10,    0,   83,    2, 0x08 /* Private */,
      11,    0,   84,    2, 0x08 /* Private */,
      12,    1,   85,    2, 0x08 /* Private */,
      14,    1,   88,    2, 0x08 /* Private */,
      15,    1,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   13,

       0        // eod
};

void Doctor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Doctor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_patientNewpushButton_clicked(); break;
        case 1: _t->on_patientGenderMaleradioButton_clicked(); break;
        case 2: _t->on_patientGenderFemaleradioButton_clicked(); break;
        case 3: _t->on_patientGenderNoneradioButton_clicked(); break;
        case 4: _t->receiveData(); break;
        case 5: _t->sendData(); break;
        case 6: _t->goOnSend((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 7: _t->sendFile(); break;
        case 8: _t->serverConnect(); break;
        case 9: _t->on_yearcomboBox_textActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_monthcomboBox_textActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_dayComboBox_textActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Doctor::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Doctor.data,
    qt_meta_data_Doctor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Doctor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Doctor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Doctor.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Doctor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
