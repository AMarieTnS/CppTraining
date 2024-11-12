#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

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

  Bureaucrat(const std::string &sName, int iGrade);

  std::string GetName() const noexcept;
  int GetGrade() const noexcept;

  void IncrementGrade();
  void DecrementGrade();

private:
  const std::string sName;
  int iGrade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif