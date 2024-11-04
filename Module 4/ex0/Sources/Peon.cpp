#include "../Includes/Peon.hpp"
#include <iostream>

Peon::Peon(const std::string &sName) : Victim(sName) {
  std::cout << "Zog zog." << std::endl;
}
Peon::~Peon() { std::cout << "Bleuark..." << std::endl; }
Peon::Peon(const Peon &copy) : Victim(copy) {}
Peon &Peon::operator=(const Peon &Overload) {
  if (this != &Overload) {
    Victim::operator=(Overload);
  }
  return *this;
}

void Peon::getPolymorphed() const {
  std::cout << getName() << " has been turned into a pink pony!" << std::endl;
}