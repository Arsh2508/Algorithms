#include <iostream>
#include <type_traits>
#include <vector>

template <typename RandomIt>
void InsertionSort(RandomIt first, RandomIt last)
{
    using T = typename std::iterator_traits<RandomIt>::value_type;
    for(auto it = first + 1; it < last; ++it) {
        T key = *it;
        RandomIt j = it;

        while(j > first && *(j - 1) > key) {
            *j = *(j - 1);
            --j;
        }
        *j = key;
    }
}

int main()
{
    std::vector<double> vec = {3.3, 2.4, 6.3, 7, 9.78, 1, 6.1, 5};
    InsertionSort(vec.begin(), vec.end());
    for(double i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}