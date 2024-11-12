#include "Bureaucrat.hpp"

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.GetName() << ", bureaucrat grade " << bureaucrat.GetGrade();
  return os;
}