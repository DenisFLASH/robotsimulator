#include "MobileObject.h"
#include <iostream>
#include <string>
using namespace std;

MobileObject::MobileObject(string name, int x, int y, int radius, double heading)
{
    m_name = name;
    m_x = x;
    m_y = y;
    m_radius = radius;
    m_heading = heading;
    m_speed = 0.0;
    m_acceleration = 0.0;
}

string MobileObject::getName()
{
    return m_name;
}

int MobileObject::getX()
{
    return m_x;
}

int MobileObject::getY()
{
    return m_y;
}

int MobileObject::getRadius()
{
    return m_radius;
}

double MobileObject::getSpeed()
{
    return m_speed;
}

double MobileObject::getAcceleration()
{
    return m_acceleration;
}

double MobileObject::getHeading()
{
    return m_heading;
}

void MobileObject::showObjectInfo()
{
    cout << "Mobile object \"" << m_name << "\": x = " << m_x << ", y = " << m_y <<
            ", speed = " << m_speed << ", acceleration = " << m_acceleration << ", heading = " << m_heading << endl;
}

void MobileObject::refreshCoordinates()
{

}

