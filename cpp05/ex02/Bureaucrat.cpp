#include "Bureaucrat.hpp"
#include "AForm.hpp"


Bureaucrat::Bureaucrat(){
    std::cout << "Bureacurat  defoult constructor called " << std::endl;	
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
    *this = copy;
        std::cout << "Bureaucrat copy constructor called " << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
    if(this != &copy)
        this->_grade = copy._grade;
   return (*this);
}

Bureaucrat::~Bureaucrat(){
}


std::ostream &operator<<(std::ostream &out, const Bureaucrat& bureaucrat){
	return out	<< bureaucrat.getName() << ", bureaucrat grade "
				<< bureaucrat.getGrade() << std::endl;
 }

//get/set
void Bureaucrat::setGrade(int grade) {
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
}
std::string	Bureaucrat::getName()const {return this->_name;}

int			Bureaucrat::getGrade() const {return this->_grade;}

//functions(need try catch for better testing)

void Bureaucrat::incrementGrade(){
		setGrade(_grade + 1);
}

void Bureaucrat::decrementGrade(){
		setGrade(_grade - 1);
}
 void Bureaucrat::signForm(AForm& isSigned){
	try {	
			isSigned.beSigned(*this);
			std::cout << _name << " signed " << isSigned.getName() << std::endl;
		}	
	catch (std::exception &e)
		{
			std::cout << _name << " couldn't sign " << isSigned.getName() \
				<< " because " << e.what() << std::endl;
		}
	
}

void    AForm::executeForm(AForm const &form){
    std::cout << getName() << " executed " << form.getName() <<std::endl;
}


//exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Grade too high...");
 }
const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Grade too Low...");
 }



