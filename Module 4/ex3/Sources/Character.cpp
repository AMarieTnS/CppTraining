#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string const &name) : _name(name) {
  _inventory.fill(nullptr);
}

Character::Character(Character const &copy) : _name(copy._name) {
  for (size_t i = 0; i < _inventory.size(); ++i) {
    if (copy._inventory[i])
      _inventory[i] = copy._inventory[i]->clone();
    else
      _inventory[i] = nullptr;
  }
}

Character &Character::operator=(Character const &other) {
  if (this != &other) {
    _name = other._name;
    for (size_t i = 0; i < _inventory.size(); ++i) {
      if (_inventory[i])
        delete _inventory[i];
      if (other._inventory[i])
        _inventory[i] = other._inventory[i]->clone();
      else
        _inventory[i] = nullptr;
    }
  }
  return *this;
}

Character::~Character() {
  for (size_t i = 0; i < _inventory.size(); ++i) {
    if (_inventory[i])
      delete _inventory[i];
  }
}

std::string const &Character::getName() const { return _name; }

void Character::equip(AMateria *m) {
  for (size_t i = 0; i < _inventory.size(); ++i) {
    if (!_inventory[i]) {
      _inventory[i] = m;
      break;
    }
  }
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx < static_cast<int>(_inventory.size()))
    _inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter &target) {
  if (idx >= 0 && idx < static_cast<int>(_inventory.size()) && _inventory[idx])
    _inventory[idx]->use(target);
  std::cout << "Materia " << _inventory[idx]->getType() << " now has "
            << _inventory[idx]->getXP() << " XP." << std::endl;
}