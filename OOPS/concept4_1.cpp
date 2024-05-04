#include <iostream>
using namespace std;

// Abstract class
class Shape {
public:
    // Pure virtual function i.e this function has no implementation in this class but have strong implementation in the derived classes
    virtual void draw() = 0;

    // Non-abstract member function
    void displayArea() {
        cout << "Area: " << calculateArea() << " square units" << endl;
    }

    // Pure virtual function for area calculation
    virtual double calculateArea() = 0;
};

// Derived class - Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Implementation of the draw function
    void draw() {
        cout << "Drawing a rectangle" << endl;
    }

    // Implementation of the calculateArea function
    double calculateArea() {
        return length * width;
    }
};

// Derived class - Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Implementation of the draw function
    void draw() {
        cout << "Drawing a circle" << endl;
    }

    // Implementation of the calculateArea function
    double calculateArea() {
        return 3.14 * radius * radius;
    }
};

int main() {
    Rectangle rectangle(5.0, 3.0);
    Circle circle(2.5);

    rectangle.draw();
    rectangle.displayArea();

    circle.draw();
    circle.displayArea();

    return 0;
}
