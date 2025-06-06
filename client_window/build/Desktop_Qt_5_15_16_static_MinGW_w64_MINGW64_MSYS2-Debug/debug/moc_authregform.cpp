/****************************************************************************
** Meta object code from reading C++ file 'authregform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.16)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../authregform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'authregform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.16. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AuthRegForm_t {
    QByteArrayData data[11];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AuthRegForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AuthRegForm_t qt_meta_stringdata_AuthRegForm = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AuthRegForm"
QT_MOC_LITERAL(1, 12, 7), // "auth_ok"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 5), // "login"
QT_MOC_LITERAL(4, 27, 18), // "switchToMainWindow"
QT_MOC_LITERAL(5, 46, 24), // "switchToRegistrationForm"
QT_MOC_LITERAL(6, 71, 11), // "recovery_ok"
QT_MOC_LITERAL(7, 83, 25), // "on_pushButtonAuth_clicked"
QT_MOC_LITERAL(8, 109, 24), // "on_pushButtonReg_clicked"
QT_MOC_LITERAL(9, 134, 35), // "on_pushButtonForgotPassword_c..."
QT_MOC_LITERAL(10, 170, 5) // "clear"

    },
    "AuthRegForm\0auth_ok\0\0login\0"
    "switchToMainWindow\0switchToRegistrationForm\0"
    "recovery_ok\0on_pushButtonAuth_clicked\0"
    "on_pushButtonReg_clicked\0"
    "on_pushButtonForgotPassword_clicked\0"
    "clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AuthRegForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    0,   57,    2, 0x06 /* Public */,
       5,    0,   58,    2, 0x06 /* Public */,
       6,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AuthRegForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AuthRegForm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->auth_ok((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->switchToMainWindow(); break;
        case 2: _t->switchToRegistrationForm(); break;
        case 3: _t->recovery_ok(); break;
        case 4: _t->on_pushButtonAuth_clicked(); break;
        case 5: _t->on_pushButtonReg_clicked(); break;
        case 6: _t->on_pushButtonForgotPassword_clicked(); break;
        case 7: _t->clear(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AuthRegForm::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AuthRegForm::auth_ok)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AuthRegForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AuthRegForm::switchToMainWindow)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AuthRegForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AuthRegForm::switchToRegistrationForm)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AuthRegForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AuthRegForm::recovery_ok)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AuthRegForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_AuthRegForm.data,
    qt_meta_data_AuthRegForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AuthRegForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AuthRegForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AuthRegForm.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AuthRegForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void AuthRegForm::auth_ok(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AuthRegForm::switchToMainWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AuthRegForm::switchToRegistrationForm()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void AuthRegForm::recovery_ok()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
