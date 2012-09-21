#ifndef CAR_H
#define CAR_H

#include<string>
#include<iostream>

class Visitor;


class Wheel {
public:
  std::string name;

  void accept(Visitor *visitor) {
    visitor->visit(this);
  }

  Wheel(std::string const& name_) : name(name_) {
  }
};

class Engine {
public:
  void accept(Visitor *visitor) {
    visitor->visit(this);
  }
};

class Body {
public:
  void accept(Visitor *visitor) {
    visitor->visit(this);
  }
};

class Car {
private:
  Engine *engine;
  Body *body;
  Wheel *wheels[4];

public:
  void accept(Visitor *visitor) {
    visitor->visit(this);
    engine->accept(visitor);
    body->accept(visitor);
    for (int i = 0; i < 4; i++) {
      wheels[i]->accept(visitor);
    }
  }

  Car() : engine(new Engine()), body(new Body()) {
    wheels[0] = new Wheel("front left");
    wheels[1] = new Wheel("front right");
    wheels[2] = new Wheel("back left");
    wheels[3] = new Wheel("back right");
  }

  ~Car() {
    delete engine;
    delete body;
    for (int i = 0; i < 4; i++) {
      delete wheels[i];
    }
  }
};
#endif

