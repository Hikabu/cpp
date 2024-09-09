
# include "PmergeMe.hpp"
# include "PmergeMeDeq.hpp"

int main(int ac, char **av)
{
    if (ac < 2 )
        std::cerr << "Not enough arguments" << std::endl;
    
    std::vector<int> victor;
    std::set<int> uniq;
    std::deque<int> deq;

    for (int i = 1; i < ac; i++)
    {
        std::istringstream iss(av[i]);
        long long val = 0;
        iss >> val;
        for (size_t j = 0; j < strlen(av[i]); j++)
        {
            if ( val > MAX || !isdigit(av[i][j]) )
            {
                std::cerr << "It is not positive digit" << std::endl;
                return 1;
            }
        } 
        try {
                push(val, victor);
                push(val, deq);
				std::vector<int>::iterator it = victor.begin();
				while(it != victor.end())
				{
					uniq.insert(*it);
					it++;
				}
				if (uniq.size() != victor.size())
				{
					std::cerr << "There is a duplicate\n" ;
					exit(1);
				}
            }
        catch (std::exception &e){
                std::cerr << "Error " << e.what() << std::endl; 
                return 1;
            }
    } 

    std::cout << "Before ";
    print (victor);
    clock_t start = clock();
    PmergeMe::sort(victor);
    clock_t end = clock();
    std::cout << "After ";
    print(victor);
    double duration = static_cast<double>(end - start) /  CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << ac - 1  << " elements with std::vector : " << std::fixed << duration  << " us" << std::endl;

    std::cout << "Before ";
    print (deq);
    start = clock();
    PmergeMeDeq::sortdeq(deq);
    end = clock();
    std::cout << "After ";
    print(deq);
    duration = static_cast<double>(end - start) /  CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << ac - 1  << " elements with std::vector : " << std::fixed << duration << " us" << std::endl;

}
