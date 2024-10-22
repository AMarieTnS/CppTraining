#include "Human.hpp"

Human::Human() : brain() {}

const Brain& Human::getBrain() const {
    return brain;
}

std::string Human::identify() const {
    return brain.identify();
}




/*
Then, make a Human class, that has a constant Brain attribute, with the same lifetime.
It has an identify() function, that just calls the identify() function of its Brain and
returns its result.
*/