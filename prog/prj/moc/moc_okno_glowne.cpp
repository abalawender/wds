/****************************************************************************
** Meta object code from reading C++ file 'okno_glowne.hh'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/okno_glowne.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'okno_glowne.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OknoGlowne[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      32,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      44,   11,   11,   11, 0x0a,
      64,   11,   11,   11, 0x0a,
      82,   11,   11,   11, 0x0a,
     106,   11,   11,   11, 0x0a,
     131,   11,   11,   11, 0x0a,
     155,   11,   11,   11, 0x0a,
     166,   11,   11,   11, 0x0a,
     176,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_OknoGlowne[] = {
    "OknoGlowne\0\0ZglosNapis(QString)\0"
    "ZglosStop()\0GdyOdpowiedniCzas()\0"
    "GdyNapis(QString)\0on_playButton_clicked()\0"
    "on_pauseButton_clicked()\0"
    "on_stopButton_clicked()\0GdyPauza()\0"
    "GdyPlay()\0GdyStop()\0"
};

void OknoGlowne::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OknoGlowne *_t = static_cast<OknoGlowne *>(_o);
        switch (_id) {
        case 0: _t->ZglosNapis((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->ZglosStop(); break;
        case 2: _t->GdyOdpowiedniCzas(); break;
        case 3: _t->GdyNapis((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_playButton_clicked(); break;
        case 5: _t->on_pauseButton_clicked(); break;
        case 6: _t->on_stopButton_clicked(); break;
        case 7: _t->GdyPauza(); break;
        case 8: _t->GdyPlay(); break;
        case 9: _t->GdyStop(); break;
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void OknoGlowne::ZglosNapis(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OknoGlowne::ZglosStop()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
