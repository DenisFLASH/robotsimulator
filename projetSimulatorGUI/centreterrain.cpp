#include "centreterrain.h"

#include <QBrush>

centreTerrain::centreTerrain():
    QGraphicsRectItem()
{
    setRect(0,200,300,100);
    setBrush(QBrush(Qt::red));
}

centreTerrain::~centreTerrain()
{

}

