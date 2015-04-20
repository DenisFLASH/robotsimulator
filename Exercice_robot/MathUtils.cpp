#include "MathUtils.h"
#include <cmath>
#include "Parameters.h"
#include "Vector2d.h"
#include <iostream>
#include <vector>
using namespace Parameters;
using namespace std;


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

// Abstract test of 2 rotated rectangles (Separating Axis Theorem)
bool MathUtils::areRectanglesColliding(int Ax1,int Ay1,int Ax2,int Ay2,int Ax3,int Ay3,int Ax4,int Ay4,int Bx1,int By1,int Bx2,int By2,int Bx3,int By3,int Bx4,int By4)
{
    // 1---2
    // 3---4
    Vector2d* A1 = new Vector2d(Ax1, Ay1);
    Vector2d* A2 = new Vector2d(Ax2, Ay2);
    Vector2d* A3 = new Vector2d(Ax3, Ay3);
    Vector2d* A4 = new Vector2d(Ax4, Ay4);
    Vector2d* B1 = new Vector2d(Bx1, By1);
    Vector2d* B2 = new Vector2d(Bx2, By2);
    Vector2d* B3 = new Vector2d(Bx3, By3);
    Vector2d* B4 = new Vector2d(Bx4, By4);
    vector<Vector2d*> fourAPoints;
    fourAPoints.push_back(A1);
    fourAPoints.push_back(A2);
    fourAPoints.push_back(A3);
    fourAPoints.push_back(A4);
    vector<Vector2d*> fourBPoints;
    fourBPoints.push_back(B1);
    fourBPoints.push_back(B2);
    fourBPoints.push_back(B3);
    fourBPoints.push_back(B4);

    // Step 1: Find 4 axis, each of which is perpendicular to 2 edges of one of rectangles
    // For rectangle A, take point 1 and its 2 adjacent points: 2 and 3
    Vector2d* axis1 = new Vector2d(Ax1-Ax2, Ay1-Ay2);
    Vector2d* axis2 = new Vector2d(Ax1-Ax3, Ay1-Ay3);
    // For rectangle B, take point 1 and its 2 adjacent points: 2 and 3
    Vector2d* axis3 = new Vector2d(Bx1-Bx2, By1-By2);
    Vector2d* axis4 = new Vector2d(Bx1-Bx3, By1-By3);
    vector<Vector2d*> allAxis;
    allAxis.push_back(axis1);
    allAxis.push_back(axis2);
    allAxis.push_back(axis3);
    allAxis.push_back(axis4);

    float squareNorm;
    float dotProduct;
    float scalar;
    Vector2d* projection;
    bool isIntersection;

    // Algorithm:
    // If there is AT LEAST ONE axis, for each there's no intersection of projections, than there's NO COLLISION.
    // If all 4 axis show projections' intersection, than there IS COLLISION.
    // Thus, REPEAT steps 2, 3, 4 for each axis.
    for (unsigned int i = 0; i < allAxis.size(); i++)
    {
        vector<float> scalarsA;
        vector<float> scalarsB;

        float squareNorm = Vector2d::SquareMagnitude(allAxis[i]);
        //cout << "square of axis " << (i+1) << " : " << squareNorm << endl;

        // Step 2: Project the vectors representing all 4 vertices of each rectangle (total 8 vectors)
        // on the current axis
        // Step 3: Calculate scalar values, using one more scalar product
        // (product of each projection and the vector which represents the current axis)
        for (unsigned int j = 0; j < fourAPoints.size(); j++)
        {
            dotProduct = Vector2d::DotProduct(fourAPoints[j], allAxis[i]);
            projection = new Vector2d(allAxis[i]->x * dotProduct / squareNorm, allAxis[i]->y * dotProduct / squareNorm);
            scalar = Vector2d::DotProduct(projection, allAxis[i]);
            //cout << "Projecting point A" << j+1 << " onto the axis " << i+1 << " : scalar = " << scalar << endl;
            scalarsA.push_back(scalar);
        }
        for (unsigned int j = 0; j < fourBPoints.size(); j++)
        {
            dotProduct = Vector2d::DotProduct(fourBPoints[j], allAxis[i]);
            projection = new Vector2d(allAxis[i]->x * dotProduct / squareNorm, allAxis[i]->y * dotProduct / squareNorm);
            scalar = Vector2d::DotProduct(projection, allAxis[i]);
            //cout << "Projecting point B" << j+1 << " onto the axis " << i+1 << " : scalar = " << scalar << endl;
            scalarsB.push_back(scalar);
        }

        // Step 4: Test if there is an intersection
        // If minScalarValueOfB <= maxScalarValueOfA AND maxScalarValueOfB >= minScalarValueOfA,
        // then there is an intersection.
        int minScalarValueOfA = min( min(scalarsA[0], scalarsA[1]), min(scalarsA[2], scalarsA[3]) );
        int maxScalarValueOfA = max( max(scalarsA[0], scalarsA[1]), max(scalarsA[2], scalarsA[3]) );
        int minScalarValueOfB = min( min(scalarsB[0], scalarsB[1]), min(scalarsB[2], scalarsB[3]) );
        int maxScalarValueOfB = max( max(scalarsB[0], scalarsB[1]), max(scalarsB[2], scalarsB[3]) );

        // If there's no intersection for AT LEAST ONE axis, rectangles are not colliding.
        if (minScalarValueOfB > maxScalarValueOfA || minScalarValueOfA > maxScalarValueOfB)
        {
            /*cout << "No intersection for axis " << i+1 << endl;
            cout << "minScalarValueOfA: " << minScalarValueOfA << endl;
            cout << "maxScalarValueOfA: " << maxScalarValueOfA << endl;
            cout << "minScalarValueOfB: " << minScalarValueOfB << endl;
            cout << "maxScalarValueOfB: " << maxScalarValueOfB << endl;*/
            return false;
        }
    }

    // If for all 4 axis there is an intersection, we reach this point and return true.
    return true;
}


// Simple test. We suppose that rectongle is axis-aligned (no rotation).
// Todo. Test even with a rotated rectangle.
bool MathUtils::isPointInsideRectangle(int x, int y, int xMin, int xMax, int yMin, int yMax)
{
    return ( x >= xMin && x <= xMax && y >= yMin && y <= yMax );
}
