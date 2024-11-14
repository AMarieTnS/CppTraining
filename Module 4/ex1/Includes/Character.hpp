#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AWeapon.hpp"
#include "Enemy.hpp"
#include <iostream>

class Character {
public:
  Character(const std::string &name);
  ~Character() = default;

  void recoverAP();
  void equip(AWeapon *newWeapon);
  void attack(Enemy *enemy);

  std::string getName() const;
  int getAP() const;
  AWeapon *getWeapon() const;

private:
  std::string _name;
  int _ap;
  AWeapon *_weapon;
};
std::ostream &operator<<(std::ostream &out, const Character &character);

#endif