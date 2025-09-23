#include <iostream>
#include <vector>

template <typename RandomIt>
void BubbleSort(RandomIt first, RandomIt last)
{
    if(first == last) return;
    
    for(auto it = last; it != first; --it) { 
        for(auto itj = first + 1; itj < it; ++itj) {
            if(*itj < *(itj - 1)) {
                auto tmp = *itj;
                *itj = *(itj - 1);
                *(itj - 1) = tmp;
            }
        }
    }
}

int main()
{
    std::vector<int> vec = {3, 2, 6, 4, 7, 1, 8, 3};
    BubbleSort(vec.begin(), vec.end());

    for(auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}