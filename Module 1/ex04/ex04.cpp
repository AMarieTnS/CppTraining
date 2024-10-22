#include <iostream>
#include <string>

int main() {
    std::string sValue = "HI THIS IS BRAIN";
    std::string *sMypointer = &sValue;
    std::string &sReference = sValue;

    std::cout << "Pointer: " << *sMypointer << '\n';
    std::cout << "Reference: " << sReference << '\n';

    return 0;
}