#include "../Includes/FragTrap.hpp"
#include <iostream>

void FragTrap::rangedAttack(std::string const &target) {
  std::cout << "FR4G-TP : FragTrap : " << sName << " attacks " << target
            << " at range, causing " << iRangedAttackDamage
            << " points of damage!" << std::endl;
}

void FragTrap::meleeAttack(std::string const &target) {
  std::cout << "FR4G-TP : FragTrap : " << sName << " attacks " << target
            << " at melee, causing " << iMeleeAttackDamage
            << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
  int damage = amount - iArmorDamageReduction;
  if (damage < 0) {
    damage = 0;
  }
  iHitPoints -= damage;
  if (iHitPoints <= 0) {
    iHitPoints = 0;
  }
  std::cout << "FR4G-TP : FragTrap : " << sName << " takes " << damage
            << " points of damage! Current HP: " << iHitPoints << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
  iHitPoints += amount;
  if (iHitPoints > iMaxHitPoints) {
    iEnergyPoints = iMaxHitPoints;
  }
  std::cout << "FR4G-TP : FragTrap : " << sName << " has repaired " << amount
            << " points! Current HP: " << iHitPoints << std::endl;
}

std::string FragTrap::vaulthunter_dot_exe(std::string const &target) {
  if (iEnergyPoints < 25) {
    std::cout << "FR4G-TP : FragTrap : " << sName
              << " try a vaulthunter_dot_exe but he has no energy" << std::endl;
  } else {
    iEnergyPoints -= 25;
    if (iEnergyPoints >= 25) {
      std::string attacks[] = {" throws a grenade at ", " shoots a laser at ",
                               " launches a rocket at ", " swings a sword at ",
                               " fires a sniper shot at "};
      std::string sAttack = attacks[rand() % 5];
      std::cout << "FR4G-TP " << sName << sAttack << target << std::endl;
    }
  }
  return "0";
}
