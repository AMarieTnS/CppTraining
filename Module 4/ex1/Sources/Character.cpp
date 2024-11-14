#include "Character.hpp"

Character::Character(const std::string &name)
    : _name(name), _ap(40), _weapon(nullptr) {}

void Character::recoverAP() {
  _ap += 10;
  if (_ap > 40)
    _ap = 40;
}

void Character::equip(AWeapon *newWeapon) { _weapon = newWeapon; }

void Character::attack(Enemy *enemy) {
  if ((_ap - _weapon->getAPCost() < 0) || (_weapon == nullptr)) {
    std::cout << "No attack!" << std::endl;
  } else {
    std::cout << _name << " attacks " << enemy->getType() << " with a "
              << _weapon->getName() << std::endl;
    _weapon->attack();
    enemy->takeDamage(_weapon->getDamage());
    _ap -= _weapon->getAPCost();
  }
}

std::string Character::getName() const { return _name; }

int Character::getAP() const { return _ap; }

AWeapon *Character::getWeapon() const { return _weapon; }

std::ostream &operator<<(std::ostream &out, const Character &character) {
  if (character.getWeapon()) {
    out << character.getName() << " has " << character.getAP()
        << " AP and wields a " << character.getWeapon()->getName() << std::endl;
  } else {
    out << character.getName() << " has " << character.getAP()
        << " AP and is unarmed" << std::endl;
  }
  return out;
}