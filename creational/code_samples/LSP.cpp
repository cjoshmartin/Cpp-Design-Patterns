// Liskov Substitution Principle

// Objects in a program should be replaceable with instances of their subtypes 
// without altering the correctness of the program
//

#include <string>
#include <iostream>

class Rectangle 
{
    protected:
        int width, height;
    public:
        Rectangle(const int width, const int height)
            : width{width},
            height{height}
        {
            
        }

   virtual int getWidth() const {
        return width;
    }

    virtual void setWidth(int width) {
        this->width = width;
    }

    virtual int getHeight() const {
        return height;
    }

    virtual void setHeight(int height) {
        this->height = height;
    }
    int  Area() const { return width * height;}

    void process(Rectangle& r){
       int w = r.getWidth();
        r.setHeight(10);
        std::cout<< "expect Area =" << (w * 10) << ", got " << r.Area() << std::endl;
    }
};


int main(){

    Rectangle r{5,5};
    process(r);

    getchar();
    return 0;
}