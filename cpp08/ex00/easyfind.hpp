#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <exception>
# include <algorithm>
# include <vector>
# include <iterator> //reduce the complexity and execition time
# include <list>
# include <forward_list>
# include <deque>


template <typename T>
typename T::iterator easyfind(T &container, int value);
// {
//     if (container.empty())
//         throw std::range_error ("Empty container");
//     typename T::iterator itr;  // like pointer 
//     itr = std::find(container.begin(), container.end(), value);
//     if (itr == container.end())
//         throw std::runtime_error("No occurance was detected");
//     return (itr); 
// }



# include "easyfind.tpp"
#endif
