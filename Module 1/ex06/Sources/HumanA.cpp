#include "../includes/HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string &name, Weapon &weapon)
    :sName(name)
    ,sWeapon(weapon)
{
}

void HumanA::attack() const
{
    std::cout << sName << " attacks with his " << sWeapon.GetType() << std::endl;
    /*std::string sAttackSentence = sName + " attacks with his " + sWeapon.GetType();
    return sAttackSentence;*/
}

const std::string &HumanA::GetName() const
{
    return sName;
}

void HumanA::SetWeapon(Weapon &weapon)
{
    sWeapon = weapon;
}

const Weapon &HumanA::GetWeapon() const
{
    return sWeapon;
}
