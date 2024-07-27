#include "Animal.hpp"

int main(){
    const Animal* meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << std::endl;
}