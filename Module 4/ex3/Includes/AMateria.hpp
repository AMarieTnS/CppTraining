#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class AMateria {
private:
  std::string _type;
  unsigned int _xp;

public:
  AMateria(std::string const &type);
  virtual ~AMateria() = default;
  std::string const &getType() const; // Returns the materia type
  unsigned int getXP() const;         // Returns the Materia's XP
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);
};

#endif