#-------------------------------------------------
#
# Project created by QtCreator 2015-02-10T08:53:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projetSimulatorGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    escaliers.cpp \
    marche.cpp \
    zonedepart.cpp \
    viewgame.cpp \
    centreterrain.cpp \
    distributeurpopcorne.cpp \
    claps.cpp \
    robot.cpp \
    exemplerobot.cpp

HEADERS  += mainwindow.h \
    scene.h \
    escaliers.h \
    marche.h \
    zonedepart.h \
    viewgame.h \
    centreterrain.h \
    distributeurpopcorne.h \
    claps.h \
    robot.h \
    exemplerobot.h

FORMS    += mainwindow.ui
