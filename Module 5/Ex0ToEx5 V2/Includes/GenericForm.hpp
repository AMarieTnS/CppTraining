#ifndef GENERICFORM_HPP
#define GENERICFORM_HPP

#include "Form.hpp"

class GenericForm : public Form
{
public:
    /* Constructors */
    GenericForm(const std::string &name, int gradeSign, int gradeExecute, const std::string &target);
    GenericForm(const GenericForm &other) = delete;
    GenericForm(GenericForm &&other) = delete;
    GenericForm &operator=(const GenericForm &other) = delete;
    GenericForm &operator=(GenericForm &&other) = delete;
    virtual ~GenericForm() = default;

    /* Execution Functions */
    void Execute(const Bureaucrat &executor) const override;
};

#endif