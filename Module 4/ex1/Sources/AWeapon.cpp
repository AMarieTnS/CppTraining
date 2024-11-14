#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &name, int apCost, int damage)
    : _name(name), _apCost(apCost), _damage(damage) {}
std::string AWeapon::getName() const { return _name; }
int AWeapon::getAPCost() const { return _apCost; }
int AWeapon::getDamage() const { return _damage; }
