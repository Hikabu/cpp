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
	// RobotomyRequestForm rono;
	// rono.setTarget("hshs");
	// std::cout << rono.getTarget() << std::endl;

	std::cout << COLOR_BLUE << "\t\t----------Create bureaucrat----------" << COLOR_CLEAN << std::endl;
	Bureaucrat Harry("Harry", 25);

	std::cout << Harry;

	std::cout << COLOR_BLUE << "\t\t----------Create Form----------" << COLOR_CLEAN << std::endl;
	ShrubberyCreationForm Form("Shrubbery");
	RobotomyRequestForm Form1("Robotomy");
	PresidentialPardonForm Form2("President");

	std::cout << Form;
	std::cout << Form1;
	std::cout << Form2;
	
		std::cout << COLOR_BLUE << "\t\t----------SHrubberyForm----------" << COLOR_CLEAN << std::endl;
		Harry.signForm(Form);
		Harry.executeForm(Form);
		std::cout << COLOR_BLUE << "\t\t----------RobotyForm----------" << COLOR_CLEAN << std::endl;
		Harry.signForm(Form1);
		Harry.executeForm(Form1);
		Harry.executeForm(Form1);
		Harry.executeForm(Form1);
		Harry.executeForm(Form1);
		std::cout << COLOR_BLUE << "\t\t----------PresidentForm----------" << COLOR_CLEAN << std::endl;
		Harry.signForm(Form2);
		Harry.executeForm(Form2);

		// std::cout << COLOR_BLUE << "\t\t----------TooLow----------" << COLOR_CLEAN << std::endl;

			// Bureaucrat Harry("Harry", 151);

		// std::cout << "\tSHrubberyForm" << std::endl;
		// try{Harry.executeForm(Form);}
		// catch(std::exception &e){std::cout << e.what() << std::endl;}
		// 	std::cout << "\tRobotomForm" << std::endl;
		// try{Harry.executeForm(Form1);}
		// catch(std::exception &e){std::cout << e.what() << std::endl;}
		// 	std::cout << "\tPresidentForm" << std::endl;
		// try{Harry.executeForm(Form2);}
		// catch(std::exception &e){std::cout << e.what() << std::endl;}

		// std::cout << COLOR_BLUE << "\t\t----------Toohigh----------" << COLOR_CLEAN << std::endl;
			// Bureaucrat Harry("Harry", 0);

		// 	std::cout << "\tSHrubberyForm" << std::endl;
		// try{Harry.executeForm(Form);}
		// catch(std::exception &e){std::cout << e.what() << std::endl;}
		// 	std::cout << "\tRobotomForm" << std::endl;
		// try{Harry.executeForm(Form1);}
		// catch(std::exception &e){std::cout << e.what() << std::endl;}
		// 	std::cout << "\tPresidentForm" << std::endl;
		// try{Harry.executeForm(Form2);}
		// catch(std::exception &e){std::cout << e.what() << std::endl;}
}
