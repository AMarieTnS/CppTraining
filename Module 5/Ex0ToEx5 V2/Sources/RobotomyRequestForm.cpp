#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : Form("Robotomy Request", 72, 45), _target(target) {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  if (!isSigned()) {
    throw GradeException("Grade too low");
  }
  if (executor.getGrade() > getGradeExecute()) {
    throw GradeException("Grade too hight");
  }
  std::cout << "Drilling noises... ";
  if (rand() % 2) {
    std::cout << _target << " has been robotomized successfully." << std::endl;
  } else {
    std::cout << "Robotomy failed." << std::endl;
  }
}

const std::string &RobotomyRequestForm::getTarget() const { return _target; }