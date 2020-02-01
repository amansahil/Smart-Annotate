/****************************************************************************
** Meta object code from reading C++ file 'image_editor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SRC/image_editor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'image_editor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImageEditor_t {
    QByteArrayData data[10];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageEditor_t qt_meta_stringdata_ImageEditor = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ImageEditor"
QT_MOC_LITERAL(1, 12, 17), // "cursorTypeChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 22), // "annotationShapeChanged"
QT_MOC_LITERAL(4, 54, 18), // "deleteSelectedItem"
QT_MOC_LITERAL(5, 73, 16), // "copySelectedItem"
QT_MOC_LITERAL(6, 90, 17), // "pasteSelectedItem"
QT_MOC_LITERAL(7, 108, 24), // "pasteSelectedItemInPlace"
QT_MOC_LITERAL(8, 133, 19), // "connectClickElipses"
QT_MOC_LITERAL(9, 153, 18) // "deleteClickElipses"

    },
    "ImageEditor\0cursorTypeChanged\0\0"
    "annotationShapeChanged\0deleteSelectedItem\0"
    "copySelectedItem\0pasteSelectedItem\0"
    "pasteSelectedItemInPlace\0connectClickElipses\0"
    "deleteClickElipses"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageEditor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ImageEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ImageEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cursorTypeChanged(); break;
        case 1: _t->annotationShapeChanged(); break;
        case 2: _t->deleteSelectedItem(); break;
        case 3: _t->copySelectedItem(); break;
        case 4: _t->pasteSelectedItem(); break;
        case 5: _t->pasteSelectedItemInPlace(); break;
        case 6: _t->connectClickElipses(); break;
        case 7: _t->deleteClickElipses(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ImageEditor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageEditor::cursorTypeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ImageEditor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageEditor::annotationShapeChanged)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ImageEditor::staticMetaObject = { {
    &QGraphicsScene::staticMetaObject,
    qt_meta_stringdata_ImageEditor.data,
    qt_meta_data_ImageEditor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ImageEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImageEditor.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int ImageEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
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
void ImageEditor::cursorTypeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ImageEditor::annotationShapeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
