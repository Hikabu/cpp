#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat : public Animal{
    private:
        Brain *_brain;
    protected:
        std::string _who;
    public:
        Cat();
        Cat(const Cat &toCopy);
        Cat &operator=(const Cat &toCopy);
        virtual ~Cat();

        void virtual makeSound() const;
        void setIdea(std::string idea);
        std::string getIdea() const;

};

#endif

