#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

class RobotomyRequestForm : public Form {
public:
  RobotomyRequestForm(const std::string &target);
  virtual ~RobotomyRequestForm() = default;
  void execute(Bureaucrat const &executor) const override;

private:
  std::string _target;
};

#endif
