#include "Pony.hpp"
#include <iostream>

Pony::Pony(const std::string &name, int age) : name(name), age(age) {
    std::cout << "Pony " << name << " is created." << std::endl;
}

Pony::~Pony() {
    std::cout << "Pony " << name << " is destroyed." << std::endl;
}

void Pony::doStuff() const {
    std::cout << "Pony " << name << " is doing stuff." << std::endl;
}
