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
    QByteArrayData data[45];
    char stringdata0[1041];
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
QT_MOC_LITERAL(3, 23, 20), // "setImageListToResult"
QT_MOC_LITERAL(4, 44, 12), // "setClassList"
QT_MOC_LITERAL(5, 57, 11), // "setImageDir"
QT_MOC_LITERAL(6, 69, 12), // "setClassFile"
QT_MOC_LITERAL(7, 82, 17), // "setAnnotationFile"
QT_MOC_LITERAL(8, 100, 20), // "setSelectedImageFile"
QT_MOC_LITERAL(9, 121, 18), // "setCursorTypeLabel"
QT_MOC_LITERAL(10, 140, 17), // "setShapeTypeLabel"
QT_MOC_LITERAL(11, 158, 22), // "clearClassItemLineEdit"
QT_MOC_LITERAL(12, 181, 16), // "setCursorToCross"
QT_MOC_LITERAL(13, 198, 16), // "setCursorToArrow"
QT_MOC_LITERAL(14, 215, 10), // "doAutoSave"
QT_MOC_LITERAL(15, 226, 28), // "on_imageBrowseButton_clicked"
QT_MOC_LITERAL(16, 255, 28), // "on_classBrowseButton_clicked"
QT_MOC_LITERAL(17, 284, 33), // "on_annotationBrowseButton_cli..."
QT_MOC_LITERAL(18, 318, 28), // "on_addNameItemButton_clicked"
QT_MOC_LITERAL(19, 347, 32), // "on_deleteClassItemButton_clicked"
QT_MOC_LITERAL(20, 380, 29), // "on_sortClassAscButton_clicked"
QT_MOC_LITERAL(21, 410, 29), // "on_sortClassDscButton_clicked"
QT_MOC_LITERAL(22, 440, 20), // "on_imageList_clicked"
QT_MOC_LITERAL(23, 461, 24), // "on_sortImagesAsc_clicked"
QT_MOC_LITERAL(24, 486, 24), // "on_sortImagesDsc_clicked"
QT_MOC_LITERAL(25, 511, 28), // "on_sortImagesdateAsc_clicked"
QT_MOC_LITERAL(26, 540, 28), // "on_sortImagesDateDsc_clicked"
QT_MOC_LITERAL(27, 569, 24), // "on_restoreImages_clicked"
QT_MOC_LITERAL(28, 594, 23), // "on_searchImages_clicked"
QT_MOC_LITERAL(29, 618, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(30, 640, 30), // "on_actionMark_Object_triggered"
QT_MOC_LITERAL(31, 671, 27), // "on_actionAdd_Text_triggered"
QT_MOC_LITERAL(32, 699, 25), // "on_actionSelect_triggered"
QT_MOC_LITERAL(33, 725, 25), // "on_actionDelete_triggered"
QT_MOC_LITERAL(34, 751, 23), // "on_actionCopy_triggered"
QT_MOC_LITERAL(35, 775, 24), // "on_actionPaste_triggered"
QT_MOC_LITERAL(36, 800, 22), // "on_clearButton_clicked"
QT_MOC_LITERAL(37, 823, 20), // "on_classList_clicked"
QT_MOC_LITERAL(38, 844, 28), // "on_actionRectangle_triggered"
QT_MOC_LITERAL(39, 873, 33), // "on_actionSmart_annotate_trigg..."
QT_MOC_LITERAL(40, 907, 30), // "on_actionSmart_Click_triggered"
QT_MOC_LITERAL(41, 938, 24), // "on_connectButton_clicked"
QT_MOC_LITERAL(42, 963, 22), // "on_clearPoints_clicked"
QT_MOC_LITERAL(43, 986, 29), // "on_actionHow_to_use_triggered"
QT_MOC_LITERAL(44, 1016, 24) // "on_actionAbout_triggered"

    },
    "Labeller\0setImageList\0\0setImageListToResult\0"
    "setClassList\0setImageDir\0setClassFile\0"
    "setAnnotationFile\0setSelectedImageFile\0"
    "setCursorTypeLabel\0setShapeTypeLabel\0"
    "clearClassItemLineEdit\0setCursorToCross\0"
    "setCursorToArrow\0doAutoSave\0"
    "on_imageBrowseButton_clicked\0"
    "on_classBrowseButton_clicked\0"
    "on_annotationBrowseButton_clicked\0"
    "on_addNameItemButton_clicked\0"
    "on_deleteClassItemButton_clicked\0"
    "on_sortClassAscButton_clicked\0"
    "on_sortClassDscButton_clicked\0"
    "on_imageList_clicked\0on_sortImagesAsc_clicked\0"
    "on_sortImagesDsc_clicked\0"
    "on_sortImagesdateAsc_clicked\0"
    "on_sortImagesDateDsc_clicked\0"
    "on_restoreImages_clicked\0"
    "on_searchImages_clicked\0on_saveButton_clicked\0"
    "on_actionMark_Object_triggered\0"
    "on_actionAdd_Text_triggered\0"
    "on_actionSelect_triggered\0"
    "on_actionDelete_triggered\0"
    "on_actionCopy_triggered\0"
    "on_actionPaste_triggered\0"
    "on_clearButton_clicked\0on_classList_clicked\0"
    "on_actionRectangle_triggered\0"
    "on_actionSmart_annotate_triggered\0"
    "on_actionSmart_Click_triggered\0"
    "on_connectButton_clicked\0"
    "on_clearPoints_clicked\0"
    "on_actionHow_to_use_triggered\0"
    "on_actionAbout_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Labeller[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      43,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  229,    2, 0x08 /* Private */,
       3,    0,  230,    2, 0x08 /* Private */,
       4,    0,  231,    2, 0x08 /* Private */,
       5,    0,  232,    2, 0x08 /* Private */,
       6,    0,  233,    2, 0x08 /* Private */,
       7,    0,  234,    2, 0x08 /* Private */,
       8,    0,  235,    2, 0x08 /* Private */,
       9,    0,  236,    2, 0x08 /* Private */,
      10,    0,  237,    2, 0x08 /* Private */,
      11,    0,  238,    2, 0x08 /* Private */,
      12,    0,  239,    2, 0x08 /* Private */,
      13,    0,  240,    2, 0x08 /* Private */,
      14,    0,  241,    2, 0x0a /* Public */,
      15,    0,  242,    2, 0x08 /* Private */,
      16,    0,  243,    2, 0x08 /* Private */,
      17,    0,  244,    2, 0x08 /* Private */,
      18,    0,  245,    2, 0x08 /* Private */,
      19,    0,  246,    2, 0x08 /* Private */,
      20,    0,  247,    2, 0x08 /* Private */,
      21,    0,  248,    2, 0x08 /* Private */,
      22,    0,  249,    2, 0x08 /* Private */,
      23,    0,  250,    2, 0x08 /* Private */,
      24,    0,  251,    2, 0x08 /* Private */,
      25,    0,  252,    2, 0x08 /* Private */,
      26,    0,  253,    2, 0x08 /* Private */,
      27,    0,  254,    2, 0x08 /* Private */,
      28,    0,  255,    2, 0x08 /* Private */,
      29,    0,  256,    2, 0x08 /* Private */,
      30,    0,  257,    2, 0x08 /* Private */,
      31,    0,  258,    2, 0x08 /* Private */,
      32,    0,  259,    2, 0x08 /* Private */,
      33,    0,  260,    2, 0x08 /* Private */,
      34,    0,  261,    2, 0x08 /* Private */,
      35,    0,  262,    2, 0x08 /* Private */,
      36,    0,  263,    2, 0x08 /* Private */,
      37,    0,  264,    2, 0x08 /* Private */,
      38,    0,  265,    2, 0x08 /* Private */,
      39,    0,  266,    2, 0x08 /* Private */,
      40,    0,  267,    2, 0x08 /* Private */,
      41,    0,  268,    2, 0x08 /* Private */,
      42,    0,  269,    2, 0x08 /* Private */,
      43,    0,  270,    2, 0x08 /* Private */,
      44,    0,  271,    2, 0x08 /* Private */,

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

       0        // eod
};

