#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

template <typename T>
void print(std::vector<T>& arr) 
{
    for(int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

template <typename T>
int partition(std::vector<T>& arr, int left, int right) {
    int i = left;
    int j = right - 1;

    int pivot = left + (std::rand() % (right - left));
    
    std::swap(arr[right], arr[pivot]);
    
    while(i <= j) {
        while(arr[i] < arr[right]) ++i;
        while(j >= left && arr[j] >= arr[right]) --j;
        
        if(i < j) {
            std::swap(arr[i], arr[j]);
        }
    }
    
    std::swap(arr[i], arr[right]);
    
    return i;
}

template <typename T>
void quick_sort(std::vector<T>& arr, int left, int right) {
    if(left >= right) return;
    
    int pivot = partition(arr, left, right);
    quick_sort(arr, left, pivot - 1);
    quick_sort(arr, pivot + 1, right);
}

int main()
{
    std::srand(std::time(nullptr));
    std::vector<int> array = {4, 2, 6, 5, 4, 7, 3, 1};
    quick_sort(array, 0, array.size() - 1);

    print(array);

    return 0;
}