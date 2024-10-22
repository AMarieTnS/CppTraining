#include "../Includes/ADD.hpp"
#include <iostream>

std::vector<std::string> ADD::SetContactInformation() {
  std::vector<std::string> NewContact(11);
  std::vector<std::string> sInformationAsk = {
      "First Name",     "Last Name",       "Nickname",      "Login",
      "Postal Address", "Email Address",   "Phone Number",  "Birthday",
      "Favorite Meal",  "Underwear Color", "Darkest Secret"};

  for (size_t Index = 0; Index < sInformationAsk.size(); ++Index) {
    while (NewContact[Index].empty()) {
      std::cout << sInformationAsk[Index] << ": ";
      std::getline(std::cin, NewContact[Index]);

      if (Index == 5 && NewContact[Index].find("@") == std::string::npos) {
        std::cout << "Email error, retry: ";
        std::getline(std::cin, NewContact[Index]);
      }
    }
  }
  return NewContact;
}

void ADD::AddContact() {
  std::vector<std::string> NewContact = SetContactInformation();
  Contacts.push_back(NewContact);
  std::cout << "Contact added" << std::endl << std::endl;
}

const std::vector<std::vector<std::string>> &ADD::GetContacts() const {
  return Contacts;
}
