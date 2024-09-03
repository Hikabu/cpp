#include "RPN.hpp"

int main(int ac, char **av)
{ 
    try{

        if (ac != 2)
        {
            std::cerr << "Wrong number of arguments\n";
            return (1);
        }
        RPN::start(av[1]);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}