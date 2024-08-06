#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>

class PresidentialPardonForm {
    private:



    public:
        PresidentialPardonForm ();
        PresidentialPardonForm (const PresidentialPardonForm  &toCopy);
        PresidentialPardonForm  &operator=(const PresidentialPardonForm  &value);
        ~PresidentialPardonForm ();

};


#endif