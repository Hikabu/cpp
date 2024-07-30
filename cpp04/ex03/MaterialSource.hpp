#ifndef MATERIALSOURCE_HPP
# define MATERIALSOURCE_HPP

#include <iostream>
#include "AMateria.hpp"


class MateriaSource {
    protected:

    public:
        MateriaSource();
        MateriaSource(const MateriaSource& toCopy);
        MateriaSource& operator=(const MateriaSource &toCopy);
        virtual ~MateriaSource();
};

#endif