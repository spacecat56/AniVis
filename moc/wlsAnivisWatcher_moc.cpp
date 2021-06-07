/****************************************************************************
** Meta object code from reading C++ file 'wlsAnivisWatcher.h'
**
** Created: Mon Jun 7 15:14:02 2021
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
static const uint qt_meta_data_wls_anivis_watcher[] = {

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
      20,   19,   19,   19, 0x0a,
      39,   19,   19,   19, 0x0a,
      62,   57,   19,   19, 0x0a,
      86,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_wls_anivis_watcher[] = {
    "wls_anivis_watcher\0\0on_scene_cleared()\0"
    "on_scene_loaded()\0time\0on_time_changed(DzTime)\0"
    "on_anivis_value_changed()\0"
};

void wls_anivis_watcher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        wls_anivis_watcher *_t = static_cast<wls_anivis_watcher *>(_o);
        switch (_id) {
        case 0: _t->on_scene_cleared(); break;
        case 1: _t->on_scene_loaded(); break;
        case 2: _t->on_time_changed((*reinterpret_cast< DzTime(*)>(_a[1]))); break;
        case 3: _t->on_anivis_value_changed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData wls_anivis_watcher::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject wls_anivis_watcher::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_wls_anivis_watcher,
      qt_meta_data_wls_anivis_watcher, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &wls_anivis_watcher::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *wls_anivis_watcher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *wls_anivis_watcher::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_wls_anivis_watcher))
        return static_cast<void*>(const_cast< wls_anivis_watcher*>(this));
    return QObject::qt_metacast(_clname);
}

int wls_anivis_watcher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
