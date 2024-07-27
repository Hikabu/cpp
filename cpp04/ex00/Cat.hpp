#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>

class Cat : public Animal{
    protected:
        std::string _type;

    public:
        Cat();
        Cat(const Cat &toCopy);
        Cat &operator=(const Cat &toCopy);
        ~Cat();

};

#endif

