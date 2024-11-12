#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string &sName, int iGrade)
    : sName(sName), iGrade(iGrade) {
  if (iGrade < 1) {
    throw GradeTooHighException();
  }
  if (iGrade > 150) {
    throw GradeTooLowException();
  }
}

std::string Bureaucrat::GetName() const noexcept { return sName; }

int Bureaucrat::GetGrade() const noexcept { return iGrade; }

void Bureaucrat::IncrementGrade() {
  if (iGrade <= 1) {
    throw GradeTooHighException();
  }
  --iGrade;
}

void Bureaucrat::DecrementGrade() {
  if (iGrade >= 150) {
    throw GradeTooLowException();
  }
  ++iGrade;
}

void Bureaucrat::signForm(Form &form) {
  try {
    form.beSigned(*this);
    std::cout << sName << " signs " << form.GetName() << std::endl;
  } catch (const std::exception &e) {
    std::cout << sName << " cannot sign " << form.GetName() << " because "
              << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(Form const &form) const {
  try {
    form.execute(*this);
    std::cout << sName << " executes " << form.GetName() << std::endl;
  } catch (const std::exception &e) {
    std::cout << sName << " cannot execute " << form.GetName() << " because "
              << e.what() << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.GetName() << ", bureaucrat grade " << bureaucrat.GetGrade();
  return os;
}
