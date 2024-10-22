#ifndef PONY_HPP
#define PONY_HPP

#include <string>

class Pony {
public:
    Pony(const std::string &name, int age);
    ~Pony();

    void doStuff() const;

private:
    std::string name;
    int age;
};

#endif
