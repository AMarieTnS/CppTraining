#include "../Header/SEARCH.h"
#include <iostream>
using namespace std;

void formatString(string &str) {
    if (str.length() < 10) {
        str.insert(0, 10 - str.length(), ' ');
    } else if (str.length() > 9) {
        str = str.substr(0, 9) + ".";
    }
}

void SEARCH::displayContacts(const Contact contacts[], int size) {
    cout << "     Index|First name| Last name|  Nickname" << endl;
    for (int Index = 0; Index < size; ++Index) {
        string sFirstName = contacts[Index].sFirstName;
        string sLastName = contacts[Index].sLastName;
        string sNickname = contacts[Index].sNickname;
        string sLogin = contacts[Index].sLogin;
        string sPostalAddress = contacts[Index].sPostalAddress;
        string sEmailAddress = contacts[Index].sEmailAddress;
        string sPhoneNumber = contacts[Index].sPhoneNumber;
        string sBirthday = contacts[Index].sBirthday;
        string sFavoriteMeal = contacts[Index].sFavoriteMeal;
        string sUnderwearColor = contacts[Index].sUnderwearColor;
        string sDarkestSecret = contacts[Index].sDarkestSecret;

        formatString(sFirstName);
        formatString(sLastName);
        formatString(sNickname);
        formatString(sLogin);
        formatString(sPostalAddress);
        formatString(sEmailAddress);
        formatString(sPhoneNumber);
        formatString(sBirthday);
        formatString(sFavoriteMeal);
        formatString(sUnderwearColor);
        formatString(sDarkestSecret);

        cout << "         " << Index << "|" << sFirstName << "|" << sLastName << "|" << sNickname << endl;
        string sContact;
        cout << "Search contact :"; cin >> sContact;
        if (sContact == contacts[Index].sFirstName)
        {
            cout << "First name : " + contacts[Index].sFirstName + "\n";
            cout << "Last name : " + contacts[Index].sLastName + "\n";
            cout << "Nickname : " + contacts[Index].sNickname + "\n";
            cout << "Login : " + contacts[Index].sLogin + "\n";
            cout << "Postal address : " + contacts[Index].sPostalAddress + "\n";
            cout << "Email address : " + contacts[Index].sEmailAddress + "\n";
            cout << "Phone number : " + contacts[Index].sPhoneNumber + "\n";
            cout << "Birthday : " + contacts[Index].sBirthday + "\n";
            cout << "Favorite meal : " + contacts[Index].sFavoriteMeal + "\n";
            cout << "Underwear color : " + contacts[Index].sUnderwearColor + "\n";
            cout << "Darkest secret : " + contacts[Index].sDarkestSecret + "\n";
        }
    }
}


/*void SEARCH::displayContacts(const Contact contacts[], int size) {
    string sFirstName, sLastName, sNickname;
    cout << "    Index |First name| Last name|  Nickname" << endl;
    for (int Index = 0; Index < size; ++Index) {
        while (contacts[Index].sFirstName.length() < 10)
        {
            sFirstName = " " + contacts[Index].sFirstName;
        }
        if (contacts[Index].sFirstName.length() > 9)
        {
            sFirstName = contacts[Index].sFirstName.substr(0, 9) + ".";
        }
        while (contacts[Index].sLastName.length() < 10)
        {
            sLastName = " " + contacts[Index].sLastName;
        }
        if (contacts[Index].sLastName.length() > 9)
        {
            sLastName = contacts[Index].sLastName.substr(0, 9) + ".";
        }
        while (contacts[Index].sNickname.length() < 10)
        {
            sNickname = " " + contacts[Index].sNickname;
        }
        if (contacts[Index].sNickname.length() > 9)
        {
            sNickname = contacts[Index].sNickname.substr(0, 9) + ".";
        }
        cout << "         "  << Index <<  "|"  << sFirstName <<  "|" << sLastName <<  "|"  << sNickname << endl;
    }
    
}*/





/*
The program will display a list of the available non-empty contacts in 4
columns: index, first name, last name and nickname.

Each column must be 10 chars wide, right aligned and separated by a ’|’
character. Any output longer than the columns’ width is truncated and the
last displayable character is replaced by a dot (’.’).

Then the program will prompt again for the index of the desired entry and
displays the contact’s information, one field per line. If the input makes no
sense, define a relevant behavior.
*/