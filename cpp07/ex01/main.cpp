// #include "iter.hpp"
#include <string>
#include <iostream>
int main(){

    // std::string H = "lal";
    // std::string *G = &H;
    // // float  H = G;
    // // *H = "hfhf";
    // // std::cout << H<< std::endl << G << std::endl; 
    //   std::cout << G<< std::endl << &(*G) << "=" << &H<< std::endl; 

    char g[25] = "jhdfgkjdfhgkjdfhgkjdsfhg";
    char *h = g;
    std::cout << h << std::endl;
    h++;
    std::cout << h << "|" << *h << std::endl;

}

