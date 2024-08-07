#include "PresidentialPardonForm.hpp"


 PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
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


