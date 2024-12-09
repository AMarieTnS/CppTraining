#ifndef INTERN_HPP
#define INTERN_HPP

#include <memory>
#include <string>
#include <map>
#include "Form.hpp"

class Intern
{
public:
  /* Constructors */
  Intern();
  Intern(const Intern &other) = delete;
  Intern(Intern &&other) = delete;
  Intern &operator=(const Intern &other) = delete;
  Intern &operator=(Intern &&other) = delete;
  virtual ~Intern() = default;

  /* Execution Functions */
  std::unique_ptr<Form> MakeForm(const std::string &formName, const std::string &target);

private:
  std::unique_ptr<Form> CreateShrubberyForm(const std::string &target);
  std::unique_ptr<Form> CreateRobotomyForm(const std::string &target);
  std::unique_ptr<Form> CreatePardonForm(const std::string &target);

  void InitializeFormCreationMap();

  std::map<std::string, std::unique_ptr<Form> (Intern::*)(const std::string &)> _formCreationMap;
};

#endif