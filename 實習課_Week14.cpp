#include <iostream>

const int TRA_UP = 5;
const int TRA_DOWN = 2;
const int TRA_HEIGHT = 4;
const int TRI_LENGTH = 5;
const int TRI_HEIGHT = 7;

class Shape {
    public:
      virtual float area(){};
};

class Trapezoid: public Shape {
    public:
        Trapezoid(float up, float down, float height){
            this->up = up;
            this->down = down;
            this->height = height;
        };
        float area() override{
            return (up + down) * height / 2;
        };

      private:
        float up;
        float down;
        float height;
};

class Triangle: public Shape {
    public:
        Triangle(float length, float height){
            this->length = length;
            this->height = height;
        };
        float area() override{
            return length * height / 2;
        };

      private:
        float length;
        float height;
};

int main(){
    auto a = Trapezoid(TRA_UP, TRA_DOWN, TRA_HEIGHT);
    auto b = Triangle(TRI_LENGTH, TRI_HEIGHT);
    std::cout << "Rectangle Area: " << '(' << TRA_UP << " + " << TRA_DOWN  << ") * " << TRA_HEIGHT << " / 2 = "<< a.area() << std::endl;
    std::cout << "Triangle Area: " << TRI_LENGTH << " * " << TRI_HEIGHT << " / 2 = " << b.area() << std::endl;
    return 0;
}
