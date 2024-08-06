#include "ShrubberyCreationForm.hpp"

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_GREY "\x1b[90m"
#define COLOR_CLEAN "\x1b[0m"

 ShrubberyCreationForm::ShrubberyCreationForm()
{
    
    std::cout << "Constructor called" << std::endl;
}

 ShrubberyCreationForm:: ShrubberyCreationForm(const  ShrubberyCreationForm &toCopy){
    *this = toCopy;
    std::cout << "Copy constructor called" << std::endl;
}

 ShrubberyCreationForm & ShrubberyCreationForm::operator=(const  ShrubberyCreationForm &toCopy){
    std::cout << " ShrubberyCreationForm assignation operator called" << std::endl;
    return (*this);
}

 ShrubberyCreationForm::~ ShrubberyCreationForm(){
    std::cout << "Destructor called" << std::endl;
}


