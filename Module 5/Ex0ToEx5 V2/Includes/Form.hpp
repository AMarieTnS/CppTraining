#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Exceptions.hpp"
#include "memory"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
  Form(const std::string &name, int gradeSign, int gradeExecute, std::string target);
  Form(const Form &other) = delete;
  Form(Form &&other) = delete;
  Form &operator=(const Form &other) = delete;
  Form &operator=(Form &&other) = delete;
  virtual ~Form() = default;

  const std::string &GetName() const noexcept;
  bool IsSigned() const noexcept;
  int GetGradeSign() const noexcept;
  int GetGradeExecute() const noexcept;
  void BeSigned(const Bureaucrat &bureaucrat);
  virtual void Execute(const Bureaucrat &executor) const = 0;
  const std::string &GetTarget() const noexcept;

private:
  const std::string _name;
  bool _signed;
  const int _gradeSign;
  const int _gradeExecute;
  const std::string _target;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif