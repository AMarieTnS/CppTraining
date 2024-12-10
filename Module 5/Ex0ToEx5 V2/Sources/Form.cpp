#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(const std::string &name, int gradeSign, int gradeExecute, std::string target)
    : _name(name), _signed(false), _gradeSign(gradeSign),
      _gradeExecute(gradeExecute), _target(target)
{
  if (_gradeSign < 1 || _gradeExecute < 1)
  {
    throw GradeTooHighException();
  }
  if (_gradeSign > 150 || _gradeExecute > 150)
  {
    throw GradeTooLowException();
  }
}

const std::string &Form::GetName() const noexcept { return _name; }

bool Form::IsSigned() const noexcept { return _signed; }

int Form::GetGradeSign() const noexcept { return _gradeSign; }

int Form::GetGradeExecute() const noexcept { return _gradeExecute; }

void Form::BeSigned(const Bureaucrat &bureaucrat)
{
  if (bureaucrat.GetGrade() > _gradeSign)
  {
    throw GradeTooLowException();
  }
  _signed = true;
}

const std::string &Form::GetTarget() const noexcept { return _target; }

void Form::CheckExecution(const Bureaucrat &executor) const
{
  if (!IsSigned())
  {
    throw NotSignedException();
  }
  if (executor.GetGrade() > GetGradeExecute())
  {
    throw GradeTooHighException();
  }
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
  os << "Form " << form.GetName() << " (s.grade " << form.GetGradeSign()
     << ", ex.grade " << form.GetGradeExecute() << ")";
  if (form.IsSigned())
  {
    os << " is signed.";
  }
  else
  {
    os << " is not signed.";
  }
  return os;
}