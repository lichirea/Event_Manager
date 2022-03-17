/****************************************************************************
** Meta object code from reading C++ file 'Interface.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Interface.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdminWidget_t {
    const uint offsetsAndSize[36];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_AdminWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_AdminWidget_t qt_meta_stringdata_AdminWidget = {
    {
QT_MOC_LITERAL(0, 11), // "AdminWidget"
QT_MOC_LITERAL(12, 19), // "EventsUpdatedSignal"
QT_MOC_LITERAL(32, 0), // ""
QT_MOC_LITERAL(33, 14), // "addEventSignal"
QT_MOC_LITERAL(48, 11), // "std::string"
QT_MOC_LITERAL(60, 5), // "title"
QT_MOC_LITERAL(66, 11), // "description"
QT_MOC_LITERAL(78, 4), // "time"
QT_MOC_LITERAL(83, 9), // "attendees"
QT_MOC_LITERAL(93, 4), // "link"
QT_MOC_LITERAL(98, 17), // "updateEventSignal"
QT_MOC_LITERAL(116, 17), // "deleteEventSignal"
QT_MOC_LITERAL(134, 21), // "addEventButtonHandler"
QT_MOC_LITERAL(156, 8), // "addEvent"
QT_MOC_LITERAL(165, 24), // "updateEventButtonHandler"
QT_MOC_LITERAL(190, 11), // "updateEvent"
QT_MOC_LITERAL(202, 24), // "deleteEventButtonHandler"
QT_MOC_LITERAL(227, 11) // "deleteEvent"

    },
    "AdminWidget\0EventsUpdatedSignal\0\0"
    "addEventSignal\0std::string\0title\0"
    "description\0time\0attendees\0link\0"
    "updateEventSignal\0deleteEventSignal\0"
    "addEventButtonHandler\0addEvent\0"
    "updateEventButtonHandler\0updateEvent\0"
    "deleteEventButtonHandler\0deleteEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminWidget[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x06,    0 /* Public */,
       3,    5,   75,    2, 0x06,    1 /* Public */,
      10,    5,   86,    2, 0x06,    7 /* Public */,
      11,    2,   97,    2, 0x06,   13 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    0,  102,    2, 0x0a,   16 /* Public */,
      13,    5,  103,    2, 0x0a,   17 /* Public */,
      14,    0,  114,    2, 0x0a,   23 /* Public */,
      15,    5,  115,    2, 0x0a,   24 /* Public */,
      16,    0,  126,    2, 0x0a,   30 /* Public */,
      17,    2,  127,    2, 0x0a,   31 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4, QMetaType::Int, QMetaType::Int, 0x80000000 | 4,    5,    6,    7,    8,    9,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4, QMetaType::Int, QMetaType::Int, 0x80000000 | 4,    5,    6,    7,    8,    9,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,    5,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4, QMetaType::Int, QMetaType::Int, 0x80000000 | 4,    5,    6,    7,    8,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4, QMetaType::Int, QMetaType::Int, 0x80000000 | 4,    5,    6,    7,    8,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,    5,    7,

       0        // eod
};

void AdminWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdminWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->EventsUpdatedSignal(); break;
        case 1: _t->addEventSignal((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< std::string(*)>(_a[5]))); break;
        case 2: _t->updateEventSignal((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< std::string(*)>(_a[5]))); break;
        case 3: _t->deleteEventSignal((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->addEventButtonHandler(); break;
        case 5: _t->addEvent((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< std::string(*)>(_a[5]))); break;
        case 6: _t->updateEventButtonHandler(); break;
        case 7: _t->updateEvent((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< std::string(*)>(_a[5]))); break;
        case 8: _t->deleteEventButtonHandler(); break;
        case 9: _t->deleteEvent((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AdminWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdminWidget::EventsUpdatedSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AdminWidget::*)(std::string , std::string , int , int , std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdminWidget::addEventSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AdminWidget::*)(std::string , std::string , int , int , std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdminWidget::updateEventSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AdminWidget::*)(std::string , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdminWidget::deleteEventSignal)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject AdminWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_AdminWidget.offsetsAndSize,
    qt_meta_data_AdminWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AdminWidget_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *AdminWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdminWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AdminWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void AdminWidget::EventsUpdatedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AdminWidget::addEventSignal(std::string _t1, std::string _t2, int _t3, int _t4, std::string _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AdminWidget::updateEventSignal(std::string _t1, std::string _t2, int _t3, int _t4, std::string _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AdminWidget::deleteEventSignal(std::string _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
struct qt_meta_stringdata_UserWidget_t {
    const uint offsetsAndSize[2];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_UserWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_UserWidget_t qt_meta_stringdata_UserWidget = {
    {
QT_MOC_LITERAL(0, 10) // "UserWidget"

    },
    "UserWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserWidget[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void UserWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject UserWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_UserWidget.offsetsAndSize,
    qt_meta_data_UserWidget,
    qt_static_metacall,
    nullptr,
    nullptr,
    nullptr
} };


const QMetaObject *UserWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int UserWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_LoginWidget_t {
    const uint offsetsAndSize[20];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_LoginWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_LoginWidget_t qt_meta_stringdata_LoginWidget = {
    {
QT_MOC_LITERAL(0, 11), // "LoginWidget"
QT_MOC_LITERAL(12, 16), // "startAdminSignal"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 8), // "QString&"
QT_MOC_LITERAL(39, 8), // "password"
QT_MOC_LITERAL(48, 15), // "startUserSignal"
QT_MOC_LITERAL(64, 11), // "std::string"
QT_MOC_LITERAL(76, 8), // "filetype"
QT_MOC_LITERAL(85, 18), // "adminButtonHandler"
QT_MOC_LITERAL(104, 17) // "userButtonHandler"

    },
    "LoginWidget\0startAdminSignal\0\0QString&\0"
    "password\0startUserSignal\0std::string\0"
    "filetype\0adminButtonHandler\0"
    "userButtonHandler"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoginWidget[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    0 /* Public */,
       5,    1,   41,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   44,    2, 0x08,    4 /* Private */,
       9,    0,   45,    2, 0x08,    5 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LoginWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LoginWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->startAdminSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->startUserSignal((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 2: _t->adminButtonHandler(); break;
        case 3: _t->userButtonHandler(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LoginWidget::*)(QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginWidget::startAdminSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LoginWidget::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginWidget::startUserSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject LoginWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_LoginWidget.offsetsAndSize,
    qt_meta_data_LoginWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_LoginWidget_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *LoginWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LoginWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LoginWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void LoginWidget::startAdminSignal(QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LoginWidget::startUserSignal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_Interface_t {
    const uint offsetsAndSize[16];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Interface_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Interface_t qt_meta_stringdata_Interface = {
    {
QT_MOC_LITERAL(0, 9), // "Interface"
QT_MOC_LITERAL(10, 10), // "startAdmin"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 8), // "QString&"
QT_MOC_LITERAL(31, 8), // "password"
QT_MOC_LITERAL(40, 9), // "startUser"
QT_MOC_LITERAL(50, 11), // "std::string"
QT_MOC_LITERAL(62, 8) // "filetype"

    },
    "Interface\0startAdmin\0\0QString&\0password\0"
    "startUser\0std::string\0filetype"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Interface[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x0a,    0 /* Public */,
       5,    1,   29,    2, 0x0a,    2 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void Interface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Interface *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->startAdmin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->startUser((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Interface::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Interface.offsetsAndSize,
    qt_meta_data_Interface,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Interface_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>


>,
    nullptr
} };


const QMetaObject *Interface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Interface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Interface.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Interface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
