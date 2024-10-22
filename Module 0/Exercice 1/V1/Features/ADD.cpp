#include "../Header/ADD.h"
#include <iostream>
using namespace std;

int ADD(Contact contacts[], int currentSize) {
    if (currentSize >= MAX_CONTACTS) {
        cout << "Maximum number of contacts reached." << endl;
        return currentSize;
    }

    Contact newContact;

    cout << "First name : ";
    cin >> newContact.sFirstName;
    cout << "Last name : ";
    cin >> newContact.sLastName;
    cout << "Nickname : ";
    cin >> newContact.sNickname;
    cout << "Login : ";
    cin >> newContact.sLogin;
    cout << "Postal address : ";
    cin >> newContact.sPostalAddress;
    cout << "Email address : ";
    cin >> newContact.sEmailAddress;
    while (newContact.sEmailAddress.find("@") == std::string::npos)
    {
        cout << "Email error, retry : ";
        cin >> newContact.sEmailAddress;
    }
    cout << "Phone number : ";
    cin >> newContact.sPhoneNumber;
    cout << "Birthday : ";
    cin >> newContact.sBirthday;
    cout << "Favorite meal : ";
    cin >> newContact.sFavoriteMeal;
    cout << "Underwear color : ";
    cin >> newContact.sUnderwearColor;
    cout << "Darkest secret : ";
    cin >> newContact.sDarkestSecret;

    contacts[currentSize] = newContact;
    return currentSize + 1;
}

    /*
    int iNumberContact(0);
    vector<vector<string>>  sContact(iNumberContact, vector<string>(11));

    string sFirstName, sLastName, sNickname, sLogin, sPostalAddress, sEmailAddress, sPhoneNumber, sBirthday, sFavoriteMeal, sUnderwearColor, sDarkestSecret;

    cout << "First name : ";
    cin >> sFirstName;
    sContact[iNumberContact][0] = sFirstName;
    cout << "Last name : ";
    cin >> sLastName;
    sContact[iNumberContact][1] = sLastName;
    cout << "Nickname : ";
    cin >> sNickname;
    sContact[iNumberContact][2] = sNickname;
    cout << "Login : ";
    cin >> sLogin;
    sContact[iNumberContact][3] = sLogin;
    cout << "Postal address : ";
    cin >> sPostalAddress;
    sContact[iNumberContact][4] = sPostalAddress;
    cout << "Email address : ";
    cin >> sEmailAddress;
    sContact[iNumberContact][5] = sEmailAddress;
    cout << "Phone number : ";
    cin >> sPhoneNumber;
    sContact[iNumberContact][6] = sPhoneNumber;
    cout << "Birthday : ";
    cin >> sBirthday;
    sContact[iNumberContact][7] = sBirthday;
    cout << "Favorite meal : ";
    cin >> sFavoriteMeal;
    sContact[iNumberContact][8] = sFavoriteMeal;
    cout << "Underwear color : ";
    cin >> sUnderwearColor;
    sContact[iNumberContact][9] = sUnderwearColor;
    cout << "Darkest secret : ";
    cin >> sDarkestSecret;
    sContact[iNumberContact][10] = sDarkestSecret;

    iNumberContact++;
    return sContact;
    return
}*/