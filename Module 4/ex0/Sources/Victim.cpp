#include "../Includes/Victim.hpp"
#include <iostream>

Victim::Victim() { std::cout << "Default constructor" << std::endl; }
Victim::Victim(const std::string &sName) : sName(sName) {
  std::cout << "Some random victim called " << sName << " just appeared!"
            << std::endl;
}
Victim::~Victim() {
  std::cout << "Victim " << sName << " just died for no apparent reason!"
            << std::endl;
}
Victim::Victim(const Victim &copy) : sName(copy.sName) {
  std::cout << "Copy assignment operator" << std::endl;
}
Victim &Victim::operator=(const Victim &Overload) {
  if (this != &Overload) {
    sName = Overload.getName();
    std::cout << "I'm " << sName << " and I like otters!" << std::endl;
  }
  return *this;
}

std::string Victim::getName() const { return sName; }

void Victim::getPolymorphed() const {
  std::cout << sName << " has been turned into a cute little sheep!"
            << std::endl;
}
std::ostream &operator<<(std::ostream &out, const Victim &victim) {
  out << "I'm " << victim.getName() << " and I like otters!" << std::endl;
  return out;
}