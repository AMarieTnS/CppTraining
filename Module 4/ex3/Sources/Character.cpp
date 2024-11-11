#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string const &sName) : sName(sName) {
  Inventory.fill(nullptr);
}
Character::Character(Character const &Copy) : sName(Copy.sName) {
  for (size_t i = 0; i < Inventory.size(); ++i) {
    if (Copy.Inventory[i])
      Inventory[i] = Copy.Inventory[i]->clone();
    else
      Inventory[i] = nullptr;
  }
}
Character &Character::operator=(Character const &Overload) {
  if (this != &Overload) {
    sName = Overload.sName;
    for (size_t i = 0; i < Inventory.size(); ++i) {
      if (Inventory[i])
        delete Inventory[i];
      if (Overload.Inventory[i])
        Inventory[i] = Overload.Inventory[i]->clone();
      else
        Inventory[i] = nullptr;
    }
  }
  return *this;
}
Character::~Character() {
  for (size_t i = 0; i < Inventory.size(); ++i) {
    if (Inventory[i])
      delete Inventory[i];
  }
}

std::string const &Character::getName() const { return sName; }

void Character::equip(AMateria *m) {
  for (size_t i = 0; i < Inventory.size(); ++i) {
    if (!Inventory[i]) {
      Inventory[i] = m;
      break;
    }
  }
}
void Character::unequip(int idx) {
  if (idx >= 0 && idx < static_cast<int>(Inventory.size()))
    Inventory[idx] = nullptr;
}
void Character::use(int idx, ICharacter &target) {
  if (idx >= 0 && idx < static_cast<int>(Inventory.size()) && Inventory[idx])
    Inventory[idx]->use(target);
}