#include "../Includes/SEARCH.hpp"
#include <iostream>
#include <string>

void formatString(std::string &str) {
  if (str.length() < 10) {
    str.insert(0, 10 - str.length(), ' ');
  } else if (str.length() > 9) {
    str = str.substr(0, 9) + ".";
  }
}

void SEARCH::DisplayContacts(const ADD &Contacts) const {
  std::cout << "     Index|First name| Last name|  Nickname" << std::endl;
  const auto &ContactList = Contacts.GetContacts();
  for (std::size_t Index = 0; Index < ContactList.size(); ++Index) {
    const auto &contact = ContactList[Index];
    std::string sFirstName = contact[0];
    std::string sLastName = contact[1];
    std::string sNickname = contact[2];
    std::string sIndex = std::to_string(Index + 1);
    formatString(sIndex);
    formatString(sFirstName);
    formatString(sLastName);
    formatString(sNickname);

    std::cout << sIndex + "|" + sFirstName + "|" + sLastName + "|" + sNickname << std::endl << std::endl;
  }
}

void SEARCH::DisplayOneContact(const ADD &Contact) const {
  const auto &ContactList = Contact.GetContacts();
  if (!ContactList.empty()) {
    std::cout << "Enter the first name of the contact: ";
    std::string sFirstName;
    std::getline(std::cin, sFirstName);
    bool bIsok = false;

    for (const auto &contact : ContactList) {
      if (contact[0] == sFirstName) {
        std::cout << "First name: " << contact[0] << std::endl;
        std::cout << "Last name: " << contact[1] << std::endl;
        std::cout << "Nickname: " << contact[2] << std::endl;
        std::cout << "Login: " << contact[3] << std::endl;
        std::cout << "Postal address: " << contact[4] << std::endl;
        std::cout << "Email address: " << contact[5] << std::endl;
        std::cout << "Phone number: " << contact[6] << std::endl;
        std::cout << "Birthday: " << contact[7] << std::endl;
        std::cout << "Favorite meal: " << contact[8] << std::endl;
        std::cout << "Underwear color: " << contact[9] << std::endl;
        std::cout << "Darkest secret: " << contact[10] << std::endl << std::endl;
        bIsok = true;
      }
    }
    if (!bIsok) {
      std::cout << "Contact not found" << std::endl;
    }
  }
}