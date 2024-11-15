#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <iostream>
#include <string>

class Conversion {
public:
  Conversion(const std::string fromString);
  void convert() const;
  void converToChar() const;
  void converToInt() const;
  void converToFloat() const;
  void converToDouble() const;

private:
  std::string _string;
};
#endif