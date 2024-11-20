#include "Base.hpp"
#include "ClassA.hpp"
#include "ClassB.hpp"
#include "ClassC.hpp"
#include <iostream>
#include <string>
#include <memory>
void identify_from_pointer(std::unique_ptr<Base> &p)
{
  if (dynamic_cast<ClassA *>(p.get()))
  {
    std::cout << "A" << std::endl;
  }
  else if (dynamic_cast<ClassB *>(p.get()))
  {
    std::cout << "B" << std::endl;
  }
  else if (dynamic_cast<ClassC *>(p.get()))
  {
    std::cout << "C" << std::endl;
  }
  else
    std::cout << "ERROR POINTER" << std::endl;
}

void identify_from_reference(Base &p) {
  try {
    dynamic_cast<ClassA &>(p);
    std::cout << "A" << std::endl;
  } catch (const std::exception &e) {
  }

  try {
    dynamic_cast<ClassB &>(p);
    std::cout << "B" << std::endl;
  } catch (const std::exception &e) {
  }

  try {
    dynamic_cast<ClassC &>(p);
    std::cout << "C" << std::endl;
  } catch (const std::exception &e) {
  }
}