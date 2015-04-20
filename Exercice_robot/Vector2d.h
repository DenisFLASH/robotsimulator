#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cfloat>
#include <climits>
#include <string>
using namespace std;

/*The Vector2d class is an object consisting of simply an x and
  y value. Certain operators are overloaded to make it easier
  for vector math to be performed.*/

class Vector2d {
public:
    /*The x and y values are public to give easier access for
      outside funtions. Accessors and mutators are not really
      necessary*/
    float x;
    float y;

    //Constructor assigns the inputs to x and y.
    Vector2d();
    Vector2d(float, float);

    //Check if the Vectors have the same values.
    bool operator==(const Vector2d*) const;

    //Product functions
    static float DotProduct(const Vector2d*, const Vector2d*);

    //Returns the length of the vector from the origin.
    static float Magnitude(const Vector2d*);
    static float SquareMagnitude(const Vector2d*);

    //Return the unit vector of the input
    static Vector2d Normal(const Vector2d*);
};

#endif
