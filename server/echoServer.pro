QT -= gui

QT += core network sql

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

QT += network

SOURCES += \
    main.cpp \
    mytcpserver.cpp \
    dbsingleton.cpp \
    emailutils.cpp \
    userutils.cpp

HEADERS += \
    mytcpserver.h \
    dbsingleton.h \
    emailutils.h \
    userutils.h

# Директории для сборки по умолчанию
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
