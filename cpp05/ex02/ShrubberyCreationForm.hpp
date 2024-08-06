#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
    public:
        ShrubberyCreationForm ();
        ShrubberyCreationForm (const ShrubberyCreationForm  &toCopy);
        ShrubberyCreationForm  &operator=(const ShrubberyCreationForm  &value);
        virtual ~ShrubberyCreationForm ();

};


#endif