#include "Brain.hpp"
#include <sstream>

Brain::Brain() {}

std::string Brain::identify() const {
    std::stringstream ss;
    ss << "0x" << std::hex << std::uppercase << reinterpret_cast<uintptr_t>(this);
    return ss.str();
}



/*
Create a Brain class, with whatever you think befits a brain. It will have an identify()
function, that returns a string containing the brain’s address in memory, in hexadecimal
format, prefixed by 0x (For example, "0x194F87EA").
*/