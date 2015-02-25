#include "Robot.h"
#include <iostream>
using namespace std;

Robot::Robot(int x, int y, int radius, double heading)
{
    m_x = x;
    m_y = y;
    m_radius = radius;
    m_heading = heading;
    m_speed = 0.0;
    //m_acceleration = 0.0;
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
int Robot::getRadius()
{
    return m_radius;
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

void Robot::displayInfo()
{
    cout << "Robot: x = " << m_x << ", y = " << m_y <<
            ", speed = " << m_speed << ", acceleration = " << m_acceleration << ", heading = " << m_heading << endl;
}


// ServiceActionMoteur
void Robot::avancer()
{
    m_speed = 5.0;
}

void Robot::reculer()
{
    m_speed = -5.0;
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
