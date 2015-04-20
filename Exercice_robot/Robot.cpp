#include "Robot.h"
#include "MathUtils.h"
#include "Parameters.h"
#include <QPainter>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
using namespace MathUtils;
using namespace Parameters;

#define PI 3.14159265358979323846

Robot::Robot(string name, int x, int y, int length, int width, double heading):
robotEyeDirection(0)
{
    m_name = name;
    m_x = x;
    m_y = y;
    m_length = length;
    m_width = width;
    m_heading = heading;
    m_speed = 0.0;
    m_turnSpeed = 0.0;

    // 2 constants
    distanceToCorner = sqrt(m_length*m_length + m_width*m_width) / 2;
    angleToCorner = atan( (1.0*m_width) / (1.0*m_length) );

    setRotation(m_heading);

    // 4 corners
    updateCornersCoordinates();

    //setRect(QRectF(20, 40, 50, 100));
    //setBrush(QBrush(m_color));
    cout << "Robot created..." << endl;
}

Robot::~Robot()
{
    cout << "...Robot destroyed." << endl;
}

// QGraphicsItem methods /////////////////////////////
QRectF Robot::boundingRect() const
{
   qreal adjust = 0.5;
   int xScaled,
       yScaled,
       widthScaled,
       heightScaled;
   scaleCoordinatesOfRectangle(m_x, m_y, m_length, m_width, &xScaled, &yScaled, &widthScaled, &heightScaled);

   return QRectF(-0.5*widthScaled, -0.5*heightScaled, widthScaled, heightScaled);

    /*return QRectF(-30 - adjust, -40 - adjust,
                  36 + adjust, 60 + adjust);*/
}
/*
    int x = - 0.5 * m_length;
    int y = - 0.5 * m_width;
    int w = m_length;
    int h = m_width;
    return QRectF(x, y, w, h);}*/

/*QPainterPath Robot::shape() const
{

}*/
void Robot::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    //QPixmap pixMap("/Users/liban/Desktop/SimulateurEngineLast/avatars/clumpsy.png");
        //QRectF target(10.0, 20.0, 80.0, 60.0);
        //QRectF source(0.0, 0.0, 70.0, 40.0);
        //QImage image("../avatars/clumpsy.png");

      //  painter->drawImage(target, &image, source);
        cout << "\n\t\tin robot.paint()" << endl;
        // Body
        int xScaled,
            yScaled,
            widthScaled,
            heightScaled;
        scaleCoordinatesOfRectangle(m_x, m_y, m_length, m_width, &xScaled, &yScaled, &widthScaled, &heightScaled);

       // painter->setBrush(scene()->collidingItems(this).isEmpty() ? Qt::darkYellow : Qt::red);
        painter->setBrush(Qt::cyan);
        //painter->drawEllipse(-10, -20, 20, 40);
        painter->drawRect(-0.5*widthScaled, -20, widthScaled, heightScaled);

        // Eyes
        painter->setBrush(Qt::white);
        painter->drawEllipse(0.4*widthScaled, -0.1*heightScaled, 8, 8);
        painter->drawEllipse(0.4*widthScaled, 0.2*heightScaled, 8, 8);
      //  painter->drawEllipse(-10, -17, 8, 8);
        //painter->drawEllipse(2, -17, 8, 8);
    /*
        // Nose
        painter->setBrush(Qt::black);
        painter->drawEllipse(QRectF(-2, -22, 4, 4));

        // Pupils
        painter->drawEllipse(QRectF(-8.0 + robotEyeDirection, -17, 4, 4));
        painter->drawEllipse(QRectF(4.0 + robotEyeDirection, -17, 4, 4));
    */
        // Roue Avant
        painter->setBrush(Qt::black);
        painter->drawEllipse(0.2*widthScaled, -0.5*heightScaled, 16, 16);
        painter->drawEllipse(0.2*widthScaled, 0.5*heightScaled, 16, 16);

         // Roue Arriere
        painter->setBrush(Qt::black);
        painter->drawEllipse(-0.3*widthScaled, -0.5*heightScaled, 16, 16);
        painter->drawEllipse(-0.3*widthScaled, 0.5*heightScaled, 16, 16);
    /*
        painter->drawEllipse(-17, -12, 16, 16);
        painter->drawEllipse(1, -12, 16, 16);
    /*
        // Tail
        QPainterPath path(QPointF(0, 20));
        path.cubicTo(-5, 22, -5, 22, 0, 25);
        path.cubicTo(5, 27, 5, 32, 0, 30);
        path.cubicTo(-5, 32, -5, 42, 0, 35);
        painter->setBrush(Qt::NoBrush);
        painter->drawPath(path);

    */
}

