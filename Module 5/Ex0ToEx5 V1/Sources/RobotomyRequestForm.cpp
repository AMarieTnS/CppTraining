#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : Form("Robotomy", 72, 137), _target(target) {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (!isSigned()) {
    throw Form::GradeTooLowException();
  }
  if (executor.getGrade() > getGradeExecute()) {
    throw Form::GradeTooLowException();
  }
  std::cout << "drilling noises" << std::endl;
  int rate = rand() % 1;
  if (rate == 0) {
    std::cout << _target << " has been robotomized" << std::endl;
  } else
    std::cout << _target << " is a failure" << std::endl;
}
