#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : _name(name), _grade(grade) {
  if (_grade < 1) {
    throw GradeTooHighException();
  }
  if (_grade > 150) {
    throw GradeTooLowException();
  }
}

std::string Bureaucrat::getName() const noexcept { return _name; }

int Bureaucrat::getGrade() const noexcept { return _grade; }

void Bureaucrat::incrementGrade() {
  if (_grade <= 1) {
    throw GradeTooHighException();
  }
  --_grade;
}

void Bureaucrat::decrementGrade() {
  if (_grade >= 150) {
    throw GradeTooLowException();
  }
  ++_grade;
}

void Bureaucrat::signForm(Form &form) {
  try {
    form.beSigned(*this);
    std::cout << _name << " signs " << form.getName() << std::endl;
  } catch (const std::exception &e) {
    std::cout << _name << " cannot sign " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(Form const &form) const {
  try {
    form.execute(*this);
    std::cout << _name << " executes " << form.getName() << std::endl;
  } catch (const std::exception &e) {
    std::cout << _name << " cannot execute " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return os;
}
