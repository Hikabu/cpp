#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm{
    private:
        const std::string   _name;
        bool                _indicator;
        const int           _gradeReqmnt;
        const int           _gradeExecReq;
        std::string         _target;

    public:
        AForm(const std::string &name, const int gradeReqmnt, const int gradeExecReq);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &copy);
        virtual ~AForm();

        //exceptions

        class GradeTooHighException : public std::exception{
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                virtual const char *what() const throw();
        };
         class FormNotSignedException : public std::exception{
            public:
                virtual const char *what() const throw();
        };

        //get set
        virtual std::string getName() const;
        virtual bool        getIndicator() const;
        virtual int         getSignIn() const;
        virtual int         getgradeExecReq() const;
        virtual std::string getTarget() const;

        virtual void        setTarget(const std::string target);

        //functions 
        void virtual beSigned(Bureaucrat const &bureaucrat);
        void virtual execute(Bureaucrat const &executor) const = 0;
       
};
    std::ostream &operator<<(std::ostream &out, const AForm& AForm);

#endif
