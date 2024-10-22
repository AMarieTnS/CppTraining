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

    std::cout << sIndex + "|" + sFirstName + "|" + sLastName + "|" + sNickname
              << std::endl;
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
        const std::vector<std::string> labels = {
            "First name",     "Last name",       "Nickname",      "Login",
            "Postal address", "Email address",   "Phone number",  "Birthday",
            "Favorite meal",  "Underwear color", "Darkest secret"};

        for (size_t i = 0; i < contact.size(); ++i) {
          std::cout << labels[i] << ": " << contact[i] << std::endl;
        }
        bIsok = true;
        break;
      }
    }

    if (!bIsok) {
      std::cout << "Contact not found" << std::endl;
    }
  }
}