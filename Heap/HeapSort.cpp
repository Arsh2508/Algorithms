#include <iostream>
#include <vector>

template <typename T>
void MaxHeapify(std::vector<T>& arr, size_t heap_size, size_t i)
{
    size_t l = i * 2 + 1;
    size_t r = i * 2 + 2;
    size_t largest = i;

    if(l < heap_size && arr[l] > arr[largest]) {
        largest = l;
    }
    if(r < heap_size && arr[r] > arr[largest]) {
        largest = r;
    }

    if(largest != i) {
        std::swap(arr[i], arr[largest]);
        MaxHeapify(arr, heap_size, largest);
    }
}

template <typename T> 
void BuildMaxHeap(std::vector<T>& arr, size_t &heap_size)
{
    heap_size = arr.size();

    for(int i = (heap_size / 2) - 1; i >= 0; --i) {
        MaxHeapify(arr, heap_size, i);
    }
}

template <typename T>
void HeapSort(std::vector<T>& arr)
{
    size_t heap_size = 0;
    BuildMaxHeap(arr, heap_size);

    for(size_t i = heap_size - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        --heap_size;
        MaxHeapify(arr, heap_size, 0);
    }
}

int main()
{
    std::vector<int> arr = {4, 12, 6, 2, 34, 73, 12, 43};

    HeapSort(arr);

    std::cout << "The sorted array is \n";
    for(auto i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}