/****************************************************************************
** Meta object code from reading C++ file 'gardnerwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../gardnerwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gardnerwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSGardnerWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSGardnerWindowENDCLASS = QtMocHelpers::stringData(
    "GardnerWindow",
    "logout",
    "",
    "addFlower",
    "addNote",
    "saveCurrFlower",
    "saveCurrNote",
    "saveGurdnerData"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSGardnerWindowENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[14];
    char stringdata1[7];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[8];
    char stringdata5[15];
    char stringdata6[13];
    char stringdata7[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSGardnerWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSGardnerWindowENDCLASS_t qt_meta_stringdata_CLASSGardnerWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "GardnerWindow"
        QT_MOC_LITERAL(14, 6),  // "logout"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 9),  // "addFlower"
        QT_MOC_LITERAL(32, 7),  // "addNote"
        QT_MOC_LITERAL(40, 14),  // "saveCurrFlower"
        QT_MOC_LITERAL(55, 12),  // "saveCurrNote"
        QT_MOC_LITERAL(68, 15)   // "saveGurdnerData"
    },
    "GardnerWindow",
    "logout",
    "",
    "addFlower",
    "addNote",
    "saveCurrFlower",
    "saveCurrNote",
    "saveGurdnerData"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGardnerWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject GardnerWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSGardnerWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGardnerWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGardnerWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GardnerWindow, std::true_type>,
        // method 'logout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addFlower'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addNote'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveCurrFlower'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveCurrNote'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveGurdnerData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void GardnerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GardnerWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->logout(); break;
        case 1: _t->addFlower(); break;
        case 2: _t->addNote(); break;
        case 3: _t->saveCurrFlower(); break;
        case 4: _t->saveCurrNote(); break;
        case 5: _t->saveGurdnerData(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *GardnerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GardnerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGardnerWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GardnerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
