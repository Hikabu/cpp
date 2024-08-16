#include <iostream>
#include <sstream>
#include <string>
#include "Array.hpp"

#define SIZE 2

template <typename T>
void compareArrays(const Array<T>& a, const Array<T>& b) {
	std::cout << "Size of array A: " << a.size() << std::endl
		<< "Size of array B: " << b.size() << std::endl;
	std::cout << "Address of array A: " << &a << std::endl
		<< "Address of array B: " << &b << std::endl;
	if (&a != &b)
		std::cout << "Addresses of arrays A and B are different: OK" << std::endl;
	else {
		std::cout << "Addresses of arrays A and B are similar: KO" << std::endl;
		return ;
	}
	if (a.size() == b.size()) {
		std::cout << "Sizes of arrays are similar: OK" << std::endl;
		for (int i = 0; i < a.size(); i++) {
			if (&a[i] != &b[i])
				std::cout << "Addresses of elements of arrays at index [" << i
					<< "] are different: OK" << std::endl;
			else
				std::cout << "Addresses of elements of arrays at index [" << i
					<< "] are similar, and/or values : KO" << std::endl;
			if (a[i] == b[i])
				std::cout << "Values of elements of arrays at index [" << i
					<< "] are similar: OK" << std::endl;
			else
				std::cout << "Values of elements of arrays at index [" << i
					<< "] are different: KO" << std::endl;
		}
	}
	else
		std::cout << "Sizes of arrays are different: OK" << std::endl;
}

template <typename T>
void testArray(const Array<T>& array) {
	std::cout << "Array size: [" << array.size() << "]" << std::endl
		<< "Array address: [" << &array << "]" << std::endl;
	try {
		for (int index = 0; true; index++) {
			std::cout << "Trying to access the element of the array at the index ["
				<< index << "]" << std::endl;
			std::cout << "The element of the array at the index [" << index 
				<< "] is:" << std::endl << "-> " << array[index] << std::endl
				<< "Address of the element is -> " << &array[index] << std::endl;
		}
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

int main () {
	std::cout << "\n=== Basic Test ===\n" << std::endl;

	Array<int>* arr1 = new Array<int>;
	std::cout << "Variable \'arr1\':" << std::endl;
	testArray(*arr1);

	std::cout << std::endl;

	Array<int>* arr2 = new Array<int>(SIZE);
	for (int i = 0; i < SIZE; i++)
		(*arr2)[i] = i + 1;
	std::cout << "Variable \'arr2\':" << std::endl;
	testArray(*arr2);

	std::cout << std::endl;

	Array<std::string>* arr3 = new Array<std::string>(SIZE);
	for (int i = 0; i < SIZE; i++) {
		std::stringstream ss;
		ss << i;
		std::string number = ss.str();
		(*arr3)[i] = "Line number " + number;
	}
	std::cout << "Variable \'arr3\':" << std::endl;
	testArray(*arr3);

	std::cout << "\n=== The End ===\n" << std::endl;

	std::cout << "\n=== Assignment Operator Test ===\n" << std::endl;

	*arr1 = *arr2;
	std::cout << "Compare variables \'arr1\' and \'arr2\':" << std::endl;
	compareArrays(*arr1, *arr2);
	std::cout << std::endl;
	std::cout << "Variable \'arr2\'" << std::endl;
	testArray(*arr2);
	for (int i = 0; i < arr2->size(); ++i)
		(*arr2)[i] = (*arr2)[i] * 10000;
	std::cout << "\nVariable \'arr2\' is modified\n" << std::endl;
	std::cout << "Variable \'arr2\':" << std::endl;
	testArray(*arr2);
	std::cout << std::endl;
	std::cout << "Variable \'arr1\' shouldn't has modified values:" << std::endl;
	testArray(*arr1);

	std::cout << "\n=== The End ===\n" << std::endl;

	std::cout << "\n=== Copy Constructor Test ===\n" << std::endl;

	Array<std::string>* arr4 = new Array<std::string>(*arr3);
	std::cout << "Compare variables \'arr3\' and \'arr4\':" << std::endl;
	compareArrays(*arr3, *arr4);
	std::cout << std::endl;
	std::cout << "Variable \'arr4\'" << std::endl;
	testArray(*arr4);
	for (int i = 0; i < arr3->size(); ++i)
		(*arr3)[i] = (*arr3)[i] + ": modified";
	std::cout << "\nVariable \'arr3\' is modified\n" << std::endl;
	std::cout << "Variable \'arr3\':" << std::endl;
	testArray(*arr3);
	std::cout << std::endl;
	std::cout << "Variable \'arr4\' shouldn't has modified values:" << std::endl;
	testArray(*arr4);

	std::cout << "\n=== The End ===\n" << std::endl;

	std::cout << "\n=== Constant Variable Test ===\n" << std::endl;

	const Array<std::string>* arr5 = new const Array<std::string>(*arr4);
	std::cout << "Original variable \'arr4\':" << std::endl;
	testArray(*arr4);
	for (int i = 0; i < arr3->size(); ++i)
		(*arr3)[i] = (*arr3)[i] + ": modified for constant test";
	std::cout << "\nVariable \'arr4\' is modified\n" << std::endl;
	std::cout << "Modified variable \'arr4\':" << std::endl;
	testArray(*arr3);
	std::cout << std::endl;
	std::cout << "Variable \'const arr5\' should be the same as original variable \'arr4\':" << std::endl;
	testArray(*arr5);
	std::cout << std::endl;
	Array<std::string>* arr6 = new Array<std::string>;
	*arr6 = *arr5;
	std::cout << std::endl;
	std::cout << "Variable \'arr6\' (non-const variable initilized by const variable):" << std::endl;
	testArray(*arr6);
	std::cout << std::endl;
	std::cout << "Compare variables \'const arr5\' and \'arr6\':" << std::endl;
	compareArrays(*arr5, *arr6);
	std::cout << std::endl;

	std::cout << "\n=== The End ===\n" << std::endl;

	// // === Changing the values of the constant Array shouldn't be able through [] operator
	// for (unsigned int i = 0; i < arr5->size(); ++i)
	// 	(*arr5)[i] = (*arr5)[i] + ": modified";
	// // =================

	delete arr1;
	delete arr2;
	delete arr3;
	delete arr4;
	delete arr5;
	delete arr6;

	return 0;
}

// Develop a class template Array that contains elements of type T and that implements
// the following behavior and functions:
//
// • Construction with no parameter: Creates an empty array.
//
// • Construction with an unsigned int n as a parameter: Creates an array of n elements
// initialized by default.
// Tip: Try to compile int * a = new int(); then display *a.
//
// • Construction by copy and assignment operator. In both cases, modifying either the
// original array or its copy after copying musn’t affect the other array.
//
// • You MUST use the operator new[] to allocate memory. Preventive allocation (al-
// locating memory in advance) is forbidden. Your program must never access non-
// allocated memory.
//
// • Elements can be accessed through the subscript operator: [ ].
//
// • When accessing an element with the [ ] operator, if its index is out of bounds, an
// std::exception is thrown.
//
// • A member function size() that returns the number of elements in the array. This
// member function takes no parameter and musn’t modify the current instance.
// As usual, ensure everything works as expected and turn in a main.cpp file that
// contains your tests.



