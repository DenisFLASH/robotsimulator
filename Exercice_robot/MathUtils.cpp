#include "MathUtils.h"
#include <cmath>
#include "Parameters.h"
using namespace Parameters;


double MathUtils::polarToX(int xCenter, double r, double phi)
{
    return xCenter + r * cos(phi);
}

double MathUtils::polarToY(int yCenter, double r, double phi)
{

    return yCenter - r * sin(phi);  // "-" because of SCREEN coordinates
}

// Coordinates translation between PlayingArea (3000x2000) and Simulator GUI swindow (900x600)
void MathUtils::scaleCoordinatesOfRectangle(int x, int y, int w, int h, int* xScaled, int* yScaled, int* widthScaled, int* heightScaled)
{
    double scaleFactorX = 1.0 * SIMULATOR_SCREEN_WIDTH / TABLE_WIDTH;
    double scaleFactorY = 1.0 * SIMULATOR_SCREEN_HEIGHT / TABLE_HEIGHT;
    *xScaled = x * scaleFactorX;
    *yScaled = y * scaleFactorY;
    *widthScaled = w * scaleFactorX;
    *heightScaled = h * scaleFactorY;
}


double MathUtils::angleNormalize(double angle)
{
    double result = angle;
    if(result < 0)
        result += 2 *PI;
    if(result >= 2 *PI)
        result -= 2 *PI;
    return (result);
}
