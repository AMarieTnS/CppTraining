#ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP

#include "Bureaucrat.hpp"
#include "Intern.hpp"

class OfficeBlock {
public:
  OfficeBlock();
  OfficeBlock(Intern &intern, Bureaucrat &signing, Bureaucrat &executing);
  ~OfficeBlock() = default;

  void setIntern(Intern &intern);
  void setSigner(Bureaucrat &signing);
  void setExecutor(Bureaucrat &executing);

  void doBureaucracy(const std::string &formName,
                     const std::string &target) const;

  class SpecificException : public std::exception {
  public:
    const char *what() const noexcept override { return "Grade too high"; }
  };

private:
  Intern *_intern;
  Bureaucrat *_signing;
  Bureaucrat *_executing;
};

#endif