#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>

class ShrubberyCreationForm {
    private:



    public:
        ShrubberyCreationForm ();
        ShrubberyCreationForm (const ShrubberyCreationForm  &toCopy);
        ShrubberyCreationForm  &operator=(const ShrubberyCreationForm  &value);
        ~ShrubberyCreationForm ();

};


#endif