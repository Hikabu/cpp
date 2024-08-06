#include "ShrubberyCreationForm.hpp"

 ShrubberyCreationForm::ShrubberyCreationForm() : AForm ("ShrubberyCreationForm", 145, 137)
{
}

 ShrubberyCreationForm:: ShrubberyCreationForm(const  ShrubberyCreationForm &toCopy) : AForm(toCopy){
    *this = toCopy;
}

 ShrubberyCreationForm & ShrubberyCreationForm::operator=(const  ShrubberyCreationForm &toCopy){
    if (this == &toCopy)
        return (*this);
    AForm::operator=(toCopy); //copy itself 
    return(*this);
}

 ShrubberyCreationForm::~ ShrubberyCreationForm(){

 }


