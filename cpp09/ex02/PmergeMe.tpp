#include "PmergeMe.hpp"

template <typename Container>

// void  firstSortMergeVec(std::vector<int> &arr)
Container firstSortMergeVec(Container &arr)
{
    if (arr.size() <= 1)
        return arr;
    //deviding into two halves
    int mid = arr.size() / 2;
    Container left(arr.begin(), arr.begin() + mid);
    Container right(arr.begin() + mid, arr.end());

    //recurs sort two halves
    firstSortMergeVec(left);
    firstSortMergeVec(right);
    arr = sortMergeVector(left, right);
    return (arr);
}
template <typename Container>
Container sortMergeVector(const Container &vec1, const Container &vec2)
{
    // std::vector<int> result;
    // std::vector<int>::size_type i = 0, j = 0;

    Container result;
    typename Container::size_type i = 0, j = 0;

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
    while (j < vec2.size())
    {
        result.push_back(vec2[j]);
        j++;
    }
    return result;
}

