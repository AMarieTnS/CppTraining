#include "ZombieHorde.hpp"
#include <ctime>

ZombieHorde::ZombieHorde(int N){
    const std::string names[] = {"Zombie", "Zimbo", "Zabie", "Zombse", "Zizou"};
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < N ; i++){
        zombies.push_back(new Zombie(names[rand() % 5], "Blue Zombie")) ;
    }
}

ZombieHorde::~ZombieHorde(){
    for (Zombie* zombie: zombies){
        delete zombie;
    }
}

void ZombieHorde::announce() const{
    for (Zombie* zombie: zombies){
        zombie -> announce();
    }
}
