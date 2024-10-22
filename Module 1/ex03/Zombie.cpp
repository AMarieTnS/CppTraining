#include "zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name, std::string type) : name(name), type(type) {}

void Zombie::announce() const {
    std::cout << name << " (" << type << ") Braiiiiiiinnnssss..." << std::endl;
}