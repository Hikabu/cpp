#include "PresidentialPardonForm.hpp"


 PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5),
                                                                     _target(target)
{
}

 PresidentialPardonForm:: PresidentialPardonForm(const  PresidentialPardonForm &toCopy) : AForm(toCopy){
    *this = toCopy;
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
    (void)executor;
    std::cout  << _target << " has been pardoned by Zaphod Beeblebrox " << std::endl;
}
