#include "../Includes/Fixed.hpp"
#include <iostream>

Fixed::Fixed() : iFixedPointValue(0) {
  std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }
Fixed::Fixed(const Fixed &copy) {
  std::cout << "Copy constructor called" << std::endl;
  *this = copy;
}
Fixed &Fixed::operator=(const Fixed &Overload) {
  std::cout << "Assignation operator called" << std::endl;
  this->iFixedPointValue = Overload.getRawBits();
  return *this;
}
int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->iFixedPointValue;
}
void Fixed::setRawBits(int const raw) { this->iFixedPointValue = raw; }