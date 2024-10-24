#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
  int iFixedPointValue;
  static const int iFractionalBits = 8;

public:
  Fixed();
  Fixed(const int iValue);
  Fixed(const float fValue);
  ~Fixed();
  Fixed(const Fixed &copy);
  Fixed &operator=(const Fixed &Overload);
  // Moove?
  // rule of 3, rule of 5
  // poly et surcharge

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

  bool operator>(const Fixed &Value) const;
  bool operator<(const Fixed &Value) const;
  bool operator>=(const Fixed &Value) const;
  bool operator<=(const Fixed &Value) const;
  bool operator==(const Fixed &Value) const;
  bool operator!=(const Fixed &Value) const;

  Fixed operator+(const Fixed &Value);
  Fixed operator-(const Fixed &Value);
  Fixed operator*(const Fixed &Value);
  Fixed operator/(const Fixed &Value);

  Fixed &operator++();
  Fixed operator++(int);
  Fixed &operator--();
  Fixed operator--(int);

  static Fixed &min(Fixed &ValueA, Fixed &ValueB);
  static Fixed &max(Fixed &ValueA, Fixed &ValueB);
  static const Fixed &min(const Fixed &ValueA, const Fixed &ValueB);
  static const Fixed &max(const Fixed &ValueA, const Fixed &ValueB);
};

std::ostream &operator<<(std::ostream &OutValue, const Fixed &sFixed);

#endif
