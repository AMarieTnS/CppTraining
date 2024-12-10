#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern()
{
  InitializeFormCreationMap();
}

void Intern::InitializeFormCreationMap()
{
  _formCreationMap["shrubbery creation"] = &Intern::CreateShrubberyForm;
  _formCreationMap["robotomy request"] = &Intern::CreateRobotomyForm;
  _formCreationMap["presidential pardon"] = &Intern::CreatePardonForm;
}

std::unique_ptr<Form> Intern::MakeForm(const std::string &formName, const std::string &target)
{
  auto it = _formCreationMap.find(formName);
  if (it != _formCreationMap.end())
  {
    return (this->*(it->second))(target);
  }
  throw UnknownFormException();
}

std::unique_ptr<Form> Intern::CreateShrubberyForm(const std::string &target)
{
  return std::make_unique<ShrubberyCreationForm>(target);
}

std::unique_ptr<Form> Intern::CreateRobotomyForm(const std::string &target)
{
  return std::make_unique<RobotomyRequestForm>(target);
}

std::unique_ptr<Form> Intern::CreatePardonForm(const std::string &target)
{
  return std::make_unique<PresidentialPardonForm>(target);
}