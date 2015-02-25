#ifndef FIXEDOBJECT_H
#define FIXEDOBJECT_H

#include <string>
using namespace std;

class FixedObject
{
private:
    string m_name;
    int m_xStart,
        m_yStart,
        m_width,
        m_heigth,
        m_relief;

public:
    FixedObject(string name, int xStart, int yStart, int width, int height, int relief);
    string getName();
    int getXStart();
    int getYStart();
    int getWidth();
    int getHeight();
    int getRelief();
    void showObjectInfo();
};

#endif // FIXEDOBJECT_H
