#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_GREY "\x1b[90m"
#define COLOR_CLEAN "\x1b[0m"

 Intern::Intern(){}

 Intern:: Intern(const Intern &toCopy){ (void)toCopy;}

 Intern & Intern::operator=(const  Intern &toCopy) {(void)toCopy; return (*this);}
 
 Intern::~ Intern(){}


 const char* Intern::FormNotFound::what() const throw(){
    return ("Form not found...");
 }
 AForm *Intern::makeForm(std::string const &formName, std::string const &formTarget) const{
    AForm* ret = 0;
    size_t i = 0;
    std::string formNames[3] = {"ShrubberyCreationForm", "RobotomyRequestForm","PresidentialPardonForm" }; //arrayinit
    for (; formName != formNames[i] && i < 3; i++)
    switch(i)
    {
        case 0:
            ret = new ShrubberyCreationForm(formTarget);
            std::cout << "Intern creates " << formTarget << std::endl;
            break;
        case 1:
            ret = new RobotomyRequestForm(formTarget);
            std::cout << "Intern creates " << formTarget << std::endl;
            break;
        case 2:
            ret = new PresidentialPardonForm(formTarget);
            std::cout << "Intern creates " << formTarget << std::endl;
            break;
        default:
            throw FormNotFound();
            break;
    }
    return (ret);
 }



