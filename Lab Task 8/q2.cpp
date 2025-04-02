#include<iostream>
using namespace std;

class Shape {
protected:
    int position;
    string colour;
public:
    Shape(int p, string c) : position(p), colour(c) {}
    virtual void draw() = 0;
    virtual float getPerimeter() = 0;
    virtual float getArea() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    float radius;
    int centerPosition;
public:
    Circle(float r, int center, int p, string c) : Shape(p, c), radius(r), centerPosition(center) {}
    void draw() override {
        cout << "\nCircle Details:"
             << "\nRadius: " << radius
             << "\nCenter Position: " << centerPosition
             << "\nPosition: " << position
             << "\nColour: " << colour;
    }
    float getPerimeter() override {
        return 2 * 3.14 * radius;
    }
    float getArea() override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
    float width, height;
    int topLeftPosition;
public:
    Rectangle(int p, string c, float w, float h, int t)
        : Shape(p, c), width(w), height(h), topLeftPosition(t) {}
    void draw() override {
        cout << "\nRectangle Details:"
             << "\nWidth: " << width
             << "\nHeight: " << height
             << "\nTop Left Position: " << topLeftPosition
             << "\nPosition: " << position
             << "\nColour: " << colour;
    }
    float getPerimeter() override {
        return 2 * (height + width);
    }
    float getArea() override {
        return height * width;
    }
};

class Triangle : public Shape {
    float base, height;
    float side1, side2, side3;
public:
    Triangle(int p, string c, float b, float h, float s1, float s2, float s3)
        : Shape(p, c), base(b), height(h), side1(s1), side2(s2), side3(s3) {}
    void draw() override {
        cout << "\nTriangle Details:"
             << "\nBase: " << base
             << "\nHeight: " << height
             << "\nSides: " << side1 << ", " << side2 << ", " << side3
             << "\nPosition: " << position
             << "\nColour: " << colour;
    }
    float getPerimeter() override {
        return side1 + side2 + side3;
    }
    float getArea() override {
        return 0.5 * base * height;
    }
};

int main() {
    Circle c(5, 10, 1, "Red");
    Rectangle r(2, "Blue", 4, 6, 3);
    Triangle t(3, "Green", 5, 7, 3, 4, 5);
    
    c.draw();
    cout << "\nPerimeter: " << c.getPerimeter() << " Area: " << c.getArea();
    
    r.draw();
    cout << "\nPerimeter: " << r.getPerimeter() << " Area: " << r.getArea();
    
    t.draw();
    cout << "\nPerimeter: " << t.getPerimeter() << " Area: " << t.getArea();
    
    return 0;
}
