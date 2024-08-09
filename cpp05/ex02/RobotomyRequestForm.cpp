#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_GREY "\x1b[90m"
#define COLOR_CLEAN "\x1b[0m"

 RobotomyRequestForm::RobotomyRequestForm() : AForm()                                                          
{
}
 RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45)                                                          
{
    setTarget(target);
}

 RobotomyRequestForm:: RobotomyRequestForm(const RobotomyRequestForm &toCopy) : AForm(toCopy){
    // If ShrubberyCreationForm has any additional members not in AForm,
    // initialize them here. Otherwise, leave this empty.
}

 RobotomyRequestForm & RobotomyRequestForm::operator=(const  RobotomyRequestForm &toCopy) {
    if (this == &toCopy)
        return (*this);
    AForm::operator=(toCopy);
    return (*this);
}

 RobotomyRequestForm::~ RobotomyRequestForm(){}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const{
    if (executor.getGrade() > AForm::getgradeExecReq())
        throw GradeTooLowException();
    else if (getIndicator() == false)
        throw FormNotSignedException();
    std::cout << COLOR_GREEN << "Some noises: SegFoultSegFoultSegFoultSegFoultSegFoult" << COLOR_CLEAN << std::endl;
    int randVal = std::rand();
    if (randVal % 2 == 0)
        std::cout << _target << " has been robotomized successfully " << std::endl;
    else
        std::cout << getTarget() << " robotomy failed " << std::endl;
}
