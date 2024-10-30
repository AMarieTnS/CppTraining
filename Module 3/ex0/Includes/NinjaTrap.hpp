#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class NinjaTrap : virtual public ClapTrap {
public:
  // default constructor
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

  // constructor
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

  // Destructor
  ~NinjaTrap() { std::cout << "NinjaTrap : Destructor created" << std::endl; }

  void ninjaShoebox(ClapTrap &target);
  void ninjaShoebox(FragTrap &target);
  void ninjaShoebox(ScavTrap &target);
  void ninjaShoebox(NinjaTrap &target);
};
#endif
