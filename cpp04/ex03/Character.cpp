#include "Character.hpp"

AMateria *GROUND[100];
int GROUND_COUNT= 0;
void throwAway(AMateria *mat){
    GROUND[GROUND_COUNT] = mat;
    GROUND_COUNT++;
}


Character::Character(std::string name) : ICharacter(){
    _name = name;
    _count = 0;
    for(int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    _count = 0;
    // std::cout << "Character constructor called" << std::endl;
}

Character::Character( const Character &copy) {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    *this = copy;
    // for (int i = 0; i < 4; i++)
    //     _onFloor[i] = copy._onFloor[i]->clone(); 
}

Character &Character::operator=(const Character &copy){
    if (this == &copy)
        return (*this);
    _name = copy._name;
    for (int i = 0; i < copy._count; i++)
    {
        if (_inventory[i]){
            delete _inventory[i];
            _inventory[i] = NULL;
        }
       _inventory[i] = copy._inventory[i]->clone();
    }
    return (*this);
}

Character::~Character(){
    for (int i = 0; i < 4; i++){
        if (_inventory[i] != NULL)
            delete _inventory[i];
    }
}

std::string const &Character::getName() const {return _name;}

void Character::equip(AMateria* m){
    for (int i = 0; i < 4; i++){
        if (_inventory[i] == NULL){
            _inventory[i] = m;
            ++_count;
            return ;
        }
    }
    std::cout << "Can't equip " << m->getType() << " is full" << std::endl;
}

void Character::unequip(int idx){
    if (idx < 0 || idx < 4 || !_count || !_inventory[idx]){
        std::cout << _name << " is empty, how to unequip?" << std::endl;
        return ;
    }
    --_count;
    throwAway(_inventory[idx]);

    // AMateria** tmp = new AMateria*[_count + 1];
    // for (int i = 0; i < _count; i++)
    //     tmp[i] = _onFloor[i]; //for not loosing that already thrown
    // tmp[_count] = _inventory[idx]; // remove place on the floor
    // delete [] _onFloor;
    // _onFloor = tmp;

    // _inventory[idx] = 0; //empty slots 
    // std::cout << _onFloor[_count]->getType() << " unequip on floor " << std::endl;    _count++; //added to the floor
}

void Character::use(int idx, ICharacter& target){
    if (idx >= 0 && idx < 4 && _inventory[idx] != NULL)
        _inventory[idx]->use(target);
    else
        std::cout << _name << " empty equipment slots " << std::endl;
}