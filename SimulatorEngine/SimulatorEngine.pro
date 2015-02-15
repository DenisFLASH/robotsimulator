#-------------------------------------------------
#
# Project created by QtCreator 2015-02-15T18:00:04
#
#-------------------------------------------------

QT       -= gui

TARGET = SimulatorEngine
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += "/home/denis/Dropbox/IT/INSTA/Robotique/Qt/PlayingArea/"
LIBS += "/home/denis/Dropbox/IT/INSTA/Robotique/Qt/build-PlayingArea-Desktop-Release/libPlayingArea.a"

SOURCES += SimulatorEngine.cpp

HEADERS += SimulatorEngine.h \
    ../PlayingArea/PlayingArea.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
