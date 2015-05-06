/****************************************************************************
** Meta object code from reading C++ file 'ciecz.hh'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/ciecz.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ciecz.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Zbiornik[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Zbiornik[] = {
    "Zbiornik\0\0ZglosNapis(QString)\0"
    "GdyOdpowiedniCzas()\0"
};

void Zbiornik::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Zbiornik *_t = static_cast<Zbiornik *>(_o);
        switch (_id) {
        case 0: _t->ZglosNapis((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->GdyOdpowiedniCzas(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Zbiornik::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Zbiornik::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Zbiornik,
      qt_meta_data_Zbiornik, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Zbiornik::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Zbiornik::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Zbiornik::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Zbiornik))
        return static_cast<void*>(const_cast< Zbiornik*>(this));
    return QWidget::qt_metacast(_clname);
}

int Zbiornik::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Zbiornik::ZglosNapis(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_OknoGlowne[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_OknoGlowne[] = {
    "OknoGlowne\0\0GdyNapis(QString)\0"
};

void OknoGlowne::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OknoGlowne *_t = static_cast<OknoGlowne *>(_o);
        switch (_id) {
        case 0: _t->GdyNapis((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData OknoGlowne::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OknoGlowne::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_OknoGlowne,
      qt_meta_data_OknoGlowne, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OknoGlowne::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OknoGlowne::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OknoGlowne::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OknoGlowne))
        return static_cast<void*>(const_cast< OknoGlowne*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int OknoGlowne::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
