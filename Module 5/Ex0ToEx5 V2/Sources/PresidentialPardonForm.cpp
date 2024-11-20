#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : Form("President", 25, 5), _target(target) {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  if (!isSigned()) {
    throw GradeTooLowException();
  }
  if (executor.getGrade() > getGradeExecute()) {
    throw GradeTooHighException();
  }
  std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
const std::string &PresidentialPardonForm::getTarget() const { return _target; }