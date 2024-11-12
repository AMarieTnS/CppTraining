#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &sName, int iGradeSign, int iGradeExecute)
    : sName(sName), iGradeSign(iGradeSign), iGradeExecute(iGradeExecute),
      bSigned(false) {
  if (iGradeSign < 1 || iGradeExecute < 1) {
    throw GradeTooHighException();
  }
  if (iGradeSign > 150 || iGradeExecute > 150) {
    throw GradeTooLowException();
  }
}

std::string Form::GetName() const noexcept { return sName; }
bool Form::isSigned() const noexcept { return bSigned; }
int Form::GetGradeSign() const noexcept { return iGradeSign; }

int Form::GetGradeExecute() const noexcept { return iGradeExecute; }

bool Form::GetSigned() const noexcept { return bSigned; }

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.GetGrade() > iGradeSign) {
    throw GradeTooLowException();
  }
  bSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  if (form.GetSigned()) {
    os << form.GetName() << " is signed and requires grade "
       << form.GetGradeSign() << " to sign.";
  } else {
    os << form.GetName() << " is not signed and requires grade "
       << form.GetGradeExecute() << " to execute.";
  }
  return os;
}
