#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "Exceptions.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>
#include <string>

class RobotomyRequestForm : public Form {
public:
  RobotomyRequestForm(const std::string &target);
  virtual ~RobotomyRequestForm() = default;
  void execute(const Bureaucrat &executor) const override;
  const std::string &getTarget() const override;

private:
  std::string _target;
};

#endif
