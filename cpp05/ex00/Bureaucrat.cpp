#include "Bureaucrat.hpp"
Bureaucrat::Bureaucrat(){
    std::cout << "Bureacurat  defoult constructor called " << std::endl;	
}
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
    std::cout << "Bureacurat constructor called " << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade){
    std::cout << "Bureaucrat copy constructor called " << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
    if(this != &copy){
		_grade = copy._grade;
	}	
   return (*this);
}

Bureaucrat::~Bureaucrat(){}


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


//functions(need try catch for better working)
void Bureaucrat::incrementGrade()  {setGrade(_grade + 1);}

void Bureaucrat::decrementGrade()  {setGrade(_grade - 1);}


//exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Grade too high...");
 }
const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Grade too Low...");
 }



