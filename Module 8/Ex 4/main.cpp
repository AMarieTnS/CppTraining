#include "tokenizer.hpp"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Usage: " << argv[0] << " <expression>\n";
    return 1;
  }

  std::string expr = argv[1];
  Tokenizer tokenizer;
  auto tokens = tokenizer.Tokenize(expr);
  std::cout << "Tokens: ";
  for (const auto &token : tokens)
  {
    if (token.type == TokenType::number)
      std::cout << "Num(" << token.value << ") ";
    else if (token.type == TokenType::operation)
      std::cout << "Op(" << token.op << ") ";
    else if (token.type == TokenType::bracketOpen)
      std::cout << "ParOpen ";
    else if (token.type == TokenType::bracketClose)
      std::cout << "ParClose ";
  }

  auto postfix = tokenizer.ToPostfix(tokens);
  std::cout << std::endl
            << "Postfix : ";
  for (const auto &token : postfix)
  {
    if (token.type == TokenType::number)
      std::cout << "Num(" << token.value << ") ";
    else if (token.type == TokenType::operation)
      std::cout << "Op(" << token.op << ") ";
  }

  tokenizer.EvaluatePostfix(postfix);

  return 0;
}