#include "MutantStack.hpp"
int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top element is: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout<< "the size is: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	std::cout << "Begin: " << *it << std::endl;
	std::cout << "------------------" << std::endl;
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "------------------" << std::endl;
	std::stack<int> s(mstack);

		std::cout << "----Copy constructor----" << std::endl;
	MutantStack<int> dstack(mstack);
	std::cout << "Mstack size: " << mstack.size() << std::endl;
	std::cout << "Dstack size: " << dstack.size() << std::endl;

	std::cout << std::endl;


	std::cout << "----Assignment operator----" << std::endl;
	MutantStack<int> nstack;
	nstack = mstack;
	std::cout << "Mstack size: " << mstack.size() << std::endl;
	std::cout << "Nstack size: " << nstack.size() << std::endl;

	std::cout << std::endl;

	std::cout << "---------list--------" << std::endl;
	MutantStack<int, std::list<int> > lst;
	lst.push(9);
	lst.push(19);
	lst.push(29);
	lst.push(409);

	std::cout << "size list: " << lst.size() << std::endl;
	std::cout << "top element is: " << lst.top() << std::endl;

	std::cout << "---------vector--------" << std::endl;
	MutantStack<int, std::vector<int> > victor;
	victor.push(9);
	victor.push(19);
	victor.push(29);
	victor.push(59);

	std::cout << "size list: " << victor.size() << std::endl;
	std::cout << "top element is: " << victor.top() << std::endl;

	return 0;
}