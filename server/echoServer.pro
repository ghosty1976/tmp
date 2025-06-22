QT -= gui

QT += core network sql qml

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    dbsingleton.cpp \
    userutils.cpp \
    equationssolver.cpp \
    mytcpserver.cpp

HEADERS += \
    dbsingleton.h \
    userutils.h \
    equationssolver.h \
    mytcpserver.h

# Директории для сборки по умолчанию
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

