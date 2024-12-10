#include "OfficeBlock.hpp"
#include "GenericForm.hpp"
#include <iostream>

OfficeBlock::OfficeBlock()
{
    InitializeFormCreationMap();
}

OfficeBlock::OfficeBlock(std::unique_ptr<Intern> intern, std::unique_ptr<Bureaucrat> signing, std::unique_ptr<Bureaucrat> executing)
    : _intern(std::move(intern)), _signing(std::move(signing)), _executing(std::move(executing))
{
    InitializeFormCreationMap();
}

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

void OfficeBlock::InitializeFormCreationMap()
{
    _formCreationMap["mutant pig termination"] = &OfficeBlock::CreateGenericForm;
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
    auto it = _formCreationMap.find(formName);
    if (it != _formCreationMap.end())
    {
        form = (this->*(it->second))(formName, target);
    }
    else
    {
        form = _intern->MakeForm(formName, target);
    }

    std::cout << "Intern creates a " << form->GetName() << " Form (s.grade " << form->GetGradeSign()
              << ", ex.grade " << form->GetGradeExecute() << ") targeted on " << target << " (Unsigned)" << std::endl;

    _signing->SignForm(*form);
    _executing->ExecuteForm(*form);
}