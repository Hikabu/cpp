#include "MutantStack.hpp"
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T>() {}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container> &copy) : std::stack<T> (copy) {}

template <typename T, typename Container>
MutantStack<T, Container>&MutantStack<T, Container>::operator=(const MutantStack<T, Container> &copy)
{
    if (this != &copy)
        std::stack<T>::operator=(copy);
    return (*this);
}
template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(){}

//iterator 
template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::begin()
{
    return this->c.begin();
}
template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::end()
{
    return this->c.end();
}

//const iterator
template <typename T, typename Container>
typename Container::const_iterator MutantStack<T, Container>::begin() const
{
    return this->c.begin();
}
template <typename T, typename Container>
typename Container::const_iterator MutantStack<T, Container>::end() const
{
    return this->c.end();
}
//reverse iterator

template <typename T, typename Container>
typename Container::reverse_iterator MutantStack<T, Container>::rbegin()
{
    return this->c.rbegin();
}
template <typename T, typename Container>
typename Container::reverse_iterator MutantStack<T, Container>::rend()
{
    return this->c.rend();
}
//reverse const iterator

template <typename T, typename Container>
typename Container::const_reverse_iterator MutantStack<T, Container>::rbegin() const
{
    return this->c.rbegin();
}
template <typename T, typename Container>
typename Container::const_reverse_iterator MutantStack<T, Container>::rend() const
{
    return this->c.rend();
}