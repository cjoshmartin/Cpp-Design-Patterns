#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>


enum class PointType
{
    cartesian,
    polar
};

class Point
{
public:
    float x,y;

    Point(const float a, const float b, PointType type = PointType::cartesian)
    {
        if(type == PointType::cartesian)
        {
            x = a;
            y = b;
        }
        else
        {
            x = a * cos(b);
            y = a=a * sin(b);
        }
    }
};
