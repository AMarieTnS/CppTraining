#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap {
public:
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
  ~FragTrap() { std::cout << "FragTrap : Destructor created" << std::endl; }

  template <typename T> std::string vaulthunter_dot_exe(T const &target) {
    if (iEnergyPoints < 25) {
      std::cout << "FR4G-TP : FragTrap : " << sName
                << " try a vaulthunter_dot_exe but he has no energy"
                << std::endl;
    } else {
      iEnergyPoints -= 25;
      std::string attacks[] = {" throws a grenade at ", " shoots a laser at ",
                               " launches a rocket at ", " swings a sword at ",
                               " fires a sniper shot at "};
      std::string sAttack = attacks[rand() % 5];
      std::cout << "FR4G-TP " << sName << sAttack << target << std::endl;
    }
    return "0";
  }
};

#endif
