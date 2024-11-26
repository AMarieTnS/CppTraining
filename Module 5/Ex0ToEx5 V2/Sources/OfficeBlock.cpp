#include "OfficeBlock.hpp"
#include "Form.hpp"
#include <iostream>

OfficeBlock::OfficeBlock() : _intern(nullptr), _signing(nullptr), _executing(nullptr) {}

OfficeBlock::OfficeBlock(std::unique_ptr<Intern> intern, std::unique_ptr<Bureaucrat> signing, std::unique_ptr<Bureaucrat> executing)
    : _intern(std::move(intern)), _signing(std::move(signing)), _executing(std::move(executing)) {}

void OfficeBlock::SetIntern(std::unique_ptr<Intern> intern)
{
    _intern = std::move(intern);
}

void OfficeBlock::SetSigner(std::unique_ptr<Bureaucrat> signing)
{
    _signing = std::move(signing);
}

void OfficeBlock::SetExecutor(std::unique_ptr<Bureaucrat> executing)
{
    _executing = std::move(executing);
}

void OfficeBlock::DoBureaucracy(FormType formType, const std::string &target) const
{
    if (!_intern || !_signing || !_executing)
    {
        throw std::runtime_error("OfficeBlock is not fully staffed.");
    }
    std::unique_ptr<Form> form = _intern->MakeForm(formType, target);
    _signing->SignForm(*form);
    _executing->ExecuteForm(*form);
}