#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define COLOR_CLEAN "\x1b[0m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"

int main(){
    Bureaucrat buro("buto", 2);
    ShrubberyCreationForm form("ShruForm");

    buro.signForm(form);
    buro.executeForm(form);



}
