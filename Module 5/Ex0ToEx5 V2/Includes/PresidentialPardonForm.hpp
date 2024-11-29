#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "Exceptions.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>
#include <string>

class PresidentialPardonForm : public Form
{
public:
  /* Constructors */
  PresidentialPardonForm(const std::string &target);
  PresidentialPardonForm(const PresidentialPardonForm &other) = delete;
  PresidentialPardonForm(PresidentialPardonForm &&other) = delete;
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other) = delete;
  PresidentialPardonForm &operator=(PresidentialPardonForm &&other) = delete;
  ~PresidentialPardonForm() = default;

  /* Execution Functions */
  void Execute(const Bureaucrat &executor) const override;
};

#endif