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

// Calculates new coordinates of the robot after its STEP action.
// Interaction with table borders and fixed objects taken into account.
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

    for (unsigned int i = 0; i < p_playingArea->getAllFixedObjects().size(); i++)
    {
        FixedObject* fixedObject = p_playingArea->getAllFixedObjects()[i];
        if (isCollisionBetweenRobotAndFixedObject(robot, fixedObject))
        {
            cout << "!!! Collision between robot and " << fixedObject->getName() << endl;
            robot->setX(xOld);
            robot->setY(yOld);
        }
    }

    // Know when we know if the robot changed his center's coordinates or not,
    // we can update the coordinates of its center.
    robot->updateCornersCoordinates();
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

    return areRectanglesColliding(Ax1,Ay1,Ax2,Ay2,Ax3,Ay3,Ax4,Ay4,Bx1,By1,Bx2,By2,Bx3,By3,Bx4,By4);
}


// 1) Simple test: detect a collision if at least one of the corners of a robot (rectangle A) touches rectangle B.
// Todo: "dead angle" ==> abstract test of 2 rotated rectangles.
// Or, simpler: add a test of whether a corner of a fixed object is INSIDE the rotated robot's rectangle.
bool SimulatorEngine::areRectanglesColliding(int Ax1,int Ay1,int Ax2,int Ay2,int Ax3,int Ay3,int Ax4,int Ay4,int Bx1,int By1,int Bx2,int By2,int Bx3,int By3,int Bx4,int By4)
{
    // 1---2
    // 3---4
    int BxMin = Bx1;
    int BxMax = Bx2;
    int ByMin = By1;
    int ByMax = By3;
    if ( isPointInsideRectangle(Ax1,Ay1,BxMin,BxMax,ByMin,ByMax) ||
         isPointInsideRectangle(Ax2,Ay2,BxMin,BxMax,ByMin,ByMax) ||
         isPointInsideRectangle(Ax3,Ay3,BxMin,BxMax,ByMin,ByMax) ||
         isPointInsideRectangle(Ax4,Ay4,BxMin,BxMax,ByMin,ByMax) )
    {
        return true;
    }
    return false;
}

// Simple test. We suppose that rectongle is axis-aligned (no rotation).
// Todo. Test even with a rotated rectangle.
bool SimulatorEngine::isPointInsideRectangle(int x, int y, int xMin, int xMax, int yMin, int yMax)
{
    return ( x >= xMin && x <= xMax && y >= yMin && y <= yMax );
}
