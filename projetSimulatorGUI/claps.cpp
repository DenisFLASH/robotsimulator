#include "claps.h"

#include <QBrush>

claps::claps():
    QGraphicsRectItem()
{
    setRect(150,550,20,50);
    setBrush(QBrush(Qt::green));
}

claps::~claps()
{

}

