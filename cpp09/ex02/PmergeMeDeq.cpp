#include "PmergeMeDeq.hpp"
void PmergeMeDeq::fill_pairs(std::deque<int> &v, std::deque<std::pair<int, int> > &pairs)
{
    std::deque<int>::iterator it = v.begin();
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

void PmergeMeDeq::sort_pairs(std::deque<std::pair<int, int> > &pairs)
{
    std::deque<std::pair<int, int> >::iterator it = pairs.begin();
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
void PmergeMeDeq::sortMergedeque(std::deque<std::pair<int, int> > &pairs, int left, int mid, int right) //deque is sorted by the frst el of each pair
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::deque<std::pair<int, int> > L;
    std::deque<std::pair<int, int> > R;
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
void PmergeMeDeq::firstSortMergeVec(std::deque<std::pair<int, int> > &pairs, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        firstSortMergeVec(pairs, left, mid);
        firstSortMergeVec(pairs, mid + 1, right);
        sortMergedeque(pairs, left, mid, right);
    }
}

void PmergeMeDeq::insert(std::deque<std::pair<int, int> > &pairs, std::deque<int> &newV)
{
    std::deque<std::pair<int, int> >::iterator it = pairs.begin();
    while (it != pairs.end())
    {
        newV.push_back(it->first);
        it++;
    }
    newV.insert(newV.begin(), pairs.begin()->second);
    pairs.erase(pairs.begin());
}
void PmergeMeDeq::print_pairs(std::deque<std::pair<int, int> > &pairs)
{
    std::deque<std::pair<int, int> >::iterator it = pairs.begin();
    std::cout << "Pairs: " << std::endl;
    while (it != pairs.end())
    {
        std::cout << it->first << " " << it->second << std::endl;
        it++;
    }
}

void PmergeMeDeq::print_groups(std::deque<std::deque<int> > &groups)
{
    std::deque<std::deque<int> >::iterator it = groups.begin();
    std::cout << "Groups: " << std::endl;
    while (it != groups.end())
    {
        std::deque<int>::iterator it2 = it->begin();
        while(it2 != it->end())
        {
            std::cout << *it2 << " ";
            it2++;
        }
        std::cout << std::endl;
        it++;
    }
}


void PmergeMeDeq::binary_insert(std::deque<int> &sorted, int num, int groupIx)
{
    std::deque<int> copy = sorted;
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
void PmergeMeDeq::insert_in_sorted(std::deque<std::deque<int> > &groups, std::deque<int> &sorted)
{
    std::deque<std::deque<int> >::iterator it = groups.begin();
    int groupIx = 2;
    while (it != groups.end())
    {
        std::deque<int>::iterator it2 = it->begin();
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
void PmergeMeDeq::amount_of_groups(std::deque<std::pair<int, int> > &pairs, std::deque<std::deque<int> > &groups)
{
    size_t var = 2;
    int i = 1;
    int last;
    while (var <= pairs.size() + 2)
    {
        std::deque<int> v;
        groups.push_back(v);
        i++;
        last = var;
        var = pow(2, i) - last;
    }
}
void PmergeMeDeq::devide_to_groups(std::deque<std::pair<int, int> > &pairs, std::deque<std::deque<int> > &groups)
{
    size_t subdeque = 0;
    std::deque<std::pair<int, int> >::iterator it = pairs.begin();
    amount_of_groups(pairs, groups);
    size_t var = 2;
    int last;
    while (subdeque < groups.size())
    {
        for (size_t i = 0; i < var && it < pairs.end(); i++, it++)
        {
            if (it->second != 0)
                groups[subdeque].insert(groups[subdeque].begin(), it->second); //subdeque 
        }
        last = var;
        subdeque++;
        var = pow(2, subdeque + 1) - last;// Merge pairs into groups of pow 
    }
}
void PmergeMeDeq::sortdeq(std::deque<int> &v)
{
    // print(v);
    std::deque<int> sorted;
    std::deque<std::pair<int, int> > pairs;
    fill_pairs(v, pairs);
    sort_pairs(pairs);
    firstSortMergeVec(pairs, 0, pairs.size() - 1);
    // print_pairs(pairs);
    insert(pairs, sorted);
    std::deque<std::deque<int> > groups;
    devide_to_groups(pairs, groups);
    // print_groups(groups);
    insert_in_sorted(groups, sorted);
	std::cout << std::endl;

}