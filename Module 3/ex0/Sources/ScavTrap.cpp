#include "../Includes/ScavTrap.hpp"
#include <iostream>

void ScavTrap::rangedAttack(std::string const &target) {
  std::cout << "FR4G-TP : ScavTrap : " << sName << " attacks " << target
            << " at range, causing " << iRangedAttackDamage
            << " points of damage!" << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target) {
  std::cout << "FR4G-TP : ScavTrap : " << sName << " attacks " << target
            << " at melee, causing " << iMeleeAttackDamage
            << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
  int damage = amount - iArmorDamageReduction;
  if (damage < 0) {
    damage = 0;
  }
  iHitPoints -= damage;
  if (iHitPoints <= 0) {
    iHitPoints = 0;
  }
  std::cout << "FR4G-TP : ScavTrap : " << sName << " takes " << damage
            << " points of damage! Current HP: " << iHitPoints << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
  iHitPoints += amount;
  if (iHitPoints > iMaxHitPoints) {
    iEnergyPoints = iMaxHitPoints;
  }
  std::cout << "FR4G-TP : ScavTrap : " << sName << " has repaired " << amount
            << " points! Current HP: " << iHitPoints << std::endl;
}

std::string ScavTrap::challengeNewcomer(std::string const &target) {
  std::string Challenge[] = {" dice roll ", " rock paper scissors ",
                             " olive throw ", " MMA match ", " duel of gazes "};
  std::string sChallenge = Challenge[rand() % 5];
  std::cout << "FR4G-TP : ScavTrap : " << sName << " Challengs " << target
            << " to a " << sChallenge << std::endl;
  return "0";
}
