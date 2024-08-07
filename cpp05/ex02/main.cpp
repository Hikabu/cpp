#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define COLOR_CLEAN "\x1b[0m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"

int main()
{
	std::cout << COLOR_BLUE << "\t\tCreate bureaucrat" << COLOR_CLEAN << std::endl;
	Bureaucrat Harry("Harry", 110);
	Bureaucrat Ron("Ron", 70);
	Bureaucrat Goyl("Goyl", 80);

	std::cout << Harry;
	std::cout << Ron;
	std::cout << Goyl;

	std::cout << COLOR_BLUE << "\t\tCreate Form" << COLOR_CLEAN << std::endl;
	ShrubberyCreationForm Form("Shrubbery");
	RobotomyRequestForm Form1("Robotomy");
	std::cout << Form;
	std::cout << Form1;

}
