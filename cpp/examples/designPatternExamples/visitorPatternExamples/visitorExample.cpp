/**
 * Example illustrates use of visitor pattern
 *
 * @file visitorExample.cpp
 */

#include <iostream>
#include "PrintVisitor.h"
#include "Car.h"

int main() {
  Car car;
  PrintVisitor visitor;
  car.accept(&visitor);
  return 0;
}