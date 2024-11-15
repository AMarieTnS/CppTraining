#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Exceptions.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

class Form;

class Bureaucrat {
public:
  Bureaucrat(const std::string &name, int grade);
  const std::string &getName() const;
  int getGrade() const;
  void incrementGrade();
  void decrementGrade();

  void signForm(Form &form);
  void executeForm(const Form &form) const;

private:
  const std::string _name;
  int _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif