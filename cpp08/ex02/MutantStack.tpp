#include "MutantStack.hpp"

MutantStack::MutantStack() : _n(0) {}

MutantStack::MutantStack(unsigned int n) : _n(n) {}

MutantStack::MutantStack(const MutantStack &copy) : _n(copy._n), _vector(copy._vector) {}

MutantStack &MutantStack::operator=(const MutantStack &copy)
{
    if (this != &copy)
    {
        _n = copy._n;
        _vector = copy._vector;
    }
    return (*this);
}

void    MutantStack::addNumber(unsigned int n)
{
    if (_vector.size() >= _n)
        throw std::length_error("Container is fullll\n");
    else
        _vector.push_back(n);
}

MutantStack::~MutantStack(){}

int MutantStack::shortestMutantStack()
{
    if (_vector.size() < 2)
        throw std::length_error ("Can't find, container is too short\n");
    std::vector<int> tmp(_vector);
    std::sort(tmp.begin(), tmp.end());
    int possiblMin = tmp[1] - tmp[0];
    for (unsigned int walker = 2; walker < tmp.size(); walker++)
    {
        if (possiblMin > tmp[walker] - tmp[walker - 1])
            possiblMin =  (tmp[walker] - tmp[walker - 1]);
    }
    return (possiblMin);
}

int MutantStack::longestMutantStack()
{
    if (_vector.size() < 2)
        throw std::length_error ("Can't find, container is too short\n");
    std::vector<int> tmp(_vector);
    std::sort(tmp.begin(), tmp.end());
    unsigned int max =  (tmp[tmp.size() -1]  - tmp[0]);
    return (max);
}

void MutantStack::print()
{
    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}
