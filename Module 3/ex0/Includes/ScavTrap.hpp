#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap {
public:
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

  ~ScavTrap() { std::cout << "ScavTrap : Destructor created" << std::endl; }

  template <typename T> std::string challengeNewcomer(T const &target) {
    std::string Challenge[] = {" dice roll ", " rock paper scissors ",
                               " olive throw ", " MMA match ",
                               " duel of gazes "};
    std::string sChallenge = Challenge[rand() % 5];
    std::cout << "FR4G-TP : ScavTrap : " << sName << " Challengs " << target
              << " to a " << sChallenge << std::endl;
    return "0";
  }
};
#endif
