/****************************************************************************
** Meta object code from reading C++ file 'TlvParserWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "TlvParserWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TlvParserWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TlvParserWindow_t {
    const uint offsetsAndSize[20];
    char stringdata0[103];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TlvParserWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TlvParserWindow_t qt_meta_stringdata_TlvParserWindow = {
    {
QT_MOC_LITERAL(0, 15), // "TlvParserWindow"
QT_MOC_LITERAL(16, 5), // "parse"
QT_MOC_LITERAL(22, 0), // ""
QT_MOC_LITERAL(23, 17), // "enableParseButton"
QT_MOC_LITERAL(41, 4), // "text"
QT_MOC_LITERAL(46, 10), // "tagClicked"
QT_MOC_LITERAL(57, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(74, 4), // "item"
QT_MOC_LITERAL(79, 6), // "column"
QT_MOC_LITERAL(86, 16) // "tagDoubleClicked"

    },
    "TlvParserWindow\0parse\0\0enableParseButton\0"
    "text\0tagClicked\0QTreeWidgetItem*\0item\0"
    "column\0tagDoubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TlvParserWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x08,    1 /* Private */,
       3,    1,   39,    2, 0x08,    2 /* Private */,
       5,    2,   42,    2, 0x08,    4 /* Private */,
       9,    2,   47,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int,    7,    8,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int,    7,    8,

       0        // eod
};

void TlvParserWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TlvParserWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->parse(); break;
        case 1: _t->enableParseButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->tagClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->tagDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject TlvParserWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_TlvParserWindow.offsetsAndSize,
    qt_meta_data_TlvParserWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TlvParserWindow_t
, QtPrivate::TypeAndForceComplete<TlvParserWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *TlvParserWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TlvParserWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TlvParserWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TlvParserWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
