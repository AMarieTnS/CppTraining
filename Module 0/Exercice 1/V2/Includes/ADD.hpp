#ifndef ADD_H
#define ADD_H

#include <string>
#include <vector>

class ADD{
public:
void AddContact();
const std::vector<std::vector<std::string>> &GetContacts() const;

private:
std::vector<std::vector<std::string>> Contacts;
std::vector<std::string> SetContactInformation();
};

#endif