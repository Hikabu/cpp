#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"

class Intern{
    public:
        Intern ();
        Intern (const Intern  &toCopy);
        Intern  &operator=(const Intern  &value);
        ~Intern ();

        AForm *makeForm(std::string const &formName, std::string const &formTarget) const;
        class FormNotFound : public std::exception{
            public:
                virtual const char *what() const throw();
        };
};


#endif
