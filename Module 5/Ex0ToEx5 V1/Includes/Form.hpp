#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
public:
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const noexcept override { return "Grade too high"; }
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const noexcept override { return "Grade too low"; }
  };

  Form(const std::string &name, int gradeSign, int gradeExecute);
  virtual ~Form() {}

  std::string getName() const noexcept;
  bool isSigned() const noexcept;

  int getGradeSign() const noexcept;
  int getGradeExecute() const noexcept;
  bool getSigned() const noexcept;

  void beSigned(const Bureaucrat &bureaucrat);
  virtual void execute(Bureaucrat const &executor) const = 0;

private:
  const std::string _name;
  const int _gradeSign;
  const int _gradeExecute;
  bool _signed;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
