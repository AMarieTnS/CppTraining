#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

class Instruction
{
public:
    /* Constructors */
    Instruction() = default;
    Instruction(const Instruction &other) = delete;
    ~Instruction() = default;
    Instruction(Instruction &&other) = delete;
    Instruction &operator=(const Instruction &other) = delete;
    Instruction &operator=(Instruction &&other) = delete;

    /* Execution Functions */
    virtual ~Instruction() = default;
    virtual void Execute(char *&p) = 0;
};

#endif