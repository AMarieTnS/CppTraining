
#include "./Includes/Human.hpp"
#include <string>

int main() {
  Human Human;
  Human.action("meleeAttack", "JB");
  Human.action("rangedAttack", "JB");
  Human.action("intimidatingShout", "JB");
  Human.action("Shoot", "JB");

  return 0;
}