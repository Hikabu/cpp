#include "PresidentialPardonForm.hpp"

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_GREY "\x1b[90m"
#define COLOR_CLEAN "\x1b[0m"

 PresidentialPardonForm::PresidentialPardonForm()
{
    
    std::cout << "Constructor called" << std::endl;
}

 PresidentialPardonForm:: PresidentialPardonForm(const  PresidentialPardonForm &toCopy){
    *this = toCopy;
    std::cout << "Copy constructor called" << std::endl;
}

 PresidentialPardonForm & PresidentialPardonForm::operator=(const  PresidentialPardonForm &toCopy){
    std::cout << " PresidentialPardonForm assignation operator called" << std::endl;
    return (*this);
}

 PresidentialPardonForm::~ PresidentialPardonForm(){
    std::cout << "Destructor called" << std::endl;
}


