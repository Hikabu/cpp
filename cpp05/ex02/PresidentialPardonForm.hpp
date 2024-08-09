#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm{
    public:
        PresidentialPardonForm ();
        PresidentialPardonForm (std::string _target); //constructors are not inherit 
        PresidentialPardonForm (const PresidentialPardonForm  &toCopy);
        PresidentialPardonForm  &operator=(const PresidentialPardonForm  &value);
        virtual ~PresidentialPardonForm ();

        virtual void execute(Bureaucrat const &executor) const;


};


#endif
