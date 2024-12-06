#include "tokenizer.hpp"

std::vector<Token> Tokenizer::Tokenize(const std::string &expr)
{
  std::vector<Token> tokens;
  for (size_t i = 0; i < expr.size(); ++i)
  {
    if (isdigit(expr[i]))
    {
      int num = 0;
      while (i < expr.size() && isdigit(expr[i]))
      {
        num = num * 10 + (expr[i] - '0');
        ++i;
      }
      --i;
      tokens.push_back({TokenType::number, num, 0});
    }
    else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
    {
      tokens.push_back({TokenType::operation, 0, expr[i]});
    }
    else if (expr[i] == '(')
    {
      tokens.push_back({TokenType::bracketOpen, 0, 0});
    }
    else if (expr[i] == ')')
    {
      tokens.push_back({TokenType::bracketClose, 0, 0});
    }
  }
  return tokens;
}

int precedence(char op)
{
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  return 0;
}

std::vector<Token> Tokenizer::ToPostfix(const std::vector<Token> &tokens)
{
  std::vector<Token> output;
  std::stack<Token> ops;
  for (const auto &token : tokens)
  {
    if (token.type == TokenType::number)
    {
      output.push_back(token);
    }
    else if (token.type == TokenType::operation)
    {
      while (!ops.empty() && precedence(ops.top().op) >= precedence(token.op))
      {
        output.push_back(ops.top());
        ops.pop();
      }
      ops.push(token);
    }
    else if (token.type == TokenType::bracketOpen)
    {
      ops.push(token);
    }
    else if (token.type == TokenType::bracketClose)
    {
      while (!ops.empty() && ops.top().type != TokenType::bracketOpen)
      {
        output.push_back(ops.top());
        ops.pop();
      }
      ops.pop();
    }
  }
  while (!ops.empty())
  {
    output.push_back(ops.top());
    ops.pop();
  }
  return output;
}

std::string Tokenizer::GetOpName(char op)
{
  switch (op)
  {
  case '+':
    return "Add";
  case '-':
    return "Subtract";
  case '*':
    return "Multiply";
  case '/':
    return "Divide";
  default:
    return "Unknown";
  }
}

void Tokenizer::EvaluatePostfix(const std::vector<Token> &postfix)
{
  std::cout << std::endl;
  std::stack<int> stack;
  for (const auto &token : postfix)
  {
    if (token.type == TokenType::number)
    {
      stack.push(token.value);
      std::cout << "I Num(" << token.value << ") | OP Push | ST ";
    }
    else if (token.type == TokenType::operation)
    {
      int b = stack.top();
      stack.pop();
      int a = stack.top();
      stack.pop();
      int result;
      if (token.op == '+')
        result = a + b;
      else if (token.op == '-')
        result = a - b;
      else if (token.op == '*')
        result = a * b;
      else if (token.op == '/')
        result = a / b;
      stack.push(result);
      std::cout << "I Op(" << token.op << ") | OP " << GetOpName(token.op) << " | ST ";
    }
    std::stack<int> temp = stack;
    while (!temp.empty())
    {
      std::cout << temp.top() << " ";
      temp.pop();
    }
    std::cout << "]" << std::endl;
  }
  std::cout << "Result : " << stack.top() << std::endl;
}