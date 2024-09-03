#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Wrong number of arguments\n";
        return (1);
    }
    RPN::start(av[1]);
    return (0);
}