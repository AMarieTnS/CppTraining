#include "Conversion.hpp"
#include <iomanip>
#include <iostream>
#include <string.h>

Conversion::Conversion(const std::string fromString) : _string(fromString) {}
void Conversion::convert() const {
  converToChar();
  converToInt();
  converToFloat();
  converToDouble();
}

void Conversion::converToChar() const {
  try {
    if (isprint(std::stoi(_string))) {
      std::cout << "char: '" << static_cast<char>(std::stoi(_string)) << "'"
                << std::endl;
    } else {
      std::cerr << "char: Non displayable" << std::endl;
    }
  } catch (const std::exception &e) {
    std::cerr << "char: impossible" << std::endl;
  }
}

void Conversion::converToInt() const {
  try {
    std::cout << "int : " << stoi(_string) << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "impossible" << std::endl;
  }
}

void Conversion::converToFloat() const {
  try {
    std::cout << "float : " << std::fixed << std::setprecision(1)
              << static_cast<float>(stoi(_string)) << "f" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "nanf" << std::endl;
  }
}

void Conversion::converToDouble() const {
  try {
    std::cout << "string as double = " << static_cast<double>(stoi(_string))
              << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "nan" << std::endl;
  }
}
