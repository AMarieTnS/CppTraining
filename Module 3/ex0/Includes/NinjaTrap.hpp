#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class NinjaTrap : virtual public ClapTrap {
public:
  NinjaTrap() : ClapTrap("Default Ninja name") {
    iHitPoints = 60;
    iMaxHitPoints = 60;
    iEnergyPoints = 120;
    iMaxEnergyPoints = 120;
    iLevel = 1;
    iMeleeAttackDamage = 60;
    iRangedAttackDamage = 5;
    iArmorDamageReduction = 0;
    std::cout << "NinjaTrap : Default constructor created" << std::endl;
  }

  NinjaTrap(std::string Name) : ClapTrap(Name) {
    iHitPoints = 60;
    iMaxHitPoints = 60;
    iEnergyPoints = 120;
    iMaxEnergyPoints = 120;
    iLevel = 1;
    iMeleeAttackDamage = 60;
    iRangedAttackDamage = 5;
    iArmorDamageReduction = 0;
    std::cout << "NinjaTrap : Constructor created" << std::endl;
  }

  ~NinjaTrap() { std::cout << "NinjaTrap : Destructor created" << std::endl; }

  template <typename T> void ninjaShoebox(T &target) {
    if (std::is_same_v<T, ClapTrap>) {
      std::cout << sName << " is droping a muntain on " << target.sName
                << std::endl;
    } else if (std::is_same_v<T, FragTrap>) {
      std::cout << sName << " sing for " << target.sName << std::endl;
    } else if (std::is_same_v<T, ScavTrap>) {
      std::cout << sName << " is hide in the shadow of " << target.sName
                << std::endl;
    } else if (std::is_same_v<T, NinjaTrap>) {
      std::cout << sName << " do the rasengan on " << target.sName << std::endl;
    } else {
      std::cout << sName << " Try to attack someone but can't find the person! "
                << target.sName << std::endl;
    }
  }
};
#endif