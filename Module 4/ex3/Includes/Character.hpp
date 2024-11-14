#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <array>
#include <iostream>
#include <string>

class Character : public ICharacter {
private:
  static constexpr int INVENTORY_SIZE = 4;
  std::array<AMateria *, INVENTORY_SIZE> _inventory;
  std::string _name;

public:
  Character(std::string const &name);
  Character(Character const &copy);
  Character &operator=(Character const &other);
  ~Character();

  std::string const &getName() const override;
  void equip(AMateria *m) override;
  void unequip(int idx) override;
  void use(int idx, ICharacter &target) override;
};

#endif