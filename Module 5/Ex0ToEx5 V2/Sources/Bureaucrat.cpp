#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Exceptions.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : _name(name), _grade(grade) {}

const std::string &Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade() {
  if (_grade <= 1)
  {
    throw GradeTooHighException();
  }
  _grade--;
}

void Bureaucrat::decrementGrade() {
  if (_grade >= 150)
  {
    throw GradeTooLowException();
  }
  _grade++;
}

void Bureaucrat::signForm(Form &form)
{
  try
  {
    form.beSigned(*this);
    std::cout << "Bureaucrat " << _name << " (Grade " << _grade << ") signs a "
              << form.getName() << " Form (s.grade " << form.getGradeSign()
              << ", ex.grade " << form.getGradeExecute() << ") targeted on "
              << form.getTarget() << " (Unsigned)" << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cout << _name << " cannot sign " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(const Form &form) const
{
  try
  {
    form.execute(*this);
  }
  catch (const std::exception &e)
  {
    std::cout << _name << " cannot execute " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return os;
}