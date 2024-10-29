#include "../Includes/FragTrap.hpp"
#include <iostream>

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
