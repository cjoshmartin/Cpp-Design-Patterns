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

    // beginning of Factories
    static Point NewCartesian(const float x, const float y)
    {
        return {x,y};
    }

    static Point NewPolar(const float r, const float theta)
    {
        return {r*cos(theta),r*sin(theta)};
    }

    // end of Factories
    friend std::ostream& operator<<(std::ostream& os, const Point& obj)
    {
        return os << "x: " << obj.x << " y: " << obj.y;
    }
};



int main()
{
    Point p{1,2};
    // Cartesian
    auto c = Point::NewCartesian(1,2);
    std::cout << c << std::endl;

    // Polar
    std::cout << Point::NewPolar(5,M_PI_4) << std::endl;

    getchar();
    return 0;
}