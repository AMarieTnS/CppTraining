#include "../Includes/Weapon.hpp"


Weapon::Weapon(const std::string &sWeapon)
        :stype(sWeapon)
{
}

const std::string &Weapon::GetType() const
{
    return stype;
}

void Weapon::SetType(std::string sType)
{
    this->stype = sType;
}
