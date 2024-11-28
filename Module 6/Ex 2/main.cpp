#include "generate.hpp"
#include "identify.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>

int main() {
  std::srand(std::time(0));

  std::unique_ptr<VariantBase> base = generate();

  std::cout << "Identify from pointer: ";
  identify_from_pointer(base);

  std::cout << "Identify from reference: ";
  identify_from_reference(*base);

  return 0;
}