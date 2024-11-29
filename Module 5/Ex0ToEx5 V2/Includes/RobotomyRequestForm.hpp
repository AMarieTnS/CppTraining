#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "Exceptions.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>
#include <string>

class RobotomyRequestForm : public Form
{
public:
  /* Constructors */
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &other) = delete;
  RobotomyRequestForm(RobotomyRequestForm &&other) = delete;
  RobotomyRequestForm &operator=(const RobotomyRequestForm &other) = delete;
  RobotomyRequestForm &operator=(RobotomyRequestForm &&other) = delete;
  ~RobotomyRequestForm() = default;

  /* Execution Functions */
  void Execute(const Bureaucrat &executor) const override;
};

#endif
