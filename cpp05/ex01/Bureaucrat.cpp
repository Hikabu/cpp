#include "Bureaucrat.hpp"
#include "Form.hpp"


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
 void Bureaucrat::signForm(Form& isSigned){
	try {	
			isSigned.beSigned(*this);
			std::cout << _name << " signed " << isSigned.getName() << std::endl;
		}	
	catch (std::exception &e)
		{
			std::cout << _name << " couldn't sign " << isSigned.getName() \
				<< " because " << e.what() << std::endl;
		}

		/*if do it through if else - need allocate memort*/
	// if (isSigned.getIndicator() == true)
	// 	std::cout << _name << " signed " << isSigned.getName() << std::endl;
	// else 
	// 	{
	// 		std::exception& e = *new GradeTooHighException;
	// 		std::cout << _name << " couldn't sign " << isSigned.getName() \
	// 			<< " because " << e.what() << std::endl;
	// 	}
	
}

//exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Grade too high...");
 }
const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Grade too Low...");
 }



