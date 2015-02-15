#ifndef ROBOT_H
#define ROBOT_H

#include "MobileObject.h"
#include <string>
using namespace std;

class Robot : public MobileObject
{

public:
    Robot(string name, int x, int y, int radius, double heading);
    void move();
    void moveBack();
    void stepTurnLeft();
    void stepTurnRight();

    void init();
    void step();

private:
    int m_x, m_y, m_radius;
    double m_speed, m_heading, m_stepTurnAngle;

    void checkIfRobotOutsideTable(int& x, int& y, int radius);
};

#endif // ROBOT_H
