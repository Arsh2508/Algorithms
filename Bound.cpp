#include <iostream>
#include <vector>
#include <type_traits>

template <typename RandomIt, typename T = typename std::iterator_traits<RandomIt>::value_type> 
RandomIt lower_bound(RandomIt first, RandomIt last, const T& value)
{
    RandomIt it;
    typename std::iterator_traits<RandomIt>::difference_type count, step;
    count = last - first;
    
    while(count > 0) {
        step = count / 2;
        it = first + step;
        if(*it < value) {
            first = it + 1;
            count -= (step + 1);
        }
        else {
            count = step;
        }
    }
    return first;
}

template <typename RandomIt, typename T = typename std::iterator_traits<RandomIt>::value_type> 
RandomIt upper_bound(RandomIt first, RandomIt last, const T& value)
{
    RandomIt it;
    typename std::iterator_traits<RandomIt>::difference_type count, step;
    count = last - first;

    while(count > 0) {
        step = count / 2;
        it = first + step;
        if(*it <= value) {
            first = it + 1;
            count -= (step + 1);
        }
        else {
            count = step;
        }
    }
    return first;
}




int main()
{
    std::vector<int> arr = {1, 2, 2, 4, 4, 4, 5, 5, 6, 8, 8, 9};

    auto it = ::lower_bound(arr.begin(), arr.end(), 5);
    std::cout << *it++ << " " << *it++ << " " << *it << std::endl;

    auto it2 = ::upper_bound(arr.begin(), arr.end(), 5);
    std::cout << *it2++ << " " << *it2++ << " " << *it2 << std::endl;
    return 0;
}