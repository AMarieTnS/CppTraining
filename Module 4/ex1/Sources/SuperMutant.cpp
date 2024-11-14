#include "SuperMutant.hpp"
#include "iostream"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant") {
  std::cout << "Gaaah. Me want smash heads!" << std::endl;
}
SuperMutant::~SuperMutant() { std::cout << "Aaargh..." << std::endl; }

SuperMutant::SuperMutant(const SuperMutant &copy) : Enemy(copy) {}

SuperMutant &SuperMutant::operator=(const SuperMutant &other) {
  if (this != &other) {
    Enemy::operator=(other);
  }
  return *this;
}