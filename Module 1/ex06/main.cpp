#include <string>
#include "./Includes/Weapon.hpp"
#include "./Includes/HumanA.hpp"
#include "./Includes/HumanB.hpp"
#include <iostream>

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        std::cout << bob.GetName() << std::endl;
;
        club.SetType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.SetWeapon(club);
        jim.attack();
        club.SetType("some other type of club");
        jim.attack();
    }
}

/*int main(){
    Weapon JohnWeapon("Rifle");
    Weapon JBWeapon("crude spiked club");

    HumanA John ("John", JohnWeapon);
    HumanB JB ("JB", JBWeapon);

    std::cout << JB.attack() << std::endl;
    JBWeapon.SetType("some other type of club");
    std::cout << JB.attack() << std::endl;

return 0;
}*/