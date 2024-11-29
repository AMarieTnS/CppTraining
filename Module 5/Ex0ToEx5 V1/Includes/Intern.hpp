#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

class Intern {
public:
  Intern() = default;
  ~Intern() = default;
  Form *makeForm(const std::string &nameForm, const std::string &targetForm);

private:
  std::string _nameForm;
  std::string _targetForm;
};

#endif
