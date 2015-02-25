TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Cerveau.cpp \
    StrategieGlobale.cpp \
    Capteur.cpp \
    Deplacement.cpp \
    Pince.cpp

HEADERS += \
    Capteur.h \
    Deplacement.h \
    StrategieGlobale.h \
    ston.h \
    Pince.h \
    Cerveau.h

