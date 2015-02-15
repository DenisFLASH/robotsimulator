#-------------------------------------------------
#
# Project created by QtCreator 2015-02-15T11:38:25
#
#-------------------------------------------------

QT       -= gui

TARGET = PlayingArea
TEMPLATE = lib
CONFIG += staticlib

SOURCES += PlayingArea.cpp \
    FixedObject.cpp \
    MobileObject.cpp

HEADERS += PlayingArea.h \
    FixedObject.h \
    MobileObject.h \
    Parameters.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
