#ifndef JUMPFORWARD_HPP
#define JUMPFORWARD_HPP

#include <iostream>
#include <memory>

class JumpForward
{
public:
    /* Constructors */
    JumpForward() = default;
    JumpForward(const JumpForward &other) = delete;
    ~JumpForward() = default;
    JumpForward(JumpForward &&other) = delete;
    JumpForward &operator=(const JumpForward &other) = delete;
    JumpForward &operator=(JumpForward &&other) = delete;

    /* Execution Functions */
    void operator()(char *&rawPtr, const std::string &src, int &i);
};

#endif