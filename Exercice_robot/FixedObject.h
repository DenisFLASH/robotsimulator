#ifndef FIXEDOBJECT_H
#define FIXEDOBJECT_H

#include <QGraphicsRectItem>
#include <string>
using namespace std;
using namespace Qt;

class FixedObject : public QGraphicsRectItem
{
private:
    string m_name;
    int m_xStart,
        m_yStart,
        m_width,
        m_heigth,
        m_relief;
    GlobalColor m_color;

public:
    FixedObject(string name, GlobalColor color, int xStart, int yStart, int width, int height, int relief);
    ~FixedObject();
    string getName();
    GlobalColor getColor();
    int getXStart();
    int getYStart();
    int getWidth();
    int getHeight();
    int getRelief();
    void showObjectInfo();
};

#endif // FIXEDOBJECT_H
