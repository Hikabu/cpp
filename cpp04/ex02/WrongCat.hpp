#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
    
    protected:
        std::string _type;

    public:
        WrongCat();
        WrongCat(const WrongCat &toCopy);
        WrongCat &operator=(const WrongCat &toCopy);
        ~WrongCat();

        void makeSound() const;
};

#endif