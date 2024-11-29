#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <exception>
#include <iostream>
#include <string>

class Form;

class Bureaucrat {
public:
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const noexcept override { return "Grade too high"; }
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const noexcept override { return "Grade too low"; }
  };

  Bureaucrat(const std::string &name, int grade);

  std::string getName() const noexcept;
  int getGrade() const noexcept;

  void incrementGrade();
  void decrementGrade();

  void signForm(Form &form);
  void executeForm(Form const &form) const;

private:
  const std::string _name;
  int _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
