#include <iostream>
#include <vector>

template <typename T>
int partition(std::vector<T>& arr, int left, int right){
    T pivot = arr[right];
    int j = right - 1;
    int i = left;

    while(i <= j) {
        while(arr[i] < pivot) ++i;
        while(j >= left && arr[j] >= pivot) --j;

        if(i < j) {
            std::swap(arr[j], arr[i]);
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
    std::vector<int> array = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    quick_sort(array, 0, array.size() - 1);

    for(int i : array) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}