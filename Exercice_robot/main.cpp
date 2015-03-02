#include <QtGui>
#include <QApplication>
#include "PlayingArea.h"
#include "Robot.h"
#include "Parameters.h"
#include "StrategieGlobale.h"
#include "SimulatorEngine.h"
#include "SupportGUI.h"
#include <iostream>
using namespace Parameters;


int main(int argc, char** argv)
{
    QApplication app(argc, argv);


    Robot* ryad = new Robot("Ryad", TEAM_A_MAIN_ROBOT_INIT_X, TEAM_A_MAIN_ROBOT_INIT_Y,
                            TEAM_A_MAIN_ROBOT_LENGTH, TEAM_A_MAIN_ROBOT_WIDTH, NORTH);
    StrategieGlobale* brain = new StrategieGlobale();
    ryad->bindServiceInitialisation(brain);
    ryad->bindServicePasAPas(brain);
    brain->bindServiceActionMoteur(ryad);
    //brain->bindServiceActionPince(ryad);
    //brain->bindServiceCapteur(ryad);

    PlayingArea* area = new PlayingArea();
    area->setTheOnlyRobot(ryad);

    // 2 THREADS.
    SimulatorEngine engine;
    engine.bindPlayingArea(area);
    SupportGUI supportGUI;
    supportGUI.bindPlayingArea(area);


    // "start" runs the threads.
    // "wait" makes the main thread wait until 'engine' and 'supportGUI' threads finish their execution.
    engine.start();
    supportGUI.start();
    engine.wait();
    supportGUI.wait();


    delete area;
    delete brain;
    delete ryad;

    return app.exec();
}

