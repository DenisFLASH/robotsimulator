#include "MathUtils.h"
#include <cmath>


double MathUtils::polarToX(int xCenter, double r, double phi)
{
    return xCenter + r * cos(phi);
}

double MathUtils::polarToY(int yCenter, double r, double phi)
{

    return yCenter - r * sin(phi);  // "-" because of SCREEN coordinates
}
