#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int gradeSign, int gradeExecute)
    : _name(name), _signed(false), _gradeSign(gradeSign),
      _gradeExecute(gradeExecute) {
  if (_gradeSign < 1 || _gradeExecute < 1) {
    throw GradeTooHighException();
  }
  if (_gradeSign > 150 || _gradeExecute > 150) {
    throw GradeTooLowException();
  }
}

const std::string &Form::getName() const noexcept { return _name; }

bool Form::isSigned() const noexcept { return _signed; }

int Form::getGradeSign() const noexcept { return _gradeSign; }

int Form::getGradeExecute() const noexcept { return _gradeExecute; }

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > _gradeSign) {
    throw GradeTooLowException();
  }
  _signed = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "Form " << form.getName() << " (s.grade " << form.getGradeSign()
     << ", ex.grade " << form.getGradeExecute() << ")";
  if (form.isSigned()) {
    os << " is signed.";
  } else {
    os << " is not signed.";
  }
  return os;
}