#include "OfficeBlock.hpp"
#include <memory>

OfficeBlock::OfficeBlock() : _intern(nullptr), _signing(nullptr), _executing(nullptr) {}

OfficeBlock::OfficeBlock(std::unique_ptr<Intern> intern, std::unique_ptr<Bureaucrat> signing, std::unique_ptr<Bureaucrat> executing)
    : _intern(std::move(intern)), _signing(std::move(signing)), _executing(std::move(executing)) {}

void OfficeBlock::setIntern(std::unique_ptr<Intern> intern)
{
    _intern = std::move(intern);
}

void OfficeBlock::setSigner(std::unique_ptr<Bureaucrat> signing)
{
    _signing = std::move(signing);
}

void OfficeBlock::setExecutor(std::unique_ptr<Bureaucrat> executing)
{
    _executing = std::move(executing);
}
void OfficeBlock::doBureaucracy(const std::string &formName,
                                const std::string &target) const {
  if (!_intern || !_signing || !_executing) {
      throw GradeTooHighException();
  }

  std::unique_ptr<Form> form = _intern->makeForm(formName, target);
  _signing->signForm(*form);
  _executing->executeForm(*form);
}