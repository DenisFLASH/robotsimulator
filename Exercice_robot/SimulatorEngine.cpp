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

PlayingArea* SimulatorEngine::getPlayingArea()
{
    return p_playingArea;
}

void SimulatorEngine::run()
{
    cout << "\n\n\t\t!!!!!!  THREAD SimulatorEngine STARTED RUNNING..." << this->currentThread()->objectName().toStdString() << endl;
    Robot* theOnlyRobot = p_playingArea->getTheOnlyRobot();
    theOnlyRobot->init();
    while(1)
    {
        theOnlyRobot->displayInfo();
        theOnlyRobot->step();
        refreshRobotCoordinates(theOnlyRobot);
        usleep(STEP_DURATION_MICROSECONDS);
    }
}

void SimulatorEngine::refreshRobotCoordinates(Robot* robot)
{
    int xOld = robot->getX();
    int yOld = robot->getY();
    double speed = robot->getSpeed();
    double heading = robot->getHeading();

    // Changes the coordinates anyway
    int xNew = xOld + speed * cos(heading);
    int yNew = yOld - speed * sin(heading);
    robot->setX(xNew);
    robot->setY(yNew);

    // If the move is impossible, "rollback" to the old coordinates
    if (isRobotOutsideTable(robot))
    {
        cout << "!!! Impossible to move outside of the table." << endl;
        robot->setX(xOld);
        robot->setY(yOld);
    }
}


// Returns true if at least one of the corners of the robot is outside of the table.
bool SimulatorEngine::isRobotOutsideTable(Robot *robot)
{
    int xNW = robot->getXNW();
    int yNW = robot->getYNW();
    int xNE = robot->getXNE();
    int yNE = robot->getYNE();
    int xSW = robot->getXSW();
    int ySW = robot->getYSW();
    int xSE = robot->getXSE();
    int ySE = robot->getYSE();
    if ( xNW <= 0 || xNW >= TABLE_WIDTH ||
         xNE <= 0 || xNE >= TABLE_WIDTH ||
         xSW <= 0 || xSW >= TABLE_WIDTH ||
         xSE <= 0 || xSE >= TABLE_WIDTH ||
         yNW <= 0 || yNW >= TABLE_HEIGHT ||
         yNE <= 0 || yNE >= TABLE_HEIGHT ||
         ySW <= 0 || ySW >= TABLE_HEIGHT ||
         ySE <= 0 || ySE >= TABLE_HEIGHT )
    {
        return true;
    }
    return false;
}
