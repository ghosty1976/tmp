QT += core gui widgets network charts

CONFIG += c++17

SOURCES += \
    networkclient.cpp \
    authregform.cpp \
    functions_for_client.cpp \
    main.cpp \
    mainwindow.cpp \
    managerformss.cpp \
    passwordrecoveryform.cpp \
    registrationform.cpp \
    solution.cpp

HEADERS += \
    authregform.h \
    functions_for_client.h \
    mainwindow.h \
    managerformss.h \
    networkclient.h \
    passwordrecoveryform.h \
    registrationform.h \
    solution.h

FORMS += \
    authregform.ui \
    mainwindow.ui \
    passwordrecoveryform.ui \
    registrationform.ui \
    solution.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
