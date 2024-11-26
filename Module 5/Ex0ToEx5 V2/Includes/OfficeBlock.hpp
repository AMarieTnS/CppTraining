#ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <memory>

class OfficeBlock {
public:
  OfficeBlock();
  OfficeBlock(std::unique_ptr<Intern> intern, std::unique_ptr<Bureaucrat> signing, std::unique_ptr<Bureaucrat> executing);
  OfficeBlock(const OfficeBlock &other) = delete;
  OfficeBlock(OfficeBlock &&other) = delete;
  OfficeBlock &operator=(const OfficeBlock &other) = delete;
  OfficeBlock &operator=(OfficeBlock &&other) = delete;
  ~OfficeBlock() = default;
  void SetIntern(std::unique_ptr<Intern> intern);
  void SetSigner(std::unique_ptr<Bureaucrat> signing);
  void SetExecutor(std::unique_ptr<Bureaucrat> executing);

  void DoBureaucracy(FormType formType, const std::string &target) const;

private:
  std::unique_ptr<Intern> _intern;
  std::unique_ptr<Bureaucrat> _signing;
  std::unique_ptr<Bureaucrat> _executing;
};

#endif