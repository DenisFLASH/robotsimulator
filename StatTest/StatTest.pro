#-------------------------------------------------
#
# Project created by QtCreator 2015-02-15T11:07:27
#
#-------------------------------------------------

QT       += core
QT       -= gui

TEMPLATE = app
TARGET = StatTest

CONFIG   += console
CONFIG   -= app_bundle

INCLUDEPATH += "/home/denis/Dropbox/IT/INSTA/Robotique/Qt/PlayingArea/" \
               "/home/denis/Dropbox/IT/INSTA/Robotique/Qt/SimulatorEngine/"
LIBS += "/home/denis/Dropbox/IT/INSTA/Robotique/Qt/build-PlayingArea-Desktop-Release/libPlayingArea.a" \
        "/home/denis/Dropbox/IT/INSTA/Robotique/Qt/build-SimulatorEngine-Desktop-Release/libSimulatorEngine.a"


SOURCES += main.cpp

HEADERS += \
    ../PlayingArea/PlayingArea.h \
    ston.h

