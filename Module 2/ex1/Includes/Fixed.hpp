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

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream &operator<<(std::ostream &OutValue, const Fixed &sFixed);

#endif
