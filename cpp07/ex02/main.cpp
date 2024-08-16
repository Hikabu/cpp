#include <iostream>
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750


int main (int, char**)
{
    // int arr[3] = {1,2,3}; // A3_i an array of three el of the int type
    // std::cout << typeid(arr).name() << std::endl; //  Pi pointer to int
    // int *ptr = arr;
    // std::cout << typeid(ptr).name() << std::endl;


    srand (static_cast<unsigned int>(time(0)));
    int randVal;
    Array <int> arr(42);
    for (int i = 0; i < 42; i++)
    {
        randVal = std::rand() % 10;
        arr[i] = randVal;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << " The size of array is " << arr.size() << std::endl;
    try {std::cout << arr[41];}
    catch(std::exception &e) {std::cout << e.what() << std::endl;}
    return (0);
// }


// ------------amother main test
    // Array<int> numbers(MAX_VAL);
    // int* mirror = new int[MAX_VAL];
    // srand(time(NULL));
    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     const int value = rand();
    //     numbers[i] = value;
    //     mirror[i] = value;
    // }
    // //SCOPE 
    // {
    //     Array<int> tmp = numbers;
    //     Array<int> test(tmp);
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     if (mirror[i] != numbers[i])
    //     {
    //         std::cerr << "didn't save the same value!!" << std::endl;
    //         return 1;
    //     }
    // }
    // try
    // {
    //     numbers[-2] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // try
    // {
    //     numbers[MAX_VAL] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     numbers[i] = rand();
    // }
    // delete [] mirror;//
    return 0;
}



