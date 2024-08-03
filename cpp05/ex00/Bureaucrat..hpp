#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat{
    private:
        const std::string _name;

    public:
       Bureaucrat();
       Bureaucrat(const Bureaucrat &copy);
       Bureaucrat &operator=(const Bureaucrat &copy);
        ~Bureaucrat();
        
};

#endif