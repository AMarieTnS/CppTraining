#include "Includes/FragTrap.hpp"

int main() {
  FragTrap fragtrap("JB");

  fragtrap.rangedAttack("target1");
  fragtrap.takeDamage(50);

  fragtrap.meleeAttack("target2");
  fragtrap.takeDamage(40);

  fragtrap.beRepaired(30);

  fragtrap.vaulthunter_dot_exe("target1");
  fragtrap.vaulthunter_dot_exe("target2");
  fragtrap.vaulthunter_dot_exe("target3");
  fragtrap.vaulthunter_dot_exe("target4");
  fragtrap.vaulthunter_dot_exe("target5");

  return 0;
}