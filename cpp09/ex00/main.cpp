#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    Bitcoin bit;
    std::map < std::string, std::string > map;
    if (ac != 2)
    {
        std::cerr << "Wrong amount of arguments" << std::endl;
        return (0);
    }
    try
    {
        bit.start (av[1]);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
