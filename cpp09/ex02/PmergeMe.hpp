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
# include <set>
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

class PmergeMe{
	private:
		PmergeMe(const PmergeMe &) {};
		PmergeMe &operator=(const PmergeMe &) {return *this;};
	public:
	//sorting vector
		PmergeMe(){};
		~PmergeMe(){};
		static void sort(std::vector<int> &v);
		static void fill_pairs(std::vector<int> &v, std::vector<std::pair<int, int> > &pairs);
		static void sort_pairs(std::vector<std::pair<int, int> > &pairs);
		static void firstSortMergeVec(std::vector<std::pair<int, int> > &pairs, int left, int right);
		static void sortMergeVector(std::vector<std::pair<int, int> > &pairs, int left, int mid, int right);
		static void insert(std::vector<std::pair<int, int> > &pairs, std::vector<int> &new_v);
		static void print_groups(std::vector<std::vector<int> > &groups);
		static void insert_in_sorted(std::vector< std::vector<int> > &groups, std::vector<int> &sorted);
		static void binary_insert(std::vector<int> &sorted, int num, int group_index);
		static void devide_to_groups(std::vector<std::pair<int, int> > &pairs, std::vector<std::vector<int> > &groups);
		static void print_pairs(std::vector<std::pair<int, int> > &pairs);
		static void amount_of_groups(std::vector<std::pair<int, int> > &pairs, std::vector<std::vector<int> > &groups);
	};

#endif