void Labeller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Labeller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setImageList(); break;
        case 1: _t->setImageListToResult(); break;
        case 2: _t->setClassList(); break;
        case 3: _t->setImageDir(); break;
        case 4: _t->setClassFile(); break;
        case 5: _t->setAnnotationFile(); break;
        case 6: _t->setSelectedImageFile(); break;
        case 7: _t->setCursorTypeLabel(); break;
        case 8: _t->setShapeTypeLabel(); break;
        case 9: _t->clearClassItemLineEdit(); break;
        case 10: _t->setCursorToCross(); break;
        case 11: _t->setCursorToArrow(); break;
        case 12: _t->doAutoSave(); break;
        case 13: _t->on_imageBrowseButton_clicked(); break;
        case 14: _t->on_classBrowseButton_clicked(); break;
        case 15: _t->on_annotationBrowseButton_clicked(); break;
        case 16: _t->on_addNameItemButton_clicked(); break;
        case 17: _t->on_deleteClassItemButton_clicked(); break;
        case 18: _t->on_sortClassAscButton_clicked(); break;
        case 19: _t->on_sortClassDscButton_clicked(); break;
        case 20: _t->on_imageList_clicked(); break;
        case 21: _t->on_sortImagesAsc_clicked(); break;
        case 22: _t->on_sortImagesDsc_clicked(); break;
        case 23: _t->on_sortImagesdateAsc_clicked(); break;
        case 24: _t->on_sortImagesDateDsc_clicked(); break;
        case 25: _t->on_restoreImages_clicked(); break;
        case 26: _t->on_searchImages_clicked(); break;
        case 27: _t->on_saveButton_clicked(); break;
        case 28: _t->on_actionMark_Object_triggered(); break;
        case 29: _t->on_actionAdd_Text_triggered(); break;
        case 30: _t->on_actionSelect_triggered(); break;
        case 31: _t->on_actionDelete_triggered(); break;
        case 32: _t->on_actionCopy_triggered(); break;
        case 33: _t->on_actionPaste_triggered(); break;
        case 34: _t->on_clearButton_clicked(); break;
        case 35: _t->on_classList_clicked(); break;
        case 36: _t->on_actionRectangle_triggered(); break;
        case 37: _t->on_actionSmart_annotate_triggered(); break;
        case 38: _t->on_actionSmart_Click_triggered(); break;
        case 39: _t->on_connectButton_clicked(); break;
        case 40: _t->on_clearPoints_clicked(); break;
        case 41: _t->on_actionHow_to_use_triggered(); break;
        case 42: _t->on_actionAbout_triggered(); break;
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
        if (_id < 43)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 43;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 43)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 43;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
