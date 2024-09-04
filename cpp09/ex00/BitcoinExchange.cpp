#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin (const Bitcoin &) {} 

Bitcoin& Bitcoin::operator=(const Bitcoin &) { return *this; }

int Bitcoin::readAll(const std::string &av)
{
    //read csv
    std::map < std::string, std::string > map;
    std::ifstream fileOpen("data.csv"); //only for read
    if (!fileOpen.is_open())
    {
        fileOpen.clear();
        std::cerr << "Could not open the file" << std::endl;
        return (1);
    }
    {
        std::string storeStr;
        std::getline(fileOpen, storeStr);
        while(std::getline(fileOpen, storeStr))
        {
            std::istringstream readStr(storeStr);
            std::string date, exchangeRate;
            if (std::getline(readStr, date, ',') && std::getline(readStr, exchangeRate, '\n'))
            {
                map[date] =  exchangeRate;//  static_cast<float>(std::atof(exchangeRate.c_str()))
                // std::cout << map[date] << std::endl;
            }
        }
        fileOpen.close();
        (void) av;
    }
    //read input 

    std::map < std::string, std::string >::iterator it;
    std::string inputFileName = av;
    std::string str;
    std::ifstream file(inputFileName);
    if (!file.is_open())
    {
        std::cerr << "Could not open the file" << std::endl;
        return (1);
    }
    while (std::getline(file, str))
    {
        std::istringstream iss(str);
        std::string data, exchangeRate;
        std::getline(iss, data, '|');
        std::getline (iss, exchangeRate);

        if (Bitcoin::checkDate(data) && Bitcoin::checkValue(exchangeRate))
        {
            // std::cout << "great" << std::endl;
            it = map.lower_bound(data);
            if (it != map.begin())
            {
                --it;
                std::cout << data << "=>" << exchangeRate << " = " << Bitcoin::calculValue(exchangeRate, it->second) << std::endl;
            }
        }
    }
    file.close();
    return (0);
}

 bool Bitcoin::checkValue(std::string &excangeRate)
 {
    std::istringstream strStream(excangeRate);
    float toFloat;
    bool isValid = true;

    if (!strStream.eof() && !strStream.fail())
    {
        strStream >> toFloat; // like std::cin >> variable
        if (toFloat < 0 )
        {
            std::cerr << "Error: not a positive number.\n" ;
            isValid = false;
        }
        else if (toFloat > 1000)
        {
            std::cerr << "Error: too large a number.\n" ;
            isValid = false;
        }
    }
        else 
        {
             std::cerr << "Error: bad input.\n" ;
            isValid = false;
        }
    return isValid;
 }

bool Bitcoin::checkDate(std::string &date)
{
    if (date.size() != 11 || date[4] != '-' || date[7] != '-')
    {   
        std::cerr << "Error: bad input " << date << std::endl;
        return (0);
    }
    std::istringstream strStream(date);
    int year, month, day;
    char sign;
    bool isValid;

    sign = '-';
    isValid = true;
    
    if (strStream >> year >> sign >> month >> sign >> day)
    {
        if (year < 0 || month < 0 || month > 12 || day < 0 || day > 31)
        {
            std::cerr << "Error: bad input " << date  << std::endl;
            isValid = false;
        }
        else if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
        {
            std::cerr << "Error: bad input " << date << std::endl;
            isValid = false;
        }
        else if (day > 29 && month == 2)
        {
            std::cerr << "Error: bad input " << date  << std::endl;
            isValid = false;
        }
        else if (day > 28 && month == 2 && ((year % 100 == 0 && year % 400 != 0) || year % 4 != 0))
        {
            std::cerr << "Error: bad input " << date << std::endl;
            isValid = false;
        }
    }
    return isValid;

}
float Bitcoin::calculValue (std::string &data, std::string datBasVal)
{
    std::istringstream strDate(data);
    std::istringstream strBase(datBasVal);

    float inDate;
    float inBase;

    strDate >> inDate;
    strBase >> inBase;
    return inDate * inBase;
}
