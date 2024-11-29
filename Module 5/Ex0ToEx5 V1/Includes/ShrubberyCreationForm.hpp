#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <exception>
#include <iostream>
#include <string>

class ShrubberyCreationForm : public Form {
public:
  ShrubberyCreationForm(const std::string &target);
  virtual ~ShrubberyCreationForm() = default;
  void execute(Bureaucrat const &executor) const override;

private:
  std::string _target;
};

#endif
