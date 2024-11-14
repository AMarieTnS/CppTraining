#include "../Includes/Sorcerer.hpp"
#include "../Includes/Victim.hpp"

#include <iostream>

Sorcerer::Sorcerer(const std::string &name, const std::string &title)
    : _name(name), _title(title) {
  std::cout << name << ", " << title << ", is born!" << std::endl;
}
Sorcerer::~Sorcerer() {
  std::cout << _name << ", " << _title
            << ", is dead. Consequences will never be the same!" << std::endl;
}
Sorcerer::Sorcerer(const Sorcerer &copy)
    : _name(copy._name), _title(copy._title) {}

Sorcerer &Sorcerer::operator=(const Sorcerer &Overload) {
  if (this != &Overload) {
    _name = Overload.getName();
    _title = Overload.getTitle();
    std::cout << "I am " << _name << " , " << _title << ", and I like ponies!"
              << std::endl;
  }
  return *this;
}

std::string Sorcerer::getName() const { return _name; }
std::string Sorcerer::getTitle() const { return _title; }

void Sorcerer::polymorph(const Victim &victim) const {
  victim.getPolymorphed();
}

std::ostream &operator<<(std::ostream &out, const Sorcerer &sorcerer) {
  out << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle()
      << ", and I like ponies!" << std::endl;
  return out;
}