#include "Base.hpp"
#include "ClassA.hpp"
#include "ClassB.hpp"
#include "ClassC.hpp"
#include <iostream>
#include <string>
#include <memory>

std::unique_ptr<Base> generate(void)
{
  int randomInstanciates = rand() % 3;
  switch (randomInstanciates) {
  case 0:
    return std::make_unique<ClassA>();
  case 1:
    return std::make_unique<ClassB>();
  case 2:
    return std::make_unique<ClassC>();
  default:
    return nullptr;
  }
}