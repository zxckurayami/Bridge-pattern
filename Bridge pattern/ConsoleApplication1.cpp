// Виконав Іван Єнко
#include <Windows.h>
#include <iostream>

// Реалізація абстракції
class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

// Конкретна реалізація
class CircleShape : public Shape {
public:
    void draw() override {
        std::cout << "Draw a circle" << std::endl;
    }
};

class SquareShape : public Shape {
public:
    void draw() override {
        std::cout << "Draw a square" << std::endl;
    }
};

// Інша абстракція
class Drawing {
public:
    virtual void drawShape() = 0;
    virtual ~Drawing() {}
};

// Конкретна реалізація абстракції
class DrawingAPI {
public:
    virtual void drawShape() = 0;
    virtual ~DrawingAPI() {}
};

// Реалізація абстракції з використанням DrawingAPI
class DrawingImpl : public Drawing {
public:
    DrawingImpl(DrawingAPI* api) : api(api) {}

    void drawShape() override {
        api->drawShape();
    }

private:
    DrawingAPI* api;
};

// Конкретна реалізація абстракції
class DrawingAPI1 : public DrawingAPI {
public:
    void drawShape() override {
        std::cout << "Drawing shape with API1" << std::endl;
    }
};

class DrawingAPI2 : public DrawingAPI {
public:
    void drawShape() override {
        std::cout << "Drawing shape with API2" << std::endl;
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // Використання Bridge pattern
    DrawingAPI1* api1 = new DrawingAPI1();
    DrawingImpl* drawing1 = new DrawingImpl(api1);
    drawing1->drawShape();

    DrawingAPI2* api2 = new DrawingAPI2();
    DrawingImpl* drawing2 = new DrawingImpl(api2);
    drawing2->drawShape();

    // Використання Shape та реалізації для кола
    Shape* circle = new CircleShape();
    circle->draw();

    // Використання Shape та реалізації для квадрата
    Shape* square = new SquareShape();
    square->draw();

    delete api1;
    delete api2;
    delete drawing1;
    delete drawing2;
    delete circle;
    delete square;

    return 0;
}
