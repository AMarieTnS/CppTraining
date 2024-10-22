#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include "zombie.hpp"
#include <vector>

class ZombieHorde {
private:
    std::vector<Zombie*> zombies;

public:
    ZombieHorde(int N);
    ~ZombieHorde();
    void announce() const;
};

#endif
