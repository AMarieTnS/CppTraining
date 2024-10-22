#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
  Fixed() : value(0) {}
  ~Fixed() { delete value; }
  Fixed(const Fixed &copy) : value(new int(*copy.value)) {}
  Fixed &operator=(const Fixed &Fixed);
  int getRawBits(void) const;
  void setRawBits(int const raw);

private:
  int *value;
  static const int iFractionalBits = 8;
};

#endif
