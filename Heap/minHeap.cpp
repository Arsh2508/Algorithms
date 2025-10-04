#include "minHeap.hpp"

#include <stdexcept>

template <typename T>
min_heap<T>::min_heap() : heap_size{0} {}

template <typename T>
min_heap<T>::min_heap(const std::vector<T> &array) : heap_size{0}, arr{array}
{
    BuildMinHeap();
}

template <typename T>
typename min_heap<T>::size_type min_heap<T>::left(size_type i)
{
    return 2 * i + 1;
}

template <typename T>
typename min_heap<T>::size_type min_heap<T>::right(size_type i)
{
    return 2 * i + 2;
}

template <typename T>
void min_heap<T>::MinHeapify(size_type i)
{
    size_type l = left(i);
    size_type r = right(i);
    size_type smallest = i;

    if(l < heap_size && arr[l] < arr[i]) {
        smallest = l;
    }
    if(r < heap_size && arr[r] < arr[smallest]) {
        smallest = r;
    }

    if(largest != i) {
        std::swap(arr[i], arr[smallest]);
        MinHeapify(smallest);
    }
}

template <typename T>
void min_heap<T>::BuildMinHeap()
{
    heap_size = arr.size();

    for(int i = heap_size / 2 - 1; i >= 0; --i) {
        MinHeapify(i);
    }
}

template <typename T>
typename min_heap<T>::reference min_heap<T>::top()
{
    if(heap_size < 1) throw std::out_of_range("Heap is empty!");
    return arr[0];
}

template <typename T>
typename min_heap<T>::const_reference min_heap<T>::top() const
{
    if(heap_size < 1) throw std::out_of_range("Heap is empty!");
    return arr[0];
}

template <typename T>
typename min_heap<T>::value_type min_heap<T>::extract_top()
{
    if(heap_size < 1) throw std::out_of_range("Heap is empty!");
    
    value_type min = arr[0];

    arr[0] = arr[heap_size - 1];
    --heap_size;

    MinHeapify(0);

    return min;
}

template <typename T>
void min_heap<T>::push(const_reference val)
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
        if(arr[parent] > arr[i]) {
            std::swap(arr[parent], arr[i]);
            i = parent;
        }
        else break;
    } 
    

}

template <typename T>
void min_heap<T>::pop()
{
    if(heap_size < 1) throw std::out_of_range("Heap is empty!");

    arr[0] = arr[heap_size - 1];
    --heap_size;

    MinHeapify(0);
}