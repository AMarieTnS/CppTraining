#include "Character.hpp"

Character::Character(std::string const &sName)
    : sName(sName), iAP(40), Weapon(nullptr) {}
Character::~Character() {}
void Character::recoverAP() {
  iAP += 10;
  if (iAP > 40)
    iAP = 40;
}
void Character::equip(AWeapon *NeyWeapon) { Weapon = NeyWeapon; }
void Character::attack(Enemy *Enemy) {
  if (iAP - Weapon->getAPCost() < 0 || !Weapon) {
    std::cout << "No attack !" << std::endl;
  } else {
    std::cout << this->sName << " attacks " << Enemy->getType() << " with a "
              << Weapon->getName() << std::endl;
    this->Weapon->attack();
    Enemy->takeDamage(Weapon->getDamage());
    this->iAP -= Weapon->getAPCost();
  }
  if (Enemy->getHP() < 0) {
    delete Enemy;
  }
}

std::string Character::getName() const { return sName; }
int Character::getAP() const { return iAP; }
AWeapon *Character::getWeapon() const { return Weapon; }

std::ostream &operator<<(std::ostream &out, const Character &Character) {
  if (Character.getWeapon()) {
    std::cout << Character.getName() << " has " << Character.getAP()
              << " AP and wields a " << Character.getWeapon()->getName()
              << std::endl;
  } else {
    std::cout << Character.getName() << " has " << Character.getAP()
              << " AP and is unarmed" << std::endl;
  }
  return out;
}
