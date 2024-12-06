#include "JumpBackward.hpp"

void JumpBackward::operator()(char *&p, const std::string &src, int &i)
{
    if (*p != 0)
    {
        int loopCounter = 1;
        while (loopCounter > 0)
        {
            --i;
            if (src[i] == '[')
                --loopCounter;
            else if (src[i] == ']')
                ++loopCounter;
        }
    }
}