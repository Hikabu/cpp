#include "ScalarConverter.hpp"

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_GREY "\x1b[90m"
#define COLOR_CLEAN "\x1b[0m"

int ScalarConverter::_count = 0;
int ScalarConverter::_dot = 0;
int ScalarConverter::_float = 0;


 ScalarConverter::ScalarConverter() {}
 ScalarConverter::ScalarConverter(std::string av) : _av(av){

 }                                           
 ScalarConverter:: ScalarConverter(const ScalarConverter &toCopy){
   *this = toCopy;
}

 ScalarConverter & ScalarConverter::operator=(const  ScalarConverter &toCopy) {
    _av = toCopy._av;
    return (*this);
}

 ScalarConverter::~ ScalarConverter(){}

 void ScalarConverter::convert(const std::string &input){
    if (input.size() == 1 && isalpha(input[0]))
    {
        std::cout << "char: '" << input << "'" << std::endl;
		int number = (int)input[0];
        std::cout << "int: '" << number << "'"<< std::endl;
        std::cout << "float: '" << std::fixed << "'" << std::setprecision(1) << static_cast<float>(number) <<"f" << std::endl;
		std::cout << "double: '" << std::fixed << "'" << std::setprecision(1) <<static_cast<double>(number) << std::endl;
    }
    else if (!input.compare("-inff") || !input.compare("+inff") || !input.compare("nanf")  // !0 = true 
            || !input.compare("-inf") || !input.compare("+inf") || !input.compare("nan")) 
        {
            std::cout << "char: impossible " << std::endl;
            std::cout << "int: impossible " << std::endl;
            if (!input.compare("-inf") || !input.compare("+inf") || !input.compare("nan"))
            {
                std::cout << "float: '" << input << "f'" << std::endl;
                std::cout << "double: '" << input << "'" <<  std::endl;
            }
            else
            {
                std::cout << "float: " << input << std::endl;
                std::string copyInput = input; //erase()not working with const
                std::cout << "double: " << copyInput.erase(copyInput.size() - 1) << std::endl;
            }
        }
    else if (ScalarConverter::forNumber(input))
        {
            int nbr;

            nbr = std::stoi(input);
            if (!(isprint(nbr)))
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
            std::cout << "int: '" << nbr << std::endl;
            if (_dot)
            {
                float nbrF;
                nbrF = std::stof(input);
                std::cout << "float: " << std::fixed << std::setprecision(_count - _dot - 1 - _float)
                            << static_cast<float>(nbrF) << "f" << std::endl;
                double nbrD = std::stod(input);
                std::cout << "double: " << static_cast<double>(nbrD) << std::endl;
            }
            else
            {
                std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nbr) << "f" << std::endl;
                std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(nbr) << std::endl;

            }
        }
        else
            std::cout << "Invalid arguments" << std::endl;
 }



int ScalarConverter::forNumber(const std::string &digit){
    while (digit[_count])
    {
        if (isdigit(digit[_count]) || digit[_count] == '.' || digit[_count] == '+'  \
           || digit[_count] == '-' || digit[_count] == 'f')
        {
            if (digit[_count] == '.')
                _dot = _count;
            if (digit[_count] == 'f')
                _float = 1;
            _count++;
        }
        else
            break;
    }
    if ((size_t(_count) == digit.size())) 
        return (1);
    else
        return (0);
}