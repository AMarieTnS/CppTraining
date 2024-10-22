#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
public:
    HumanA(const std::string &name, Weapon &weapon);

    void attack() const;

    const std::string& GetName() const;
    void SetWeapon(Weapon &weapon);
    const Weapon& GetWeapon() const;

private:
    std::string sName;
    Weapon &sWeapon;
};

#endif
