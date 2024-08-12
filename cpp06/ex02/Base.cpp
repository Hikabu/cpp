#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}

Base* generate(void){
    srand(time(NULL)); //starting point from 1 1970
    int i = rand() % 3;
    if (i == 0)
        return new A;
    else if (i == 1)
        return new B;
    else 
        return new C;
}

void identify(Base* p){
    if (dynamic_cast<A*>(p))
        std::cout << "points to an object of type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "points to an object of type B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "points to an object of type C" << std::endl;
    else
        std::cout << "Type unknow" << std::endl;
}

void identify(Base& p){
    try
    {
        (void) dynamic_cast<A&>(p);
        std::cout << "Reference to object A" << std::endl;
        return ;
    }
    catch (std::bad_cast &e){}
     try
    {
        (void) dynamic_cast<B&>(p);
        std::cout << "Reference to object B" << std::endl;
        return ;
    } 
    catch (std::bad_cast &e){}
     try
    {
        (void) dynamic_cast<C&>(p);
        std::cout << "Reference to object C" << std::endl;
        return ;
    } 
    catch (std::bad_cast &e){}
}