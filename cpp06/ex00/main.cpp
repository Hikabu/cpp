#include "ScalarConverter.hpp"

int main(int ac, char **av){
try{
    if (ac != 2){
        std::cout << "i should be like ./converter [input]" << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}