#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <array>
#include <iostream>
#include <string>


class Character : public ICharacter {
private:
  std::array<AMateria *, 4> Inventory;
  std::string sName;

public:
  Character(std::string const &sName);
  Character(Character const &Copy);
  Character &operator=(Character const &Overload);
  virtual ~Character();

  std::string const &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
};

#endif