#include <iostream>
#include "Includes/ADD.hpp"
#include "Includes/SEARCH.hpp"

int main()
{
    ADD Contacts;
    SEARCH Search;
    std::string sCommand("");

    while (sCommand != "EXIT")
    {
        std::cout << "Selection de la commande (ADD, SEARCH, EXIT) : ";
        std::cin >> sCommand;
        std::cin.ignore();

        if (sCommand == "ADD") {
            Contacts.AddContact();
        }

        else if (sCommand == "SEARCH") 
        {
            Search.DisplayContacts(Contacts);
            Search.DisplayOneContact(Contacts);
        }
    }
    return 0;
}