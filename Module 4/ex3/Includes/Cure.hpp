#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria {
public:
  Cure();
  ~Cure() = default;
  AMateria *clone() const override;
  void use(ICharacter &target) override;
};

#endif