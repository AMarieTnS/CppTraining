#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP


#include <string>

class Zombie {
private:
    std::string name;
    std::string type;

public:
    Zombie(std::string name, std::string type);
    void announce() const;
};

#endif
