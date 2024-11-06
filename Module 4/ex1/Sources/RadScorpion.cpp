#include "RadScorpion.hpp"
#include <iostream>

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion") {
  std::cout << "click click click" << std::endl;
}
RadScorpion::~RadScorpion() { std::cout << "* SPROTCH *" << std::endl; }

RadScorpion::RadScorpion(const RadScorpion &copy) : Enemy(copy) {}

RadScorpion &RadScorpion::operator=(const RadScorpion &Overload) {
  if (this != &Overload) {
    Enemy::operator=(Overload);
  }
  return *this;
}

void RadScorpion::Attack() const {
  std::cout << "piouuu piouuu piouuu" << std::endl;
}
