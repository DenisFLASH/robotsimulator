#include "distributeurpopcorne.h"

#include <QBrush>
#include <QPainter>
DistributeurPopCorne::DistributeurPopCorne()
    : QGraphicsRectItem()
{
    setRect(100,0,50,50);
    setBrush(QBrush(Qt::blue));
    setZValue(2);
    setVisible(true);
    m_text = 5;
}

DistributeurPopCorne::~DistributeurPopCorne()
{

}



