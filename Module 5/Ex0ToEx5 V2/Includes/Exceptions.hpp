#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <string>

class GradeException : public std::exception {
public:
  GradeException(const std::string &message);
  const char *what() const noexcept override;

private:
  std::string _message;
};

class UnknownFormException : public std::exception {
public:
  UnknownFormException(const std::string &message);
  const char *what() const noexcept override;

private:
  std::string _message;
};

#endif