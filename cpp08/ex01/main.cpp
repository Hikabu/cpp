#include "Span.hpp"


int main() 
{
	{
		std::cout << "Main test says: " << std::endl; 
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	
	{		
		std::cout << "---Fill array---\n";
		Span span(9);
		// std::vector<int> victor(10000);
		srand(time(NULL));
		for(unsigned int i = 0; i < 10; i++)
			span.addNumber(std::rand() % 100);
		span.print();
		std::cout << "---Full array---\n";
		try{span.addNumber(88);}
		catch(std::exception &e){std::cerr << e.what() << std::endl;}
	}
	return 0; 
}

