#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Exceptions.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
public:
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const Form &other) = delete;
  virtual ~Bureaucrat() = default;
  Bureaucrat(Form &&other) = delete;
  Bureaucrat &operator=(const Form &other) = delete;
  Bureaucrat &operator=(Form &&other) = delete;

  const std::string &GetName() const;
  int GetGrade() const;
  void IncrementGrade();
  void DecrementGrade();

  void SignForm(Form &form);
  void ExecuteForm(const Form &form) const;

private:
  const std::string _name;
  int _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif