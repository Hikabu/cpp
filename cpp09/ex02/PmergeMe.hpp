#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <deque>
# include <iostream>
# include <ctime>
# include <cstring>
# include <sstream>
# define MAX 2147483647

template <typename Container>
void push(size_t value, Container&arr)
{
        arr.push_back(value);
}

template <typename Container>
void print(Container&arr)
{
        for (unsigned int i = 0; i < arr.size(); i++)
                std::cout << arr[i] << ' ';
        std::cout << std::endl;
}

template <typename Container>
Container sortMergeVector(Container &vec1, Container &vec2);

template <typename Container>
Container firstSortMergeVec(Container &arr);

template <typename Container>
void faster(Container &arr);
#include "PmergeMe.tpp"

#endif
