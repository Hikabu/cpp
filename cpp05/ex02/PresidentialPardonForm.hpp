#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm{
    public:
        PresidentialPardonForm (std::string _target);
        PresidentialPardonForm (const PresidentialPardonForm  &toCopy);
        PresidentialPardonForm  &operator=(const PresidentialPardonForm  &value);
        virtual ~PresidentialPardonForm ();

        virtual void execute(Bureaucrat const &executor) const;


};


#endif
