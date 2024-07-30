#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"


class Cure : public AMateria  {
    protected:

    public:
        Cure();
        Cure(const Cure& copy);
        Cure& operator=(const Cure &copy);
        virtual ~Cure();

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif