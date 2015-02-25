#include "PlayingArea.h"
#include "Robot.h"
#include "Parameters.h"
#include "StrategieGlobale.h"
#include "SimulatorEngine.h"

using namespace Parameters;


int main()
{
    Robot* ryad = new Robot(TEAM_A_MAIN_ROBOT_INIT_X, TEAM_A_MAIN_ROBOT_INIT_Y, TEAM_A_MAIN_ROBOT_RADIUS, 0.3);
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

    /*SupportGUI* gui = new SupportGUI();
    gui->bindPlayingArea(area);*/

    // test
    //engine->getPlayingArea()->getTheOnlyRobot()->displayInfo();

    engine->run();

    delete engine;
    delete area;
    delete brain;
    delete ryad;
}

