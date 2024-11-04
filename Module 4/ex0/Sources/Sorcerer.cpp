#include "../Includes/Sorcerer.hpp"
#include "../Includes/Victim.hpp"

#include <iostream>

Sorcerer::Sorcerer() { std::cout << "Default constructor" << std::endl; }
Sorcerer::Sorcerer(const std::string &sName, const std::string &sTitle)
    : sName(sName), sTitle(sTitle) {
  std::cout << sName << ", " << sTitle << ", is born!" << std::endl;
}
Sorcerer::~Sorcerer() {
  std::cout << sName << ", " << sTitle
            << ", is dead. Consequences will never be the same!" << std::endl;
}
Sorcerer::Sorcerer(const Sorcerer &copy)
    : sName(copy.sName), sTitle(copy.sTitle) {
  std::cout << "Copy assignment operator" << std::endl;
}

Sorcerer &Sorcerer::operator=(const Sorcerer &Overload) {
  if (this != &Overload) {
    sName = Overload.getName();
    sTitle = Overload.getTitle();
    std::cout << "I am " << sName << " , " << sTitle << ", and I like ponies!"
              << std::endl;
  }
  return *this;
}

std::string Sorcerer::getName() const { return sName; }
std::string Sorcerer::getTitle() const { return sTitle; }
void Sorcerer::setName(std::string const sNewName) { this->sName = sNewName; }
void Sorcerer::setTitle(std::string const sNewTitle) {
  this->sTitle = sNewTitle;
}

void Sorcerer::polymorph(const Victim &victim) const {
  victim.getPolymorphed();
}

std::ostream &operator<<(std::ostream &out, const Sorcerer &sorcerer) {
  out << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle()
      << ", and I like ponies!" << std::endl;
  return out;
}
