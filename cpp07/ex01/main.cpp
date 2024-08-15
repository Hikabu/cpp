#include "iter.hpp"

int main(){
	//chars
    char array[] = {'a','b', 'c', 'd'};

    iter(array, sizeof(array), print);
    iter (array, sizeof(array), add);
    std::cout << std::endl;
    iter(array, sizeof(array), print);
    std::cout << std::endl;

	//doubles
    std::cout << std::endl;
    double arrayDub[] = {1.7,2.5,3.3,4.8,5.323}; // 8 bytes each element
    iter(arrayDub, sizeof(arrayDub) / sizeof(arrayDub[0]), print); //40 /8 
    iter (arrayDub, sizeof(arrayDub) / sizeof(arrayDub[0]), add);
	std::cout << std::endl;
    iter(arrayDub, sizeof(arrayDub) / sizeof(arrayDub[0]), print);
    std::cout << std::endl;
    
	//int 
	std::cout << std::endl;
    double arrayInt[] = {1,2,3,4,5}; // 2 bytes each element
    iter(arrayInt, sizeof(arrayInt) / sizeof(arrayInt[0]), print); //10 /2 
    iter (arrayInt, sizeof(arrayInt) / sizeof(arrayInt[0]), add);
	std::cout << std::endl;
    iter(arrayInt, sizeof(arrayInt) / sizeof(arrayInt[0]), print);

    	//strings
	std::cout << std::endl;
    std::string arrayStr[] = {"What", "Where", "Who"}; //8 bytes each element
    // std::cout << sizeof(arrayStr) << std::endl;
    iter(arrayStr, sizeof(arrayStr) / sizeof(arrayStr[0]), print); 
    iter (arrayStr, sizeof(arrayStr) / sizeof(arrayStr[0]), add);
	std::cout << std::endl;
    iter(arrayStr, sizeof(arrayStr) / sizeof(arrayStr[0]), print);
    

    return (0);
}

