#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : Form("President", 25, 5), _target(target) {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (!isSigned()) {
    throw Form::GradeTooLowException();
  }
  if (executor.getGrade() > getGradeExecute()) {
    throw Form::GradeTooLowException();
  }
  std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
