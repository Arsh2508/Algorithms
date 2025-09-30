#include <iostream>
#include <vector>

template <typename T>
int partition(std::vector<T>& arr, int left, int right) {
    T pivot = arr[left];
    int i = left + 1;
    int j = right;

    while(i <= j) {
        while(i <= right && arr[i] <= pivot) {
            ++i;
        }
        while(arr[j] > pivot) {
            --j;
        }
        if(i < j) {
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[j], arr[left]);

    return j;
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
    std::vector<int> array = {5, 2, 7, 1, 4, 8, 9, 3, 6};
    quick_sort(array, 0, array.size() - 1);

    for(int i : array) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}