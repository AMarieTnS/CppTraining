#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <string>
#include <array>

constexpr size_t ARRAY_SIZE = 30000;

class Interpreter
{
public:
    /* Constructors */
    Interpreter();
    Interpreter(const Interpreter &other) = delete;
    ~Interpreter() = default;
    Interpreter(Interpreter &&other) = delete;
    Interpreter &operator=(const Interpreter &other) = delete;
    Interpreter &operator=(Interpreter &&other) = delete;

    /* Execution Functions */

    void Interpret(const std::string &src);

private:
    std::array<char, ARRAY_SIZE> arr;
    char *p;
};

#endif