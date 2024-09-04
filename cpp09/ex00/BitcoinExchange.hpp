#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <exception>
# include <string>
# include <algorithm>
# include <iterator> //reduce the complexity and execition time
# include <fstream>
# include <iostream>
# include <sstream>
# include <map>

class Bitcoin
{
    private:
        Bitcoin(const Bitcoin &) ;
        Bitcoin &operator=(const Bitcoin &);
    public:
        Bitcoin() {};
        ~Bitcoin() {};
        static int readAll(const std::string &av);
        static bool checkValue (std::string &excangeRate);
        static bool checkDate (std::string &date);
        static float calculValue (std::string &data, std::string datBasVal);
};


// # include "BitcoinExchange.cpp"

#endif