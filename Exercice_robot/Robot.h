#ifndef ROBOT_H
#define ROBOT_H

#include "ston.h"
#include <string>
using namespace std;

class Robot: public ServiceActionMoteur,
             //public ServiceActionPince,
             //public ServiceCapteur,
             public ServiceRequisInitialisation,
             public ServiceRequisPasAPas
{
private:
    int m_x,
        m_y,
        m_length,
        m_width;
    double m_speed,
           m_acceleration,
           m_heading,
           m_stepTurnAngle;
    double distanceToCorner, // r
           angleToCorner;    // beta
    string m_name;

    ServiceInitialisation* p_serviceInit;
    ServicePasAPas* p_servicePasAPas;

public:
    Robot(string name, int x, int y, int length, int width, double heading);
    virtual ~Robot();
    void bindServiceInitialisation(ServiceInitialisation* serviceInitialisation);
    void bindServicePasAPas(ServicePasAPas* servicePasAPas);
    void init();
    void step();

public:
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    int getLength();
    int getWidth();
    double getSpeed();
    void setSpeed(double speed);
    double getAcceleration();
    double getHeading();
    string getName();
    void displayInfo();

    double getXNW();
    double getYNW();
    double getXNE();
    double getYNE();
    double getXSW();
    double getYSW();
    double getXSE();
    double getYSE();

    // ServiceActionMoteur
    void avancer(double puissance); // move()
    void reculer(double puissance); // moveBack()
    void arreterMoteur();
    void tournerAGauche(); // stepTurnLeft()
    void tournerADroite(); // stepTurnRight()

    // ServiceActionPince
    // todo

    // ServiceCapteur
    // todo
};



#endif // ROBOT_H
