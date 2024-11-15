#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "Exceptions.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>
#include <string>

class PresidentialPardonForm : public Form {
public:
  PresidentialPardonForm(const std::string &target);
  virtual ~PresidentialPardonForm() = default;
  void execute(const Bureaucrat &executor) const override;
  const std::string &getTarget() const override;

private:
  std::string _target;
};

#endif
