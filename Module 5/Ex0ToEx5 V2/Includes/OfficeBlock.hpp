#ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <memory>

class OfficeBlock {
public:
  OfficeBlock();
  OfficeBlock(std::unique_ptr<Intern> intern, std::unique_ptr<Bureaucrat> signing, std::unique_ptr<Bureaucrat> executing);
  ~OfficeBlock() = default;

  void setIntern(std::unique_ptr<Intern> intern);
  void setSigner(std::unique_ptr<Bureaucrat> signing);
  void setExecutor(std::unique_ptr<Bureaucrat> executing);

  void doBureaucracy(const std::string &formName, const std::string &target) const;

private:
  std::unique_ptr<Intern> _intern;
  std::unique_ptr<Bureaucrat> _signing;
  std::unique_ptr<Bureaucrat> _executing;
};

#endif