void Robot::advance(int step)
{
    int xScaled,
        yScaled,
        widthScaled,
        heightScaled;
    scaleCoordinatesOfRectangle(m_x, m_y, m_length, m_width, &xScaled, &yScaled, &widthScaled, &heightScaled);
    setRotation(- m_heading * 180 / PI);
    setPos(xScaled, yScaled);
}
// ///////////////////////////////////////////////////


// Binding with StrategieGlobale ///////////////////
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
// ///////////////////////////////////////////////

// Setters, getters ///////////////
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
double Robot::getTurnSpeed()
{
    return m_turnSpeed;
}
double Robot::getHeading()
{
    return m_heading;
}
void Robot::setHeading(double heading)
{
    m_heading = heading;
}
string Robot::getName()
{
    return m_name;
}
double Robot::getXNW()
{
    return m_XNW;
}
double Robot::getYNW()
{
    return m_YNW;
}
double Robot::getXNE()
{
    return m_XNE;
}
double Robot::getYNE()
{
    return m_YNE;
}
double Robot::getXSW()
{
    return m_XSW;
}
double Robot::getYSW()
{
    return m_YSW;
}
double Robot::getXSE()
{
    return m_XSE;
}
double Robot::getYSE()
{
    return m_YSE;
}

// Updates coordinates of all corners, knowing x,y of robot's center, its geometry and heading.
void Robot::updateCornersCoordinates()
{
    m_XNW = polarToX(m_x, distanceToCorner, angleToCorner + m_heading);
    m_YNW = polarToY(m_y, distanceToCorner, angleToCorner + m_heading);
    m_XNE = polarToX(m_x, distanceToCorner, - angleToCorner + m_heading);
    m_YNE = polarToY(m_y, distanceToCorner, - angleToCorner + m_heading);
    m_XSW = polarToX(m_x, distanceToCorner, PI - angleToCorner + m_heading);
    m_YSW = polarToY(m_y, distanceToCorner, PI - angleToCorner + m_heading);
    m_XSE = polarToX(m_x, distanceToCorner, PI + angleToCorner + m_heading);
    m_YSE = polarToY(m_y, distanceToCorner, PI + angleToCorner + m_heading);
}

void Robot::displayInfo()
{
    cout << m_name << ": x = " << m_x << ", y = " << m_y
            << ", speed = " << m_speed << ", turnSpeed = " << m_turnSpeed << ", heading = " << m_heading
            /*<< ", distanceToCorner = " << distanceToCorner << ", angleToCorner = " << angleToCorner */
            << "\n\tNW: [" << getXNW() << ", " << getYNW() << "]"
            << "\n\tNE: [" << getXNE() << ", " << getYNE() << "]"
            << "\n\tSW: [" << getXSW() << ", " << getYSW() << "]"
            << "\n\tSE: [" << getXSE() << ", " << getYSE() << "]" << endl;
}



// ==== IMPLEMENTING SERVICES ====

// ServiceActionMoteur
void Robot::avancer(double puissance)
{
    m_speed = ROBOT_MAX_SPEED * puissance;
    m_turnSpeed = 0;
}
void Robot::reculer(double puissane)
{
    m_speed = -ROBOT_MAX_SPEED * puissane;
    m_turnSpeed = 0;
}
void Robot::arreterMoteur()
{
    m_speed = 0.0;
}
void Robot::tournerAGauche()
{
    m_turnSpeed = STEP_TURN_ANGLE;
    m_speed = 0.0;
}
void Robot::tournerADroite()
{
   m_turnSpeed = -STEP_TURN_ANGLE;
   m_speed = 0.0;
}
