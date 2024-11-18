#include "Base.hpp"
#include "ClassA.hpp"
#include "ClassB.hpp"
#include "ClassC.hpp"
#include <iostream>
#include <string>

Base *generate(void) {
  int randomInstanciates = rand() % 3;
  switch (randomInstanciates) {
  case 0:
    return new ClassA();
  case 1:
    return new ClassB();
  case 2:
    return new ClassC();
  default:
    return nullptr;
  }
}
