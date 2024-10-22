#include "zombieEvent.hpp"

int main() {

    ZombieEvent event;
    event.setZombieType("Cool zombie");

    Zombie* myZombie = event.newZombie("Zonzon");
    myZombie->announce();
    delete myZombie;

    event.randomChump();

    return 0;
}
