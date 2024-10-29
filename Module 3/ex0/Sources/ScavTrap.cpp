#include "../Includes/ScavTrap.hpp"
#include <iostream>

std::string ScavTrap::challengeNewcomer(std::string const &target) {
  std::string Challenge[] = {" dice roll ", " rock paper scissors ",
                             " olive throw ", " MMA match ", " duel of gazes "};
  std::string sChallenge = Challenge[rand() % 5];
  std::cout << "FR4G-TP : ScavTrap : " << sName << " Challengs " << target
            << " to a " << sChallenge << std::endl;
  return "0";
}
