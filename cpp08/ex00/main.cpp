
// #include <vector>
// #include <map>
// #include <iostream>
// # include "easyfind.hpp"


// int main() {
//     // Sequential container (vector)
//     std::vector<int> numbers = {1, 2, 3, 4, 5};
//     numbers.push_back(6);  // Add to the end
    
//     // Print vector
//     for (int num : numbers) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;

//     // Associative container (map)
//     std::map<std::string, int> ages;
//     ages["Alice"] = 25;  // Add key-value pair
//     ages["Bob"] = 30;

//     // Print map
//     for (const auto& pair : ages) {
//         std::cout << pair.first << " is " << pair.second << " years old." << std::endl;
//     }

//     return 0;
// }

# include "easyfind.hpp"
int main()
{
    //works only with int and implicitly convertable to int
    std::vector<int> victor;
    std::list<int> lst;
    std::forward_list<int> forList;
    std::array<int, 7> arr;
    std::deque<int> deq;

    for (int i = 0; i < 5; i++)
    {
        victor.push_back(i);
        lst.push_back(i);
        forList.push_front(i);
        arr[i] = i;
        deq.push_back(i);
    }
    try
    {
        std::cout << *easyfind(victor, 4) << std::endl;
        std::cout << *easyfind(lst, 4) << std::endl;
        std::cout << *easyfind(forList, 2) << std::endl;
        std::cout << *easyfind(arr, 6) << std::endl;
        std::cout << *easyfind(deq, 8) << std::endl;
    }
    catch(std::exception &e)
    {       
        std::cerr << e.what() << std::endl;
    }

}

