TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Cerveau.cpp \
    StrategieGlobale.cpp \
    Deplacement.cpp \
    Pince.cpp \
    Robot.cpp \
    Capteur.cpp \
    PlayingArea.cpp \
    FixedObject.cpp \
    SimulatorEngine.cpp \
    MathUtils.cpp

HEADERS += \
    Deplacement.h \
    StrategieGlobale.h \
    ston.h \
    Pince.h \
    Cerveau.h \
    Robot.h \
    Capteur.h \
    PlayingArea.h \
    FixedObject.h \
    Parameters.h \
    SimulatorEngine.h \
    MathUtils.h

