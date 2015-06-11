/****************************************************************************
** Meta object code from reading C++ file 'zbiornik.hh'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/zbiornik.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zbiornik.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Zbiornik[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      30,    9,    9,    9, 0x05,
      57,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      84,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Zbiornik[] = {
    "Zbiornik\0\0ZglosNapis(QString)\0"
    "ZglosLiczbeCzasteczek(int)\0"
    "ZglosCzasSymulacji(double)\0"
    "GdyOdpowiedniCzas()\0"
};

void Zbiornik::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Zbiornik *_t = static_cast<Zbiornik *>(_o);
        switch (_id) {
        case 0: _t->ZglosNapis((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->ZglosLiczbeCzasteczek((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->ZglosCzasSymulacji((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 3: _t->GdyOdpowiedniCzas(); break;
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Zbiornik::ZglosNapis(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Zbiornik::ZglosLiczbeCzasteczek(const int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Zbiornik::ZglosCzasSymulacji(const double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
