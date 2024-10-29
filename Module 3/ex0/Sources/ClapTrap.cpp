#include "../Includes/ClapTrap.hpp"
#include <iostream>

void ClapTrap::rangedAttack(std::string const &target) {
  std::cout << "FR4G-TP : ClapTrap : " << sName << " attacks " << target
            << " at range, causing " << iRangedAttackDamage
            << " points of damage!" << std::endl;
}

void ClapTrap::meleeAttack(std::string const &target) {
  std::cout << "FR4G-TP : ClapTrap : " << sName << " attacks " << target
            << " at melee, causing " << iMeleeAttackDamage
            << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  int damage = amount - iArmorDamageReduction;
  if (damage < 0) {
    damage = 0;
  }
  iHitPoints -= damage;
  if (iHitPoints <= 0) {
    iHitPoints = 0;
  }
  std::cout << "FR4G-TP : ClapTrap : " << sName << " takes " << damage
            << " points of damage! Current HP: " << iHitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  iHitPoints += amount;
  if (iHitPoints > iMaxHitPoints) {
    iEnergyPoints = iMaxHitPoints;
  }
  std::cout << "FR4G-TP : ClapTrap : " << sName << " has repaired " << amount
            << " points! Current HP: " << iHitPoints << std::endl;
}
