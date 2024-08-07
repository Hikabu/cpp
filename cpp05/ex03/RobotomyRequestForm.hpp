#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm{
    public:
        RobotomyRequestForm ();
        RobotomyRequestForm (const std::string target);
        RobotomyRequestForm (const RobotomyRequestForm  &toCopy);
        RobotomyRequestForm  &operator=(const RobotomyRequestForm  &value);
        virtual ~RobotomyRequestForm ();

        virtual void execute(Bureaucrat const &executor) const;
};


#endif
