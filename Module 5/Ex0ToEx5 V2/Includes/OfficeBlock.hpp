#ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <memory>

class OfficeBlock
{
public:
  /* Constructors */
  OfficeBlock();
  OfficeBlock(std::unique_ptr<Intern> intern, std::unique_ptr<Bureaucrat> signing, std::unique_ptr<Bureaucrat> executing);
  OfficeBlock(const OfficeBlock &other) = delete;
  OfficeBlock(OfficeBlock &&other) = delete;
  OfficeBlock &operator=(const OfficeBlock &other) = delete;
  OfficeBlock &operator=(OfficeBlock &&other) = delete;
  ~OfficeBlock() = default;

  /* Execution Functions */
  void DoBureaucracy(const std::string &formName, const std::string &target);

  /* Setters */
  void SetIntern(std::unique_ptr<Intern> intern);
  void SetSigner(std::unique_ptr<Bureaucrat> signing);
  void SetExecutor(std::unique_ptr<Bureaucrat> executing);

private:
  std::unique_ptr<Form> CreateGenericForm(const std::string &formName, const std::string &target);
  std::unique_ptr<Intern> _intern;
  std::unique_ptr<Bureaucrat> _signing;
  std::unique_ptr<Bureaucrat> _executing;

  struct FormCreationEntry
  {
    const char *formName;
    std::unique_ptr<Form> (OfficeBlock::*createForm)(const std::string &, const std::string &);
  };

  static const FormCreationEntry formCreationArray[];
};

#endif