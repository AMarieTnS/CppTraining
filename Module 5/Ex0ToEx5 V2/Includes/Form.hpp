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
/* Constructors */
  Form(const std::string &name, int gradeSign, int gradeExecute, std::string target);
  Form(const Form &other) = delete;
  Form(Form &&other) = delete;
  Form &operator=(const Form &other) = delete;
  Form &operator=(Form &&other) = delete;
  virtual ~Form() = default;

  /* Execution Functions */
  virtual void Execute(const Bureaucrat &executor) const = 0;
  bool IsSigned() const noexcept;
  void BeSigned(const Bureaucrat &bureaucrat);

  /* Getters */
  const std::string &GetName() const noexcept;
  int GetGradeSign() const noexcept;
  int GetGradeExecute() const noexcept;
  const std::string &GetTarget() const noexcept;

private:
  const std::string _name;
  bool _signed;
  const int _gradeSign;
  const int _gradeExecute;
  const std::string _target;

protected:
  void CheckExecution(const Bureaucrat &executor) const;
};

/* Operator Overload */
std::ostream &operator<<(std::ostream &os, const Form &form);

#endif