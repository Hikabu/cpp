#include "Span.hpp"


int main() 
{
		srand(time(NULL));
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
		Span span(10);
		for(unsigned int i = 0; i < 10; i++)
			span.addNumber(std::rand() % 100);
		span.print();
		std::cout << "---Full array---\n";
		try{span.addNumber(88); span.print();}
		catch(std::exception &e){std::cerr << e.what() << std::endl;}

	}
  {
    std::cout << "---Only 1 arg---\n";
    Span span(1);
    try{span.addNumber(43); span.print(); span.longestSpan();}
    catch(std::exception &e){std::cerr << e.what() << std::endl;}
  }
  {
    Span span(10000);
    std::cout << "---Big span---\n";
    try 
    {
        std::vector<int> victor(10000);
        for (unsigned int i = 0; i < victor.size(); i++)
          span.addNumber(std::rand()); //max nmr not const  
        // span.print();
        std::cout << "The longest span is " << span.longestSpan() << std::endl;
        std::cout << "The shortest span is "  << span.shortestSpan() << std::endl;;
    }
    catch(std::exception &e){std::cerr << e.what() << std::endl;}
  }
	return 0; 
}

