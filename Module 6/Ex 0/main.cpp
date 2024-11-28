#include "Conversion.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
    return 1;
  }
  Conversion conversion(argv[1]);
  conversion.convert();
  return 0;
}