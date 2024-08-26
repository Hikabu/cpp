# include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    if (container.empty())
        throw std::range_error ("Empty container");
    typename T::iterator itr;  // like pointer 
    itr = std::find(container.begin(), container.end(), value);
    if (itr == container.end())
        throw std::runtime_error("No occurance was detected");
    return (itr); 
}