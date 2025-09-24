#include <iostream>
#include <vector>
#include <type_traits>

template <typename T>
void Merge(std::vector<T>& arr, size_t left, size_t mid, size_t right)
{
    std::vector<T> vec1(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<T> vec2(arr.begin() + mid + 1, arr.begin() + right + 1);

    size_t i = 0;
    size_t j = 0;
    size_t pos = left;

    while(i < vec1.size() && j < vec2.size()) {
        if(vec1[i] <= vec2[j]) {
            arr[pos++] = vec1[i++];
        }
        else {
            arr[pos++] = vec2[j++];
        }
    }

    while(j < vec2.size()) {
        arr[pos++] = vec2[j++];
    }

    while (i < vec1.size()) {
        arr[pos++] = vec1[i++];
    }
    
}

template <typename T>
void MergeSort(std::vector<T>& arr, size_t left, size_t right)
{
    if(left >= right) return;

    size_t mid = left + (right - left) / 2;

    MergeSort(arr, left, mid);

    MergeSort(arr, mid + 1, right);

    Merge(arr, left, mid, right);
}

int main()
{
    std::vector<int> vec = {34, 23, 76, 11, 88, 24, 65, 38, 8, 23, 2, 17, 27};

    MergeSort(vec, 0, vec.size() - 1);

    for(auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}