#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
    private:
        std::string _ideas[100];

    public:
        Brain();
        Brain(const Brain& toCopy);
        Brain& operator=(const Brain &toCopy);
        virtual ~Brain();

        //get
        std::string getType(int i) const;
        void setType( int i,  std::string type);
};




#endif