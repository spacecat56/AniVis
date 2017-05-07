/****************************************************************************
** Meta object code from reading C++ file 'wlsAnivisWatcher.h'
**
** Created: Sun May 7 11:16:18 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wlsAnivisWatcher.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wlsAnivisWatcher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_wlsAnivisWatcher[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,
      35,   17,   17,   17, 0x0a,
      56,   51,   17,   17, 0x0a,
      78,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_wlsAnivisWatcher[] = {
    "wlsAnivisWatcher\0\0onSceneCleared()\0"
    "onSceneLoaded()\0time\0onTimeChanged(DzTime)\0"
    "onAnivisValueChanged()\0"
};

void wlsAnivisWatcher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        wlsAnivisWatcher *_t = static_cast<wlsAnivisWatcher *>(_o);
        switch (_id) {
        case 0: _t->onSceneCleared(); break;
        case 1: _t->onSceneLoaded(); break;
        case 2: _t->onTimeChanged((*reinterpret_cast< DzTime(*)>(_a[1]))); break;
        case 3: _t->onAnivisValueChanged(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData wlsAnivisWatcher::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject wlsAnivisWatcher::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_wlsAnivisWatcher,
      qt_meta_data_wlsAnivisWatcher, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &wlsAnivisWatcher::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *wlsAnivisWatcher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *wlsAnivisWatcher::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_wlsAnivisWatcher))
        return static_cast<void*>(const_cast< wlsAnivisWatcher*>(this));
    return QObject::qt_metacast(_clname);
}

int wlsAnivisWatcher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
