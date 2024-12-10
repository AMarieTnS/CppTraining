#ifndef JUMPBACKWARD_HPP
#define JUMPBACKWARD_HPP

#include <iostream>
#include <memory>

class JumpBackward
{
public:
    /* Constructors */
    JumpBackward() = default;
    JumpBackward(const JumpBackward &other) = delete;
    ~JumpBackward() = default;
    JumpBackward(JumpBackward &&other) = delete;
    JumpBackward &operator=(const JumpBackward &other) = delete;
    JumpBackward &operator=(JumpBackward &&other) = delete;

    /* Execution Functions */
    void operator()(char *&rawPtr, const std::string &src, int &i);
};
#endif
