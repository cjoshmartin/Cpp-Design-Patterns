#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>



class Point
{

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
    static PointFactory Factory;
};


int main()
{
    auto p = Point::Factory.NewCartesian(2,3);
    cout << p << std::endl;

    getchar();
    return 0;
}