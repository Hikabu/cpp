#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define COLOR_CLEAN "\x1b[0m"
#define COLOR_A "\x1b[34m"

AForm::AForm(const std::string &name,const int gradeReqmnt, const int gradeExecReq) : 
                                _name(name),
                                _gradeReqmnt(gradeReqmnt),
                                _gradeExecReq(gradeExecReq)
{
    _indicator = false;
    if (_gradeExecReq < 1 || _gradeReqmnt < 1)
        throw(GradeTooHighException());
    if (_gradeExecReq > 150 || _gradeReqmnt > 150)
        throw(GradeTooLowException());
    // std::cout << "condtructor called" << std::endl; 
}

AForm::AForm(const AForm &copy) : _name(copy._name),
                                _gradeReqmnt(copy._gradeReqmnt),
                                _gradeExecReq(copy._gradeExecReq){
    *this = copy;
}

AForm &AForm::operator=(const AForm &copy){
    if (this != &copy){
        this->_indicator = copy._indicator;
    }
    return (*this);
}
std::ostream &operator<<(std::ostream &out, const AForm& AForm){
    return (out << COLOR_A << "info about AForm"  << "\n\tForn grade for SignIn: " << AForm.getSignIn() \
        << "\n\tAForm grade to Execute: " << AForm.getgradeExecReq() \
        << "\n\tand name is: " << AForm.getName() << COLOR_CLEAN << std::endl);
}
AForm::~AForm(){}

//get set
std::string AForm::getName() const {return _name;}
bool        AForm::getIndicator() const {return _indicator;}
int         AForm::getSignIn() const {return _gradeReqmnt;}
int         AForm::getgradeExecReq() const {return _gradeExecReq;}
std::string AForm::getTarget() const {return _target;}

void        AForm::setTarget(const std::string target) {_target = target;}

//exceptions 

const char *AForm::GradeTooHighException::what() const throw(){
    return ("Grade is too high...");
}
const char *AForm::GradeTooLowException::what() const throw(){
    return ("Grade is too low...");
}

//functions 
void    AForm::beSigned(Bureaucrat const &bureaucrat){
    if (bureaucrat.getGrade() > _gradeReqmnt)
        throw GradeTooLowException();
    _indicator = true;
}

