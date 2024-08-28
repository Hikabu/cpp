#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <iostream>
# include <exception>
# include <algorithm>
# include <vector>
# include <iterator> //reduce the complexity and execition time
# include <list>
# include <forward_list>
# include <deque>

class MutantStack
{
    private:
        unsigned int _n;
        std::vector <int> _vector;

    public:
        MutantStack();
        MutantStack (unsigned int n);
        MutantStack (const MutantStack& copy);
        MutantStack &operator=(const MutantStack& copy); 
        ~MutantStack();

        void    addNumber(unsigned int n);
        int     shortestMutantStack();
        int     longestMutantStack();
        void    print();
};

#endif
