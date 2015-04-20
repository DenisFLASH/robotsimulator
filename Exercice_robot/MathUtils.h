#ifndef MATHUTILS_H
#define MATHUTILS_H


namespace MathUtils
{
    double polarToX(int xCenter, double r, double phi);
    double polarToY(int yCenter, double r, double phi);
    void scaleCoordinatesOfRectangle(int x, int y, int w, int h, int* xScaled, int* yScaled, int* widthScaled, int* heightScaled);
    double angleNormalize(double angle);
}

#endif // MATHUTILS_H
