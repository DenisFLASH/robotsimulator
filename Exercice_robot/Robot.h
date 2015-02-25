#ifndef ROBOT_H
#define ROBOT_H

#include "ston.h"


class Robot: public ServiceActionMoteur,
             //public ServiceActionPince,
             //public ServiceCapteur,
             public ServiceRequisInitialisation,
             public ServiceRequisPasAPas
{
private:
    int m_x,
        m_y,
        m_radius;
    double m_speed,
           m_acceleration,
           m_heading,
           m_stepTurnAngle;

    ServiceInitialisation* p_serviceInit;
    ServicePasAPas* p_servicePasAPas;

public:
    Robot(int x, int y, int radius, double heading);
    virtual ~Robot();
    void bindServiceInitialisation(ServiceInitialisation* serviceInitialisation);
    void bindServicePasAPas(ServicePasAPas* servicePasAPas);
    void init();
    void step();

    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    int getRadius();
    double getSpeed();
    void setSpeed(double speed);
    double getAcceleration();
    double getHeading();
    void displayInfo();

    // ServiceActionMoteur
    void avancer(); // move()
    void reculer(); // moveBack()
    void arreterMoteur();
    void tournerAGauche(); // stepTurnLeft()
    void tournerADroite(); // stepTurnRight()

    // ServiceActionPince
    // todo

    // ServiceCapteur
    // todo
};



#endif // ROBOT_H
