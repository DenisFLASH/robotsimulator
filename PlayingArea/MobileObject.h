#ifndef MOBILEOBJECT_H
#define MOBILEOBJECT_H

#include <string>
using namespace std;

class MobileObject
{
private:
    string m_name;
    int m_x,
        m_y,
        m_radius;
    double m_speed,
           m_acceleration,
           m_heading;

public:
    MobileObject(string name, int x, int y, int radius, double heading);
    string getName();
    int getX();
    int getY();
    int getRadius();
    double getSpeed();
    double getAcceleration();
    double getHeading();
    void showObjectInfo();
    void refreshCoordinates();
};

#endif // MOBILEOBJECT_H
