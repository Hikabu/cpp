#ifndef MATERIALSOURCE_HPP
# define MATERIALSOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
    protected:
        AMateria* _store[4];
        int _count;
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& toCopy);
        MateriaSource& operator=(const MateriaSource &toCopy);
        virtual ~MateriaSource();

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const &);
};

#endif