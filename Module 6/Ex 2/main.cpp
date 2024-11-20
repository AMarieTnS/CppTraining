#include "Base.hpp"
#include "ClassA.hpp"
#include "ClassB.hpp"
#include "ClassC.hpp"
#include "Generate.hpp"
#include "Identify.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>

int main() {
  std::srand(std::time(0));

  std::unique_ptr<Base> base = generate();

  std::cout << "Identify from pointer: ";
  identify_from_pointer(base);

  std::cout << "Identify from reference: ";
  identify_from_reference(*base);

  return 0;
}
