#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : Form("President", 25, 5), _target(target) {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  if (!isSigned()) {
    throw GradeException("Grade too low");
  }
  if (executor.getGrade() > getGradeExecute()) {
    throw GradeException("Grade too hight");
  }
  std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
const std::string &PresidentialPardonForm::getTarget() const { return _target; }