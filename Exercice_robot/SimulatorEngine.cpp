#include "SimulatorEngine.h"
#include "Parameters.h"
#include "MathUtils.h"
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
    setRobot(p_playingArea->getTheOnlyRobot());
}

PlayingArea* SimulatorEngine::getPlayingArea()
{
    return p_playingArea;
}

void SimulatorEngine::step()
{
    p_robot->displayInfo();
    p_robot->step();
    refreshRobotCoordinates(p_robot);
}

Robot *SimulatorEngine::getRobot() const
{
    return p_robot;
}

void SimulatorEngine::setRobot(Robot* value)
{
    p_robot = value;
}




// Calculates new coordinates of the robot after its STEP action.
// Interaction with table borders and fixed objects taken into account.
void SimulatorEngine::refreshRobotCoordinates(Robot* robot)
{
    int xOld = robot->getX();
    int yOld = robot->getY();
    double headingOld = robot->getHeading();

    // Changes the coordinates anyway (center and corners)
    int xNew = xOld + robot->getSpeed() * cos(headingOld);
    int yNew = yOld - robot->getSpeed() * sin(headingOld);
    double headingNew = headingOld + robot->getTurnSpeed();
    robot->setX(xNew);
    robot->setY(yNew);
    robot->setHeading(headingNew);
    robot->updateCornersCoordinates();

    // If the move is impossible, "rollback" to the old coordinates
    if (isRobotOutsideTable(robot))
    {
        cout << "!!! Impossible to move outside of the table." << endl;
        robot->setX(xOld);
        robot->setY(yOld);
        robot->setHeading(headingOld);
        robot->updateCornersCoordinates();
    }

    for (unsigned int i = 0; i < p_playingArea->getAllFixedObjects().size(); i++)
    {
        FixedObject* fixedObject = p_playingArea->getAllFixedObjects()[i];
        if (isCollisionBetweenRobotAndFixedObject(robot, fixedObject))
        {
            cout << "!!! Collision between robot and " << fixedObject->getName() << endl;
            robot->setX(xOld);
            robot->setY(yOld);
            robot->setHeading(headingOld);
            robot->updateCornersCoordinates();
        }
    }


}


// Returns true if at least one of the corners of the robot is outside of the table.
bool SimulatorEngine::isRobotOutsideTable(Robot* robot)
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

bool SimulatorEngine::isCollisionBetweenRobotAndFixedObject(Robot* robot, FixedObject* fixedObject)
{
    // !!! Order is important. 1,2,3,4 means that 1 and 4 (2 and 3) are opposite corners.
    int Ax1 = robot->getXNW();  // 1(NW)---2(NE)
    int Ay1 = robot->getYNW();  // 3(SW)---4(SE)
    int Ax2 = robot->getXNE();
    int Ay2 = robot->getYNE();
    int Ax3 = robot->getXSW();
    int Ay3 = robot->getYSW();
    int Ax4 = robot->getXSE();
    int Ay4 = robot->getYSE();
    int Bx1 = fixedObject->getXStart(); // starts at top-left
    int By1 = fixedObject->getYStart();
    int Bx2 = fixedObject->getXStart() + fixedObject->getWidth(); // 1(NW)---2(NE)
    int By2 = fixedObject->getYStart();                           // 3(SW)---4(SE)
    int Bx3 = fixedObject->getXStart();
    int By3 = fixedObject->getYStart() + fixedObject->getHeight();
    int Bx4 = fixedObject->getXStart() + fixedObject->getWidth();
    int By4 = fixedObject->getYStart() + fixedObject->getHeight();

    return MathUtils::areRectanglesColliding(Ax1,Ay1,Ax2,Ay2,Ax3,Ay3,Ax4,Ay4,Bx1,By1,Bx2,By2,Bx3,By3,Bx4,By4);
}
