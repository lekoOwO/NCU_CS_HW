#include <iostream>

class Shape {
    public:
      virtual void area();
};

class Rectangle: public Shape {
    public:
        Rectangle(float length, float height, float c){
            this->length = length;
            this->height = height;
            this->c = c;
        };
        void area() override{
            std::cout << length * height << std::endl;
        };

      private:
        float length;
        float height;
        float c;
};

class Triangle: public Shape {
    public:
        Triangle(float length, float height){
            this->length = length;
            this->height = height;
        };
        void area() override{
            std::cout << length * height / 2 << std::endl;
        };

      private:
        float length;
        float height;
};

int main(){
    auto a = Rectangle(0.5, 5, 6);
    auto b = Triangle(5, 6);
    a.area();
    b.area();
    return 0;
}
