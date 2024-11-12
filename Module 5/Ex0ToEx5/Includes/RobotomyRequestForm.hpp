#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

class RobotomyRequestForm : public Form {
public:
  RobotomyRequestForm(const std::string &sTarget);
  virtual ~RobotomyRequestForm();
  void execute(Bureaucrat const &executor) const override;

private:
  std::string sTarget;
};

#endif
