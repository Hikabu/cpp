# include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2 )
        std::cerr << "Not enough arguments" << std::endl;
    
    std::vector<int> victor;

    for (int i = 1; i < ac; i++)
    {
        for (size_t j = 0; j < strlen(av[i]); j++)
        {
            if (!isdigit(av[i][j]))
            {
                std::cerr << "It is not positive digit" << std::endl;
                return 1;
            }
        } 
        try {
                std::istringstream iss(av[i]);
                push(std::stoi(av[i]), victor);
            }
        catch (std::exception &e){
                std::cerr << "Error " << e.what() << std::endl; 
                return 1;
            }
    } 

    std::cout << "Before ";
    print (victor);
    firstSortMergeVec(victor);
    std::cout << "After ";
    print(victor);
}
