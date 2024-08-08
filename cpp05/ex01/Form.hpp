#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
// #include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private:
        const std::string   _name;
        bool                _indicator;
        const int           _gradeReqmnt;
        const int           _gradeExecReq;
    public:
        Form();
        Form(const std::string &name, const int gradeReqmnt, const int gradeExecReq);
        Form(const Form &copy);
        Form &operator=(const Form &copy);
        ~Form();

        //exceptions
        class GradeTooHighException : public std::exception{
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                virtual const char *what() const throw();
        };

        //get
        std::string getName() const;
        bool        getIndicator() const;
        int         getSignIn() const;
        int         getgradeExecReq() const;

        //functions 
        void beSigned(Bureaucrat const &bureaucrat);
       
};
    std::ostream &operator<<(std::ostream &out, const Form& Form);

#endif

