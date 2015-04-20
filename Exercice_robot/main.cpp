#include <QtGui>
#include <QApplication>
#include "PlayingArea.h"
#include "Robot.h"
#include "Parameters.h"
#include "Scene.h"
#include "StrategieGlobale.h"
#include "SimulatorEngine.h"
#include <QGraphicsView>
#include <iostream>
using namespace Parameters;


int main(int argc, char** argv)
{
    QApplication app(argc, argv);


    Robot* ryad = new Robot("Ryad", TEAM_A_MAIN_ROBOT_INIT_X, TEAM_A_MAIN_ROBOT_INIT_Y,
                            TEAM_A_MAIN_ROBOT_LENGTH, TEAM_A_MAIN_ROBOT_WIDTH, EAST);
    StrategieGlobale* brain = new StrategieGlobale();
    ryad->bindServiceInitialisation(brain);
    ryad->bindServicePasAPas(brain);
    brain->bindServiceActionMoteur(ryad);
    //brain->bindServiceActionPince(ryad);
    //brain->bindServiceCapteur(ryad);

    PlayingArea* area = new PlayingArea();
    area->setTheOnlyRobot(ryad);

    SimulatorEngine* engine = new SimulatorEngine();
    engine->bindPlayingArea(area);
    engine->getPlayingArea()->getTheOnlyRobot()->init();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), engine, SLOT(step()));
    timer.start(STEP_DURATION_MILLISECONDS);


    // GUI
    Scene* scene = new Scene();
    scene->bindPlayingArea(area);
    scene->initDrawFixedObjects();
    //scene->initDrawRobot();
    QGraphicsView view(scene);
    QTimer ihmTimer;
    QObject::connect(&ihmTimer, SIGNAL(timeout()), scene, SLOT(advance()));
    view.show();
    ihmTimer.start(100);



    return app.exec();





    /*// "start" runs the threads.
    // "wait" makes the main thread wait until 'engine' and 'supportGUI' threads finish their execution.
    engine.start();
    supportGUI.start();
    engine.wait();
    supportGUI.wait();*/

    /*delete engine;
    delete area;
    delete brain;
    delete ryad;*/
}

