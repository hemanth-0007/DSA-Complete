#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    virtual void draw() {
        cout << "Drawing a generic shape." << endl;
    }

    virtual double area() {
        return 0.0;
    }
};

// Derived class - Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}
    // Here the override keyword is optional one
    void draw() override {
        cout << "Drawing a rectangle." << endl;
    }

    double area() override {
        return length * width;
    }
};

// Derived class - Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void draw() override {
        cout << "Drawing a circle." << endl;
    }

    double area() override {
        return 3.14 * radius * radius;
    }
};

// Function to display the area of a shape
void displayArea(Shape* shape) {
    shape->draw();
    cout << "Area: " << shape->area() << " square units." << endl;
}

int main() {
    Shape* s;
    Rectangle rectangle(5.0, 3.0);
    Circle circle(2.5);
    s = &circle;
    s->draw();
    cout<<s->area();
    // displayArea(&rectangle); // Calls the draw() and area() functions of the Rectangle class
    // displayArea(&circle);    // Calls the draw() and area() functions of the Circle class

    return 0;
}
