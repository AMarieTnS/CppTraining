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

    Form(const std::string &sName, int iGradeSign, int iGradeExecute);
    virtual ~Form() {}

    std::string GetName() const noexcept;
    bool isSigned() const noexcept;

    int GetGradeSign() const noexcept;
    int GetGradeExecute() const noexcept;
    bool GetSigned() const noexcept;

    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;

  private:
    const std::string sName;
    const int iGradeSign;
    const int iGradeExecute;
    bool bSigned;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
