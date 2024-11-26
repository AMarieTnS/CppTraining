#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <string>

class GradeTooHighException : public std::exception
{
public:
  GradeTooHighException() : _message("Grade is too high!") {}
  const char *what() const noexcept override
  {
    return _message.c_str();
  }

private:
  std::string _message;
};

class GradeTooLowException : public std::exception
{
public:
  GradeTooLowException() : _message("Grade is too low!") {}
  const char *what() const noexcept override
  {
    return _message.c_str();
  }

private:
  std::string _message;
};

class UnknownFormException : public std::exception
{
public:
  UnknownFormException() : _message("Unknown form!") {}
  const char *what() const noexcept override
  {
    return _message.c_str();
  }

private:
  std::string _message;
};

#endif