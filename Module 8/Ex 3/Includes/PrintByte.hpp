#ifndef PRINTBYTE_HPP
#define PRINTBYTE_HPP

#include <memory>
#include <iostream>

class PrintByte
{
public:
    /* Constructors */
    PrintByte() = default;
    PrintByte(const PrintByte &other) = delete;
    ~PrintByte() = default;
    PrintByte(PrintByte &&other) = delete;
    PrintByte &operator=(const PrintByte &other) = delete;
    PrintByte &operator=(PrintByte &&other) = delete;

    /* Execution Functions */
    void operator()(char *&rawPtr);
};

#endif