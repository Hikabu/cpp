#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm{
    public:
        PresidentialPardonForm ();
        PresidentialPardonForm (const PresidentialPardonForm  &toCopy);
        PresidentialPardonForm  &operator=(const PresidentialPardonForm  &value);
        virtual ~PresidentialPardonForm ();

};


#endif