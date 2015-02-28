#include <QGraphicsScene>
#include "FixedObject.h"
#include <iostream>
#include <string>
using namespace std;
using namespace Qt;

FixedObject::FixedObject(string name, GlobalColor color, int xStart, int yStart, int width, int height, int relief)
           : QGraphicsRectItem()
{
    m_name = name;
    m_color = color;
    m_xStart = xStart;
    m_yStart = yStart;
    m_width = width;
    m_heigth = height;
    m_relief = relief;
    setRect(m_xStart, m_yStart, m_width, m_heigth);
    setBrush(QBrush(m_color));
    cout << "FixedObject created..." << endl;
}

FixedObject::~FixedObject()
{
    cout << "...FixedObject destroyed." << endl;
}

GlobalColor FixedObject::getColor()
{
    return m_color;
}

string FixedObject::getName()
{
    return m_name;
}

int FixedObject::getXStart()
{
    return m_xStart;
}

int FixedObject::getYStart()
{
    return m_yStart;
}

int FixedObject::getWidth()
{
    return m_width;
}

int FixedObject::getHeight()
{
    return m_heigth;
}

int FixedObject::getRelief()
{
    return m_relief;
}

void FixedObject::showObjectInfo()
{
    cout << "Fixed object \"" << m_name << "\": x = " << m_xStart << ", y = " << m_yStart <<
            ", width = " << m_width << ", height = " << m_heigth << ", relief = " << m_relief << endl;
}

