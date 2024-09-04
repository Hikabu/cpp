#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    Bitcoin bit;
    if (ac != 2)
    {
        std::cerr << "Wrong amount of arguments" << std::endl;
        return (1);
    }
    try
    {
        bit.readAll(av[1]);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
