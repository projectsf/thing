/**
 * Example used in visitorExample.cpp
 *
 * @file Visitor.h
 */

 
class Wheel;
class Engine;
class Body;
class Car;


class Visitor {
  public:
    virtual void visit(Wheel *wheel) = 0;
    virtual void visit(Engine *engine) = 0;
    virtual void visit(Body *body) = 0;
    virtual void visit(Car *car) = 0;
};