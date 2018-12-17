#include <iostream>

class Shape {
    public:
      virtual float area(){};
};

class Rectangle: public Shape {
    public:
        Rectangle(float length, float width, float height){
            this->length = length;
            this->height = height;
            this->width = width;
        };
        float area() override{
            return length * height * width;
        };

      private:
        float length;
        float height;
        float width;
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
    auto a = Rectangle(0.5, 5, 6);
    auto b = Triangle(5, 6);
    std::cout << "Rectangle Area: " << a.area() << std::endl;
    std::cout << "Triangle Area: " << b.area() << std::endl;
    return 0;
}
