#include "Bureaucrat.hpp"
#include "Form.hpp"

#define COLOR_CLEAN "\x1b[0m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"

int main(){

    std::cout << COLOR_YELLOW << "\t\tHow to fill up the form and what are the grades?" << std::endl;
    std::cout << "\tYou want sign form - the score should be higher than Bureaucrat grade \n" << COLOR_CLEAN << std::endl;
        //if required grade is 0
    try{
        Bureaucrat  maggot("Maggot", 6);
        Form        form("Form", 9, 0);

        std::cout << form << std::endl;
        maggot.signForm(form);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

     //if  grade to sign is lower than bureaucrat 
     std::cout << COLOR_BLUE << "\t\t-----test1 create form-------" << COLOR_CLEAN << std::endl;
     try{
        Bureaucrat  maggot("Maggot", 6);
        Form        form("Form", 1, 5); //too high
        std::cout << form << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
     try{
        Bureaucrat  maggot("Maggot", 6);
        Form        form("Form", 151, 5); //too low
        std::cout << form << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << COLOR_BLUE << "\t\t-----test2 sign form-------" << COLOR_CLEAN << std::endl;
    try{
        Bureaucrat  maggot("Maggot", 6);
        Form        form("Form", 7, 1);
        maggot.signForm(form);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}