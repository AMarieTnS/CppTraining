#include "../Includes/Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : iFixedPointValue(0) {}
Fixed::Fixed(const int iValue) { iFixedPointValue = iValue << iFractionalBits; }
Fixed::Fixed(const float fValue) {
  iFixedPointValue = roundf(fValue * (1 << iFractionalBits));
}
Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &copy) { *this = copy; }
Fixed &Fixed::operator=(const Fixed &Overload) {
  this->iFixedPointValue = Overload.getRawBits();
  return *this;
}
int Fixed::getRawBits(void) const { return this->iFixedPointValue; }
void Fixed::setRawBits(int const raw) { this->iFixedPointValue = raw; }

float Fixed::toFloat(void) const {
  return static_cast<float>(iFixedPointValue) / (1 << iFractionalBits);
}
int Fixed::toInt(void) const { return iFixedPointValue >> iFractionalBits; }

std::ostream &operator<<(std::ostream &OutValue, const Fixed &sFixed) {
  OutValue << sFixed.toFloat();
  return OutValue;
}

bool Fixed::operator>(const Fixed &Value) const {
  return this->iFixedPointValue > Value.getRawBits();
}
bool Fixed::operator<(const Fixed &Value) const {
  return this->iFixedPointValue < Value.getRawBits();
}
bool Fixed::operator>=(const Fixed &Value) const {
  return this->iFixedPointValue >= Value.getRawBits();
}
bool Fixed::operator<=(const Fixed &Value) const {
  return this->iFixedPointValue <= Value.getRawBits();
}
bool Fixed::operator==(const Fixed &Value) const {
  return this->iFixedPointValue == Value.getRawBits();
}
bool Fixed::operator!=(const Fixed &Value) const {
  return this->iFixedPointValue != Value.getRawBits();
}

Fixed Fixed::operator+(const Fixed &Value) {
  return Fixed(toFloat() + Value.toFloat());
}
Fixed Fixed::operator-(const Fixed &Value) {
  return Fixed(toFloat() - Value.toFloat());
}
Fixed Fixed::operator*(const Fixed &Value) {
  return Fixed(toFloat() * Value.toFloat());
}
Fixed Fixed::operator/(const Fixed &Value) {
  return Fixed(toFloat() / Value.toFloat());
}

Fixed &Fixed::operator++() {
  iFixedPointValue++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp = *this;
  ++iFixedPointValue;
  return temp;
}

Fixed &Fixed::operator--() {
  iFixedPointValue--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed temp = *this;
  --iFixedPointValue;
  return temp;
}

Fixed &Fixed::min(Fixed &ValueA, Fixed &ValueB) {
  Fixed *MinValue = &ValueA;
  if (ValueA > ValueB) {
    MinValue = &ValueB;
  }
  return *MinValue;
}

Fixed &Fixed::max(Fixed &ValueA, Fixed &ValueB) {
  Fixed *MaxValue = &ValueA;
  if (ValueA < ValueB) {
    MaxValue = &ValueB;
  }
  return *MaxValue;
}

const Fixed &Fixed::min(const Fixed &ValueA, const Fixed &ValueB) {
  Fixed const *MinValue = &ValueA;
  if (ValueA > ValueB) {
    MinValue = &ValueB;
  }
  return *MinValue;
}

const Fixed &Fixed::max(const Fixed &ValueA, const Fixed &ValueB) {
  Fixed const *MaxValue = &ValueA;
  if (ValueA < ValueB) {
    MaxValue = &ValueB;
  }
  return *MaxValue;
}