#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <iostream>
# include <exception>
# include <algorithm>
# include <vector>
# include <iterator> //reduce the complexity and execition time
# include <deque>
# include <stack>
# include <list>

// template <typename T>
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack (const MutantStack& copy);
        MutantStack &operator=(const MutantStack& copy); 
        ~MutantStack();

    //iterator 
    typedef typename Container::iterator iterator;
    iterator begin( void );
    iterator end ( void );

    //const iterator read-only
    typedef typename Container::const_iterator const_iterator;
    const_iterator begin( void ) const ;
    const_iterator end ( void ) const ;

    //reverse iterator
    typedef typename Container::reverse_iterator reverse_iterator;
    reverse_iterator rbegin( void );
    reverse_iterator rend( void );

    //reverse const iterator 
    typedef typename Container::const_reverse_iterator const_reverse_iterator;
    const_reverse_iterator rbegin ( void ) const ;
    const_reverse_iterator rend( void ) const ;
};
# include "MutantStack.tpp"
#endif
