#include "Span.hpp"

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &copy) : _n(copy._n), _vector(copy._vector) {}

Span &Span::operator=(const Span &copy)
{
    if (this != &copy)
    {
        _n = copy._n;
        _vector = copy._vector;
    }
    return (*this);
}

void    Span::addNumber(unsigned int n)
{
    if (_vector.size() >= n)
        throw std::length_error("Container is fullll\n");
    else
        _vector.push_back(n);
}

Span::~Span(){}

int Span::shortestSpan()
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

int Span::longestSpan()
{
    if (_vector.size() < 2)
        throw std::length_error ("Can't find, container is too short\n");
    std::vector<int> tmp(_vector);
    std::sort(tmp.begin(), tmp.end());
    unsigned int max =  (tmp[tmp.size() -1]  - tmp[0]);
    return (max);
}

void Span::print()
{
    for (std::vector<int>::iterator it = _vector.begin();
        it != _vector.end(); it++)
        std::cout << *it << " ";
        std::cout << std::endl;
}