#include "SimulatorEngine.h"
#include "Parameters.h"
#include <iostream>
#include <unistd.h>
#include <cmath>
using namespace std;
using namespace Parameters;



SimulatorEngine::SimulatorEngine()
{
    cout << "SimulatorEngine created..." << endl;
}

SimulatorEngine::~SimulatorEngine()
{
    cout << "...SimulatorEngine destroyed." << endl;
}

void SimulatorEngine::bindPlayingArea(PlayingArea* area)
{
    p_playingArea = area;
}

PlayingArea *SimulatorEngine::getPlayingArea()
{
    return p_playingArea;
}

void SimulatorEngine::run()
{
    Robot* theOnlyRobot = p_playingArea->getTheOnlyRobot();
    theOnlyRobot->init();
    while(1)
    {
        theOnlyRobot->step();
        refreshCoordinates();
        theOnlyRobot->displayInfo();
        usleep(STEP_DURATION_MICROSECONDS);
    }
}

void SimulatorEngine::refreshCoordinates()
{
    Robot* robot = p_playingArea->getTheOnlyRobot();
    int x = robot->getX();
    int y = robot->getY();
    double speed = robot->getSpeed();
    double heading = robot->getHeading();

    int xNew = x + speed * cos(heading);
    int yNew = y - speed * sin(heading);

    robot->setX(xNew);
    robot->setY(yNew);

    //checkIfRobotOutsideTable(m_x, m_y, m_radius);
}
