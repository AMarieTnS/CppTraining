#include "Includes/FragTrap.hpp"
#include "Includes/NinjaTrap.hpp"
#include "Includes/ScavTrap.hpp"

int main() {
  FragTrap Claptrap1("JB");
  ScavTrap Claptrap2("Momo");
  NinjaTrap Claptrap3("Coco");

  srand(time(0));

  // Ex00 & Ex02
  std::cout << std::endl << "############EX00############" << std::endl;
  Claptrap1.rangedAttack("target1");
  Claptrap1.takeDamage(50);
  Claptrap1.meleeAttack("target2");
  Claptrap1.takeDamage(40);
  Claptrap1.beRepaired(30);
  Claptrap1.vaulthunter_dot_exe("target1");
  Claptrap1.vaulthunter_dot_exe("target2");
  Claptrap1.vaulthunter_dot_exe("target3");
  Claptrap1.vaulthunter_dot_exe("target4");
  Claptrap1.vaulthunter_dot_exe("target5");

  // ex01 & Ex02
  std::cout << std::endl << "############EX01############" << std::endl;
  Claptrap2.rangedAttack("target1");
  Claptrap2.takeDamage(50);
  Claptrap2.meleeAttack("target2");
  Claptrap2.takeDamage(40);
  Claptrap2.beRepaired(30);
  Claptrap2.challengeNewcomer("target1");
  Claptrap2.challengeNewcomer("target2");
  Claptrap2.challengeNewcomer("target3");
  Claptrap2.challengeNewcomer("target4");
  Claptrap2.challengeNewcomer("target5");

  // ex03
  std::cout << std::endl << "############EX03############" << std::endl;
  Claptrap3.ninjaShoebox(Claptrap1);
  Claptrap3.ninjaShoebox(Claptrap2);
  Claptrap3.ninjaShoebox(Claptrap3);
  return 0;
}