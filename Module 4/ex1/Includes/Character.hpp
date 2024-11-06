#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AWeapon.hpp"
#include "Enemy.hpp"
#include <iostream>

class Character {
private:
  std::string sName;
  int iAP;
  AWeapon *Weapon;

public:
  Character(std::string const &sName);
  virtual ~Character();
  void recoverAP();
  void equip(AWeapon *Weapon);
  void attack(Enemy *Enemy);
  std::string virtual getName() const;
  int virtual getAP() const;
  AWeapon *getWeapon() const;
};
std::ostream &operator<<(std::ostream &out, const Character &Character);

#endif