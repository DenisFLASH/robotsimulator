#ifndef ROBOT_H
#define ROBOT_H

#include <QGraphicsRectItem>
#include "ston.h"
#include <string>
using namespace std;

class Robot: public QGraphicsItem,
             public ServiceActionMoteur,
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
    double m_XNW, m_YNW, m_XNE, m_YNE, m_XSW, m_YSW, m_XSE, m_YSE;
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

    // Methods of QGraphicsItem ////////////////////////////////////////////////////////////
    void advance(int phase);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    // /////////////////////////////////////////////////////////////////////////////////////


    // Binding with StrategieGlobale ////////////////////////////////////////////
    void bindServiceInitialisation(ServiceInitialisation* serviceInitialisation);
    void bindServicePasAPas(ServicePasAPas* servicePasAPas);
    void init();
    void step();
    // /////////////////////////////////////////////////////////////////////////


    // Setters, getters //////////
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
    double getXNW();
    double getYNW();
    double getXNE();
    double getYNE();
    double getXSW();
    double getYSW();
    double getXSE();
    double getYSE();
    void updateCornersCoordinates();
    void displayInfo();
    // /////////////////////////////

    // ServiceActionMoteur
    void avancer(double puissance); // move()
    void reculer(double puissance); // moveBack()
    void arreterMoteur();
    void tournerAGauche(); // stepTurnLeft()
    void tournerADroite(); // stepTurnRight()

    // ServiceActionPince
    // todo

    // ServiceCapteur
    // todo (!!!) move to SimulatorEngine
};



#endif // ROBOT_H
