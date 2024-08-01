#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#define COLOR_CLEAN "\x1b[0m"
#define COLOR_ANOTHER "\x1b[35m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_DONT "\x1b[34m"

int main(){
        // Dog basik;
    	// {
	    // 	Dog tmp = basik;
	    // }
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    Animal *animals[8];
    std::cout << COLOR_ANOTHER << std::endl;
    for (int i = 0; i < 5; i++)
        animals[i] = new Dog();
    std ::cout << COLOR_CLEAN << std::endl;
    std::cout << COLOR_YELLOW << std::endl;
    for (int i = 0; i < 5; i++)
        animals[i]->makeSound();
    std ::cout << COLOR_CLEAN << std::endl;
    std::cout << COLOR_DONT << std::endl;
    for (int i = 5; i < 8; i++)
        animals[i] = new Cat();
    std ::cout << COLOR_CLEAN << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::cout << i << std::endl;
        delete animals[i];
    }
    // system ("leaks brain");
    return (0);
}