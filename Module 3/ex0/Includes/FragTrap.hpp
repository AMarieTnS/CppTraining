#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include <iostream>

class FragTrap {
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
  FragTrap()
      : iHitPoints(100), iMaxHitPoints(100), iEnergyPoints(100),
        iMaxEnergyPoints(100), iLevel(1), sName("Default FragTrap name"),
        iMeleeAttackDamage(30), iRangedAttackDamage(20),
        iArmorDamageReduction(5) {
    std::cout << "Default constructor created" << std::endl;
  }
  // constructor
  FragTrap(std::string Name)
      : iHitPoints(100), iMaxHitPoints(100), iEnergyPoints(100),
        iMaxEnergyPoints(100), iLevel(1), sName(Name), iMeleeAttackDamage(30),
        iRangedAttackDamage(20), iArmorDamageReduction(5) {
    std::cout << "Constructor created" << std::endl;
  }
  // Destructor
  ~FragTrap() { std::cout << "Destructor created" << std::endl; }
  // copy
  FragTrap(const FragTrap &copy)
      : iHitPoints(copy.iHitPoints), iMaxHitPoints(copy.iMaxHitPoints),
        iEnergyPoints(copy.iEnergyPoints),
        iMaxEnergyPoints(copy.iMaxEnergyPoints), iLevel(copy.iLevel),
        sName(copy.sName), iMeleeAttackDamage(copy.iMeleeAttackDamage),
        iRangedAttackDamage(copy.iRangedAttackDamage),
        iArmorDamageReduction(copy.iArmorDamageReduction) {
    std::cout << "Copy created" << std::endl;
  }

  // affectation
  FragTrap &operator=(const FragTrap &copy) {
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
    std::cout << "Assignation created" << std::endl;

    return *this;
  }
  // move
  FragTrap(FragTrap &&move) noexcept
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
    std::cout << "Move" << std::endl;
  }
  // affectation move
  FragTrap &operator=(FragTrap &&move) noexcept {
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
    std::cout << "Assignation move" << std::endl;
    return *this;
  }

  void rangedAttack(std::string const &target);
  void meleeAttack(std::string const &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  std::string vaulthunter_dot_exe(std::string const &target);
};
#endif
