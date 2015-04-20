#ifndef ROBOT_H
#define ROBOT_H
#include <QGraphicsRectItem>
#include <QPainterPath>
#include <QRectF>
#include <QStyleOption>

class robot: public QGraphicsItem
{

public:
    robot();
    ~robot();
    QRectF boundingRect() const;
    //QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
protected:
    void advance(int step);

private:
    qreal angle;
    qreal speed;
    qreal robotEyeDirection;
    QColor color;
    static QPixmap *led_on;
};

#endif // ROBOT_H
