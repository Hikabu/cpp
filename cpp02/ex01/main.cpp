#include "Fixed.hpp"

int main()
{
    Fixed       a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is  " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return (0);
 } 



/*it will not compile heed to use double
if instead of 3.1 we compare to 0.5, the comparison is 
successful and the program displays Yes, because
the number 0.5 can be represented with the accuracy 
of the float type without losing decimal digits.*/



//  #include <iostream> 
// int main()
// {
//     float a = 3.1;
//     if(a == 3.1)
//         std::cout << "Yes\n";
//     else
//         std::cout << "No\n";
//     return 0;
// }