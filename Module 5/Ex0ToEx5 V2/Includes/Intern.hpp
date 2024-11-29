#ifndef INTERN_HPP
#define INTERN_HPP

#include <memory>
#include <string>
#include "Form.hpp"
#include <functional>

class Intern
{
public:
  /* Constructors */
  Intern() = default;
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

  struct FormCreationEntry
  {
    const char *formName;
    std::unique_ptr<Form> (Intern::*createForm)(const std::string &);
  };

  static const FormCreationEntry formCreationArray[];
};

#endif