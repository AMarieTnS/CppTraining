#ifndef SETBYTE_HPP
#define SETBYTE_HPP

#include <memory>
#include <iostream>

class SetByte
{
public:
    /* Constructors */
    SetByte() = default;
    SetByte(const SetByte &other) = delete;
    ~SetByte() = default;
    SetByte(SetByte &&other) = delete;
    SetByte &operator=(const SetByte &other) = delete;
    SetByte &operator=(SetByte &&other) = delete;

    /* Execution Functions */
    void operator()(char *&rawPtr);
};

#endif
