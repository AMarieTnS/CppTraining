#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int gradeSign, int gradeExecute)
    : _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute),
      _signed(false) {
  if (_gradeSign < 1 || _gradeExecute < 1) {
    throw GradeTooHighException();
  }
  if (_gradeSign > 150 || _gradeExecute > 150) {
    throw GradeTooLowException();
  }
}

std::string Form::getName() const noexcept { return _name; }
bool Form::isSigned() const noexcept { return _signed; }
int Form::getGradeSign() const noexcept { return _gradeSign; }
int Form::getGradeExecute() const noexcept { return _gradeExecute; }
bool Form::getSigned() const noexcept { return _signed; }

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > _gradeSign) {
    throw GradeTooLowException();
  }
  _signed = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  if (form.getSigned()) {
    os << form.getName() << " is signed and requires grade "
       << form.getGradeSign() << " to sign.";
  } else {
    os << form.getName() << " is not signed and requires grade "
       << form.getGradeExecute() << " to execute.";
  }
  return os;
}
