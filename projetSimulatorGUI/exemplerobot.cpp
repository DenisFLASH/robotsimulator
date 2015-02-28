#include "exemplerobot.h"
#include <QGraphicsItemAnimation>
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsScene>
#include <QtGui>

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


 RobotPart::RobotPart(QGraphicsItem *parent)
     : QGraphicsItem(parent), color(Qt::lightGray), dragOver(false)
 {
     setAcceptDrops(true);
 }

 void RobotPart::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
 {
     if (event->mimeData()->hasColor()
         || (qgraphicsitem_cast<RobotHead *>(this) && event->mimeData()->hasImage())) {
         event->setAccepted(true);
         dragOver = true;
         update();
     } else {
         event->setAccepted(false);
     }
 }

 void RobotPart::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
 {
     Q_UNUSED(event);
     dragOver = false;
     update();
 }

 void RobotPart::dropEvent(QGraphicsSceneDragDropEvent *event)
 {
     dragOver = false;
    /* if (event->mimeData()->hasColor())
         color = qVariantValue<QColor>(event->mimeData()->colorData());
     else if (event->mimeData()->hasImage())
         pixmap = qVariantValue<QPixmap>(event->mimeData()->imageData());
     */
     update();
 }

 RobotHead::RobotHead(QGraphicsItem *parent)
     : RobotPart(parent)
 {
 }

 QRectF RobotHead::boundingRect() const
 {
     return QRectF(-15, -50, 30, 50);
 }

 void RobotHead::paint(QPainter *painter,
            const QStyleOptionGraphicsItem *option, QWidget *widget)
 {
     Q_UNUSED(option);
     Q_UNUSED(widget);
     if (pixmap.isNull()) {
         painter->setBrush(dragOver ? color.light(130) : color);
         painter->drawRoundRect(-10, -30, 20, 30);
         painter->setBrush(Qt::white);
         painter->drawEllipse(-7, -3 - 20, 7, 7);
         painter->drawEllipse(0, -3 - 20, 7, 7);
         painter->setBrush(Qt::black);
         painter->drawEllipse(-5, -1 - 20, 2, 2);
         painter->drawEllipse(2, -1 - 20, 2, 2);
         painter->setPen(QPen(Qt::black, 2));
         painter->setBrush(Qt::NoBrush);
         painter->drawArc(-6, -2 - 20, 12, 15, 190 * 16, 160 * 16);
     } else {
         painter->scale(.2272, .2824);
         painter->drawPixmap(QPointF(-15 * 4.4, -50 * 3.54), pixmap);
     }
 }

 int RobotHead::type() const
 {
     return Type;
 }

 RobotTorso::RobotTorso(QGraphicsItem *parent)
     : RobotPart(parent)
 {
 }

 QRectF RobotTorso::boundingRect() const
 {
     return QRectF(-30, -20, 60, 60);
 }

 void RobotTorso::paint(QPainter *painter,
            const QStyleOptionGraphicsItem *option, QWidget *widget)
 {
     Q_UNUSED(option);
     Q_UNUSED(widget);

     painter->setBrush(dragOver ? color.light(130) : color);
     painter->drawRoundRect(-20, -20, 40, 60);
     painter->drawEllipse(-25, -20, 20, 20);
     painter->drawEllipse(5, -20, 20, 20);
     painter->drawEllipse(-20, 22, 20, 20);
     painter->drawEllipse(0, 22, 20, 20);
 }

 RobotLimb::RobotLimb(QGraphicsItem *parent)
     : RobotPart(parent)
 {
 }

 QRectF RobotLimb::boundingRect() const
 {
     return QRectF(-5, -5, 40, 10);
 }

 void RobotLimb::paint(QPainter *painter,
            const QStyleOptionGraphicsItem *option, QWidget *widget)
 {
     Q_UNUSED(option);
     Q_UNUSED(widget);

     painter->setBrush(dragOver ? color.light(130) : color);
     painter->drawRoundRect(boundingRect(), 50, 50);
     painter->drawEllipse(-5, -5, 10, 10);
 }

 Robot::Robot()
 {
     QGraphicsItem *torsoItem = new RobotTorso(this);
     QGraphicsItem *headItem = new RobotHead(torsoItem);
     QGraphicsItem *upperLeftArmItem = new RobotLimb(torsoItem);
     QGraphicsItem *lowerLeftArmItem = new RobotLimb(upperLeftArmItem);
     QGraphicsItem *upperRightArmItem = new RobotLimb(torsoItem);
     QGraphicsItem *lowerRightArmItem = new RobotLimb(upperRightArmItem);
     QGraphicsItem *upperRightLegItem = new RobotLimb(torsoItem);
     QGraphicsItem *lowerRightLegItem = new RobotLimb(upperRightLegItem);
     QGraphicsItem *upperLeftLegItem = new RobotLimb(torsoItem);
     QGraphicsItem *lowerLeftLegItem = new RobotLimb(upperLeftLegItem);

     headItem->setPos(0, -18);
     upperLeftArmItem->setPos(-15, -10);
     lowerLeftArmItem->setPos(30, 0);
     upperRightArmItem->setPos(15, -10);
     lowerRightArmItem->setPos(30, 0);
     upperRightLegItem->setPos(10, 32);
     lowerRightLegItem->setPos(30, 0);
     upperLeftLegItem->setPos(-10, 32);
     lowerLeftLegItem->setPos(30, 0);

     timeLine = new QTimeLine;

     QGraphicsItemAnimation *headAnimation = new QGraphicsItemAnimation;
     headAnimation->setItem(headItem);
     headAnimation->setTimeLine(timeLine);
     headAnimation->setRotationAt(0, 20);
     headAnimation->setRotationAt(1, -20);
     headAnimation->setScaleAt(1, 1.1, 1.1);

     QGraphicsItemAnimation *upperLeftArmAnimation = new QGraphicsItemAnimation;
     upperLeftArmAnimation->setItem(upperLeftArmItem);
     upperLeftArmAnimation->setTimeLine(timeLine);
     upperLeftArmAnimation->setRotationAt(0, 190);
     upperLeftArmAnimation->setRotationAt(1, 180);

     QGraphicsItemAnimation *lowerLeftArmAnimation = new QGraphicsItemAnimation;
     lowerLeftArmAnimation->setItem(lowerLeftArmItem);
     lowerLeftArmAnimation->setTimeLine(timeLine);
     lowerLeftArmAnimation->setRotationAt(0, 50);
     lowerLeftArmAnimation->setRotationAt(1, 10);

     QGraphicsItemAnimation *upperRightArmAnimation = new QGraphicsItemAnimation;
     upperRightArmAnimation->setItem(upperRightArmItem);
     upperRightArmAnimation->setTimeLine(timeLine);
     upperRightArmAnimation->setRotationAt(0, 300);
     upperRightArmAnimation->setRotationAt(1, 310);

     QGraphicsItemAnimation *lowerRightArmAnimation = new QGraphicsItemAnimation;
     lowerRightArmAnimation->setItem(lowerRightArmItem);
     lowerRightArmAnimation->setTimeLine(timeLine);
     lowerRightArmAnimation->setRotationAt(0, 0);
     lowerRightArmAnimation->setRotationAt(1, -70);

     QGraphicsItemAnimation *upperLeftLegAnimation = new QGraphicsItemAnimation;
     upperLeftLegAnimation->setItem(upperLeftLegItem);
     upperLeftLegAnimation->setTimeLine(timeLine);
     upperLeftLegAnimation->setRotationAt(0, 150);
     upperLeftLegAnimation->setRotationAt(1, 80);

     QGraphicsItemAnimation *lowerLeftLegAnimation = new QGraphicsItemAnimation;
     lowerLeftLegAnimation->setItem(lowerLeftLegItem);
     lowerLeftLegAnimation->setTimeLine(timeLine);
     lowerLeftLegAnimation->setRotationAt(0, 70);
     lowerLeftLegAnimation->setRotationAt(1, 10);

     QGraphicsItemAnimation *upperRightLegAnimation = new QGraphicsItemAnimation;
     upperRightLegAnimation->setItem(upperRightLegItem);
     upperRightLegAnimation->setTimeLine(timeLine);
     upperRightLegAnimation->setRotationAt(0, 40);
     upperRightLegAnimation->setRotationAt(1, 120);

     QGraphicsItemAnimation *lowerRightLegAnimation = new QGraphicsItemAnimation;
     lowerRightLegAnimation->setItem(lowerRightLegItem);
     lowerRightLegAnimation->setTimeLine(timeLine);
     lowerRightLegAnimation->setRotationAt(0, 10);
     lowerRightLegAnimation->setRotationAt(1, 50);

     QGraphicsItemAnimation *torsoAnimation = new QGraphicsItemAnimation;
     torsoAnimation->setItem(torsoItem);
     torsoAnimation->setTimeLine(timeLine);
     torsoAnimation->setRotationAt(0, 5);
     torsoAnimation->setRotationAt(1, -20);

     timeLine->setUpdateInterval(1000 / 25);
     timeLine->setCurveShape(QTimeLine::SineCurve);
     timeLine->setLoopCount(0);
     timeLine->setDuration(2000);
     timeLine->start();
 }

 Robot::~Robot()
 {
     delete timeLine;
 }

 QRectF Robot::boundingRect() const
 {
     return QRectF();
 }

 void Robot::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option, QWidget *widget)
 {
     Q_UNUSED(painter);
     Q_UNUSED(option);
     Q_UNUSED(widget);
 }
 /*void Robot::advance(int step)
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
        /* QLineF lineTorobot(QPointF(0, 0), mapFromItem(item, 0, 0));
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

     /* // Add some random movement
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
 }*/
