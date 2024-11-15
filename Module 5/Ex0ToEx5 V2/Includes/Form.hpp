#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;
#include "Exceptions.hpp"

class Form {
public:
  Form(const std::string &name, int gradeSign, int gradeExecute);
  virtual ~Form() = default;

  const std::string &getName() const noexcept;
  bool isSigned() const noexcept;
  int getGradeSign() const noexcept;
  int getGradeExecute() const noexcept;
  void beSigned(const Bureaucrat &bureaucrat);
  virtual void execute(const Bureaucrat &executor) const = 0;
  virtual const std::string &getTarget() const = 0;

private:
  const std::string _name;
  bool _signed;
  const int _gradeSign;
  const int _gradeExecute;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif