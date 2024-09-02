#include "BitcoinExchange.hpp"

static void start(char *av)
{
    std::fstream file;
    std::string filename = "data.csv";
    file.open(filename);
    if (!file.is_open()){
        file.clear();
        std::cerr << "Could not open the file" << std::endl;
    }
    
    

}