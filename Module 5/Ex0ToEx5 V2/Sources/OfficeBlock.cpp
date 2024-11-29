#include "OfficeBlock.hpp"
#include <iostream>
#include <GenericForm.hpp>

const OfficeBlock::FormCreationEntry OfficeBlock::formCreationArray[] = {
    {"mutant pig termination", &OfficeBlock::CreateGenericForm},
    {nullptr, nullptr}};

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

std::unique_ptr<Form> OfficeBlock::CreateGenericForm(const std::string &formName, const std::string &target)
{
    if (formName == "mutant pig termination")
    {
        return std::make_unique<GenericForm>("Mutant Pig Termination", 130, 50, target);
    }
    throw UnknownFormException();
}

void OfficeBlock::DoBureaucracy(const std::string &formName, const std::string &target)
{
    if (!_intern || !_signing || !_executing)
    {
        throw UnknownFormException();
    }

    std::unique_ptr<Form> form;
    for (int i = 0; formCreationArray[i].formName != nullptr; ++i)
    {
        if (formName == formCreationArray[i].formName)
        {
            form = (this->*formCreationArray[i].createForm)(formName, target);
            break;
        }
    }

    if (!form)
    {
        form = _intern->MakeForm(formName, target);
    }

    std::cout << "Intern creates a " << form->GetName() << " Form (s.grade " << form->GetGradeSign()
              << ", ex.grade " << form->GetGradeExecute() << ") targeted on " << target << " (Unsigned)" << std::endl;

    _signing->SignForm(*form);
    _executing->ExecuteForm(*form);
}