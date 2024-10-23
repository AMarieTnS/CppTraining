#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
  Fixed();                                 // constructeur
  ~Fixed();                                // destructeur
  Fixed(const Fixed &copy);                // copie du constructeur
  Fixed &operator=(const Fixed &Overload); // opetation overload
  int getRawBits(void) const;
  void setRawBits(int const raw);

private:
  int iFixedPointValue;
  static const int iFractionalBits = 8;
};

#endif
