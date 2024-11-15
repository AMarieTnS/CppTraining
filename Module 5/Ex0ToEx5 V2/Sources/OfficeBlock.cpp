#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock()
    : _intern(nullptr), _signing(nullptr), _executing(nullptr) {}

OfficeBlock::OfficeBlock(Intern &intern, Bureaucrat &signing,
                         Bureaucrat &executing)
    : _intern(&intern), _signing(&signing), _executing(&executing) {}

void OfficeBlock::setIntern(Intern &intern) { _intern = &intern; }

void OfficeBlock::setSigner(Bureaucrat &signing) { _signing = &signing; }

void OfficeBlock::setExecutor(Bureaucrat &executing) {
  _executing = &executing;
}

void OfficeBlock::doBureaucracy(const std::string &formName,
                                const std::string &target) const {
  if (!_intern || !_signing || !_executing) {
    throw SpecificException();
  }

  Form *form = _intern->makeForm(formName, target);
  _signing->signForm(*form);
  _executing->executeForm(*form);
  delete form;
}