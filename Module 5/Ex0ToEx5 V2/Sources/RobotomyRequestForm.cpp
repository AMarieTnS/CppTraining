#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : Form("Robotomy Request", 72, 45, target) {}

void RobotomyRequestForm::Execute(const Bureaucrat &executor) const
{
  CheckExecution(executor);
  std::cout << "Drilling noises... ";
  if (rand() % 2)
  {
    std::cout << Form::GetTarget() << " has been robotomized successfully." << std::endl;
  }
  else
  {
    std::cout << "Robotomy failed." << std::endl;
  }
}