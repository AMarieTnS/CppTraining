#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon{
public:
    Weapon(const std::string &stype);

    const std::string& GetType() const;
    void SetType(std::string stype);

private:    
    std::string stype;
};

#endif
