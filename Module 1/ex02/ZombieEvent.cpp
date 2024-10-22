#include "zombieEvent.hpp"
#include <ctime>

void ZombieEvent::setZombieType(std::string type) {
    this->type = type;
}

Zombie* ZombieEvent::newZombie(std::string name) {
    return new Zombie(name, type);
}

void ZombieEvent::randomChump(){
    const std::string names[] = {"Zombie", "Zimbo", "Zabie", "Zombse", "Zizou"};
    srand(static_cast<unsigned int>(time(0)));
    Zombie* Zombie= newZombie(names[rand() % 4 + 0]);
    Zombie-> announce();
    delete Zombie;
}