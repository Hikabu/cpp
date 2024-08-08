#include "Bureaucrat.hpp"

#define COLOR_CLEAN "\x1b[0m"
#define COLOR_YELLOW "\x1b[33m"

int main(){
// exceptions
    try{
        Bureaucrat babyCrat("babyCrat", 180);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    try{
        Bureaucrat babyCrat("babyCrat", 0);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    //tests
    std::cout << COLOR_YELLOW << "\n\t Right working bureaucrat\n" << COLOR_CLEAN<< std::endl;
    try{
        Bureaucrat babyCrat("babyCrat", 120);
        babyCrat.incrementGrade();
        std::cout << babyCrat;
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    try{
        Bureaucrat babyCrat("babyCrat", 120);
        babyCrat.decrementGrade();
        std::cout << babyCrat;
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << COLOR_YELLOW << "\n\t If grade 150 or 1 \n" << COLOR_CLEAN<< std::endl;
    try{
        Bureaucrat babyCrat("babyCrat", 150);
        babyCrat.incrementGrade();
        std::cout << "after " << babyCrat;
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    try{
        Bureaucrat babyCrat("babyCrat", 1);
        babyCrat.decrementGrade();
        std::cout << "after " << babyCrat;
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << COLOR_YELLOW << "\n\t If grade 2 or 150 \n" << COLOR_CLEAN<< std::endl;
    try{
        Bureaucrat babyCrat("babyCrat", 149);
        babyCrat.incrementGrade();
        std::cout << "after " << babyCrat;
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    try{
        Bureaucrat babyCrat("babyCrat", 2);
        babyCrat.decrementGrade();
        std::cout << "after " << babyCrat;
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }
}
