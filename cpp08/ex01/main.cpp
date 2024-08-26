#include "Span.hpp"


int main() 
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

  try
  {

  }
  catch(std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0; 
}

