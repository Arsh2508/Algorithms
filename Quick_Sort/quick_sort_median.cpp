#include <iostream>
#include <vector>

template <typename T>
int partition(std::vector<T>& arr, int left, int right) {
    int i = left;
    int j = right - 1;

    int mid = left + (right - left) / 2;
    int pivot = 0;
    if(arr[left] <= arr[mid] || arr[mid] <= arr[right]) {
        pivot = mid;
    }
    else if(arr[mid] <= arr[left] || arr[left] <= arr[right]) {
        pivot = left;
    }
    else {
        pivot = right;
    }

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
    std::vector<int> array = {3, 1, 5, 2, 4, 7, 6, 9, 0};
    quick_sort(array, 0, array.size() - 1);

    for(int i : array) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}