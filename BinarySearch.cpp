#include <iostream>
#include <vector>
#include <type_traits>
#include <algorithm>

template <typename RandomIt, typename T = typename std::iterator_traits<RandomIt>::value_type>
bool BinarySearch(RandomIt first, RandomIt last, const T& target)
{
    while(first <= last) {
        RandomIt mid = first + (last - first) / 2;
        if(*mid == target) {
            return true;
        }
        if(*mid > target) {
            last = mid - 1;
        }
        else {
            first = mid + 1;
        }
    }

    return false;
}

template <typename RandomIt, typename T = typename std::iterator_traits<RandomIt>::value_type>
bool BinarySearchRec(RandomIt first, RandomIt last, const T& target)
{
    if(first > last) {
        return false;
    }

    RandomIt mid = first + (last - first) / 2;
    if(*mid == target) {
        return true;
    }
    if(*mid > target) {
        return BinarySearchRec(first, mid - 1, target);
    }
    else {
        return BinarySearchRec(mid + 1, last, target);
    }
}

int main()
{
    std::vector<int> vec = {4, 2, 7, 9, 5, 13, 5, 23, 8, 14, 6};
    std::sort(vec.begin(), vec.end());
    
    for(auto i : {4, 6, 13, 66, 12, 1}){
        if(BinarySearch(vec.begin(), vec.end(), i)) {
            std::cout << "Found \n";
        }
        else {
            std::cout << "Not found\n";
        }
    }
    std::cout << std::endl;

        for(auto i : {4, 6, 13, 66, 12, 1}){
        if(BinarySearchRec(vec.begin(), vec.end(), i)) {
            std::cout << "Found: Recursively\n";
        }
        else {
            std::cout << "Not found: Revursively\n";
        }
    }
    return 0;
}