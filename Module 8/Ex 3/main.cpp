#include "Mindopen.hpp"
#include "FileReader.hpp"
#include <iostream>

int main()
{
    try
    {
        FileReader fileReader;
        std::string code = fileReader.ReadFile("../Mindopen.txt");

        Mindopen interpreter;
        interpreter.Interpret(code);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}