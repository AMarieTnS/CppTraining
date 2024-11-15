#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "Exceptions.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>
#include <string>

class ShrubberyCreationForm : public Form {
public:
  ShrubberyCreationForm(const std::string &target);
  virtual ~ShrubberyCreationForm() = default;
  void execute(const Bureaucrat &executor) const override;
  const std::string &getTarget() const override;

private:
  std::string _target;
};

#endif