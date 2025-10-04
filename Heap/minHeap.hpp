#ifndef MIN_HEAP
#define MIN_HEAP
#include <vector>

template <typename T>
class min_heap {
public:

    using size_type = size_t;
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;

    min_heap();
    min_heap(const std::vector<T>& array);
    size_type left(size_type i);
    size_type right(size_type i);
    void MinHeapify(size_type i);
    void BuildMinHeap();

    reference top();
    const_reference top() const;

    value_type extract_top();

    void push(const_reference val);
    void pop();

private:
    std::vector<T> arr;
    size_type heap_size;
};

#include "minHeap.cpp"
#endif