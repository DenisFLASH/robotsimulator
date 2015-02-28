#include "Robot.h"
#include "MathUtils.h"
#include "Parameters.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
using namespace MathUtils;
using namespace Parameters;

#define PI 3.14159265358979323846

Robot::Robot(string name, int x, int y, int length, int width, double heading)
{
    m_name = name;
    m_x = x;
    m_y = y;
    m_length = length;
    m_width = width;
    m_heading = heading;
    m_speed = 0.0;
    //m_acceleration = 0.0;
    distanceToCorner = sqrt(m_length*m_length + m_width*m_width) / 2;
    angleToCorner = atan( (1.0*m_width) / (1.0*m_length) );
    cout << "Robot created..." << endl;
}

Robot::~Robot()
{
    cout << "...Robot destroyed." << endl;
}

void Robot::bindServiceInitialisation(ServiceInitialisation* serviceInitialisation)
{
    p_serviceInit = serviceInitialisation;
}

void Robot::bindServicePasAPas(ServicePasAPas* servicePasAPas)
{
    p_servicePasAPas = servicePasAPas;
}

void Robot::init()
{
    p_serviceInit->init();
}

void Robot::step()
{
    p_servicePasAPas->step();
}


int Robot::getX()
{
    return m_x;
}
void Robot::setX(int x)
{
    m_x = x;
}
int Robot::getY()
{
    return m_y;
}
void Robot::setY(int y)
{
    m_y = y;
}
int Robot::getLength()
{
    return m_length;
}
int Robot::getWidth()
{
    return m_width;
}
double Robot::getSpeed()
{
    return m_speed;
}
void Robot::setSpeed(double speed)
{
    m_speed = speed;
}
double Robot::getAcceleration()
{
    return m_acceleration;
}
double Robot::getHeading()
{
    return m_heading;
}
string Robot::getName()
{
    return m_name;
}

void Robot::displayInfo()
{
    cout << m_name << ": x = " << m_x << ", y = " << m_y
            << ", speed = " << m_speed << ", acceleration = " << m_acceleration << ", heading = " << m_heading
            << ", distanceToCorner = " << distanceToCorner << ", angleToCorner = " << angleToCorner
            << "\n\tNW: [" << getXNW() << ", " << getYNW() << "]"
            << "\n\tNE: [" << getXNE() << ", " << getYNE() << "]"
            << "\n\tSW: [" << getXSW() << ", " << getYSW() << "]"
            << "\n\tSE: [" << getXSE() << ", " << getYSE() << "]" << endl;
}


// СOORDINATES OF 4 CORNERS
double Robot::getXNW()
{
    return polarToX(m_x, distanceToCorner, angleToCorner + m_heading);
}
double Robot::getYNW()
{
    //cout << "getYNW(): return polarToY(" << m_y << ", " << distanceToCorner << ", " << angleToCorner + m_heading<< ")" << endl;
    //int yNew = polarToY(m_y, distanceToCorner, angleToCorner + m_heading);
    //cout << "= " << yNew << endl;
    return polarToY(m_y, distanceToCorner, angleToCorner + m_heading);
}
double Robot::getXNE()
{
    return polarToX(m_x, distanceToCorner, - angleToCorner + m_heading);
}
double Robot::getYNE()
{
    return polarToY(m_y, distanceToCorner, - angleToCorner + m_heading);
}
double Robot::getXSW()
{
    return polarToX(m_x, distanceToCorner, PI - angleToCorner + m_heading);
}
double Robot::getYSW()
{
    return polarToY(m_y, distanceToCorner, PI - angleToCorner + m_heading);
}
double Robot::getXSE()
{
    return polarToX(m_x, distanceToCorner, PI + angleToCorner + m_heading);
}
double Robot::getYSE()
{
    return polarToY(m_y, distanceToCorner, PI + angleToCorner + m_heading);
}


// ==== IMPLEMENTING SERVICES ====

// ServiceActionMoteur
void Robot::avancer(double puissance)
{
    m_speed = puissance * ROBOT_MAX_SPEED;
}

void Robot::reculer(double puissance)
{
    m_speed = - puissance * ROBOT_MAX_SPEED;
}

void Robot::arreterMoteur()
{
    m_speed = 0.0;
}

void Robot::tournerAGauche()
{
    m_heading -= m_stepTurnAngle;
}

void Robot::tournerADroite()
{
     m_heading += m_stepTurnAngle;
}
