#include <QGraphicsScene>
#include "escaliers.h"
#include "marche.h"
Escaliers::Escaliers() : QGraphicsRectItem()
{
    setRect(300,0,150,100);
    setBrush(QBrush(Qt::yellow));
}

Escaliers::~Escaliers()
{

}

