#include "robot.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <iostream>
#include <math.h>
using namespace std;

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}

robot::robot()
    : angle(0), speed(0), robotEyeDirection(0),
      color(qrand() % 256, qrand() % 256, qrand() % 256)
{
    setRotation(qrand() % (360 * 16));
    //QPixmap image;
   // image.load(":/Users/liban/Desktop/Simulateur RobotInsta/simovies_canevas/avatars/clumpsy.png");
   // led_on = new QPixmap(":/Users/liban/Desktop/Simulateur RobotInsta/simovies_canevas/avatars/clumpsy.png");
}

robot::~robot()
{

}
QRectF robot::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust, 36 + adjust, 60 + adjust);
    //return QRectF(38 - adjust, 62 - adjust, 176 + adjust, 200 + adjust);
}
/*
QPainterPath robot::shape() const
{
    QPainterPath path;
    path.addRect(-10, -20, 20, 40);
    return path;
}
*/
void robot::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    cout << "robot.paint()" << endl;
    // Body
    painter->setBrush(scene()->collidingItems(this).isEmpty() ? Qt::darkYellow : Qt::red);
    painter->drawEllipse(-10, -20, 20, 40);
    //painter->drawImage(0,0,image);
    //painter->drawImage(QRect(100, 50, 100, 100),image);


    // Eyes
    painter->setBrush(Qt::white);
    painter->drawEllipse(-10, -17, 8, 8);
    painter->drawEllipse(2, -17, 8, 8);

    // Nose
    painter->setBrush(Qt::black);
    painter->drawEllipse(QRectF(-2, -22, 4, 4));

    // Pupils
    painter->drawEllipse(QRectF(-8.0 + robotEyeDirection, -17, 4, 4));
    painter->drawEllipse(QRectF(4.0 + robotEyeDirection, -17, 4, 4));

    // Ears
    painter->setBrush(Qt::magenta);
    painter->drawEllipse(-17, -12, 16, 16);
    painter->drawEllipse(1, -12, 16, 16);

    // Tail
    QPainterPath path(QPointF(0, 20));
    path.cubicTo(-5, 22, -5, 22, 0, 25);
    path.cubicTo(5, 27, 5, 32, 0, 30);
    path.cubicTo(-5, 32, -5, 42, 0, 35);
    painter->setBrush(Qt::NoBrush);
    painter->drawPath(path);
}

void robot::advance(int step)
{
    if (!step)
        return;
    // Don't move too far away
    QLineF lineToCenter(QPointF(0, 0), mapFromScene(0, 0));
    if (lineToCenter.length() > 0) {
        qreal angleToCenter = ::acos(lineToCenter.dx() / lineToCenter.length());
        if (lineToCenter.dy() < 0)
            angleToCenter = TwoPi - angleToCenter;
        angleToCenter = normalizeAngle((Pi - angleToCenter) + Pi / 2);

        if (angleToCenter < Pi && angleToCenter > Pi / 4) {
            // Rotate left
            angle += (angle < -Pi / 2) ? 0.25 : -0.25;
        } else if (angleToCenter >= Pi && angleToCenter < (Pi + Pi / 2 + Pi / 4)) {
            // Rotate right
            angle += (angle < Pi / 2) ? 0.25 : -0.25;
        }
    } else if (::sin(angle) < 0) {
        angle += 0.25;
    } else if (::sin(angle) > 0) {
        angle -= 0.25;
    }


    // Try not to crash with any other mice
    QList<QGraphicsItem *> dangerMice = scene()->collidingItems(this);
    foreach (QGraphicsItem *item, dangerMice) {
        if (item == this)
            continue;
       QLineF lineTorobot(QPointF(0, 0), mapFromItem(item, 0, 0));
        qreal angleTorobot = ::acos(lineTorobot.dx() / lineTorobot.length());
        if (lineTorobot.dy() < 0)
            angleTorobot = TwoPi - angleTorobot;
        angleTorobot = normalizeAngle((Pi - angleTorobot) + Pi / 2);

        if (angleTorobot >= 0 && angleTorobot < Pi / 2) {
            // Rotate right
            angle += 0.5;
        } else if (angleTorobot <= TwoPi && angleTorobot > (TwoPi - Pi / 2)) {
            // Rotate left
            angle -= 0.5;
        }


    }

    // Add some random movement
    if (dangerMice.size() > 1 && (qrand() % 10) == 0) {
        if (qrand() % 1)
            angle += (qrand() % 100) / 500.0;
        else
            angle -= (qrand() % 100) / 500.0;
    }

    speed += (-50 + qrand() % 100) / 100.0;

    qreal dx = ::sin(angle) * 10;
    robotEyeDirection = (qAbs(dx / 5) < 1) ? 0 : dx / 5;

   setRotation(rotation() + dx);
   setPos(mapToParent(0, -(3 + sin(speed) * 3)));
}


