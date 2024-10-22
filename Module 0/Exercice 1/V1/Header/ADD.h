#ifndef ADD_H
#define ADD_H

#include <string>

struct Contact {
    std::string sFirstName;
    std::string sLastName;
    std::string sNickname;
    std::string sLogin;
    std::string sPostalAddress;
    std::string sEmailAddress;
    std::string sPhoneNumber;
    std::string sBirthday;
    std::string sFavoriteMeal;
    std::string sUnderwearColor;
    std::string sDarkestSecret;
};

const int MAX_CONTACTS = 10;

int ADD(Contact contacts[], int currentSize);

#endif
