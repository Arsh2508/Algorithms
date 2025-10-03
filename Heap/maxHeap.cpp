#include "maxHeap.hpp"
#include <stdexcept>

template <typename T>
max_heap<T>::max_heap() : heap_size{0} {}

template <typename T>
max_heap<T>::max_heap(const std::vector<T> &array) : heap_size{0}, arr{array}
{
    BuildMaxHeap();
}

template <typename T>
typename max_heap<T>::size_type max_heap<T>::left(size_type i)
{
    return 2 * i + 1;
}

template <typename T>
typename max_heap<T>::size_type max_heap<T>::right(size_type i)
{
    return 2 * i + 2;
}

template <typename T>
void max_heap<T>::MaxHeapify(size_type i)
{
    size_type l = left(i);
    size_type r = right(i);
    size_type largest = i;

    if(l < heap_size && arr[l] > arr[i]) {
        largest = l;
    }
    if(r < heap_size && arr[r] > arr[largest]) {
        largest = r;
    }

    if(largest != i) {
        std::swap(arr[i], arr[largest]);
        MaxHeapify(largest);
    }
}

template <typename T>
void max_heap<T>::BuildMaxHeap()
{
    heap_size = arr.size();

    for(int i = heap_size / 2 - 1; i >= 0; --i) {
        MaxHeapify(i);
    }
}

template <typename T>
typename max_heap<T>::reference max_heap<T>::top()
{
    if(heap_size < 1) throw std::out_of_range("Heap is empty!");
    return arr[0];
}

template <typename T>
typename max_heap<T>::const_reference max_heap<T>::top() const
{
    if(heap_size < 1) throw std::out_of_range("Heap is empty!");
    return arr[0];
}

template <typename T>
typename max_heap<T>::value_type max_heap<T>::extract_top()
{
    if(heap_size < 1) throw std::out_of_range("Heap is empty!");
    
    value_type max = arr[0];

    arr[0] = arr[heap_size - 1];
    --heap_size;

    MaxHeapify(0);

    return max;
}

template <typename T>
void max_heap<T>::push(const_reference val)
{
    if(heap_size == arr.size()) {
        arr.push_back(val);
    }
    else {
        arr[heap_size] = val;
    }

    size_type i = heap_size;
    ++heap_size;

    while(i > 0) {
        size_type parent = (i - 1) / 2;
        if(arr[parent] < arr[i]) {
            std::swap(arr[parent], arr[i]);
            i = parent;
        }
        else break;
    } 
    

}

template <typename T>
void max_heap<T>::pop()
{
    --heap_size;
}
