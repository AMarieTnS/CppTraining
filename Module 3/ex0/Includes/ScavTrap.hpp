#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap {
public:
  // default constructor
  ScavTrap() : ClapTrap("Default ScavTrap name") {
    iHitPoints = 100;
    iMaxHitPoints = 100;
    iEnergyPoints = 50;
    iMaxEnergyPoints = 50;
    iLevel = 1;
    iMeleeAttackDamage = 20;
    iRangedAttackDamage = 15;
    iArmorDamageReduction = 3;
    std::cout << "ScavTrap : Default constructor created" << std::endl;
  }

  // constructor
  ScavTrap(std::string Name) : ClapTrap(Name) {
    iHitPoints = 100;
    iMaxHitPoints = 100;
    iEnergyPoints = 50;
    iMaxEnergyPoints = 50;
    iLevel = 1;
    iMeleeAttackDamage = 20;
    iRangedAttackDamage = 15;
    iArmorDamageReduction = 3;
    std::cout << "ScavTrap : Constructor created" << std::endl;
  }

  // Destructor
  ~ScavTrap() { std::cout << "ScavTrap : Destructor created" << std::endl; }

  std::string challengeNewcomer(std::string const &target);
};
#endif
