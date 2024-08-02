
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"


int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    // ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(1, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
     
    // std::cout << "*--forIcetest--*" << std::endl << std::endl;{

    //     AMateria *ice = new Ice();
    //     AMateria *clone;
    //     ICharacter *who = new Character ("who");

    //     clone = ice->clone();
    //     std::cout << "Ice type: " << clone->getType() << std::endl;
    //     std::cout << "Clone type: " << clone->getType() << std::endl;
    //     std::cout << "Using type: ";
    //     ice->use(*who);

    //     delete who;
    //     delete clone;
    //     delete ice;
    // }
    //  std::cout << "*--forCuretest--*" << std::endl << std::endl;{

    //     AMateria *cure = new Cure();
    //     AMateria *clone;
    //     ICharacter *who = new Character ("who");

    //     clone = cure->clone();
    //     std::cout << "cure type: " << clone->getType() << std::endl;
    //     std::cout << "Clone type: " << clone->getType() << std::endl;
    //     std::cout << "Using type: ";
    //     cure->use(*who);

    //     delete who;
    //     delete clone;
    //     delete cure;
    // }

    // std::cout << "----Chartest-----" << std::endl;
    // {
    //     IMateriaSource *src = new MateriaSource();
    //     ICharacter *me = new Character("me");

    //     std::cout << "Character name: " << me->getName() << std::endl;
    //     std::cout << "Equiping materia" << std::endl;
    //     AMateria *tmp;
    //     tmp = src->createMateria("ice");
    //     me->equip(tmp);
    //     tmp = src->createMateria("cure");
    //     me->equip(tmp);
    //     std::cout << "Unequip " << std::endl;
    //     me->unequip(0);
    //     me->unequip(1);

    //     delete me;
    //     delete src;
    // }    
    
    return 0;
}