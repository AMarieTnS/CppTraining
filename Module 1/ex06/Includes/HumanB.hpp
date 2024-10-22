#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
public:
    HumanB(const std::string &name);

    void attack() const;

    const std::string& GetName() const;
    void SetWeapon(Weapon &weapon);
    const Weapon *GetWeapon() const;

private:
    std::string sName;
    Weapon *sWeapon;
};

#endif
