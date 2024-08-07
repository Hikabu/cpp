#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm (const std::string target);
        ShrubberyCreationForm (const ShrubberyCreationForm  &toCopy);
        ShrubberyCreationForm  &operator=(const ShrubberyCreationForm  &value);
        virtual ~ShrubberyCreationForm ();

        virtual void execute(Bureaucrat const& executor) const;
};


#endif
