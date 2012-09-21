#include<string>
#include<iostream>

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

int main() {
  Car car;
  PrintVisitor visitor;
  car.accept(&visitor);
  return 0;
}