#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &sName, int iApcost, int iDamage)
    : sName(sName), iApcost(iApcost), iDamage(iDamage) {}
AWeapon::~AWeapon() {}
std::string AWeapon::getName() const { return sName; }
int AWeapon::getAPCost() const { return iApcost; }
int AWeapon::getDamage() const { return iDamage; }
