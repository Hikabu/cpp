#include <iostream>
#include <string>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	for (int i = 1; i < ac; i++)
	{
		std::string s(av[i]);
		std::cout << av[i];
	}
	std::cout << std::endl;
	return (0);
}
