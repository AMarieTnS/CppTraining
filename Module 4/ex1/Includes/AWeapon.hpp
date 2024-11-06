#ifndef AWEAPON_HPP
#define AWEAPON_HPP
#include <iostream>

class AWeapon {
private:
  std::string sName;
  int iApcost;
  int iDamage;

public:
  AWeapon(std::string const &sName, int iApcost, int iDamage);
  virtual ~AWeapon();
  std::string virtual getName() const;
  int getAPCost() const;
  int getDamage() const;
  virtual void attack() const = 0;
};

#endif