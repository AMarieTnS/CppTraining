#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

class PresidentialPardonForm : public Form {
public:
  PresidentialPardonForm(const std::string &sTarget);
  virtual ~PresidentialPardonForm();
  void execute(Bureaucrat const &executor) const override;

private:
  std::string sTarget;
};

#endif
