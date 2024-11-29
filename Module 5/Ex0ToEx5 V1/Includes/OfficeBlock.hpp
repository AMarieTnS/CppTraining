#ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include <exception>
#include <iostream>
#include <string>

class OfficeBlock {
public:
  class SpecificException : public std::exception {
  public:
    const char *what() const noexcept override { return "SpecificException"; }
  };

  OfficeBlock();
  OfficeBlock(Intern &intern, Bureaucrat &signing, Bureaucrat &executing);
  ~OfficeBlock() = default;

  void SetIntern(Intern &intern);
  void SetSigner(Bureaucrat &signing);
  void SetExecutor(Bureaucrat &executing);

  void doBureaucracy(const std::string &name, const std::string &target) const;

private:
  Intern *_intern;
  Bureaucrat *_signing;
  Bureaucrat *_executing;
};

#endif
