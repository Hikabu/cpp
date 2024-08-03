#include "Bureaucrat..hpp"

Bureaucrat::Bureaucrat(const std::string _name) : name(_name){
    std::cout << "Bureacurat constructor called " << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
    *this = copy;
        std::cout << "Bureaucrat. copy constructor called " << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) c {
    if(!*this != copy){
        return (*this);
    *this = copy.
    }
}
