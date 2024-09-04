#include "RPN.hpp"

RPN::RPN(const RPN &) {}

RPN& RPN::operator=(const RPN &) { return *this;}

bool RPN::checkInput(const std::string &input)
{

    std::stringstream str;
    str << input;

    std::string smbl;

    while (str)
    {
        str >> smbl;
        if (smbl == "+" || smbl == "-" || smbl == "*" || smbl == "/")
            continue;
        if (smbl.length() > 1)
            return false;
        if (smbl[0] <= '0' && smbl[0] > '9')
            return (false);
    }
    return (true);
}

void RPN::start (const std::string &input)
{
    if (!checkInput(input))
        throw std::logic_error("Error");

    std::stack<double> stack;
    std::string smbl;
    std::istringstream iss(input);

    double tmpNbr;
    double psblRes;
    double value;

    while (std::getline(iss, smbl, ' '))
    {
        if (smbl == "+" || smbl == "-" || smbl == "*" || smbl == "/" )
        {
            tmpNbr = stack.top(); stack.pop();
            // std::cout << "Opertor: " << smbl << std::endl;
            if (smbl == "+"){
                psblRes = stack.top() + tmpNbr; stack.pop();}
            else if (smbl == "-"){
                psblRes = stack.top() - tmpNbr; stack.pop();}
            else if (smbl == "*"){
                psblRes = stack.top() * tmpNbr; stack.pop();}
            else if (smbl == "/")
            {
                if (tmpNbr == 0)
                {
                    std::cerr << "Wrong division" << std::endl;
                    return ;
                }
                psblRes = stack.top() / tmpNbr; stack.pop();
            }
            stack.push(psblRes);
            // std::cout << "what can be " << psblRes << std::endl;
        }
        else if (smbl >= "0" && smbl <= "9")
        {
            std::istringstream iss(smbl);
            if (iss >> value){
                // std::cout << "Int: " << value << std::endl;
                stack.push(value);
            }
        }
        else {
            std::cerr << "Wrong input" << std::endl;
            return;
        }
    }
        if (stack.size() == 1)
            std::cout << "Result " << stack.top() << std::endl;
        else
            std::cerr << "wrong input" << std::endl;
}
