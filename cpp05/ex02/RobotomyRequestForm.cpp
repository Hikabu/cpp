#include "RobotomyRequestForm.hpp"

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_GREY "\x1b[90m"
#define COLOR_CLEAN "\x1b[0m"

 RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{

}

 RobotomyRequestForm:: RobotomyRequestForm(const RobotomyRequestForm &toCopy) : AForm(toCopy){
    *this = toCopy;
    
}

 RobotomyRequestForm & RobotomyRequestForm::operator=(const  RobotomyRequestForm &toCopy) {
    
    return (*this);
}

 RobotomyRequestForm::~ RobotomyRequestForm(){
}


