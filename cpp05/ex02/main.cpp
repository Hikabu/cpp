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
	try{
			std::cout << COLOR_BLUE << "\t\t----------Create bureaucrat----------" << COLOR_CLEAN << std::endl;
			Bureaucrat Harry("Harry", 140);
			Bureaucrat Ron("Ron", 70);
			Bureaucrat Goyl("Goyl", 1);

			std::cout << Harry;
			std::cout << Ron;
			std::cout << Goyl;

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
			Ron.signForm(Form1);
			Ron.executeForm(Form1);
			Ron.executeForm(Form1);
			Ron.executeForm(Form1);
			Ron.executeForm(Form1);

			std::cout << COLOR_BLUE << "\t\t----------PresidentForm----------" << COLOR_CLEAN << std::endl;
			Goyl.signForm(Form2);
			Goyl.executeForm(Form2);
		}
	catch(std::exception &e){

		std::cout << e.what() << std::endl;
	}
}
