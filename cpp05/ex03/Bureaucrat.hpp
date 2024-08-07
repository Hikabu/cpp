#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
// #include "Form.hpp"

class AForm;

class Bureaucrat{
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &copy);
        ~Bureaucrat();

        // functions
        void        incrementGrade();
        void        decrementGrade();
        void        signForm(AForm& isSigned);
        void        executeForm(AForm const &form);

        //exceptions
        class GradeTooHighException : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw(); //dont throw exception(more predictiable)
        };

        //get/set
        std::string getName() const;
        int         getGrade() const ;
        void        setGrade(int grade);
};
    std::ostream &operator<<(std::ostream &out, const Bureaucrat& bureaucrat);

#endif
