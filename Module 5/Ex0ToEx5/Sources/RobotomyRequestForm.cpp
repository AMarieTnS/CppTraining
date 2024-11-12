#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &sTarget)
    : Form("Robotomy", 72, 137), sTarget(sTarget) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (!isSigned()) {
    throw Form::GradeTooLowException();
  }
  if (executor.GetGrade() > GetGradeExecute()) {
    throw Form::GradeTooLowException();
  }
  std::cout << "drilling noises" << std::endl;
  int rate = rand() % 1;
  if (rate == 0) {
    std::cout << sTarget << " has been robotomized" << std::endl;
  } else
    std::cout << sTarget << " is a failure" << std::endl;
}
