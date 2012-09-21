/**
 * Example used in visitorExample.cpp
 *
 * @file PrintVisitor.h
 */

#include "Visitor.h"
#include <iostream>
#include "Car.h"



class PrintVisitor : public Visitor {
public:
  void visit(Wheel *wheel) {
    std::cout << "Visiting " << wheel->name << " wheel" << std::endl;
  }

  void visit(Engine *engine) {
    std::cout << "Visiting engine" << std::endl;
  }

  void visit(Body *body) {
    std::cout << "Visiting body" << std::endl;
  }

  void visit(Car *car) {
    std::cout << "Visiting car" << std::endl;
  }
};
