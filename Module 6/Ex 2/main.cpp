#include "Base.hpp"
#include "ClassA.hpp"
#include "ClassB.hpp"
#include "ClassC.hpp"
#include "Generate.hpp"
#include "Identify.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  std::srand(std::time(0));

  Base *base = generate();

  std::cout << "Identify from pointer: ";
  identify_from_pointer(base);

  std::cout << "Identify from reference: ";
  identify_from_reference(*base);

  delete base;
  return 0;
}
