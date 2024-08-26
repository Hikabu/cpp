#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <algorithm>
# include <vector>
# include <iterator> //reduce the complexity and execition time
# include <list>
# include <forward_list>
# include <deque>

class Span
{
    private:
        unsigned int _n;
        std::vector <int> _vector;

    public:
        Span();
        Span (unsigned int n);
        Span (const Span& copy);
        Span &operator=(const Span& copy); 
        ~Span();

        void    addNumber(unsigned int n);
        int     shortestSpan();
        int     longestSpan();
};

#endif
