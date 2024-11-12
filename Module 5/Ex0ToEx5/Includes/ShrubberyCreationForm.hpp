#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <exception>
#include <iostream>
#include <string>

class ShrubberyCreationForm : public Form {
public:
  ShrubberyCreationForm(const std::string &sTarget);
  virtual ~ShrubberyCreationForm();
  void execute(Bureaucrat const &executor) const override;

private:
  std::string sTarget;
};

#endif
