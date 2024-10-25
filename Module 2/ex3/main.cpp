#include "./includes/Fixed.hpp"
#include <iostream>

int main(int, char *argv[]) {
  Fixed fixed = Fixed::Expression(argv[1]);
  std::cout << fixed << std::endl;

  return 0;
}
