#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <memory>
#include <map>
#include <iostream>

const Intern::FormCreationEntry Intern::formCreationArray[] = {
    {"shrubbery creation", &Intern::CreateShrubberyForm},
    {"robotomy request", &Intern::CreateRobotomyForm},
    {"presidential pardon", &Intern::CreatePardonForm},
    {nullptr, nullptr}};

std::unique_ptr<Form> Intern::MakeForm(const std::string &formName, const std::string &target)
{
  for (int i = 0; formCreationArray[i].formName != nullptr; ++i)
  {
    if (formName == formCreationArray[i].formName)
    {
      return (this->*formCreationArray[i].createForm)(target);
    }
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