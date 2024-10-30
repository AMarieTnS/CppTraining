#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap {
public:
  // default constructor
  FragTrap() : ClapTrap("Default FragTrap name") {
    iHitPoints = 100;
    iMaxHitPoints = 100;
    iEnergyPoints = 100;
    iMaxEnergyPoints = 100;
    iLevel = 1;
    iMeleeAttackDamage = 30;
    iRangedAttackDamage = 20;
    iArmorDamageReduction = 5;
    std::cout << "FragTrap : Default constructor created" << std::endl;
  }
  // constructor
  FragTrap(std::string Name) : ClapTrap(Name) {
    iHitPoints = 100;
    iMaxHitPoints = 100;
    iEnergyPoints = 100;
    iMaxEnergyPoints = 100;
    iLevel = 1;
    iMeleeAttackDamage = 30;
    iRangedAttackDamage = 20;
    iArmorDamageReduction = 5;
    std::cout << "FragTrap : Constructor created" << std::endl;
  }
  // Destructor
  ~FragTrap() { std::cout << "FragTrap : Destructor created" << std::endl; }

  std::string vaulthunter_dot_exe(std::string const &target);
};
#endif
