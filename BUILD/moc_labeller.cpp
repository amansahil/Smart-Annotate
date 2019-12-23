/****************************************************************************
** Meta object code from reading C++ file 'labeller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SRC/labeller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'labeller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Labeller_t {
    QByteArrayData data[10];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Labeller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Labeller_t qt_meta_stringdata_Labeller = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Labeller"
QT_MOC_LITERAL(1, 9, 12), // "setImageList"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "setClassList"
QT_MOC_LITERAL(4, 36, 11), // "setImageDir"
QT_MOC_LITERAL(5, 48, 12), // "setClassFile"
QT_MOC_LITERAL(6, 61, 17), // "setAnnotationFile"
QT_MOC_LITERAL(7, 79, 28), // "on_imageBrowseButton_clicked"
QT_MOC_LITERAL(8, 108, 28), // "on_classBrowseButton_clicked"
QT_MOC_LITERAL(9, 137, 33) // "on_annotationBrowseButton_cli..."

    },
    "Labeller\0setImageList\0\0setClassList\0"
    "setImageDir\0setClassFile\0setAnnotationFile\0"
    "on_imageBrowseButton_clicked\0"
    "on_classBrowseButton_clicked\0"
    "on_annotationBrowseButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Labeller[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Labeller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Labeller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setImageList(); break;
        case 1: _t->setClassList(); break;
        case 2: _t->setImageDir(); break;
        case 3: _t->setClassFile(); break;
        case 4: _t->setAnnotationFile(); break;
        case 5: _t->on_imageBrowseButton_clicked(); break;
        case 6: _t->on_classBrowseButton_clicked(); break;
        case 7: _t->on_annotationBrowseButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Labeller::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Labeller.data,
    qt_meta_data_Labeller,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Labeller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Labeller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Labeller.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Labeller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
