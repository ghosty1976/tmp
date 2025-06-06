/****************************************************************************
** Meta object code from reading C++ file 'authregform.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../authregform.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'authregform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
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
struct qt_meta_tag_ZN11AuthRegFormE_t {};
} // unnamed namespace

template <> constexpr inline auto AuthRegForm::qt_create_metaobjectdata<qt_meta_tag_ZN11AuthRegFormE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "AuthRegForm",
        "auth_ok",
        "",
        "login",
        "switchToMainWindow",
        "switchToRegistrationForm",
        "recovery_ok",
        "on_pushButtonAuth_clicked",
        "on_pushButtonReg_clicked",
        "on_pushButtonForgotPassword_clicked",
        "clear"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'auth_ok'
        QtMocHelpers::SignalData<void(const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'switchToMainWindow'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'switchToRegistrationForm'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'recovery_ok'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_pushButtonAuth_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonReg_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonForgotPassword_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'clear'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<AuthRegForm, qt_meta_tag_ZN11AuthRegFormE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject AuthRegForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11AuthRegFormE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11AuthRegFormE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11AuthRegFormE_t>.metaTypes,
    nullptr
} };

void AuthRegForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<AuthRegForm *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->auth_ok((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->switchToMainWindow(); break;
        case 2: _t->switchToRegistrationForm(); break;
        case 3: _t->recovery_ok(); break;
        case 4: _t->on_pushButtonAuth_clicked(); break;
        case 5: _t->on_pushButtonReg_clicked(); break;
        case 6: _t->on_pushButtonForgotPassword_clicked(); break;
        case 7: _t->clear(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (AuthRegForm::*)(const QString & )>(_a, &AuthRegForm::auth_ok, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (AuthRegForm::*)()>(_a, &AuthRegForm::switchToMainWindow, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (AuthRegForm::*)()>(_a, &AuthRegForm::switchToRegistrationForm, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (AuthRegForm::*)()>(_a, &AuthRegForm::recovery_ok, 3))
            return;
    }
}

const QMetaObject *AuthRegForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AuthRegForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11AuthRegFormE_t>.strings))
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
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void AuthRegForm::auth_ok(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
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
