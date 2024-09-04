#ifndef RPN_HPP
# define RPN_HPP

# include <exception>
# include <string>
# include <algorithm>
# include <iterator> //reduce the complexity and execition time
# include <fstream>
# include <iostream>
# include <sstream>
# include <stack>

// template <typename T>
// typename T::value_type popValue(T& stack)
// {
//     if (stack.empty())
//         throw std::runtime_error("pop from empty stack");
//    typename T::value_type v = stack.top();
//    stack.pop();
//    return v; 
// }

class RPN
{
    private:
        RPN(const RPN &) ;
        RPN &operator=(const RPN &);
    public:
        RPN() {};
        ~RPN() {};
        static bool checkInput(const std::string &input);
        static void start (const std::string &input);
};

#endif