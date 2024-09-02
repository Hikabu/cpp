#include "BitcoinExchange.hpp"

static void start(std::string av)
{
    std::fstream file;
    std::string filename = av;
    file.open(filename);
    if (!file.is_open()){
        file.clear();
        std::cerr << "Could not open the file" << std::endl;
    }

}
