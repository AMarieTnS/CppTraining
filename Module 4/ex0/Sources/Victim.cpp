#include "../Includes/Victim.hpp"
#include <iostream>

Victim::Victim() { std::cout << "Default constructor" << std::endl; }
Victim::Victim(const std::string &name) : _name(name) {
  std::cout << "Some random victim called " << name << " just appeared!"
            << std::endl;
}
Victim::~Victim() {
  std::cout << "Victim " << _name << " just died for no apparent reason!"
            << std::endl;
}
Victim::Victim(const Victim &copy) : _name(copy._name) {
  std::cout << "Copy assignment operator" << std::endl;
}
Victim &Victim::operator=(const Victim &Overload) {
  if (this != &Overload) {
    _name = Overload.getName();
    std::cout << "I'm " << _name << " and I like otters!" << std::endl;
  }
  return *this;
}

std::string Victim::getName() const { return _name; }

void Victim::getPolymorphed() const {
  std::cout << _name << " has been turned into a cute little sheep!"
            << std::endl;
}
std::ostream &operator<<(std::ostream &out, const Victim &victim) {
  out << "I'm " << victim.getName() << " and I like otters!" << std::endl;
  return out;
}