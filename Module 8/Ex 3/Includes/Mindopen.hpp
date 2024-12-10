#ifndef MINDOPEN_HPP
#define MINDOPEN_HPP

#include <string>
#include "Interpreter.hpp"

class Mindopen
{
public:
  /* Constructors */
  Mindopen() = default;
  Mindopen(const Mindopen &other) = delete;
  ~Mindopen() = default;
  Mindopen(Mindopen &&other) = delete;
  Mindopen &operator=(const Mindopen &other) = delete;
  Mindopen &operator=(Mindopen &&other) = delete;

  /* Execution Functions */
  void Interpret(const std::string &src);

private:
  Interpreter interpreter;
};

#endif