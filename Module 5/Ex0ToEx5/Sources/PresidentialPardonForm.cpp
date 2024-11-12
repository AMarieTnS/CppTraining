#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &sTarget)
    : Form("President", 25, 5), sTarget(sTarget) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (!isSigned()) {
    throw Form::GradeTooLowException();
  }
  if (executor.GetGrade() > GetGradeExecute()) {
    throw Form::GradeTooLowException();
  }
  std::cout << sTarget << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
