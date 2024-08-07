#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm{
    private:
        std::string _target;
    public:
        RobotomyRequestForm (const std::string target);
        RobotomyRequestForm (const RobotomyRequestForm  &toCopy);
        RobotomyRequestForm  &operator=(const RobotomyRequestForm  &value);
        virtual ~RobotomyRequestForm ();

        void execute(Bureaucrat const &executor) const;
};


#endif
