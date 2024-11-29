#include "Bureaucrat.hpp"
#include "Exceptions.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : _name(name), _grade(grade) {}

const std::string &Bureaucrat::GetName() const { return _name; }

int Bureaucrat::GetGrade() const { return _grade; }

void Bureaucrat::IncrementGrade()
{
  if (_grade <= 1)
  {
    throw GradeTooHighException();
  }
  _grade--;
}

void Bureaucrat::DecrementGrade()
{
  if (_grade >= 150)
  {
    throw GradeTooLowException();
  }
  _grade++;
}

void Bureaucrat::SignForm(Form &form)
{
  try
  {
    form.BeSigned(*this);
    std::cout << "Bureaucrat " << _name << " (Grade " << _grade << ") signs a "
              << form.GetName() << " Form (s.grade " << form.GetGradeSign()
              << ", ex.grade " << form.GetGradeExecute() << ") targeted on "
              << form.GetTarget() << " (Unsigned)" << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cout << _name << " cannot sign " << form.GetName() << " because "
              << e.what() << std::endl;
  }
}

void Bureaucrat::ExecuteForm(const Form &form) const
{
  try
  {
    form.Execute(*this);
  }
  catch (const std::exception &e)
  {
    std::cout << _name << " cannot execute " << form.GetName() << " because "
              << e.what() << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
  os << bureaucrat.GetName() << ", bureaucrat grade " << bureaucrat.GetGrade();
  return os;
}