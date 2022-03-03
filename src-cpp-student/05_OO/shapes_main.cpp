#include <iostream>
#include <cmath>
#include <vector>
#include "AnsiConsole.h"

struct Position{
  int x;
  int y;
  Position(int x_=0, int y_=0){ x=x_;y=y_;}
};

class Point{
protected:
  Position _position;
public:
  Point();
  Point(int x, int y);
  void draw();
};

Point::Point(){
  _position = Position(0,0);
}

Point::Point(int x, int y){
  _position = Position(x,y);
}

void Point::draw(){
  ansiConsole.printText(_position.x,_position.y,"*", Colors::RED);
}

class Circle{
protected:
  Position  _position;
  int       _radius;
public:
  Circle();
  Circle(int x, int y, int radius);
  void draw();
};

Circle::Circle(){
  _position = Position(0,0);
  _radius=0;
}

Circle::Circle(int x, int y, int radius){
  _position = Position(x,y);
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
                          Colors::GREEN);
    ansiConsole.printText(_position.x + int(x_relative)- _radius/2,
                          _position.y -h,"#",
                          Colors::GREEN);

  }
}

int main(/*int argc, char **argv*/)
{
  ansiConsole.clearScreen();
  // x=1 and y=1 is the upper left corner
  // x and y are more like column and row
  ansiConsole.printText(5,5,"Hello, World!");

  Circle* c = new Circle(30, 15, 10);
  c->draw();

  std::vector<Point *> manyPoints;
  Point* p = new Point(10,10);
  manyPoints.push_back(p);
  
  Point* p2 = new Point(2,10);
  manyPoints.push_back(p2);

  manyPoints.push_back(new Point(30,15));

  // let's draw the points!
  for (size_t i=0; i<manyPoints.size();i++){
    manyPoints[i]->draw();
  }
  

  // delete unused objects
  for (size_t i=0; i<manyPoints.size();i++){
    delete manyPoints[i];
  }
  
  delete c;

  return 0;
}
