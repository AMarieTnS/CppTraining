#include <iostream>
#include "Human.hpp"

int main(){
Human bob;
std::cout << bob.identify() << std::endl;
std::cout << bob.getBrain().identify() << std::endl;
return 0;
}



/*
Now, make it so this code compiles and displays two identical adresses:

This code must be turned in as your main, and whatever you add to the Human or
Brain classes in order to make it work must be justified (with another argument than
"Er, yeah, well, I fiddled with it until it worked.").
*/