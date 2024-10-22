#include <iostream>
#include "Header\ADD.h"
#include "Header\SEARCH.h"
#include "Features\ADD.cpp"
#include "Features\SEARCH.cpp"

using namespace std;

int main()
{
    string sCommand("");
    Contact contacts[MAX_CONTACTS];
    int currentSize = 0;
    while (sCommand != "EXIT")
    {
        cout << "Selection de la commande : ";
        cin >> sCommand;
        if(sCommand == "EXIT")
        {
            return 0;
        }

        else if (sCommand == "ADD") 
        {
            currentSize = ADD(contacts, currentSize);
        }

        else if (sCommand == "SEARCH") 
        {
            SEARCH search;
            search.displayContacts(contacts, currentSize);
        }
        else {
            sCommand = "";
        }
    }
    
    return 0;
}