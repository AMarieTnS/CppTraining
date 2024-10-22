#include "../Includes/HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name)
    :sName(name)
    ,sWeapon(nullptr)
{
}

void HumanB::attack() const
{
    if (sWeapon) 
    {
        std::cout << sName << " attacks with his " << sWeapon->GetType() << std::endl;
    } else 
    {
        std::cout << sName << "has no weapon to attack with!" << std::endl;
    }
}

const std::string &HumanB::GetName() const
{
    return sName;
}

void HumanB::SetWeapon(Weapon &weapon)
{
    sWeapon = &weapon;
}

const Weapon *HumanB::GetWeapon() const
{
    return sWeapon;
}
