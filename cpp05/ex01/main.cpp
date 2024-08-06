#include "Bureaucrat.hpp"
#include "Form.hpp"

#define COLOR_CLEAN "\x1b[0m"
#define COLOR_YELLOW "\x1b[33m"

int main(){
    try{
        Bureaucrat  maggot("Maggot", 70);
        Form        form("Form", 1, 2);

        std::cout << form << std::endl;
        maggot.signForm(form);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}