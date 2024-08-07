#include "Form.hpp"
#include "Bureaucrat.hpp"

#define COLOR_CLEAN "\x1b[0m"
#define COLOR_A "\x1b[34m"

Form::Form() : _name("name"), _gradeReqmnt(150), _gradeExecReq(150)
{
    _indicator = false; // because it is boolean variable
}

Form::Form(const std::string &name,const int gradeReqmnt, const int gradeExecReq) : 
                                _name(name),
                                _gradeReqmnt(gradeReqmnt),
                                _gradeExecReq(gradeExecReq)
{

    if (_gradeExecReq < 1 || _gradeReqmnt < 1)
        throw(GradeTooHighException());
    if (_gradeExecReq > 150 || _gradeReqmnt > 150)
        throw(GradeTooLowException());
    else
        _indicator = false;
}

Form::Form(const Form &copy) : _name(copy._name),
                                _indicator(copy._indicator),
                                _gradeReqmnt(copy._gradeReqmnt),
                                _gradeExecReq(copy._gradeExecReq){}


Form &Form::operator=(const Form &copy){
    if (this != &copy){
        _indicator = copy._indicator; // const members must be initialized in the 
    }                                 //constructor's member initializer list.                   
    return (*this);
}
std::ostream &operator<<(std::ostream &out, const Form& Form){
    return (out << COLOR_A                              \
        << "info about Form"                            \
        << "\n\tForn grade for SignIn: " << Form.getSignIn() \
        << "\n\tForm grade to Execute: " << Form.getgradeExecReq() \
        << "\n\tand name is: " << Form.getName() << COLOR_CLEAN << std::endl);
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
void    Form::beSigned(Bureaucrat const &bureaucrat){
    if (bureaucrat.getGrade() > _gradeReqmnt)
        throw GradeTooLowException();
    _indicator = true;
}
