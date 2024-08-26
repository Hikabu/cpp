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
        throw std::length_error ("Container is fullll\n");
    else
        _vector.push_back(n);
}
int Span::shortestSpan()
{
    if (_vector.size() < 2)
        throw std::length_error ("Can't find, container is too short\n");
    int possiblMin = _vector[1] - _vector[0];
    for (int walker = 2; walker < _vector.size(); walker++)
    {
        if (_vector[walker] < )
    }

}

int Span::longestSpan()
{

}