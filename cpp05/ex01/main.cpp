#include "Bureaucrat.hpp"
#include "Form.hpp"

#define COLOR_CLEAN "\x1b[0m"
#define COLOR_YELLOW "\x1b[33m"

int main(){

    Bureaucrat  maggot("Maggot", 15);
    Form        form("Form", 15, 4);

    maggot.signForm(form);
    std::cout << form << std::endl;
}