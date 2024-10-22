#include "../includes/Human.hpp"
#include <iostream>

void Human::meleeAttack(std::string const &target) {
  std::cout << "Melee attack " << "from " << target  << std::endl;
}
void Human::rangedAttack(std::string const &target) {
  std::cout << "Ranged attack " << "from " << target  << std::endl;
}
void Human::intimidatingShout(std::string const &target) {
  std::cout << "Intimidating shout " << "from " << target  << std::endl;
}

void Human::action(std::string const &action_name, std::string const &target) {
typedef void(Human::*Fonction)(std::string const &target);
Fonction actions[] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
std::string sActionName[] = {"meleeAttack", "rangedAttack", "intimidatingShout"};
for (int i; i < 3 ; i++){
    if (sActionName[i] == action_name){
        (this ->*(actions[i]))(target);
        return;
    }
}
  std::cerr << "Unknown action: " << action_name << std::endl;
}
