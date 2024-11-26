#ifndef MUTANTPIGTERMINATIONFORM_HPP
#define MUTANTPIGTERMINATIONFORM_HPP

#include "Form.hpp"
#include <string>

class MutantPigTerminationForm : public Form
{
public:
    MutantPigTerminationForm(const std::string &target);
    MutantPigTerminationForm(const MutantPigTerminationForm &other) = delete;
    MutantPigTerminationForm(MutantPigTerminationForm &&other) = delete;
    MutantPigTerminationForm &operator=(const MutantPigTerminationForm &other) = delete;
    MutantPigTerminationForm &operator=(MutantPigTerminationForm &&other) = delete;
    virtual ~MutantPigTerminationForm() = default;
    void Execute(const Bureaucrat &executor) const override;
};

#endif