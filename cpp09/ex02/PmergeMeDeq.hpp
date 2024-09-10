// #pragma once
#ifndef PMERGEMEDEQ_HPP
# define PMERGEMEDEQ_HPP

# include <vector>
# include <list>
# include <deque>
# include <iostream>
# include <ctime>
# include <cstring>
# include <sstream>
# include <set>
# include "PmergeMeDeq.hpp"
# define MAX 2147483647


class PmergeMeDeq{
	private:
		PmergeMeDeq(const PmergeMeDeq &) {};
		PmergeMeDeq &operator=(const PmergeMeDeq &) {return *this;};
	public:
	//sorting 
		PmergeMeDeq(){};
		~PmergeMeDeq(){};
		static void sortdeq(std::deque<int> &v);
		static void fill_pairs(std::deque<int> &v, std::deque<std::pair<int, int> > &pairs);
		static void sort_pairs(std::deque<std::pair<int, int> > &pairs);
		static void firstSortMergeVec(std::deque<std::pair<int, int> > &pairs, int left, int right);
		static void sortMergedeque(std::deque<std::pair<int, int> > &pairs, int left, int mid, int right);
		static void insert(std::deque<std::pair<int, int> > &pairs, std::deque<int> &new_v);
		static void print_groups(std::deque<std::deque<int> > &groups);
		static void insert_in_sorted(std::deque< std::deque<int> > &groups, std::deque<int> &sorted);
		static void binary_insert(std::deque<int> &sorted, int num, int group_index);
		static void devide_to_groups(std::deque<std::pair<int, int> > &pairs, std::deque<std::deque<int> > &groups);
		static void print_pairs(std::deque<std::pair<int, int> > &pairs);
		static void amount_of_groups(std::deque<std::pair<int, int> > &pairs, std::deque<std::deque<int> > &groups);
	};

#endif
