#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <string>

enum class TokenType
{
  number,
  operation,
  bracketOpen,
  bracketClose
};

struct Token
{
  TokenType type;
  int value;
  char op;
};

class Tokenizer
{
public:
  /* Constructors */
  Tokenizer() = default;
  Tokenizer(const Tokenizer &other) = delete;
  ~Tokenizer() = default;
  Tokenizer(Tokenizer &&other) = delete;
  Tokenizer &operator=(const Tokenizer &other) = delete;
  Tokenizer &operator=(Tokenizer &&other) = delete;

  /* Execution Functions */
  std::vector<Token> Tokenize(const std::string &expr);
  std::vector<Token> ToPostfix(const std::vector<Token> &tokens);
  void EvaluatePostfix(const std::vector<Token> &postfix);
  std::string GetOpName(char op);
};

#endif