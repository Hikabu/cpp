#include "PmergeMe.hpp"

// PmergeMe::PmergeMe(const PmergeMe &) {};
// PmergeMe &PmergeMe::operator=(const PmergeMe &) {
//     return *this;
// };

std::vector<int> firstSortMergeVec(std::vector <int> &arr)
{
    if (arr.size() <= 1)
        return ;
    //deviding into two halves
    int mid = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    //recurs sort two halves
    firstSortMergeVec(left);
    firstSortMergeVec(right);
    return sortMergeVector(left, right);
}
std::vector<int> sortMergeVector(std::vector<int> vec1, std::vector<int> vec2)
{
    std::vector<int> result;
    std::vector<int>::size_type i = 0, j = 0;

    while (i < vec1.size() && j < vec2.size())
    {
        if (vec1[i] < vec2[j]){
            result.push_back(vec1[i]);
            i++;
        }else {
            result.push_back(vec2[j]);
            j++;
        }
    }
    while (i < vec1.size())
    {
        result.push_back(vec1[i]);
        i++;
    }
    while (i < vec2.size())
    {
        result.push_back(vec2[j]);
        j++;
    }
    return result;
}

