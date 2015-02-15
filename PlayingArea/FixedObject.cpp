#include "FixedObject.h"
#include <iostream>
#include <string>
using namespace std;

FixedObject::FixedObject(string name, int xStart, int yStart, int width, int height, int relief)
{
    m_name = name;
    m_xStart = xStart;
    m_yStart = yStart;
    m_width = width;
    m_heigth = height;
    m_relief = relief;
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
    return m_heigth;
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
