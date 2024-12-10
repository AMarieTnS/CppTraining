#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock()
    : _intern(nullptr), _signing(nullptr), _executing(nullptr) {}

OfficeBlock::OfficeBlock(Intern &intern, Bureaucrat &signing,
                         Bureaucrat &executing)
    : _intern(&intern), _signing(&signing), _executing(&executing) {}

void OfficeBlock::SetIntern(Intern &intern) { this->_intern = &intern; }

void OfficeBlock::SetSigner(Bureaucrat &signing) { this->_signing = &signing; }

void OfficeBlock::SetExecutor(Bureaucrat &executing) {
  this->_executing = &executing;
}

void OfficeBlock::doBureaucracy(const std::string &formName,
                                const std::string &target) const {
  if (!_intern || !_signing || !_executing) {
    throw SpecificException();
  }

  Form *form = _intern->makeForm(formName, target);
  if (!form) {
    throw SpecificException();
  }

  try {
    _signing->signForm(*form);
    std::cout << "Bureaucrat " << _signing->getName() << " (Grade "
              << _signing->getGrade()
              << ") signs a Mutant Pig Termination Form (s.grade 130, ex.grade "
                 "50) targeted on "
              << target << " (Unsigned)" << std::endl;
  } catch (const std::exception &e) {
    delete form;
    throw;
  }

  try {
    _executing->executeForm(*form);
    std::cout << "Bureaucrat " << _executing->getName() << " (Grade "
              << _executing->getGrade()
              << ") executes a Mutant Pig Termination Form (s.grade 130, "
                 "ex.grade 50) targeted on "
              << target << " (Signed)" << std::endl;
    std::cout << "That'll do, " << target << ". That'll do..." << std::endl;
  } catch (const std::exception &e) {
    delete form;
    throw;
  }

  delete form;
}
