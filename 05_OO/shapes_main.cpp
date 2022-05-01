#include <iostream>
#include <cmath>
#include <vector>
#include "AnsiConsole.h"

struct Position{
  int x;
  int y;
  Position(int x_=0, int y_=0){ x=x_;y=y_;}
};

class Shape {
    protected:
        Position _position;
        Colors _color;

    public:
        Shape();
        Shape(int x, int y, Colors color);
        virtual void draw() = 0;
};

Shape::Shape()
{
    _position = Position(0, 0);
    _color = Colors::RED;
}

Shape::Shape(int x, int y, Colors color)
{
    _position = Position(x, y);
    _color = color;
}

class Point : public Shape {
    public:
        Point();
        Point(int x, int y);
        Point(int x, int y, Colors color);
        void draw();
};

Point::Point() : Shape(0, 0, Colors::RED) {

}

Point::Point(int x, int y) : Shape(x, y, Colors::RED) {
}

Point::Point(int x, int y, Colors color) : Shape(x, y, color) {
}

void Point::draw(){
  ansiConsole.printText(_position.x,_position.y,"*", _color);
}

class Circle : public Shape {
protected:
  int       _radius;
public:
  Circle();
  Circle(int x, int y, int radius);
  Circle(int x, int y, int radius, Colors color);
  void draw();
};

Circle::Circle() : Shape(0, 0, Colors::GREEN) {
  _radius=0;
}

Circle::Circle(int x, int y, int radius) : Shape(x, y, Colors::GREEN) {
  _radius=radius;
}

Circle::Circle(int x, int y, int radius, Colors color) : Shape(x, y, color) {
  _radius=radius;
}

void Circle::draw(){
  /* see https://de.wikibooks.org/wiki/Formelsammlung_Mathematik:_Geometrie
   * Höhensatz des Euklid
   * */
  int x_start = _position.x - _radius/2;
  int x_stop  = _position.x + _radius/2;

  for(int i=x_start; i<=x_stop; i++){
    double x_relative = double(i) - double(x_start);
    double h = sqrt(x_relative*(x_stop-x_start-x_relative));
    ansiConsole.printText(_position.x + int(x_relative)- _radius/2,
                          _position.y +h,"#",
                          _color);
    ansiConsole.printText(_position.x + int(x_relative)- _radius/2,
                          _position.y -h,"#",
                          _color);

  }
}

class Rectangle : public Shape
{
    protected: 
        int _width;
        int _height;

    public:
        Rectangle();
        Rectangle(int x, int y, int width, int height);
        Rectangle(int x, int y, int width, int height, Colors color);
        void draw();
};

Rectangle::Rectangle() : Shape(0, 0, Colors::BLUE)
{
    _width = 0;
    _height = 0;
}

Rectangle::Rectangle(int x, int y, int width, int height) : Shape(x, y, Colors::BLUE)
{
    _width = width;
    _height = height;
}

Rectangle::Rectangle(int x, int y, int width, int height, Colors color) : Shape(x, y, color)
{
    _width = width;
    _height = height;
}

void Rectangle::draw()
{
    for(int x = _position.x; x <= _position.x + _width; x++)
    {
        ansiConsole.printText(x, _position.y, "#", _color);
        ansiConsole.printText(x, _position.y + _height, "#", _color);
    }

    for(int y = _position.y; y <= _position.y + _height; y++)
    {
        ansiConsole.printText(_position.x, y, "#", _color);
        ansiConsole.printText(_position.x + _width, y, "#", _color);
    }
}

class Scene
{
    protected:
        std::vector<Point *> _points;
        std::vector<Circle *> _circles;
        std::vector<Rectangle *> _rectangles;
        std::vector<Shape *> _shapes;

    public:
        Scene();
        void addShape(Shape*);
        void removeShape();

        void addPoint(Point*);
        void addCircle(Circle*);
        void addRectangle(Rectangle*);
        void drawAll();
        void removePoint();
        void removeCircle();
        void removeRectangle();
};

Scene::Scene() {}

void Scene::addShape(Shape* shape)
{
    _shapes.push_back(shape);
}

void Scene::removeShape()
{
    _shapes.pop_back();
}

void Scene::addPoint(Point * point)
{
    _points.push_back(point);
}

void Scene::addCircle(Circle* circle)
{
    _circles.push_back(circle);
}

void Scene::addRectangle(Rectangle* rectangle)
{
    _rectangles.push_back(rectangle);
}

void Scene::removePoint()
{
    _points.pop_back();
}

void Scene::removeCircle()
{
    _circles.pop_back();
}

void Scene::removeRectangle()
{
    _rectangles.pop_back();
}

void Scene::drawAll()
{
    for(int i = 0; i < (int)_shapes.size(); i++)
    {
        _shapes[i]->draw();
    }
}

int main(/*int argc, char **argv*/)
{
ansiConsole.clearScreen();
  // x=1 and y=1 is the upper left corner
  // x and y are more like column and row


  Scene* scene = new Scene();

  scene->addShape(new Circle(10, 3, 4, Colors::WHITE));
  scene->addShape(new Circle(10, 10, 8, Colors::WHITE));
  scene->addShape(new Circle(10, 21, 12, Colors::WHITE));
  scene->addShape(new Rectangle(24, 21, 11, 6, Colors::GREEN));
  scene->addShape(new Rectangle(29, 21, 1, 6, Colors::RED));

  scene->addShape(new Point(24, 10, Colors::WHITE));
  scene->addShape(new Point(27, 16, Colors::WHITE));
  scene->addShape(new Point(21, 4, Colors::WHITE));
  scene->addShape(new Point(25, 21, Colors::WHITE));
  scene->addShape(new Point(21, 6, Colors::WHITE));
  scene->addShape(new Point(30, 15, Colors::WHITE));
  scene->addShape(new Point(15, 5, Colors::WHITE));
  scene->addShape(new Point(20, 15, Colors::WHITE));
  scene->addShape(new Point(17, 7, Colors::WHITE));

  scene->drawAll();
  

  return 0;
}
