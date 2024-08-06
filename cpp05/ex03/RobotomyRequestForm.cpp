#include "RobotomyRequestForm.hpp"

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_GREY "\x1b[90m"
#define COLOR_CLEAN "\x1b[0m"

 RobotomyRequestForm::RobotomyRequestForm()
{
    
    std::cout << "Constructor called" << std::endl;
}

 RobotomyRequestForm:: RobotomyRequestForm(const  RobotomyRequestForm &toCopy){
    *this = toCopy;
    std::cout << "Copy constructor called" << std::endl;
}

 RobotomyRequestForm & RobotomyRequestForm::operator=(const  RobotomyRequestForm &toCopy){
    std::cout << " RobotomyRequestForm assignation operator called" << std::endl;
    return (*this);
}

 RobotomyRequestForm::~ RobotomyRequestForm(){
    std::cout << "Destructor called" << std::endl;
}


