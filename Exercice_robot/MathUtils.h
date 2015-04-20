#ifndef MATHUTILS_H
#define MATHUTILS_H

namespace MathUtils
{
    double polarToX(int xCenter, double r, double phi);
    double polarToY(int yCenter, double r, double phi);
    void scaleCoordinatesOfRectangle(int x, int y, int w, int h, int* xScaled, int* yScaled, int* widthScaled, int* heightScaled);
    double angleNormalize(double angle);

    bool areRectanglesColliding(int Ax1,int Ay1,int Ax2,int Ay2,int Ax3,int Ay3,int Ax4,int Ay4,int Bx1,int By1,int Bx2,int By2,int Bx3,int By3,int Bx4,int By4);
    bool isPointInsideRectangle(int x, int y, int xMin, int xMax, int yMin, int yMax);
}

#endif // MATHUTILS_H
