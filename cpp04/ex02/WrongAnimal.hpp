#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP


#include <iostream>

class WrongAnimal{
    protected:
        std::string _type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &toCopy);
        WrongAnimal &operator=(const WrongAnimal &toCopy);
        ~WrongAnimal();

        std::string getType() const;
        void setType(std::string type);
        void makeSound() const;
};

#endif