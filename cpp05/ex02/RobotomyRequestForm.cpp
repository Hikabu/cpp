#include "RobotomyRequestForm.hpp"

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_GREY "\x1b[90m"
#define COLOR_CLEAN "\x1b[0m"

 RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45),
                                                                        _target(target)
{
}

 RobotomyRequestForm:: RobotomyRequestForm(const RobotomyRequestForm &toCopy) : AForm(toCopy){
    *this = toCopy;
    
}

 RobotomyRequestForm & RobotomyRequestForm::operator=(const  RobotomyRequestForm &toCopy) {
    if (this == &toCopy)
        return (*this);
    AForm::operator=(toCopy);
    return (*this);
}

 RobotomyRequestForm::~ RobotomyRequestForm(){}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const{
    (void)executor;
    std::cout << COLOR_GREEN << "Some noises: SegFoultSegFoultSegFoultSegFoultSegFoult" << COLOR_CLEAN << std::endl;
    int randVal = std::rand();
    if (randVal % 2 == 0)
        std::cout << _target << " has been robotomized successfully " << std::endl;
    else
        std::cout << getTarget() << " robotomy failed " << std::endl;
}
