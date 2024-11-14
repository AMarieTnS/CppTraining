#ifndef AWEAPON_HPP
#define AWEAPON_HPP
#include <iostream>

class AWeapon {
private:
  std::string _name;
  int _apCost;
  int _damage;

public:
  AWeapon(std::string const &name, int apCost, int damage);
  virtual ~AWeapon() = default;
  std::string virtual getName() const;
  int getAPCost() const;
  int getDamage() const;
  virtual void attack() const = 0;
};

#endif