#include "Form.hpp"
#include "Bureaucrat.hpp"

#define COLOR_CLEAN "\x1b[0m"
#define COLOR_A "\x1b[34m"

Form::Form(const std::string &name,const int gradeReqmnt, const int gradeExecReq) : 
                                _name(name),
                                _gradeReqmnt(gradeReqmnt),
                                _gradeExecReq(gradeExecReq)
{
    _indicator = false;
    std::cout << "condtructor called" << std::endl; 
}

Form::Form(const Form &copy) : _name(copy._name),
                                _gradeReqmnt(copy._gradeReqmnt),
                                _gradeExecReq(copy._gradeExecReq){
    *this = copy;
}

Form &Form::operator=(const Form &copy){
    if (this != &copy){
        this->_indicator = copy._indicator;
    }
    return (*this);
}
std::ostream &operator<<(std::ostream &out, const Form& Form){
    return (out << COLOR_A << "info about Form"  << "\n\tSignIn: " << Form.getSignIn() \
        << "\n\tExecute: " << Form.getgradeExecReq() \
        << "\n\tname is: " << Form.getName() << COLOR_CLEAN << std::endl);
}
Form::~Form(){}

//get 
std::string Form::getName() const {return _name;}
bool        Form::getIndicator() const {return _indicator;}
int         Form::getSignIn() const {return _gradeReqmnt;}
int         Form::getgradeExecReq() const {return _gradeExecReq;}

//exceptions 

const char *Form::GradeTooHighException::what() const throw(){
    return ("Grade is too high...");
}
const char *Form::GradeTooLowException::what() const throw(){
    return ("Grade is too low...");
}

//functions 
void    Form::beSigned(Bureaucrat& bureaucrat){
    if (bureaucrat.getGrade() > _gradeReqmnt)
        throw GradeTooLowException();
    _indicator = true;
}