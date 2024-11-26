#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : Form("Presidential Pardon", 25, 5, target) {}

void PresidentialPardonForm::Execute(const Bureaucrat &executor) const
{
  if (!IsSigned())
  {
    throw GradeTooLowException();
  }
  if (executor.GetGrade() > GetGradeExecute())
  {
    throw GradeTooHighException();
  }
  std::cout << GetTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}