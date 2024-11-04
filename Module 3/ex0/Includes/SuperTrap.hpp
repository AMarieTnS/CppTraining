#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include <iostream>

class SuperTrap : public FragTrap, public NinjaTrap {
public:
  SuperTrap() : ClapTrap(sName), FragTrap(sName), NinjaTrap(sName) {
    iHitPoints = FragTrap::iHitPoints;
    iMaxHitPoints = FragTrap::iMaxHitPoints;
    iEnergyPoints = NinjaTrap::iEnergyPoints;
    iMaxEnergyPoints = NinjaTrap::iMaxEnergyPoints;
    iLevel = 1;
    iMeleeAttackDamage = NinjaTrap::iMeleeAttackDamage;
    iRangedAttackDamage = FragTrap::iRangedAttackDamage;
    iArmorDamageReduction = FragTrap::iArmorDamageReduction;
    std::cout << "SuperTrap : Default constructor created" << std::endl;
  }
  SuperTrap(std::string sName)
      : ClapTrap(sName), FragTrap(sName), NinjaTrap(sName) {
    iHitPoints = FragTrap::iHitPoints;
    iMaxHitPoints = FragTrap::iMaxHitPoints;
    iEnergyPoints = NinjaTrap::iEnergyPoints;
    iMaxEnergyPoints = FragTrap::iMaxEnergyPoints;
    iLevel = 1;
    iMeleeAttackDamage = FragTrap::iMeleeAttackDamage;
    iRangedAttackDamage = FragTrap::iRangedAttackDamage;
    iArmorDamageReduction = FragTrap::iArmorDamageReduction;
    std::cout << "SuperTrap : Constructor created" << std::endl;
  }
  ~SuperTrap() { std::cout << "SuperTrap : Destructor created" << std::endl; }

  using ClapTrap::meleeAttack;
  using ClapTrap::rangedAttack;
  using FragTrap::vaulthunter_dot_exe;
  using NinjaTrap::ninjaShoebox;
};
#endif
