#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"
#include <iostream>


class Cure : public AMateria {
public:
  Cure();
  virtual ~Cure();
  virtual AMateria *clone() const;
  virtual void use(ICharacter &target);
};

#endif