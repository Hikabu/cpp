#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#define COLOR_CLEAN "\x1b[0m"
#define COLOR_ANOTHER "\x1b[35m"


int main(){{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << meta->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    meta->makeSound();
    j->makeSound();
    i->makeSound();

    delete meta;
    delete j;
    delete i;
    }
    {

        const WrongAnimal* cow = new WrongAnimal();
        const WrongAnimal* rabbit = new WrongAnimal();
        const WrongCat* OhCat = new WrongCat(); //type of obj
        const WrongAnimal* OhWrong = new WrongCat(); //type of obj

        std::cout << COLOR_ANOTHER <<  cow->getType() << std::endl;
        std::cout << rabbit->getType() << std::endl;
        std::cout << OhCat->getType() << std::endl;
        std::cout << OhWrong->getType() << std::endl;

        cow->makeSound(); 
        rabbit->makeSound();

        OhCat->makeSound(); // will sound 
        OhWrong->makeSound();
        std::cout << COLOR_CLEAN << std::endl;

        delete cow;
        delete rabbit;
        delete OhCat;
        std::cout << COLOR_ANOTHER  << std::endl;
        delete OhWrong;
        std::cout << COLOR_CLEAN << std::endl;
    }
    return 0;
}