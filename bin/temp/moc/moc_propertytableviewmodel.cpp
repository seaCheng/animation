/****************************************************************************
** Meta object code from reading C++ file 'propertytableviewmodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../qt-mvvm/source/libmvvm_viewmodel/mvvm/viewmodel/propertytableviewmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'propertytableviewmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModelView__PropertyTableViewModel_t {
    uint offsetsAndSizes[2];
    char stringdata0[34];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ModelView__PropertyTableViewModel_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_ModelView__PropertyTableViewModel_t qt_meta_stringdata_ModelView__PropertyTableViewModel = {
    {
        QT_MOC_LITERAL(0, 33)   // "ModelView::PropertyTableViewM..."
    },
    "ModelView::PropertyTableViewModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModelView__PropertyTableViewModel[] = {

 // content:
      10,       // revision
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

void ModelView::PropertyTableViewModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject ModelView::PropertyTableViewModel::staticMetaObject = { {
    QMetaObject::SuperData::link<ViewModel::staticMetaObject>(),
    qt_meta_stringdata_ModelView__PropertyTableViewModel.offsetsAndSizes,
    qt_meta_data_ModelView__PropertyTableViewModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ModelView__PropertyTableViewModel_t
, QtPrivate::TypeAndForceComplete<PropertyTableViewModel, std::true_type>



>,
    nullptr
} };


const QMetaObject *ModelView::PropertyTableViewModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModelView::PropertyTableViewModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModelView__PropertyTableViewModel.stringdata0))
        return static_cast<void*>(this);
    return ViewModel::qt_metacast(_clname);
}

int ModelView::PropertyTableViewModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ViewModel::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
