#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria {
private:
  std::string sName;

public:
  Ice();
  virtual ~Ice();
  virtual AMateria *clone() const;
  virtual void use(ICharacter &target);
};

#endif