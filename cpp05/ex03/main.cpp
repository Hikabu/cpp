#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#define COLOR_CLEAN "\x1b[0m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"

int main()
{
	Intern	someRandomIntern;
	AForm*	rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;
	rrf = someRandomIntern.makeForm("shrubbery creation ", "Vender");
	delete rrf;
	rrf = someRandomIntern.makeForm("presidential pardon ", "Dender");
	delete rrf;

	try{
		rrf = someRandomIntern.makeForm("presidential pardOmen ", "Dender");
		delete rrf;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
}
