#ifndef SUPERMUTAN_HPP
#define SUPERMUTAN_HPP
#include "Enemy.hpp"

class SuperMutant : public Enemy {
public:
  SuperMutant();
  ~SuperMutant();
  SuperMutant(const SuperMutant &copy);
  SuperMutant &operator=(const SuperMutant &other);
};
#endif