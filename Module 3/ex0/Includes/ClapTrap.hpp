#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap {
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
  ClapTrap()
      : iHitPoints(100), iMaxHitPoints(100), iEnergyPoints(100),
        iMaxEnergyPoints(100), iLevel(1), sName("Default ClapTrap name"),
        iMeleeAttackDamage(30), iRangedAttackDamage(20),
        iArmorDamageReduction(5) {
    std::cout << "ClapTrap : Default constructor created" << std::endl;
  }
  // constructor
  ClapTrap(std::string Name)
      : iHitPoints(100), iMaxHitPoints(100), iEnergyPoints(100),
        iMaxEnergyPoints(100), iLevel(1), sName(Name), iMeleeAttackDamage(30),
        iRangedAttackDamage(20), iArmorDamageReduction(5) {
    std::cout << "ClapTrap : Constructor created" << std::endl;
  }
  // Destructor
  ~ClapTrap() { std::cout << "ClapTrap : Destructor created" << std::endl; }
  // copy
  ClapTrap(const ClapTrap &copy)
      : iHitPoints(copy.iHitPoints), iMaxHitPoints(copy.iMaxHitPoints),
        iEnergyPoints(copy.iEnergyPoints),
        iMaxEnergyPoints(copy.iMaxEnergyPoints), iLevel(copy.iLevel),
        sName(copy.sName), iMeleeAttackDamage(copy.iMeleeAttackDamage),
        iRangedAttackDamage(copy.iRangedAttackDamage),
        iArmorDamageReduction(copy.iArmorDamageReduction) {
    std::cout << "ClapTrap : Copy created" << std::endl;
  }

  // affectation
  ClapTrap &operator=(const ClapTrap &copy) {
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
    std::cout << "ClapTrap : Assignation created" << std::endl;

    return *this;
  }
  // move
  ClapTrap(ClapTrap &&move) noexcept
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
    std::cout << "ClapTrap : Move" << std::endl;
  }
  // affectation move
  ClapTrap &operator=(ClapTrap &&move) noexcept {
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
      move.iHitPoints = 0;
      move.iMaxHitPoints = 0;
      move.iEnergyPoints = 0;
      move.iMaxEnergyPoints = 0;
      move.iLevel = 0;
      move.iMeleeAttackDamage = 0;
      move.iRangedAttackDamage = 0;
      move.iArmorDamageReduction = 0;
    }
    std::cout << "ClapTrap : Assignation move" << std::endl;
    return *this;
  }

  template <typename T> void rangedAttack(T const &target) {
    std::cout << "FR4G-TP : ClapTrap : " << sName << " attacks " << target
              << " at range, causing " << iRangedAttackDamage
              << " points of damage! Current HP: " << iHitPoints << std::endl;
  }

  template <typename T> void meleeAttack(T const &target) {
    std::cout << "FR4G-TP : ClapTrap : " << sName << " attacks " << target
              << " at melee, causing " << iMeleeAttackDamage
              << " points of damage! Current HP: " << iHitPoints << std::endl;
  }

  template <typename T> void takeDamage(T amount) {
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

  template <typename T> void beRepaired(T amount) {
    iHitPoints += amount;
    if (iHitPoints > iMaxHitPoints) {
      iHitPoints = iMaxHitPoints;
    }
    std::cout << "FR4G-TP : ClapTrap : " << sName << " has repaired " << amount
              << " points! Current HP: " << iHitPoints << std::endl;
  }
};
#endif
