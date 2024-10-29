#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <iostream>

class ScavTrap {
public:
  int iHitPoints;
  int iMaxHitPoints;
  int iEnergyPoints;
  int iMaxEnergyPoints;
  int iLevel;
  std::string sName;

  int iMeleeAttackDamage;
  int iRangedAttackDamage;
  int iArmorDamageReduction;

  // default constructor
  ScavTrap()
      : iHitPoints(100), iMaxHitPoints(100), iEnergyPoints(50),
        iMaxEnergyPoints(50), iLevel(1), sName("Default ScavTrap name"),
        iMeleeAttackDamage(20), iRangedAttackDamage(15),
        iArmorDamageReduction(3) {
    std::cout << "ScavTrap : Default constructor created" << std::endl;
  }
  // constructor
  ScavTrap(std::string Name)
      : iHitPoints(100), iMaxHitPoints(100), iEnergyPoints(50),
        iMaxEnergyPoints(50), iLevel(1), sName(Name), iMeleeAttackDamage(20),
        iRangedAttackDamage(15), iArmorDamageReduction(3) {
    std::cout << "ScavTrap : Constructor created" << std::endl;
  }
  // Destructor
  ~ScavTrap() { std::cout << "ScavTrap : Destructor created" << std::endl; }
  // copy
  ScavTrap(const ScavTrap &copy)
      : iHitPoints(copy.iHitPoints), iMaxHitPoints(copy.iMaxHitPoints),
        iEnergyPoints(copy.iEnergyPoints),
        iMaxEnergyPoints(copy.iMaxEnergyPoints), iLevel(copy.iLevel),
        sName(copy.sName), iMeleeAttackDamage(copy.iMeleeAttackDamage),
        iRangedAttackDamage(copy.iRangedAttackDamage),
        iArmorDamageReduction(copy.iArmorDamageReduction) {
    std::cout << "ScavTrap : Copy created" << std::endl;
  }

  // affectation
  ScavTrap &operator=(const ScavTrap &copy) {
    if (this != &copy) {
      iHitPoints = copy.iHitPoints;
      iMaxHitPoints = copy.iMaxHitPoints;
      iEnergyPoints = copy.iEnergyPoints;
      iMaxEnergyPoints = copy.iMaxEnergyPoints;
      iLevel = copy.iLevel;
      sName = copy.sName;
      iMeleeAttackDamage = copy.iMeleeAttackDamage;
      iRangedAttackDamage = copy.iRangedAttackDamage;
      iArmorDamageReduction = copy.iArmorDamageReduction;
    }
    std::cout << "ScavTrap : Assignation created" << std::endl;

    return *this;
  }
  // move
  ScavTrap(ScavTrap &&move) noexcept
      : iHitPoints(move.iHitPoints), iMaxHitPoints(move.iMaxHitPoints),
        iEnergyPoints(move.iEnergyPoints),
        iMaxEnergyPoints(move.iMaxEnergyPoints), iLevel(move.iLevel),
        sName(move.sName), iMeleeAttackDamage(move.iMeleeAttackDamage),
        iRangedAttackDamage(move.iRangedAttackDamage),
        iArmorDamageReduction(move.iArmorDamageReduction) {
    iHitPoints = 0;
    iMaxHitPoints = 0;
    iEnergyPoints = 0;
    iMaxEnergyPoints = 0;
    iLevel = 0;
    sName = "Default name";
    iMeleeAttackDamage = 0;
    iRangedAttackDamage = 0;
    iArmorDamageReduction = 0;
    std::cout << "ScavTrap : Move" << std::endl;
  }
  // affectation move
  ScavTrap &operator=(ScavTrap &&move) noexcept {
    if (this != &move) {
      iHitPoints = move.iHitPoints;
      iMaxHitPoints = move.iMaxHitPoints;
      iEnergyPoints = move.iEnergyPoints;
      iMaxEnergyPoints = move.iMaxEnergyPoints;
      iLevel = move.iLevel;
      sName = move.sName;
      iMeleeAttackDamage = move.iMeleeAttackDamage;
      iRangedAttackDamage = move.iRangedAttackDamage;
      iArmorDamageReduction = move.iArmorDamageReduction;
    }
    std::cout << "ScavTrap : Assignation move" << std::endl;
    return *this;
  }

  void rangedAttack(std::string const &target);
  void meleeAttack(std::string const &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  std::string challengeNewcomer(std::string const &target);
};
#endif
