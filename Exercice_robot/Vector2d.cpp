#include "Vector2d.h"
#include <cmath>
using namespace std;

Vector2d::Vector2d()
{
    x = 0.0;
    y = 0.0;
}

Vector2d::Vector2d(float sourceX, float sourceY)
{
    x = sourceX;
    y = sourceY;
}

bool Vector2d::operator==(const Vector2d* v) const
{
    return ((x == v->x) && (y == v->y));
}

float Vector2d::DotProduct(const Vector2d* a, const Vector2d* b)
{
    return ((a->x * b->x) + (a->y * b->y));
}


float Vector2d::Magnitude(const Vector2d* v)
{
    return sqrt((v->x * v->x) + (v->y * v->y));
}

float Vector2d::SquareMagnitude(const Vector2d* v)
{
    return (v->x * v->x + v->y * v->y);
}

Vector2d Vector2d::Normal(const Vector2d* v)
{
    float magnitude = Magnitude(v);
    return Vector2d(v->x / magnitude, v->y / magnitude);
}
