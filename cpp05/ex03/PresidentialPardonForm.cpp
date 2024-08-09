#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

 PresidentialPardonForm::PresidentialPardonForm() : AForm()
{
}
 PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
    setTarget(target);
}

 PresidentialPardonForm:: PresidentialPardonForm(const  PresidentialPardonForm &toCopy) : AForm(toCopy){
    // If ShrubberyCreationForm has any additional members not in AForm,
    // initialize them here. Otherwise, leave this empty.
}

 PresidentialPardonForm & PresidentialPardonForm::operator=(const  PresidentialPardonForm &toCopy){
    if (this == &toCopy)
        return (*this);
    AForm::operator=(toCopy);
    return (*this);
}

 PresidentialPardonForm::~ PresidentialPardonForm(){
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const{
    if (executor.getGrade() > AForm::getgradeExecReq())
        throw GradeTooLowException();
    else if (getIndicator() == false)
        throw FormNotSignedException();
    std::cout  << _target << " has been pardoned by Zaphod Beeblebrox " << std::endl;
}
