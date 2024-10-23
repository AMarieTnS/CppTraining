#include "./Includes/Fixed.hpp"
#include <iostream>

int main(void) {
  Fixed a;    // Constructeur
  Fixed b(a); // copie constructeur
  Fixed c;    // Constructeur
  c = b;      // constructeur = copie
  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;
  a.setRawBits(1);
  b.setRawBits(2);
  c.setRawBits(3);
  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;
  return 0;
}