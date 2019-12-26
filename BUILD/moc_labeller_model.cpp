/****************************************************************************
** Meta object code from reading C++ file 'labeller_model.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SRC/labeller_model.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'labeller_model.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LabellerModel_t {
    QByteArrayData data[10];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LabellerModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LabellerModel_t qt_meta_stringdata_LabellerModel = {
    {
QT_MOC_LITERAL(0, 0, 13), // "LabellerModel"
QT_MOC_LITERAL(1, 14, 17), // "imageFilesChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 17), // "classNamesChanged"
QT_MOC_LITERAL(4, 51, 21), // "annotationFileChanged"
QT_MOC_LITERAL(5, 73, 15), // "imageDirChanged"
QT_MOC_LITERAL(6, 89, 16), // "classFileChanged"
QT_MOC_LITERAL(7, 106, 22), // "classListChangedSorted"
QT_MOC_LITERAL(8, 129, 24), // "selectedImageFileChanged"
QT_MOC_LITERAL(9, 154, 22) // "clearClassItemLineEdit"

    },
    "LabellerModel\0imageFilesChanged\0\0"
    "classNamesChanged\0annotationFileChanged\0"
    "imageDirChanged\0classFileChanged\0"
    "classListChangedSorted\0selectedImageFileChanged\0"
    "clearClassItemLineEdit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LabellerModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,
       6,    0,   58,    2, 0x06 /* Public */,
       7,    0,   59,    2, 0x06 /* Public */,
       8,    0,   60,    2, 0x06 /* Public */,
       9,    0,   61,    2, 0x06 /* Public */,

 // signals: parameters
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

void LabellerModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LabellerModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imageFilesChanged(); break;
        case 1: _t->classNamesChanged(); break;
        case 2: _t->annotationFileChanged(); break;
        case 3: _t->imageDirChanged(); break;
        case 4: _t->classFileChanged(); break;
        case 5: _t->classListChangedSorted(); break;
        case 6: _t->selectedImageFileChanged(); break;
        case 7: _t->clearClassItemLineEdit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LabellerModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabellerModel::imageFilesChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LabellerModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabellerModel::classNamesChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LabellerModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabellerModel::annotationFileChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (LabellerModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabellerModel::imageDirChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (LabellerModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabellerModel::classFileChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (LabellerModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabellerModel::classListChangedSorted)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (LabellerModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabellerModel::selectedImageFileChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (LabellerModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabellerModel::clearClassItemLineEdit)) {
                *result = 7;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject LabellerModel::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_LabellerModel.data,
    qt_meta_data_LabellerModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LabellerModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LabellerModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LabellerModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LabellerModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void LabellerModel::imageFilesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LabellerModel::classNamesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void LabellerModel::annotationFileChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void LabellerModel::imageDirChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void LabellerModel::classFileChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void LabellerModel::classListChangedSorted()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void LabellerModel::selectedImageFileChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void LabellerModel::clearClassItemLineEdit()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
