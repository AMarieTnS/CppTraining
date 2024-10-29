#include "../Includes/NinjaTrap.hpp"
#include <iostream>

void NinjaTrap::ninjaShoebox(ClapTrap &target) {
  std::cout << sName << " is droping a muntain on " << target.sName
            << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap &target) {
  std::cout << sName << " sing for " << target.sName << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap &target) {
  std::cout << sName << " is hide in the shadow of " << target.sName
            << std::endl;
}

void NinjaTrap::ninjaShoebox(NinjaTrap &target) {
  std::cout << sName << " do the rasengan on " << target.sName << std::endl;
}