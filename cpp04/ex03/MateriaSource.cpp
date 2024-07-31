#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    for(int i = 0; i < 4; i++)
        _store[i] = NULL;
    std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource &copy) {
    for (int i = 0; i < 4; i++)
        _store[i] = copy._store[i]->clone(); 
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy){
    if (this == &copy)
        return (*this);
    for (int i = 0; i < 4; i++){
        if (_store[i])
            delete(_store[i]);
    }
    for (int i = 0; i < 4; i++)
        _store[i] = copy._store[i]->clone();
    return (*this);

}

MateriaSource::~MateriaSource(){
    for (int i = 0; i < 4; i++){
        if (_store[i])
            delete _store[i];
    }
}

void MateriaSource::learnMateria(AMateria* materia){
    if (!materia)
        return ;
    if (_count < 4)
    {
        _store[_count] = materia;
        _count++;
    }

}

AMateria *MateriaSource::createMateria(std::string const &type){
    for (int i = 0; i < 4; i++)
    {
        if (_store[i] == NULL && _store[i]->getType() == type)
            return (_store[i]->clone());
    }
    std::cout << "cannot create materia" << std::endl;
    return (0);
 }