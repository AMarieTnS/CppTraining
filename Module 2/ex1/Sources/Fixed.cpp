#include "../Includes/Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : iFixedPointValue(0) {
  std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int iValue) {
  std::cout << "Int constructor called" << std::endl;
  iFixedPointValue = iValue << iFractionalBits;
}
Fixed::Fixed(const float fValue) {
  std::cout << "Float constructor called" << std::endl;
  iFixedPointValue = roundf(fValue * (1 << iFractionalBits));
  ;
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

float Fixed::toFloat(void) const {
  return static_cast<float>(iFixedPointValue) / (1 << iFractionalBits);
}
int Fixed::toInt(void) const { return iFixedPointValue >> iFractionalBits; }

std::ostream &operator<<(std::ostream &OutValue, const Fixed &sFixed) {
  OutValue << sFixed.toFloat();
  return OutValue;
}