#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>



class Point
{

    Point(const float a, const float b)
            : x{a},
              y{b}
    {
    }
public:
    float x,y;



    friend std::ostream& operator<<(std::ostream& os, const Point& obj)
    {
        return os << "x: " << obj.x << " y: " << obj.y;
    }
    friend class PointFacotory;
};

class PointFactory
{
public:
    static Point NewCartesian(const float x, const float y)
    {
        return {x,y};
    }

    static Point NewPolar(const float r, const float theta)
    {
        return {r*cos(theta),r*sin(theta)};
    }
};


int main()
{
    Point p{1,2};
    // Cartesian
    auto c = PointFactory::NewCartesian(1,2);
    std::cout << c << std::endl;

    // Polar
    std::cout << PointFactory::NewPolar(5,M_PI_4) << std::endl;

    getchar();
    return 0;
}