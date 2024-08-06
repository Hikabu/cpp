#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>

class RobotomyRequestForm {
    private:



    public:
        RobotomyRequestForm ();
        RobotomyRequestForm (const RobotomyRequestForm  &toCopy);
        RobotomyRequestForm  &operator=(const RobotomyRequestForm  &value);
        ~RobotomyRequestForm ();

};


#endif