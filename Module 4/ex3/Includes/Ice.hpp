#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria {
public:
  Ice();
  ~Ice() = default;
  Ice *clone() const override;
  void use(ICharacter &target) override;
};

#endif