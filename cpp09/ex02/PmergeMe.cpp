#include "PmergeMe.hpp"
void PmergeMe::fill_pairs(std::vector<int> &v, std::vector<std::pair<int, int> > &pairs)
{
    std::vector<int>::iterator it = v.begin();
    while(it != v.end())
    {
        std::pair<int, int> p;
        p.first = *it;
        it++;
        if (it != v.end()){
            p.second = *it;
            it++;
        }
        else
            p.second = 0;
        pairs.push_back(p);
    }
}

void PmergeMe::sort_pairs(std::vector<std::pair<int, int> > &pairs)
{
    std::vector<std::pair<int, int> >::iterator it = pairs.begin();
    while(it != pairs.end())
    {
        if (it->first < it->second) // need to sort large nbr firstly
        {
            int tmp = it->first;
            it->first = it->second;
            it->second = tmp;
        }
        it++;
    }
}
void PmergeMe::sortMergeVector(std::vector<std::pair<int, int> > &pairs, int left, int mid, int right) //vector is sorted by the frst el of each pair
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<std::pair<int, int> > L;
    std::vector<std::pair<int, int> > R;
    for (i = 0; i < n1; i++)
        L.push_back(pairs[left + i]);
    // print_pairs(L);
    for (j = 0; j < n2; j++)
        R.push_back(pairs[mid + j + 1]);
    // print_pairs(R);
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i].first <= R[j].first)
        {
            pairs[k] = L[i];
            i++;
        }
        else{
            pairs[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        pairs[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        pairs[k] = R[j];
        j++;
        k++;
    }
}
void PmergeMe::firstSortMergeVec(std::vector<std::pair<int, int> > &pairs, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        firstSortMergeVec(pairs, left, mid);
        firstSortMergeVec(pairs, mid + 1, right);
        sortMergeVector(pairs, left, mid, right);
    }
}

void PmergeMe::insert(std::vector<std::pair<int, int> > &pairs, std::vector<int> &newV)
{
    std::vector<std::pair<int, int> >::iterator it = pairs.begin();
    while (it != pairs.end())
    {
        newV.push_back(it->first);
        it++;
    }
    newV.insert(newV.begin(), pairs.begin()->second);
    pairs.erase(pairs.begin());
}
void PmergeMe::print_pairs(std::vector<std::pair<int, int> > &pairs)
{
    std::vector<std::pair<int, int> >::iterator it = pairs.begin();
    std::cout << "Pairs: " << std::endl;
    while (it != pairs.end())
    {
        std::cout << it->first << " " << it->second << std::endl;
        it++;
    }
}

void PmergeMe::print_groups(std::vector<std::vector<int> > &groups)
{
    std::vector<std::vector<int> >::iterator it = groups.begin();
    std::cout << "Groups: " << std::endl;
    while (it != groups.end())
    {
        std::vector<int>::iterator it2 = it->begin();
        while(it2 != it->end())
        {
            std::cout << *it2 << " ";
            it2++;
        }
        std::cout << std::endl;
        it++;
    }
}


void PmergeMe::binary_insert(std::vector<int> &sorted, int num, int groupIx)
{
    std::vector<int> copy = sorted;
    size_t i = pow(2, groupIx) - 1;
    if (i - sorted.size())
        copy.erase(copy.begin() + i, copy.end());
    int left = 0;
    int right = copy.size();
    size_t mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (sorted[mid] < num && mid + 1 < sorted.size() && sorted[mid + 1] > num)
        {
            sorted.insert(sorted.begin() + mid + 1, num);
            return ;
        }
        else if (sorted[mid] < num)
            left = mid + 1;
        else
            right = mid - 1;
    }
}
void PmergeMe::insert_in_sorted(std::vector<std::vector<int> > &groups, std::vector<int> &sorted)
{
    std::vector<std::vector<int> >::iterator it = groups.begin();
    int groupIx = 2;
    while (it != groups.end())
    {
        std::vector<int>::iterator it2 = it->begin();
        while(it2 != it->end() && *it2 != 0)
        {
            binary_insert(sorted, *it2, groupIx);
            it2++;
        }
        groupIx++;
        it++;
    }
    if (sorted[0] == 0)
        sorted.erase(sorted.begin());
}
void PmergeMe::amount_of_groups(std::vector<std::pair<int, int> > &pairs, std::vector<std::vector<int> > &groups)
{
    size_t var = 2;
    int i = 1;
    int last;
    while (var <= pairs.size() + 2)
    {
        std::vector<int> v;
        groups.push_back(v);
        i++;
        last = var;
        var = pow(2, i) - last;
    }
}
void PmergeMe::devide_to_groups(std::vector<std::pair<int, int> > &pairs, std::vector<std::vector<int> > &groups)
{
    size_t subVector = 0;
    std::vector<std::pair<int, int> >::iterator it = pairs.begin();
    amount_of_groups(pairs, groups);
    size_t var = 2;
    int last;
    while (subVector < groups.size())
    {
        for (size_t i = 0; i < var && it < pairs.end(); i++, it++)
        {
            if (it->second != 0)
                groups[subVector].insert(groups[subVector].begin(), it->second); //subVector 
        }
        last = var;
        subVector++;
        var = pow(2, subVector + 1) - last;// Merge pairs into groups of pow 
    }
}
void PmergeMe::sort(std::vector<int> &v)
{
    // print(v);
    std::vector<int> sorted;
    std::vector<std::pair<int, int> > pairs;
    fill_pairs(v, pairs);
    sort_pairs(pairs);
    firstSortMergeVec(pairs, 0, pairs.size() - 1);
    // print_pairs(pairs);
    insert(pairs, sorted);
    std::vector<std::vector<int> > groups;
    devide_to_groups(pairs, groups);
    // print_groups(groups);
    insert_in_sorted(groups, sorted);
	std::cout << std::endl;

}