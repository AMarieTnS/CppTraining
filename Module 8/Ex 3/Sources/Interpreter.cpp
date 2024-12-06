#include "Interpreter.hpp"
#include "IncrementPtr.hpp"
#include "DecrementPtr.hpp"
#include "IncrementByte.hpp"
#include "DecrementByte.hpp"
#include "PrintByte.hpp"
#include "SetByte.hpp"
#include "JumpForward.hpp"
#include "JumpBackward.hpp"
#include <algorithm>
#include <iostream>

Interpreter::Interpreter() : arr{}, p(arr.data())
{
    std::fill(arr.begin(), arr.end(), 0);
}

void Interpreter::Interpret(const std::string &src)
{
    IncrementPtr incrementPtr;
    DecrementPtr decrementPtr;
    IncrementByte incrementByte;
    DecrementByte decrementByte;
    PrintByte printByte;
    SetByte setByte;
    JumpForward jumpForward;
    JumpBackward jumpBackward;
    int i = 0;
    int max = src.size();

    while (i < max)
    {
        switch (src[i])
        {
        case '>':
            incrementPtr(p);
            break;
        case '<':
            decrementPtr(p);
            break;
        case '+':
            incrementByte(p);
            break;
        case '-':
            decrementByte(p);
            break;
        case '.':
            printByte(p);
            break;
        case ',':
            setByte(p);
            break;
        case '[':
            jumpForward(p, src, i);
            break;
        case ']':
            jumpBackward(p, src, i);
            break;
        }
        ++i;
    }
}