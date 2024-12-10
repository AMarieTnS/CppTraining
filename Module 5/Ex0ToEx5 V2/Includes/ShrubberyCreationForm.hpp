#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "Exceptions.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>
#include <string>

class ShrubberyCreationForm : public Form
{
public:
  /* Constructors */
  ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other) = delete;
  ShrubberyCreationForm(ShrubberyCreationForm &&other) = delete;
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other) = delete;
  ShrubberyCreationForm &operator=(ShrubberyCreationForm &&other) = delete;
  ~ShrubberyCreationForm() = default;

  /* Execution Functions */
  void Execute(const Bureaucrat &executor) const override;
};

#endif