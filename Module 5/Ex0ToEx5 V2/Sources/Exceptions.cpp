#include "Exceptions.hpp"

GradeException::GradeException(const std::string &message)
    : _message(message) {}

const char *GradeException::what() const noexcept { return _message.c_str(); }

UnknownFormException::UnknownFormException(const std::string &message)
    : _message(message) {}

const char *UnknownFormException::what() const noexcept {
  return _message.c_str();
}