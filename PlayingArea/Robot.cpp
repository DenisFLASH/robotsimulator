#include "Robot.h"
#include <iostream>
#include <string>
using namespace std;


Robot::Robot(string name, int x, int y, int radius, double heading)
    : MobileObject(name, x, y, radius, heading)
{
    m_stepTurnAngle = 0.01;
}

/*
void Robot::move()
{
    m_x += m_speed * cos(m_heading);
    m_y += m_speed * sin(m_heading);
    checkIfRobotOutsideTable(m_x, m_y, m_radius);
}

void Robot::moveBack()
{
    m_x -= m_speed * cos(m_heading);
    m_y -= m_speed * sin(m_heading);
    checkIfRobotOutsideTable(m_x, m_y, m_radius);
}

void Robot::stepTurnLeft()
{
    m_heading -= m_stepTurnAngle;
}

void Robot::stepTurnRight()
{
    m_heading += m_stepTurnAngle;
}


void Robot::printLogMessage()
{
    cout << "Robot at x = " << getX() << ", y = " << getY() << endl;
}


// (TO DO: "abstract"?)   or implement an "interface" (not in this class)
void Robot::init()
{
    cout << "Robot Activated" << endl;
}

void Robot::step()
{
    move();
    stepTurnRight();
    move();
    printLogMessage();
    moveBack();
    printLogMessage();
}

void Robot::checkIfRobotOutsideTable(int& x, int& y, int radius)
{
    int xMin = radius;
    int xMax = Parameters::TABLE_WIDTH - radius;
    int yMin = radius;
    int yMax = Parameters::TABLE_HEIGHT - radius;
    if (x < xMin)
    {
        x = xMin;
    }
    if (x > xMax)
    {
        x = xMax;
    }
    if (y < yMin)
    {
        y = yMin;
    }
    if (y > yMax)
    {
        y = yMax;
    }
}
*/

