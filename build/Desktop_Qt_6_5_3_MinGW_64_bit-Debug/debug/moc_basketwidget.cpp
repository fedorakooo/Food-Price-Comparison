/****************************************************************************
** Meta object code from reading C++ file 'basketwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/basketwidget.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'basketwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
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
struct qt_meta_stringdata_CLASSBasketWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSBasketWidgetENDCLASS = QtMocHelpers::stringData(
    "BasketWidget",
    "addProductBasket",
    "",
    "Product*",
    "product",
    "deleteProduct",
    "deleteBasket",
    "updateInfo"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSBasketWidgetENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[13];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[8];
    char stringdata5[14];
    char stringdata6[13];
    char stringdata7[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSBasketWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSBasketWidgetENDCLASS_t qt_meta_stringdata_CLASSBasketWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "BasketWidget"
        QT_MOC_LITERAL(13, 16),  // "addProductBasket"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 8),  // "Product*"
        QT_MOC_LITERAL(40, 7),  // "product"
        QT_MOC_LITERAL(48, 13),  // "deleteProduct"
        QT_MOC_LITERAL(62, 12),  // "deleteBasket"
        QT_MOC_LITERAL(75, 10)   // "updateInfo"
    },
    "BasketWidget",
    "addProductBasket",
    "",
    "Product*",
    "product",
    "deleteProduct",
    "deleteBasket",
    "updateInfo"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSBasketWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x0a,    1 /* Public */,
       5,    0,   41,    2, 0x08,    3 /* Private */,
       6,    0,   42,    2, 0x08,    4 /* Private */,
       7,    0,   43,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject BasketWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSBasketWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSBasketWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSBasketWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<BasketWidget, std::true_type>,
        // method 'addProductBasket'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Product *, std::false_type>,
        // method 'deleteProduct'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteBasket'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void BasketWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BasketWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addProductBasket((*reinterpret_cast< std::add_pointer_t<Product*>>(_a[1]))); break;
        case 1: _t->deleteProduct(); break;
        case 2: _t->deleteBasket(); break;
        case 3: _t->updateInfo(); break;
        default: ;
        }
    }
}

const QMetaObject *BasketWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BasketWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSBasketWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BasketWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
